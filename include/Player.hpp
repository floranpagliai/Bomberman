#include <cstdlib>
#include "GL/gl.h"
#include "GL/glu.h"
#include "Input.hpp"
#include "Bomb.hpp"
#include "AObject.hpp"
#include "Vector3f.hpp"
#include "GameClock.hpp"
#include "Image.hpp"
#include "Model.hpp"

namespace Model
{
  class Player : public AObject
  {
  public:
    //Player(void);
    //~Player(void);
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    int		getAmmo() const;
    int		getPower() const;
    int		getSpeed() const;

    void	ammoUp();
    void	powerUp();
    void	speedUp();
  private:
    gdl::Model model_;
    std::list<AObject*>		objects_;

    int		ammo_;
    int		power_;
    int		speed_;
  };
}
