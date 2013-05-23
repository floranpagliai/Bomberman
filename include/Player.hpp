#include <cstdlib>
#include "GL/gl.h"
#include "GL/glu.h"
#include "Input.hpp"
<<<<<<< HEAD
#include "Bomb.hpp"
=======
#include <list>
>>>>>>> commit pour flo avec Bug creation Bomb
#include "AObject.hpp"
#include "Vector3f.hpp"
#include "GameClock.hpp"
#include "Image.hpp"
#include "Model.hpp"
<<<<<<< HEAD

=======
#include <cstdlib>
#include "Bomb.hpp"
>>>>>>> commit pour flo avec Bug creation Bomb
namespace Model
{
  class Player : public AObject
  {
  public:
    Player(std::list<AObject*> *);
    ~Player(void);

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    int		getAmmo() const;
    int		getPower() const;
    int		getSpeed() const;

    void	ammoUp();
    void	powerUp();
    void	speedUp();
<<<<<<< HEAD
  private:
    gdl::Model model_;
    std::list<AObject*>		objects_;
=======
    void	putBomb();
>>>>>>> commit pour flo avec Bug creation Bomb

  private:
    gdl::Model		model_;
    std::list<AObject*>	*objects_;
    int			ammo_;
    int			power_;
    int			speed_;
    
  };
}
