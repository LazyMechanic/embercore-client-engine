#include "ResourceManager.h"

#include <stdexcept>

namespace te {
void ResourceManager::bind(const std::string& key, BuilderPtr builder)
{
    auto builderIt = m_builders.find(key);

    if(builderIt != m_builders.end())
        throw std::runtime_error("Resource with key={ " + key + " } already bind");

    m_builders[key] = builder;
}

void ResourceManager::unbind(const std::string& key)
{
    auto builderIt = m_builders.find(key);

    if (builderIt == m_builders.end())
        throw std::runtime_error("Resource with key={ " + key + " } not found for unbind");

    builderIt->second->release();
    m_builders.erase(builderIt);
}

void ResourceManager::release(const std::string& key)
{
    auto builderIt = m_builders.find(key);

    if (builderIt == m_builders.end())
        throw std::runtime_error("Resource with key={ " + key + " } not found for release");

    builderIt->second->release();
}
}
