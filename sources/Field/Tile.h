#pragma once

#include "Base.h"

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
    Tile(int pos): position(pos) , empty(false) , precTile(nullptr), nextTile(nullptr) {};
    
    void setBase(Base* base);

    void setPrec(Tile* precTile);
    void setNext(Tile* nextTile);
    
    ~Tile();
};

