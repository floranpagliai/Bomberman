#ifndef __MAP_HPP__
#define	__MAP_HPP__

#include "AObject.hpp"
#include "MapElement.hpp"
#include "Bomberman.h"

class Map {
private:
    std::list<AObject*> *objects_;
    const char *name_;
    int posX_;
    int posZ_;
    int maxX_;


public:
    Map(const char *name, std::list<AObject*> *);
    Map(const Map &);
    virtual ~Map();

    int getMaxX() const;
    void posMap();
    void openMap();
};

#endif

