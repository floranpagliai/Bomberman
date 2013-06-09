#include "MyGame.hpp"
void playGame() {
    MyMenu menu;
    srand(time(NULL));
    menu.run();
    menu.unload();
    playGame();
}

int main(void) {
    playGame();
    return EXIT_SUCCESS;
}
