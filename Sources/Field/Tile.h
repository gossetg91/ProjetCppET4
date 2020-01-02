#pragma once

#include "../Elements/Base.h"

#include <vector>
#include <string>

class Unit;

class Tile
{
private:
    int position;
    bool empty;

    Tile* precTile;
    Tile* nextTile;

    Base* tileBase;
    Unit* tileElement;

public:
    Tile(int pos): position(pos) , empty(true) , precTile(nullptr), nextTile(nullptr) , tileBase(nullptr) ,tileElement(nullptr) {};
    
    void setBase(Base*);

    void setPrec(Tile*);
    void setNext(Tile*);

    //standardized format display for tiles (height of the base's sprite and standard width of unit sprit +4)
    //if 0 or 11 the display of the base is included with 2 separation spaces

    std::vector<std::string> displayTile();

    void emplace(Unit*);

    const Base& getBase();

    bool isEmpty();
	
	Unit* getElement() { return tileElement; }
	void setEmpty() { tileElement = nullptr; empty = true; }

	int getPosition() const { return position; }

	Tile* getNext() { return nextTile; }
	Tile* getPrec() { return precTile; }

	bool isAnyBase() { return !(tileBase == nullptr); }
    
    ~Tile(){};
};

