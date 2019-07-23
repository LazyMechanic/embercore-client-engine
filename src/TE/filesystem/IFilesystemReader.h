#pragma once

#include <filesystem>

#include "te/filesystem/FileData.h"

namespace te {
class IFilesystemReader {
public:
    /**
     * \brief IFilesystemReader destructor
     */
    virtual ~IFilesystemReader() = default;

    /**
     * \brief Read file data implementation.
     * \param path Path to file relative root dir
     * \return File data
     */
    virtual FileData read(const std::filesystem::path& path) const = 0;
};
} // namespace te