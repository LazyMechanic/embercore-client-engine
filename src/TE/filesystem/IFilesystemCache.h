#pragma once

#include <filesystem>

#include "te/filesystem/FileData.h"

namespace te {
class IFilesystemCache {
public:
    /**
     * \brief IConfigCache destructor
     */
    virtual ~IFilesystemCache() = default;

    /**
     * \brief Find file data by path
     * \param path Path to file (key)
     * \return If found then return ptr to file data, if not found then return nullptr
     */
    virtual FileData* find(const std::filesystem::path& path) = 0;

    /**
     * \brief Add file data to cache by path
     * \param path Path to file (key)
     * \param data File data (value)
     */
    virtual void add(const std::filesystem::path& path, const FileData& data) = 0;

    /**
     * \brief Remove file data from cache by path
     * \param path Path to file (key)
     */
    virtual void remove(const std::filesystem::path& path) = 0;

    /**
     * \brief Clear cache
     */
    virtual void clear() = 0;
};
} // namespace te