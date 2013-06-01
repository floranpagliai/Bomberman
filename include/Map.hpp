#ifndef __MAP_HPP__
#define	__MAP_HPP__

#include "AObject.hpp"
#include "MapElement.hpp"
#include "Player.hpp"

class Map {
private:
    int posX_;
    int posZ_;
    int maxX_;
    const char *name_;
    std::list<AObject*> *objects_;

public:
    Map(const char *name, std::list<AObject*> *);
    Map(const Map &);
    virtual ~Map();

    int getMaxX() const;
    void posMap();
    void openMap();
};

#endif

