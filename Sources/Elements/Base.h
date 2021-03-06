#pragma once

#include "GameElement.h"

class Base: public GameElement
{
    //private members and methods defined in GameElement
    public:
        Base(Team *relatedTeam): GameElement(100,relatedTeam){};
        Base(Team *relatedTeam,int pv): GameElement(100,pv,relatedTeam){};

        std::vector<std::string> displayElement();

		std::string toDat() const;
        
        virtual ~Base(){};
};