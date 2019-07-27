#pragma once

#include <filesystem>
#include <optional>

#include "te/filesystem/FileData.h"
#include "te/util/Singleton.h"

namespace te {
class FilesystemReaderImpl;
class FilesystemWriterImpl;

class Filesystem : public Singleton<Filesystem> {
public:
    /**
     * \brief Filesystem default constructor
     */
    Filesystem();

    /**
     * \brief Filesystem destructor
     */
    ~Filesystem();

    /**
     * \brief Read file data. Caching file in memory
     * \param path Path to file relative root dir
     * \return File data
     */
    [[nodiscard]] std::optional<FileData> read(const std::filesystem::path& path) const noexcept;

    /**
     * \brief Write data to file on disc
     * \param path Path to file relative root dir
     * \param data File data
     * \return If file was wrote then return 1, else return 0
     */
    int write(const std::filesystem::path& path, const FileData& data) const noexcept;

    /**
     * \brief Write string to file on disc
     * \param path Path to file relative root dir
     * \param str String
     * \return If file was wrote then return 1, else return 0
     */
    int write(const std::filesystem::path& path, const std::string& str) const noexcept;

private:
    /**
     * \brief Reader implementation
     */
    std::unique_ptr<FilesystemReaderImpl> m_readerImpl;

    /**
     * \brief Writer implementation
     */
    std::unique_ptr<FilesystemWriterImpl> m_writerImpl;
};
} // namespace te
