#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "AObject.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"
#include "Display.hpp"

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
    sf::Music *powerupSound_;
    int ammo_;
    int ammoStock_;
    int power_;
    int speed_;
    int id_;


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
    int getId() const;
    int	getAmmoStock() const;

    void recupBomb();
    bool ammoUp();
    bool powerUp();
    bool powerDown();
    bool speedUp();
};

#endif
