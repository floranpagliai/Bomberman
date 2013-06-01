#ifndef __BONUS_HPP__
#define	__BONUS_HPP__

#include "AObject.hpp"
#include "Camera.hpp"

#define BONUS_SIZE (BLOCK_SIZE - 100)
namespace Bonus {

    class FireUp : public AObject {
    private:
        Camera camera_;
        gdl::Image texture_;
        std::list<AObject*> *objects_;
        int     dirAnim_;
    public:
        FireUp(float const, float const, std::list<AObject*> *);
        virtual ~FireUp();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    };

    class PowerUp : public AObject {
    private:
        Camera camera_;
        gdl::Image texture_;
        std::list<AObject*> *objects_;
        int     dirAnim_;
    public:
        PowerUp(float const, float const, std::list<AObject*> *);
        virtual ~PowerUp();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    };

    class SpeedUp : public AObject {
    private:
        Camera camera_;
        gdl::Image texture_;
        std::list<AObject*> *objects_;
        int     dirAnim_;
    public:
        SpeedUp(float const, float const, std::list<AObject*> *);
        virtual ~SpeedUp();

        void initialize(void);
        void update(gdl::GameClock const &, gdl::Input &);
        void draw(void);
    };
}


#endif	/* BONUS_HPP */

