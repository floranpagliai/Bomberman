#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AObject.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"
#include "MyClock.hpp"

struct t_move {
    gdl::Keys::Key key;
    int angle;
    int coefX;
    int coefZ;
};

class Bomberman : public AObject {
protected:
    std::list<AObject*> *objects_;
    gdl::Model model_;
    int ammo_;
    int ammoStock_;
    int power_;
    int speed_;
    int id_;


    sf::Music *powerup;
    sf::Music *death;

public:
    Bomberman(float const, float const, int const, std::list<AObject*> *);
    virtual ~Bomberman(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    bool checkMove(gdl::Input &input, float, float);
    void move(gdl::Input &);
    void putBomb(gdl::Input &);

    bool getBonus(Bonus *);
    t_move* getKeys() const;
    int getAmmo() const;
    int getPower() const;
    int getSpeed() const;

    void recupBomb();
    bool ammoUp();
    bool powerUp();
    bool speedUp();
};

#endif
