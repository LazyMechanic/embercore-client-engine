#pragma once

#include <filesystem>

#include "te/filesystem/FileData.h"

namespace te {
class FilesystemWriterImpl
{
public:
    /**
     * \brief FilesystemWriterImpl default constructor
     */
    FilesystemWriterImpl() = default;

    /**
     * \brief FilesystemWriterImpl copy constructor
     */
    FilesystemWriterImpl(const FilesystemWriterImpl&) = default;

    /**
     * \brief FilesystemWriterImpl move constructor
     */
    FilesystemWriterImpl(FilesystemWriterImpl&&) = default;

    /**
     * \brief FilesystemWriterImpl destructor
     */
    ~FilesystemWriterImpl() = default;

    /**
     * \brief Write data to file
     * \param path Path to file
     * \param data File data
     * \return If file was wrote then return 1, else return 0
     */
    int write(const std::filesystem::path& path, const FileData& data) const noexcept;
};
}