#include "Bomberman.h"

Bomberman::Bomberman(float const x, float const z, int id, std::list<AObject*> *objects) : Player(x, z, objects) {
    this->id_ = id;
}

Bomberman::~Bomberman() {
}

