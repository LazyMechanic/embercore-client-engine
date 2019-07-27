template <class T>
Singleton<T>::Singleton()
{
    assert(m_instance == nullptr && "A singleton object cannot be created more than once");
    m_instance = static_cast<T*>(this);
}

template <class T>
Singleton<T>::~Singleton()
{
    assert(m_instance != nullptr && "Singleton ptr was manually deleted");
    m_instance = nullptr;
}

template <class T>
T& Singleton<T>::instance()
{
    assert(m_instance != nullptr && "Singleton ptr was manually deleted or not created yet");
    return (*m_instance);
}

template <class T>
T* Singleton<T>::m_instance;