#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "AObject.hpp"
#include "Bomb.hpp"

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

        int getAmmo() const;
        int getPower() const;
        int getSpeed() const;

        void ammoUp();
        void powerUp();
        void speedUp();


    protected:
        gdl::Model model_;
        std::list<AObject*> *objects_;
        int ammo_;
        int power_;
        int speed_;
        bool isPush_;
    };
}

#endif