#include "Filesystem.h"

#include <cassert>
#include <filesystem>

namespace te {
Filesystem::Filesystem() :
    m_rootDir(std::filesystem::current_path()),
    m_readerImpl(nullptr),
    m_writerImpl(nullptr),
    m_cacheImpl(nullptr)
{}

void Filesystem::setRootDir(const std::filesystem::path& rootDir)
{
    m_rootDir = rootDir;
    clearCache();
}

FileData Filesystem::read(const std::filesystem::path& path) const
{
    assert(m_cacheImpl != nullptr && "Filesystem cache implementation must be set before call read function");
    assert(m_readerImpl != nullptr && "Filesystem reader implementation must be set before call read function");

    std::scoped_lock<std::mutex> lock(m_cacheMutex);

    const std::filesystem::path endPath = m_rootDir / path;

    FileData* foundFileData = m_cacheImpl->find(endPath);
    if (foundFileData != nullptr)
        return *foundFileData;

    FileData readedFileData = m_readerImpl->read(endPath);
    m_cacheImpl->add(endPath, readedFileData);

    return readedFileData;
}

void Filesystem::write(const std::filesystem::path& path, const FileData& data) const
{
    assert(m_writerImpl != nullptr && "Filesystem writer implementation must be set before call read function");

    const std::filesystem::path endPath = m_rootDir / path;

    m_writerImpl->write(endPath, data);
}

void Filesystem::write(const std::filesystem::path& path, const std::string& str) const
{
    write(path, std::vector<char>{ str.begin(), str.end() });
}

void Filesystem::removeFromCache(const std::filesystem::path& path) const
{
    assert(m_cacheImpl != nullptr && "Filesystem cache implementation must be set before call read function");

    std::scoped_lock<std::mutex> lock(m_cacheMutex);

    const std::filesystem::path endPath = m_rootDir / path;

    m_cacheImpl->remove(endPath);
}

void Filesystem::clearCache() const
{
    assert(m_cacheImpl != nullptr && "Filesystem cache implementation must be set before call read function");

    std::scoped_lock<std::mutex> lock(m_cacheMutex);

    m_cacheImpl->clear();
}
} // namespace te
