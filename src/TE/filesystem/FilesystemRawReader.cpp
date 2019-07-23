#include "FilesystemRawReader.h"

#include <fstream>

namespace te {
FileData FilesystemRawReader::read(const std::filesystem::path& path) const
{
    std::ifstream ifile(path, std::ios::binary);
    if (!ifile.is_open())
        throw std::runtime_error("Wrong path for read file");

    const auto dataSize = std::filesystem::file_size(path);

    std::vector<char> outData;
    outData.resize(dataSize);

    // Copy file data to buffer
    ifile.read(outData.data(), dataSize);

    return outData;
}
} // namespace te
