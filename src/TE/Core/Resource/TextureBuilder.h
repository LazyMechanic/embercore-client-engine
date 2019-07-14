#pragma once

#include <TE/Core/Resource/AbstractBuilder.h>

namespace te {
class TextureBuilder : public AbstractBuilder {
public:
    TextureBuilder();

    void build() override;

private:

};
}