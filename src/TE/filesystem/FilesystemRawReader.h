#pragma once

#include <filesystem>

#include "te/filesystem/IFilesystemReader.h"

namespace te {
class FilesystemRawReader : public IFilesystemReader {
public:
    FileData read(const std::filesystem::path& path) const override;
};
} // namespace te