#pragma once

#include <memory>

namespace te {
class BaseBuilder {
public:
    BaseBuilder() = default;

    BaseBuilder(const BaseBuilder&) = default;

    BaseBuilder(BaseBuilder&&) = default;

    virtual ~BaseBuilder() = default;

    template <typename DataType>
    std::shared_ptr<DataType> getData();

    void build();

    void release();

protected:
    std::shared_ptr<void> m_data;

    virtual void buildImp() = 0;

    virtual void releaseImp() {}
};

inline void BaseBuilder::build()
{
    buildImp();
}

inline void BaseBuilder::release()
{
    m_data.reset();
}

template <typename DataType>
std::shared_ptr<DataType> BaseBuilder::getData()
{
    return std::reinterpret_pointer_cast<DataType>(m_data);
}
} // namespace te
