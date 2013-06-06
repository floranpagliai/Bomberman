#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include "AObject.hpp"
#include "Camera.hpp"
#include "Map.hpp"
#include "Display.hpp"

class MyGame : public gdl::Game {
private:
    std::list<AObject*> objects_;
    Camera camera_;
    float cameraZ_;
    gdl::Clock timer_;
    int countClock_;

public:
    sf::Music *music;
    sf::Music *intro;

    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void openMap(const char *name);
    std::string float2string(float f);
};

#endif
