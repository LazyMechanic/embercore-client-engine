#include "FilesystemReaderImpl.h"

#include "te/util/Log.h"

#include <fstream>

namespace te {
std::optional<FileData> FilesystemReaderImpl::read(const std::filesystem::path& path) const noexcept
{
    std::ifstream ifile(path, std::ios::binary);
    if (!ifile.is_open()) {
        Log::instance().error("Wrong file path. File for read not opened. path = {{ \"{}\" }}", path.string());
        return std::nullopt;
    }

    const auto dataSize = std::filesystem::file_size(path);

    std::vector<char> outData;
    outData.resize(dataSize);

    // Copy file data to buffer
    ifile.read(outData.data(), dataSize);

    return std::optional<FileData>{ outData };
}
} // namespace te
