#pragma once

#include <te/resource/BaseBuilder.h>

namespace te {
class TextureBuilder : public BaseBuilder {
public:
    TextureBuilder();

protected:
    void buildImp() override;
};
}