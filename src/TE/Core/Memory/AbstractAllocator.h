#pragma once

/**
 * \brief Abstract allocator class. Each allocator must be inherits of this class
 */
class AbstractAllocator
{
public:
    /**
     * \brief Allocate memory
     * \return Pointer to allocated memory
     */
    virtual void* allocate() = 0;

    /**
     * \brief Deallocate memory
     * \param resourcePtr Pointer to released resource
     */
    virtual void deallocate(void* resourcePtr) noexcept = 0;
};
