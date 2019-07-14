#pragma once

#include <algorithm>
#include <vector>
#include <list>

#include <TE/Core/Memory/AbstractAllocator.h>

namespace te {
template <typename ResourceType>
class ObjectPool : public AbstractAllocator {
public:
    /**
     * \brief ObjectPool constructor
     * \param chunkSize Size of each chunks
     * \param initChunkNumber Init chunk number
     * \param isFixed If true then pool can't expand
     */
    explicit ObjectPool(std::size_t chunkSize = 1024, std::size_t initChunkNumber = 1, bool isFixed = false);

    /**
     * \brief Copy ObjectPool constructor
     */
    ObjectPool(const ObjectPool&) = delete;

    /**
     * \brief Move ObjectPool constructor
     */
    ObjectPool(ObjectPool&&) = default;

    /**
     * \brief ObjectPool destructor
     */
    ~ObjectPool() = default;

    /**
     * \brief Allocate memory
     * \return Pointer to allocated memory
     */
    void* allocate() override;

    /**
     * \brief Deallocate memory
     * \param resourcePtr Pointer to released resource
     */
    void deallocate(void* resourcePtr) noexcept override;

private:
    /**
     * \brief uint8_t alias
     */
    using Byte = uint8_t;

    /**
     * \brief std::vector<Byte> alias
     */
    using Chunk = std::vector<Byte>;

    /**
     * \brief Size of each chunks
     */
    const std::size_t m_chunkSize;

    /**
     * \brief Size of resource (std::max(sizeof(ResourceType), sizeof(Byte*)))
     */
    const std::size_t m_resourceSize;

    /**
     * \brief If true then pool can't expand
     */
    const bool m_isFixed;

    /**
     * \brief List of chunks
     */
    std::list<Chunk> m_chunks;

    /**
     * \brief Ptr to next free block
     */
    Byte* m_nextFreeBlock;

    /**
     * \brief Add one chunk
     */
    void addChunk();

    /**
     * \brief Get ptr to next free resource and compute next ptr after that
     * \return Ptr to free resource
     */
    ResourceType* getNextFreeResource();
};

template <typename ResourceType>
ObjectPool<ResourceType>::ObjectPool(std::size_t chunkSize, std::size_t initChunkNumber, bool isFixed) :
    m_chunkSize(chunkSize),
    m_resourceSize(std::max(sizeof(ResourceType), sizeof(Byte*))),
    m_isFixed(isFixed),
    m_nextFreeBlock(nullptr)
{
    for (std::size_t i = 0; i < initChunkNumber; ++i) {
        addChunk();
    }
}

template <typename ResourceType>
void* ObjectPool<ResourceType>::allocate()
{
    ResourceType* resource = getNextFreeResource();

    if (resource == nullptr) {
        throw std::bad_alloc();
    }

    return resource;
}

template <typename ResourceType>
void ObjectPool<ResourceType>::deallocate(void* resourcePtr) noexcept
{
    Byte* deallocatedBlock = reinterpret_cast<Byte*>(resourcePtr);

    Byte** ptrToDeallocatedBlock = reinterpret_cast<Byte * *>(deallocatedBlock);
    *ptrToDeallocatedBlock = m_nextFreeBlock;
    m_nextFreeBlock = deallocatedBlock;
}

template <typename ResourceType>
void ObjectPool<ResourceType>::addChunk()
{
    m_chunks.emplace_back(m_resourceSize * m_chunkSize);

    for (auto it = m_chunks.back().begin(); it != m_chunks.back().end(); it = std::next(it, m_resourceSize)) {
        Byte** ptrToNextFreeBlock = reinterpret_cast<Byte * *>(&*it);
        *ptrToNextFreeBlock = m_nextFreeBlock;
        m_nextFreeBlock = &*it;
    }
}

template <typename ResourceType>
ResourceType* ObjectPool<ResourceType>::getNextFreeResource()
{
    // If there are no free block
    if (m_nextFreeBlock == nullptr) {
        // If it can add new chunk
        if (!m_isFixed) {
            addChunk();
        }
        else {
            return nullptr;
        }
    }

    ResourceType* freeResource = reinterpret_cast<ResourceType*>(m_nextFreeBlock);
    Byte** ptrToNextFreeBlock = reinterpret_cast<Byte * *>(m_nextFreeBlock);
    m_nextFreeBlock = *ptrToNextFreeBlock;

    return freeResource;
}
}