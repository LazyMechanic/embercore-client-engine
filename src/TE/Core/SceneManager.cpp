#include "SceneManager.h"

namespace te {
SceneManager::SceneManager(TrueEngine* engine) :
    m_engine(engine)
{
}

void SceneManager::update(float dt)
{
    if (m_needPop) {
        
    }



    m_needPop = false;
}

void SceneManager::draw()
{
}

void SceneManager::push(const Scene& scene)
{
}

void SceneManager::pop()
{
    if (!m_scenes.empty()) {
        m_needPop = true;
    }
    else {
        m_needPop = false;
        // TODO: add logging
    }
}

}
