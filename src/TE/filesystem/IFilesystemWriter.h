#pragma once

#include <filesystem>

#include "te/filesystem/FileData.h"

namespace te {
class IFilesystemWriter {
public:
    /**
     * \brief IFilesystemWriter destructor
     */
    virtual ~IFilesystemWriter() = default; 
    
    /**
     * \brief Write data to file
     * \param path Path to file relative root dir
     * \param data File data
     */
    virtual void write(const std::filesystem::path& path, const FileData& data) = 0;
};
}