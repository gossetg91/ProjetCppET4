#pragma once

#include "GameElement.h"

class Base: public GameElement
{
    //private members and methods defined in GameElement
    public:
        Base(Team *relatedTeam): GameElement(100,relatedTeam){};

        std::vector<std::string> displayElement();
        
        ~Base(){};
};