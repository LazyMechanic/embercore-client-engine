#pragma once

#include <filesystem>
#include <mutex>
#include <vector>

#include "te/filesystem/FileData.h"
#include "te/filesystem/IFilesystemCache.h"
#include "te/filesystem/IFilesystemReader.h"
#include "te/filesystem/IFilesystemWriter.h"
#include "te/util/Singleton.h"

namespace te {
class Filesystem : public Singleton<Filesystem> {
public:
    /**
     * \brief Filesystem default constructor. Root directory is std::filesystem::current_path()
     * and mode is ReadMode::Raw by default
     */
    Filesystem();

    /**
     * \brief Filesystem specific constructor.
     * \tparam ReaderImplType Filesystem reader implementation type
     * \tparam WriterImplType Filesystem writer implementation type
     * \tparam CacheImplType Filesystem cache implementation type
     * \param readerImp Filesystem reader implementation
     * \param writerImp Filesystem writer implementation
     * \param cacheImp Filesystem cache implementation
     * \param rootDir Root directory
     */
    template <class ReaderImplType, class WriterImplType, class CacheImplType>
    Filesystem(ReaderImplType&& readerImp,
               ReaderImplType&& writerImp,
               CacheImplType&& cacheImp,
               const std::filesystem::path& rootDir = std::filesystem::current_path());

    /**
     * \brief Filesystem copy constructor
     */
    Filesystem(const Filesystem&) = delete;

    /**
     * \brief Filesystem  destructor
     */
    ~Filesystem() = default;

    /**
     * \brief Set filesystem reader implementation
     * \tparam ReaderImplType Filesystem reader implementation type
     * \param readerImpl Instance of filesystem reader implementation
     */
    template <class ReaderImplType>
    void setReaderImpl(ReaderImplType&& readerImpl);

    /**
     * \brief Set filesystem writer implementation
     * \tparam WriterImplType Filesystem writer implementation type
     * \param writerImpl Instance of filesystem writer implementation
     */
    template <class WriterImplType>
    void setWriterImpl(WriterImplType&& writerImpl);

    /**
     * \brief Set filesystem cache implementation
     * \tparam CacheImplType Filesystem cache implementation type
     * \param cacheImpl Instance of filesystem cache implementation
     */
    template <class CacheImplType>
    void setCacheImpl(CacheImplType&& cacheImpl);

    /**
     * \brief Set root directory. Also clear cache
     * \param rootDir Root directory
     */
    void setRootDir(const std::filesystem::path& rootDir);

    /**
     * \brief Read file data. Caching file in memory
     * \param path Path to file relative root dir
     * \return File data
     */
    FileData read(const std::filesystem::path& path) const;

    /**
     * \brief Write data to file on disc
     * \param path Path to file relative root dir
     * \param data File data
     */
    void write(const std::filesystem::path& path, const FileData& data) const;

    /**
     * \brief Write string to file on disc
     * \param path Path to file relative root dir
     * \param str String
     */
    void write(const std::filesystem::path& path, const std::string& str) const;

    /**
     * \brief Remove file data from cache manually
     * \param path Path to file relative root dir
     */
    void removeFromCache(const std::filesystem::path& path) const;

    /**
     * \brief Clear cache
     */
    void clearCache() const;

private:
    /**
     * \brief Cache mutex
     */
    mutable std::mutex m_cacheMutex;

    /**
     * \brief Root dir
     */
    std::filesystem::path m_rootDir;

    /**
     * \brief Reader implementation
     */
    std::unique_ptr<IFilesystemReader> m_readerImpl;

    /**
     * \brief Writer implementation
     */
    std::unique_ptr<IFilesystemWriter> m_writerImpl;

    /**
     * \brief Cache implementation
     */
    std::unique_ptr<IFilesystemCache> m_cacheImpl;
};

#include "Filesystem.inl"
} // namespace te
