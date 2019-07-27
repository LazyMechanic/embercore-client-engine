#include "FilesystemWriterImpl.h"

#include <fstream>

#include "te/util/Log.h"

namespace te {
int FilesystemWriterImpl::write(const std::filesystem::path& path, const FileData& data) const noexcept
{
    std::ofstream ofile(path, std::ios::binary);
    if (!ofile.is_open()) {
        Log::instance().error("Wrong file path. File for write not opened. path = {{ \"{}\" }}", path.string());
        return 0;
    }

    ofile.write(data.data(), data.size() * sizeof(FileData::value_type));
    return 1;
}
} // namespace te
