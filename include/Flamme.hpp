#ifndef __FLAMME_HPP__
#define __FLAMME_HPP__

#include "AObject.hpp"
#include "Model.hpp"
#include "GameClock.hpp"
#include "Input.hpp"
#include "Camera.hpp"
#include "Bonus.hpp"

#define TIMER_FLAMME 0.145

enum eDirection {
    LEFT = 1,
    RIGHT,
    UP,
    DOWN
};

class Flamme : public AObject {
private:
    std::list<AObject*> *objects_;
    gdl::Clock timer_;
    gdl::Image texture_;
    eDirection direction_;
    int power_;
    bool isExpand_;
    int dir_;

public:
    Flamme(float const, float const, int const, int const, std::list<AObject*> *objects);
    ~Flamme();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    void propagate(void) const;
    void checkPropagation(void);
    void popBonus(void);
};

#endif
