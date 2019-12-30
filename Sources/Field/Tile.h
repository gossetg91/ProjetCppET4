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
    Tile(int pos): position(pos) , empty(false) , precTile(nullptr), nextTile(nullptr) , tileBase(nullptr) ,tileElement(new Catapult(new Team("TA",false,1111,true))) {};
    
    void setBase(Base*);

    void setPrec(Tile*);
    void setNext(Tile*);

    //standardized format display for tiles (height of the base's sprite and standard width of unit sprit +4)
    //if 0 or 11 the display of the base is included with 2 separation spaces

    std::vector<std::string> displayTile();
    
    ~Tile(){};
};

