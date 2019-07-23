#pragma once

#include <filesystem>
#include <optional>
#include <string>

#include <yaml-cpp/yaml.h>

namespace te {
class YamlParser {
public:
    /**
     * \brief Get value by key from yaml document
     * \tparam T Type to return
     * \param document Correct yaml document
     * \param key Key in yaml for search
     * \return If value by key not found then return std::nullopt, else return value
     */
    template <typename T>
    static std::optional<T> getValue(const YAML::Node& document, const std::string& key);

    /**
     * \brief Parse string by yaml engine
     * \param rawData String which contains yaml document
     * \return Parsed yaml document
     */
    static YAML::Node parse(const std::string& rawData);
};

#include "YamlParser.inl"
} // namespace te