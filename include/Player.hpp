#include "GL/gl.h"
#include "GL/glu.h"

#include "Input.hpp"
#include "Image.hpp"
#include "Model.hpp"

#include <iostream>
#include <cstdlib>
#include <list>

#include "AObject.hpp"
#include "Vector3f.hpp"
#include "GameClock.hpp"
#include "Bomb.hpp"

namespace Model
{
  class Player : public AObject
  {
  public:
    Player(float const, float const, std::list<AObject*> *);
    ~Player(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

	void	move(gdl::Input &);
    void	putBomb(gdl::Input &);

    int		getAmmo() const;
    int		getPower() const;
    int		getSpeed() const;

    void	ammoUp();
    void	powerUp();
    void	speedUp();


  protected:
    gdl::Model		model_;
    std::list<AObject*>	*objects_;
    int			ammo_;
    int			power_;
    int			speed_;
    bool		isPush_;
  };
}
