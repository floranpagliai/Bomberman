#ifndef __BONUS_HPP__
#define	__BONUS_HPP__

#include "AObject.hpp"
#include "Camera.hpp"

#define BONUS_SIZE (BLOCK_SIZE - 100)

enum eBonusType {
  AMMO = 1,
  POWER,
  SPEED
};

class Bonus : public AObject {
private:
    Camera camera_;
    gdl::Image texture_;
    std::list<AObject*> *objects_;
    eBonusType      bonusType_;
    int dirAnim_;
public:
    Bonus(float const, float const, eBonusType const, std::list<AObject*> *);
    virtual ~Bonus();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    eBonusType getBonusType() const;
};

#endif	/* BONUS_HPP */

