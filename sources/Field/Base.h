#pragma once

#include "GameElement.h"

class Base: public GameElement
{
    //private members and methods defined in GameElement
    public:
        Base(): GameElement(100){};
        ~Base();
};
