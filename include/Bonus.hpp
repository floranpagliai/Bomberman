#ifndef __BONUS_HPP__
#define	__BONUS_HPP__

#include "AObject.hpp"
#include "Camera.hpp"

#define BONUS_SIZE (BLOCK_SIZE - 100)

enum eBonus {
  AMMO = 1,
  POWER,
  SPEED
};

class Bonus : public AObject {
private:
    Camera camera_;
    gdl::Image texture_;
    std::list<AObject*> *objects_;
    eBonus      bonusType_;
    int dirAnim_;
public:
    Bonus(float const, float const, eBonus const, std::list<AObject*> *);
    virtual ~Bonus();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
};

#endif	/* BONUS_HPP */

