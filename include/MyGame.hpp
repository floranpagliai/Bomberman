#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include "AObject.hpp"
#include "Camera.hpp"
#include "Map.hpp"

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;
    float cameraZ_;
    
public:
    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void openMap(const char *name);
};

#endif
