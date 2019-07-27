#include "Filesystem.h"

#include <cassert>
#include <filesystem>

#include "te/filesystem/FilesystemReaderImpl.h"
#include "te/filesystem/FilesystemWriterImpl.h"
#include "te/util/Log.h"

namespace te {
Filesystem::Filesystem()
{
    m_readerImpl = std::make_unique<FilesystemReaderImpl>();
    m_writerImpl = std::make_unique<FilesystemWriterImpl>();
}

Filesystem::~Filesystem() = default;

std::optional<FileData> Filesystem::read(const std::filesystem::path& path) const noexcept
{
    assert(m_writerImpl != nullptr && "FilesystemReaderImpl was manually deleted or not made yet");
    return m_readerImpl->read(path);
}

int Filesystem::write(const std::filesystem::path& path, const FileData& data) const noexcept
{
    assert(m_writerImpl != nullptr && "FilesystemWriterImpl was manually deleted or not made yet");
    return m_writerImpl->write(path, data);
}

int Filesystem::write(const std::filesystem::path& path, const std::string& str) const noexcept
{
    return write(path, std::vector<char>{ str.begin(), str.end() });
}
} // namespace te
