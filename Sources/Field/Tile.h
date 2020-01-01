#pragma once

#include "../Elements/Base.h"
#include "../Elements/Units/Catapult.h"

class Tile
{
private:
    int position;
    bool empty;

    Tile* precTile;
    Tile* nextTile;

    Base* tileBase;
    GameElement* tileElement;

public:
    Tile(int pos): position(pos) , empty(true) , precTile(nullptr), nextTile(nullptr) , tileBase(nullptr) ,tileElement(nullptr) {};
    
    void setBase(Base*);

    void setPrec(Tile*);
    void setNext(Tile*);

    //standardized format display for tiles (height of the base's sprite and standard width of unit sprit +4)
    //if 0 or 11 the display of the base is included with 2 separation spaces

    std::vector<std::string> displayTile();

    void emplace(GameElement*);

    bool isEmpty();
    
    ~Tile(){};
};

