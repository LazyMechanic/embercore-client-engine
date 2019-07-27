#pragma once

#include <filesystem>
#include <optional>

#include "te/filesystem/FileData.h"

namespace te {
class FilesystemReaderImpl {
public:
    /**
     * \brief FilesystemReaderImpl default constructor
     */
    FilesystemReaderImpl() = default;

    /**
     * \brief FilesystemReaderImpl copy constructor
     */
    FilesystemReaderImpl(const FilesystemReaderImpl&) = default;

    /**
     * \brief FilesystemReaderImpl move constructor
     */
    FilesystemReaderImpl(FilesystemReaderImpl&&) = default;

    /**
     * \brief FilesystemReaderImpl destructor
     */
    ~FilesystemReaderImpl() = default;

    /**
     * \brief Read file from disc
     * \param path Path to file
     * \return If file not fount or any error return std::nullopt, else return FileData
     */
    [[nodiscard]] std::optional<FileData> read(const std::filesystem::path& path) const noexcept;
};
} // namespace te