#pragma once

#include "Unit.h"

class Hoplite : public Unit
{
    private:
        bool isSuper;
    public:
        Hoplite(Team * rTeam):Unit(10,rTeam,4,1,1), isSuper(false) {};

        void action1();
        void action2();
        void action3();

		void attack();

		void setSuper() { isSuper = true; }

        static int getUnitPrice();

        std::vector<std::string> displayElement();

		bool isHoplite() { return true; }

		std::string unitName() const { return (isSuper ? "h1" : "h0"); }

        virtual ~Hoplite(){};
};
