/*
 * File:   Map.cpp
 * Author: floran
 *
 * Created on 29 mai 2013, 15:09
 */

#include "Map.hpp"

Map::Map(const char *name, std::list<AObject*> *objects) {
    this->objects_ = objects;
    this->name_ = name;
    posX_ = 0;
    posZ_ = 0;
    maxX_ = 0;
}

Map::~Map() {
}

int Map::getMaxX() const {
    return this->maxX_;
}

void Map::posMap() {
    std::ifstream file(name_, std::ios::in);
    std::string str;
    int x = 0;
    int z = 0;
    while (getline(file, str)) {
        std::string::iterator it = str.begin();
        while (it != str.end()) {
            it++;
            x++;
        }
        posX_ = x;
        x = 0;
        z++;
    }
    posX_ = (posX_ - posX_ - posX_)/2;
    posZ_ = (z - z - z)/2;
    maxX_ = posX_;
    file.close();
}

void Map::openMap() {
    std::ifstream file(name_, std::ios::in);
    std::string str;

    this->posMap();
    while (getline(file, str)) {
        std::string::iterator it = str.begin();
        while (it != str.end()) {
            if (*it == '1') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->objects_));
            } else if (*it == '2') {
                this->objects_->push_back(new MapElement::Wall(posX_, posZ_, this->objects_));
            } else if (*it == '3') {
                this->objects_->push_back(new MapElement::Crate(posX_, posZ_, this->objects_));
            } else if (*it == '7') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->objects_));
                this->objects_->push_back(new Model::Player(posX_, posZ_, this->objects_));
            }

            it++;
            posX_++;
        }
        posX_ = maxX_;
        posZ_++;
    }
    file.close();
}

