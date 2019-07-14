#pragma once

#include <string>
#include <memory>
#include <map>

#include <TE/Core/Resource/AbstractBuilder.h>

namespace te {
class ResourceManager {
public:
    using Key = std::string;

    using BuilderPtr = std::shared_ptr<AbstractBuilder>;

    /**
     * \brief ResourceManager default constructor
     */
    ResourceManager() = default;

    /**
     * \brief ResourceManager copy constructor
     */
    ResourceManager(const ResourceManager&) = delete;

    /**
     * \brief ResourceManager move constructor
     */
    ResourceManager(ResourceManager&&) = default;

    /**
     * \brief ResourceManager destructor
     */
    ~ResourceManager() = default;

    /**
     * \brief Bind resource
     * \param key Key
     * \param builder Builder which build a resource instance
     */
    void bind(const std::string& key, BuilderPtr builder);

    /**
     * \brief Unbind resource
     * \param key Key
     */
    void unbind(const std::string& key);

    /**
     * \brief Get some resource by key. If key is not found then throw exception
     * \tparam ResourceType Resource type
     * \param key Key
     * \return Smart ptr to resource
     */
    template <typename ResourceType>
    std::shared_ptr<ResourceType> get(const std::string& key);

    /**
     * \brief Release resource from memory
     * \param key Key
     */
    void release(const std::string& key);

private:
    /**
     * \brief Map of builders
     */
    std::map<Key, BuilderPtr> m_builders;
};

template <typename ResourceType>
std::shared_ptr<ResourceType> ResourceManager::get(const std::string& key)
{
    auto builderIt = m_builders.find(key);

    if (builderIt == m_builders.end())
        throw std::runtime_error("Resource with key={ " + key + " } not found for release");

    // If data already release or not built
    if (builderIt->second->getData<ResourceType>() == nullptr)
        builderIt->second->build();

    return builderIt->second->getData<ResourceType>();
}
}
