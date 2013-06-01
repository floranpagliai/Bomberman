#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AObject.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"

class Player : public AObject {
protected:
    std::list<AObject*> *objects_;
    gdl::Model model_;
    int ammo_;
    int power_;
    int speed_;
    bool isPush_;

public:
    Player(float const, float const, std::list<AObject*> *);
    ~Player(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    void checkMove(gdl::Input &input);
    bool checkMove2(gdl::Input &input, float, int);
    void move(gdl::Input &);
    void putBomb(gdl::Input &);
    bool getBonus(Bonus *);

    int getAmmo() const;
    int getPower() const;
    int getSpeed() const;

    bool ammoUp();
    bool powerUp();
    bool speedUp();
};

#endif