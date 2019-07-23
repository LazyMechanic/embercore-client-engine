#pragma once

#include <filesystem>
#include <map>
#include <mutex>

#include "te/filesystem/IFilesystemCache.h"

namespace te {
class FilesystemStaticCache : public IFilesystemCache {
public:
    /**
     * \brief Find file data by path
     * \param path Path to file (key)
     * \return If found then return ptr to file data, if not found then return nullptr
     */
    FileData* find(const std::filesystem::path& path) override;

    /**
     * \brief Add file data to cache by path
     * \param path Path to file (key)
     * \param data File data (value)
     */
    void add(const std::filesystem::path& path, const FileData& data) override;

    /**
     * \brief Remove file data from cache by path
     * \param path Path to file (key)
     */
    void remove(const std::filesystem::path& path) override;

    /**
     * \brief Clear cache
     */
    void clear() override;

private:
    /**
     * \brief Cached file data
     */
    std::map<const std::filesystem::path, FileData> m_cache;
};
} // namespace te