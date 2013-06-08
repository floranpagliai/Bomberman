#include "Map.hpp"

Map::Map(int size, int nbPlayer, int nbIA, std::list<AObject*> *objects) {
    this->objects_ = objects;
    this->nbPlayer_ = nbPlayer;
    this->nbIA_ = nbIA;
    this->posX_ = 0;
    this->posZ_ = 0;
    this->minX_ = 0;
    this->maxX_ = 0;
    this->randMap(size);
}

Map::Map(char *name, eMapTheme theme, int nbPlayer, int nbIA, std::list<AObject*> *objects) {
    this->objects_ = objects;
    this->name_ = name;
    this->theme_ = theme;
    this->nbPlayer_ = nbPlayer;
    this->nbIA_ = nbIA;
    this->posX_ = 0;
    this->posZ_ = 0;
    this->minX_ = 0;
    this->maxX_ = 0;
    this->openMap();
}

Map::Map(const Map &old) {
    this->objects_ = old.objects_;
    this->name_ = old.name_;
    this->posX_ = old.posX_;
    this->posZ_ = old.posZ_;
    this->minX_ = old.minX_;
    this->maxX_ = old.maxX_;
}

Map::~Map() {
}

int Map::getMinX(void) const {
    return this->minX_;
}

int Map::getMaxX(void) const {
    return this->maxX_;
}

void Map::posMap(void) {
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
    maxX_ = posX_;
    posX_ = (posX_ - posX_ - posX_) / 2;
    posZ_ = (z - z - z) / 2;
    minX_ = posX_;
    file.close();
}

void Map::openMap(void) {
    std::ifstream file(name_, std::ios::in);
    std::string str;

    this->posMap();
    this->objects_->push_back(new MapElement::Background(0, 0, this->theme_, this->objects_));
    while (getline(file, str)) {
        std::string::iterator it = str.begin();
        while (it != str.end()) {
            if (*it == '1' || *it == '7' || *it == '8') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->theme_, this->objects_));
            } if (*it == '2') {
                this->objects_->push_back(new MapElement::Wall(posX_, posZ_, this->theme_, this->objects_));
            } else if (*it == '3') {
                this->objects_->push_back(new MapElement::Ground(posX_, posZ_, this->theme_, this->objects_));
                this->objects_->push_back(new MapElement::Crate(posX_, posZ_, this->theme_, this->objects_));
            } else if (*it == '7' && this->nbPlayer_ > 0 && this->nbPlayer_ < 3) {
                this->objects_->push_back(new Bomberman(posX_, posZ_, this->nbPlayer_--, this->objects_));
            } else if (*it == '8' && this->nbIA_ > 0 && this->nbIA_-- <= 10) {
                this->objects_->push_back(new Bomberman(posX_, posZ_, 3, this->objects_));
            }
            it++;
            posX_++;
        }
        posX_ = minX_;
        posZ_++;
    }
    file.close();
}

void Map::randMap(int size) {
    if (size > 100)
        size = 100;
    else if (size < 10)
        size = 10;
    int x = (size - size - size) / 2;
    int z = (size - size - size) / 2;
    this->minX_ = x;
    this->maxX_ = size;
    int value;

    while (z <= maxX_ / 2) {
        while (x <= maxX_ / 2) {
            if ((z == (size - size - size) / 2 || x == (size - size - size) / 2 || x == size / 2 || z == size / 2) ||
                    ((z % 2) == 0 && (x % 2) == 0))
                this->objects_->push_back(new MapElement::Wall(x, z, this->theme_, this->objects_));
            else {
                value = rand() % 3;
                this->objects_->push_back(new MapElement::Ground(x, z, this->theme_, this->objects_));
                if (value == 0)
                    this->objects_->push_back(new MapElement::Crate(x, z, this->theme_, this->objects_));
                else if (value == 1 && this->nbPlayer_ > 0 && this->nbPlayer_ < 3)
                    this->objects_->push_back(new Bomberman(x, z, this->nbPlayer_--, this->objects_));
                else if (value == 2 && this->nbIA_ > 0 && this->nbIA_-- <= 10)
                    this->objects_->push_back(new Bomberman(x, z, 3, this->objects_));
            }
            x++;
        }
        x = minX_;
        z++;
    }
}