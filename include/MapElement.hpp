#ifndef __MAPELEMENT_HPP__
#define __MAPELEMENT_HPP__

#include "AObject.hpp"
#include "Model.hpp"
#include "GameClock.hpp"
#include "Input.hpp"
#include "Camera.hpp"

namespace MapElement {

    class Background : public AObject {
    public:
        Background(float const, float const, std::list<AObject*> *);
        ~Background();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        std::list<AObject*> *objects_;
        gdl::Image texture_;
        Camera camera_;
    };

    class Ground : public AObject {
    public:
        Ground(float const, float const, std::list<AObject*> *);
        ~Ground();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        std::list<AObject*> *objects_;
        gdl::Image texture_;
        Camera camera_;


    };

    class Crate : public AObject {
    public:
        Crate(float const, float const, std::list<AObject*> *);
        ~Crate();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        std::list<AObject*> *objects_;
        gdl::Image texture_;
        Camera camera_;
    };

    class Wall : public AObject {
    public:
        Wall(float const, float const, std::list<AObject*> *);
        ~Wall();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    private:
        std::list<AObject*> *objects_;
        gdl::Image texture_;
        Camera camera_;
    };

}

#endif
