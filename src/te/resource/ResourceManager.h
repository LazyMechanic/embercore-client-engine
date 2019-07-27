#pragma once

#include <map>
#include <memory>
#include <mutex>
#include <string>

#include "te/resource/BaseBuilder.h"
#include "te/util/Singleton.h"

namespace te {
class ResourceManager : public Singleton<ResourceManager> {
public:
    using Key = std::string;

    using BuilderPtr = std::shared_ptr<BaseBuilder>;

    /**
     * \brief ResourceManager default constructor
     */
    ResourceManager() = default;

    /**
     * \brief ResourceManager copy constructor
     */
    ResourceManager(const ResourceManager&) = delete;

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
     * \brief Resource manager mutex
     */
    std::recursive_mutex m_mutex;

    /**
     * \brief Map of builders
     */
    std::map<Key, BuilderPtr> m_builders;
};

template <typename ResourceType>
std::shared_ptr<ResourceType> ResourceManager::get(const std::string& key)
{
    std::scoped_lock<std::recursive_mutex> lock(m_mutex);

    auto builderIt = m_builders.find(key);

    if (builderIt == m_builders.end())
        throw std::runtime_error("Resource with key={ " + key + " } not found for release");

    // If data already release or not built
    if (builderIt->second->getData<ResourceType>() == nullptr)
        builderIt->second->build();

    return builderIt->second->getData<ResourceType>();
}
} // namespace te
