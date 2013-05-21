#include "GL/gl.h"
#include "GL/glu.h"
#include "Input.hpp"

#include "AObject.hpp"
#include "Vector3f.hpp"
#include "GameClock.hpp"
#include "Image.hpp"
#include "Model.hpp"

////////////////////////////////////////////////////////////////////////////////
/// Declaration de la classe Bomberman
////////////////////////////////////////////////////////////////////////////////

namespace Model
{
  class Bomberman : public AObject
  {
  public:
    //Bomberman(void);
    //~Bomberman(void);
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
  private:
    gdl::Model model_;
  };
}
