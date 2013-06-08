#include "MyGame.hpp"

void	playGame()
{
    MyMenu menu;
    srand(time(NULL));
    std::cout << "Lancement du menu" << std::endl;
    menu.run();
    std::cout << "Retour au main apres menu" << std::endl;
    std::cout << "Appel recursif" << std::endl;
}

int main(void) {
    playGame();
  return EXIT_SUCCESS;
}
