#include "FilesystemStaticCache.h"

namespace te {
FileData* FilesystemStaticCache::find(const std::filesystem::path& path)
{
    auto foundFileData = m_cache.find(path);
    if (foundFileData != m_cache.end())
        return &foundFileData->second;

    return nullptr;
}

void FilesystemStaticCache::add(const std::filesystem::path& path, const FileData& data)
{
    m_cache[path] = data;
}

void FilesystemStaticCache::remove(const std::filesystem::path& path)
{
    const auto foundFileData = m_cache.find(path);
    if (foundFileData != m_cache.end())
        m_cache.erase(foundFileData);
}

void FilesystemStaticCache::clear()
{
    m_cache.clear();
}
} // namespace te
