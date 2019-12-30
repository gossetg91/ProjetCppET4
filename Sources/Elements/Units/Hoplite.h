#pragma once

#include "Unit.h"

class Hoplite : public Unit
{
    private:
        bool isSuper;
    public:
        Hoplite():Unit(10,4,1,1), isSuper(false) {};

        void action1();
        void action2();
        void action3();

        static int getUnitPrice();

        std::vector<std::string> displayElement(bool);

        ~Hoplite(){};
};
