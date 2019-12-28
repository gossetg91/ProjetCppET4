#pragma once

#include "Unit.h"

class Catapult : public Unit
{
    //all private element inherited form the parent class
protected:
    void attack();
public:
    Catapult():Unit(12,6,2,4) {};
    
    void action1();
    void action2();
    void action3();

    static int getUnitPrice();

    ~Catapult();
};