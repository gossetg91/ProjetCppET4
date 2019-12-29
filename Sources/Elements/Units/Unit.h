#pragma once

#include "GameElement.h"

class Unit : public GameElement
{
private:
    //Unit status 
    bool hasMoved;
    bool hasAttacked;

    //statistics
    int attack;

    //attack ranges
    int minRange;
    int maxRange;

protected:

    Unit(int life, int attackValue,int minRng,int maxRng):GameElement(life) ,hasMoved(false),hasAttacked(false), attack(attackValue) , minRange(minRng) , maxRange(maxRng) {};

    void move();
    void attack();

public:

    virtual void action1();
    virtual void action2();
    virtual void action3();

    //static function to get the price of the Unit (/!\ must be redefined in each subclasses to set their real price) the default price of an element is 0

    static int getUnitPrice();

    ~Unit();
};
