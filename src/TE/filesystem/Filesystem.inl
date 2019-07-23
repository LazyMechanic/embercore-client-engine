template <class ReaderImplType, class WriterImplType, class CacheImplType>
Filesystem::Filesystem(ReaderImplType&& readerImpl,
                       ReaderImplType&& writerImpl,
                       CacheImplType&& cacheImpl,
                       const std::filesystem::path& rootDir)
{
    setReaderImpl(readerImpl);
    setWriterImpl(writerImpl);
    setCacheImpl(cacheImpl);
}

template <class ReaderImplType>
void Filesystem::setReaderImpl(ReaderImplType&& readerImpl)
{
    static_assert(std::is_base_of<IFilesystemReader, ReaderImplType>::value == true,
                  "Filesystem reader implementation must be derived from IFilesystemReader class");

    m_readerImpl = std::make_unique<typename std::remove_reference<ReaderImplType>::type>(
        std::forward<ReaderImplType>(readerImpl));
}

template <class WriterImplType>
void Filesystem::setWriterImpl(WriterImplType&& writerImpl)
{
    static_assert(std::is_base_of<IFilesystemWriter, WriterImplType>::value == true,
                  "Filesystem writer implementation must be derived from IFilesystemWriter class");

    m_writerImpl = std::make_unique<typename std::remove_reference<WriterImplType>::type>(
        std::forward<WriterImplType>(writerImpl));
}

template <class CacheImplType>
void Filesystem::setCacheImpl(CacheImplType&& cacheImpl)
{
    static_assert(std::is_base_of<IFilesystemCache, CacheImplType>::value == true,
                  "Filesystem cache implementation must be derived from IFilesystemCache class");

    m_cacheImpl =
        std::make_unique<typename std::remove_reference<CacheImplType>::type>(std::forward<CacheImplType>(cacheImpl));
}