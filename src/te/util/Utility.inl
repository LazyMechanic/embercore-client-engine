namespace detail {
template <class T>
SharedPtrHolder<T>::SharedPtrHolder(const T& ptr) : ptr(ptr)
{}

template <class T>
SharedPtrHolder<T>::SharedPtrHolder(const SharedPtrHolder&) = default;

template <class T>
SharedPtrHolder<T>::SharedPtrHolder(SharedPtrHolder&&) noexcept = default;

template <class T>
SharedPtrHolder<T>::~SharedPtrHolder() = default;

template <class T>
void SharedPtrHolder<T>::operator()(...)
{
    ptr.reset();
}
} // namespace detail

template <class T>
std::shared_ptr<T> sharedPtrCast(const boost::shared_ptr<T>& ptr)
{
    typedef detail::SharedPtrHolder<std::shared_ptr<T>> H;
    if (H* h = boost::get_deleter<H>(ptr)) {
        return h->ptr;
    }

    return std::shared_ptr<T>(ptr.get(), detail::SharedPtrHolder<boost::shared_ptr<T>>(ptr));
}

template <class T>
boost::shared_ptr<T> sharedPtrCast(const std::shared_ptr<T>& ptr)
{
    typedef detail::SharedPtrHolder<boost::shared_ptr<T>> H;
    if (H* h = std::get_deleter<H>(ptr)) {
        return h->ptr;
    }

    return boost::shared_ptr<T>(ptr.get(), detail::SharedPtrHolder<std::shared_ptr<T>>(ptr));
}