#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "AObject.hpp"
#include "Bomb.hpp"
#include "Bonus.hpp"

namespace Model {

    class Player : public AObject {
    public:
        Player(float const, float const, std::list<AObject*> *);
        ~Player(void);

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);

        void checkMove(gdl::Input &input);
        void move(gdl::Input &);
        void putBomb(gdl::Input &);
        bool getBonus(Bonus *);

        int getAmmo() const;
        int getPower() const;
        int getSpeed() const;

        bool ammoUp();
        bool powerUp();
        bool speedUp();


    protected:
        std::list<AObject*> *objects_;
        gdl::Model model_;
        int ammo_;
        int power_;
        int speed_;
        bool isPush_;
    };
}

#endif