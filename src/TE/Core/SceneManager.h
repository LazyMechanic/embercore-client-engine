#pragma once

#include <stack>

#include <TE/Core/Scene.h>
#include <TE/Core/TrueEngine.h>

namespace te {
class SceneManager {
public:
    explicit SceneManager(TrueEngine* engine);

    ~SceneManager() = default;

    void update(float dt);

    void draw();

    void push(const Scene& scene);
    
    void pop();

private:
    TrueEngine* m_engine;

    std::stack<Scene> m_scenes;

    bool m_needPop;
};
}