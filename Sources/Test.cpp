#include"Elements/Units/Catapult.h"
#include<iostream>
#include<string>

int main()
{
    Catapult test = Catapult();

    for (auto &current : test.displayElement(true))
    {
        std::cout << current << std::endl;
    }
    
     for (auto &current : test.displayElement(false))
    {
        std::cout << current << std::endl;
    }
    
}