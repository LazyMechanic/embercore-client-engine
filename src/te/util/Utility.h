#pragma once

#include <memory>

#include <boost/shared_ptr.hpp>

namespace te {
namespace util {
namespace detail {
template <class T>
struct SharedPtrHolder {
    using SharedPtr = T;

    /**
     * \brief Shared ptr instance
     */
    T ptr;

    /**
     * \brief SharedPtrHolder specific constructor
     * \param ptr Shared ptr
     */
    explicit SharedPtrHolder(const T& ptr);

    /**
     * \brief SharedPtrHolder copy constructor
     */
    SharedPtrHolder(const SharedPtrHolder&);

    /**
     * \brief SharedPtrHolder move constructor
     */
    SharedPtrHolder(SharedPtrHolder&&) noexcept;

    /**
     * \brief SharedPtrHolder destructor
     */
    ~SharedPtrHolder();

    /**
     * \brief Functor
     * \param ... 
     */
    void operator()(...);
};
} // namespace detail

/**
 * \brief Cast boost::shared_ptr to std::shared_ptr
 * \tparam T Type that is contained in the shared ptr
 * \param ptr Shared ptr 
 * \return Converted shared ptr
 */
template <class T>
std::shared_ptr<T> sharedPtrCast(const boost::shared_ptr<T>& ptr);

/**
 * \brief Cast std::shared_ptr to boost::shared_ptr
 * \tparam T Type that is contained in the shared ptr
 * \param ptr Shared ptr
 * \return Converted shared ptr
 */
template <class T>
boost::shared_ptr<T> sharedPtrCast(const std::shared_ptr<T>& ptr);

#include "Utility.inl"
} // namespace util
} // namespace te