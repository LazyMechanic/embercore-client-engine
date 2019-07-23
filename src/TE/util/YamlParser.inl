template <typename T>
std::optional<T> YamlParser::getValue(const YAML::Node& document, const std::string& key)
{
    std::optional<T> result = std::nullopt;

    auto field = document[key];
    if (field.IsDefined())
        result = std::optional<T>{ field.as<T>() };

    return result;
}