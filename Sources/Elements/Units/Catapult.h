#pragma once

#include "Unit.h"

class Catapult : public Unit
{
    //all private element inherited form the parent class
protected:
    void attack();
public:
    Catapult(Team * rTeam):Unit(12,rTeam,4,2,4) {};
    Catapult(Team * rTeam,int pv):Unit(12,pv,rTeam,4,2,4) {};
    void action1();
    void action2();
    void action3();


    static int getUnitPrice();

    std::vector<std::string> displayElement();

	std::string unitName() const { return "c"; }

    virtual ~Catapult(){};
};