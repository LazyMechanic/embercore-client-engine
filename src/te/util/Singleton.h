#pragma once

#include <cassert>

namespace te {
template <class T>
class Singleton {
public:
    /**
     * \brief Singleton default constructor. Create static ptr to \a this
     */
    Singleton();

    /**
     * \brief Singleton copy constructor
     */
    Singleton(const Singleton<T>&) = delete;

    /**
     * \brief Singleton move constructor
     */
    Singleton(Singleton<T>&&) = delete;

    /**
     * \brief Singleton copy assignment operator
     * \return Reference to \a *this
     */
    Singleton& operator=(const Singleton<T>&) = delete;

    /**
     * \brief Singleton move assignment operator
     * \return Reference to \a *this
     */
    Singleton& operator=(Singleton<T>&&) = delete;

    /**
     * \brief Singleton destructor
     */
    virtual ~Singleton();

    /**
     * \brief Get instance of \a this object
     * \return Reference to \a *this
     */
    static T& instance();

protected:
    /**
     * \brief Ptr to instance of \a this object
     */
    static T* m_instance;
};

#include "Singleton.inl"
} // namespace te