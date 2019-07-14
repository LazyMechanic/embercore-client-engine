#pragma once

#include <memory>

namespace te {
class AbstractBuilder {
public:
    AbstractBuilder() = default;

    AbstractBuilder(const AbstractBuilder&) = default;

    AbstractBuilder(AbstractBuilder&&) = default;

    virtual ~AbstractBuilder() = default;

    template <typename DataType>
    std::shared_ptr<DataType> getData();

    virtual void build() = 0;

    void release();

protected:
    std::shared_ptr<void> m_data;
};

inline void AbstractBuilder::release()
{
    m_data.reset();
}

template <typename DataType>
std::shared_ptr<DataType> AbstractBuilder::getData()
{
    return std::reinterpret_pointer_cast<DataType>(m_data);
}
}
