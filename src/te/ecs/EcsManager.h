#pragma once

#include "te/util/Singleton.h"

namespace te {
class EcsManager : public Singleton<EcsManager> {
public:
    EcsManager();

    ~EcsManager();

    void update(float dt);

private:
};
} // namespace te