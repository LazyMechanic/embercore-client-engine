#include "YamlParser.h"

namespace te {
YAML::Node YamlParser::parse(const std::string& rawData)
{
    return YAML::Load(rawData);
}
}
