#include <cstdlib>
#include <iostream>
#include "MyGame.hpp"

int main(void) {
    gdl::Clock myClock;
    MyGame game;
    srand(time(NULL));
    //myClock.play();
    game.run();

    /*
    myClock.update();
    std::cout << "Total game time elapsed : " << myClock.getElapsedTime() << " seconde(s)" << std::endl;
    std::cout << "Total time elapsed : " << myClock.getTotalElapsedTime() << " seconde(s)" << std::endl;
    myClock.update();
    std::cout << "Total game time elapsed : " << myClock.getElapsedTime() << " seconde(s)" << std::endl;
    std::cout << "Total time elapsed : " << myClock.getTotalElapsedTime() << " seconde(s)" << std::endl;
    myClock.pause();
    myClock.update();
    std::cout << "Total game time elapsed : " << myClock.getElapsedTime() << " seconde(s)" << std::endl;
    std::cout << "Total time elapsed : " << myClock.getTotalElapsedTime() << " seconde(s)" << std::endl;*/
    return EXIT_SUCCESS;
}
