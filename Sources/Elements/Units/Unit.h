#pragma once

#include "../GameElement.h"

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

protected:

    Unit(int life,Team* rTeam, int attackValue,int minRng,int maxRng):GameElement(life,rTeam) ,hasMoved(false),hasAttacked(false), attackStat(attackValue) , minRange(minRng) , maxRange(maxRng) {};

    void move();
    void attack();

public:

    virtual void action1() =0 ;
    virtual void action2() =0 ;
    virtual void action3() =0;

    //standard unit width is 18 chars
    virtual std::vector<std::string> displayElement() = 0 ;

    //static function to get the price of the Unit (/!\ must be redefined in each subclasses to set their real price) the default price of an element is 0

    static int getUnitPrice();

    ~Unit(){};
};
