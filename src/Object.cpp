#include "Object.hpp"

namespace Object
{
  void Cube::initialize(void)
  {
  }
  
  void Cube::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
  }
  
  void Cube::draw(void)
  {
    /// Ouverture d’un contexte de rendu
    glBegin(GL_QUADS);
    
    /// Configuration de la couleur des vertices
    glColor3f(1.0f, 0.50f, 0.75f);
    

    /// Dessin des vertices

        
    /// Vertex superieur gauche
    glVertex3f(-150.0f, 150.0f, 150.0f);
    
    /// Vertex inferieur gauche
    glVertex3f(-150.0f, -150.0f, 150.0f);
    
    /// Vertex inferieur droit
    glVertex3f(150.0f, -150.0f, 150.0f);
    
    /// Vertex superieur droit
    glVertex3f(150.0f, 150.0f, 150.0f);
    
    /// Vertex superieur gauche
    glVertex3f(-150.0f, 150.0f, -150.0f);
    
    /// Vertex inferieur gauche
    glVertex3f(-150.0f, -150.0f, -150.0f);
    
    /// Vertex inferieur droit
    glVertex3f(-150.0f, -150.0f, 150.0f);
    
    /// Vertex superieur droit
    glVertex3f(-150.0f, 150.0f, 150.0f);
    
    /// Vertex superieur gauche
    glVertex3f(150.0f, 150.0f, -150.0f);
    
    /// Vertex inferieur gauche
    glVertex3f(150.0f, -150.0f, -150.0f);
    
    /// Vertex inferieur droit
    glVertex3f(-150.0f, -150.0f, -150.0f);
    
    /// Vertex superieur droit
    glVertex3f(-150.0f, 150.0f, -150.0f);
    
    /// Vertex superieur gauche
    glVertex3f(150.0f, 150.0f, 150.0f);
    
    /// Vertex inferieur gauche
    glVertex3f(150.0f, -150.0f, 150.0f);
    
    /// Vertex inferieur droit
    glVertex3f(150.0f, -150.0f, -150.0f);

    /// Vertex superieur droit
    glVertex3f(150.0f, 150.0f, -150.0f);
    
    /// Fermeture du contexte de rendu
    glEnd();
 }
}

namespace Object
{
  void Pyramide::initialize(void)
  {
  }

  void Pyramide::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->rotation_.y = ((int)rotation_.y + 1) % 360;
  }
  
  void Pyramide::draw(void)
  {
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -900.0f);
    
    /// Rotation autour de l’axe Y
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    
    /// Ouverture d’un contexte de rendu
    glBegin(GL_TRIANGLES);
    
    /// Dessin des vertices
    glColor3f(1.0f, 1.0f, 1.0f);
    
    /// Vertex haut : B
    glVertex3f(0.0f, -150.0f, -150.0f);
    
    /// Vertex inferieur gauche : C
    glVertex3f(-150.0f, -150.0f, 150.0f);
    
    /// Vertex inferieur droit : D
    glVertex3f(150.0f, -150.0f, 150.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    
    /// Vertex haut : A
    glVertex3f(0.0f, 150.0f, 0.0f);
    
    /// Vertex inferieur gauche : C
    glVertex3f(-150.0f, -150.0f, 150.0f);
    
    /// Vertex inferieur droit : D
    glVertex3f(150.0f, -150.0f, 150.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    
    /// Vertex haut : A
    glVertex3f(0.0f, 150.0f, 0.0f);
    
    /// Vertex inferieur gauche : B
    glVertex3f(0.0f, -150.0f, -150.0f);
    
    /// Vertex inferieur droit : C
    glVertex3f(-150.0f, -150.0f, 150.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    
    /// Vertex haut : A
    glVertex3f(0.0f, 150.0f, 0.0f);
    
    /// Vertex inferieur gauche : D
    glVertex3f(150.0f, -150.0f, 150.0f);
    
    /// Vertex inferieur droit : B
    glVertex3f(0.0f, -150.0f, -150.0f);
    
    /// Fermeture du contexte de rendu
    glEnd();
    glPopMatrix();
  }
}
