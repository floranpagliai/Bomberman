#include "MyGame.hpp"

int main(void) {
    MyGame game;
    srand(time(NULL));
    game.run();
    return EXIT_SUCCESS;
}
