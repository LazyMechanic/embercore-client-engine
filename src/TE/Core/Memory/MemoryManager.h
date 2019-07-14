#pragma once
#include <unordered_map>
#include <functional>
#include <typeindex>
#include <stdexcept>
#include <memory>

#include <TE/Core/Memory/AbstractAllocator.h>

namespace te {
class MemoryManager
{
public:
    /**
     * \brief Default MemoryManager constructor
     */
    MemoryManager() = default;

    /**
     * \brief Copy MemoryManager constructor
     */
    MemoryManager(const MemoryManager&) = delete;

    /**
     * \brief Move MemoryManager constructor
     */
    MemoryManager(MemoryManager&&) = default;

    /**
     * \brief MemoryManager destructor
     */
    ~MemoryManager() = default;

    /**
     * \brief Find a suitable allocator and allocate memory
     * \tparam ResourceType Resource type
     * \return Pointer to allocated memory
     */
    template <typename ResourceType>
    ResourceType* allocate();

    /**
     * \brief Find a suitable allocator and deallocate memory
     * \tparam ResourceType Resource type
     * \param resourcePtr Pointer to released resource
     */
    template <typename ResourceType>
    void deallocate(ResourceType* resourcePtr);

    /**
     * \brief Add allocator to memory manager by copy constructor
     * \tparam AllocType Allocator type
     * \tparam ResourceType Resource type
     * \param alloc Allocator
     */
    template <typename ResourceType, class AllocType, typename = typename std::enable_if<std::is_base_of<AbstractAllocator, AllocType>::value>::type>
    void addAllocator(std::shared_ptr<AllocType> alloc);

    /**
     * \brief Get shared ptr to allocator
     * \tparam ResourceType Resource type
     * \return If allocator for \a ResourceType exists then return ptr to it, nullptr otherwise
     */
    template <typename ResourceType>
    std::shared_ptr<AbstractAllocator> getAllocator() const;

    /**
     * \brief Allocate memory for resource and create smart ptr to it
     * \tparam ResourceType Resource type
     * \tparam Args Arguments types
     * \param argv Arguments
     * \return Smart ptr to resource
     */
    template <typename ResourceType, typename ... Args>
    std::shared_ptr<ResourceType> create(Args&& ... argv);

private:
    template<typename ResourceType>
    void resourceDeleter(ResourceType* resource)
    {
        resource->~ResourceType();
        deallocate(resource);
    }

    /**
     * \brief Allocators for his types
     */
    std::unordered_map<std::type_index, std::shared_ptr<AbstractAllocator>> m_allocators;
};

template <typename ResourceType>
ResourceType* MemoryManager::allocate()
{
    auto allocIt = m_allocators.find(std::type_index(typeid(ResourceType)));

    if (allocIt == m_allocators.end()) {
        throw std::logic_error("Allocator for specific type doesn\'t exist");
    }

    return std::reinterpret_pointer_cast<AbstractAllocator>(allocIt->second)->allocate();
}

template <typename ResourceType>
void MemoryManager::deallocate(ResourceType* resourcePtr)
{
    auto allocIt = m_allocators.find(std::type_index(typeid(ResourceType)));

    if (allocIt == m_allocators.end()) {
        throw std::logic_error("Allocator for specific type doesn\'t exist");
    }

    std::reinterpret_pointer_cast<AbstractAllocator>(allocIt->second)->deallocate(resourcePtr);
}

template <typename ResourceType, class AllocType, typename>
void MemoryManager::addAllocator(std::shared_ptr<AllocType> alloc)
{
    // If the allocator of this resource type exist of then throws exception
    if (m_allocators.find(std::type_index(typeid(ResourceType))) != m_allocators.end()) {
        throw std::logic_error("Addable allocator already exists");
    }

    // Add new allocator
    m_allocators[std::type_index(typeid(ResourceType))] = alloc;
}

template <typename ResourceType>
std::shared_ptr<AbstractAllocator> MemoryManager::getAllocator() const
{
    const auto allocIt = m_allocators.find(std::type_index(typeid(ResourceType)));
    if (allocIt == m_allocators.end()) {
        return nullptr;
    }

    return std::reinterpret_pointer_cast<AbstractAllocator>(allocIt->second);
}

template <typename ResourceType, typename ... Args>
std::shared_ptr<ResourceType> MemoryManager::create(Args&& ... argv)
{
    ResourceType* resource = new(allocate<ResourceType>()) ResourceType(std::forward<Args>(argv)...);
    std::shared_ptr<ResourceType> resourceSharedPtr(resource,
        std::bind(&MemoryManager::resourceDeleter<ResourceType>,
            this,
            std::placeholders::_1));

    return resourceSharedPtr;
}
}