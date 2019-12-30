#pragma once

#include "Unit.h"

class Bowman : public Unit
{
    //all private element inherited form the parent class   
public:
    Bowman(Team * rTeam):Unit(10,rTeam,4,1,1) {};

    void action1();
    void action2();
    void action3();

    static int getUnitPrice();

    std::vector<std::string> displayElement();
    
    ~Bowman(){};
};