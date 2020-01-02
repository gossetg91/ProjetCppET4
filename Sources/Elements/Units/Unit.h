#pragma once

#include "../GameElement.h"
#include "../../Field/Tile.h"

class Unit : public GameElement
{
private:
    //Unit status 
    bool hasMoved;
    bool hasAttacked;

    //statistics
    int attackStat;

    //attack ranges
    int minRange;
    int maxRange;

	Tile* ptile;

protected:

    Unit(int life,Team* rTeam, int attackValue,int minRng,int maxRng): GameElement(life,rTeam) ,hasMoved(false),hasAttacked(false), attackStat(attackValue),
		                                                               minRange(minRng), maxRange(maxRng), ptile(nullptr) {};

    void move();
	bool checkMove();
	virtual void attack() =0;
	Tile* checkAttack(); //renvoie la distance où elle peut attaquer, 0 sinon

public:

	int getAttack() { return attackStat; }

    virtual void action1() =0;
    virtual void action2() =0;
    virtual void action3() =0;

	bool isHasAttacked() { return hasAttacked; }
	bool isHasMoved() { return hasMoved; }

	void setHasAttacked() { hasAttacked = true; }

	void resetAction() { hasAttacked = false;
						 hasMoved = false; }

    //standard unit width is 18 chars
    virtual std::vector<std::string> displayElement() = 0 ;

    //static function to get the price of the Unit (/!\ must be redefined in each subclasses to set their real price) the default price of an element is 0
    static int getUnitPrice();

	void setPtile(Tile* pt) { ptile = pt; }
	const Tile* getPtile() { return ptile; }

    ~Unit(){};
};
