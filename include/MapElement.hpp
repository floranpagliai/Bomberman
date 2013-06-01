//
// MapElement.hpp for __MAPELEMENT_HPP__ in /home/cayrel_l//tek2/projet/Bomberman/include
//
// Made by lambert cayrel
// Login   <cayrel_l@epitech.net>
//
// Started on  Wed May 22 17:35:49 2013 lambert cayrel
// Last update Mon May 27 17:17:52 2013 lambert cayrel
//

#ifndef __MAPELEMENT_HPP__
#define __MAPELEMENT_HPP__

#include "AObject.hpp"
#include "Model.hpp"
#include "GameClock.hpp"
#include "Input.hpp"
#include "Camera.hpp"

namespace MapElement {

    class Ground : public AObject {
    public:
        Ground(float const, float const, std::list<AObject*> *);
        ~Ground();
        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        Camera camera_;
        gdl::Image texture_;
        std::list<AObject*> *objects_;
    };

    class Crate : public AObject {
    public:
        Crate(float const, float const, std::list<AObject*> *);
        ~Crate();
        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        Camera camera_;
        gdl::Image texture_;
        std::list<AObject*> *objects_;
    };

    class Wall : public AObject {
    public:
        Wall(float const, float const, std::list<AObject*> *);
        ~Wall();
        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        Camera camera_;
        gdl::Image texture_;
        std::list<AObject*> *objects_;
    };
}

#endif
