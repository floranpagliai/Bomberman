#ifndef __MAP_HPP__
#define	__MAP_HPP__

#include "AObject.hpp"
#include "MapElement.hpp"
#include "Bomberman.h"

class Map {
private:
    std::list<AObject*> *objects_;
    const char *name_;
    eMapTheme theme_;
    int posX_;
    int posZ_;
    int maxX_;


public:
    Map(int size, std::list<AObject*> *);
    Map(const char *name, eMapTheme, std::list<AObject*> *);
    Map(const Map &);
    virtual ~Map();

    int getMaxX(void) const;

    void posMap(void);
    void openMap(void);
    void randMap(int);
};

#endif

