#include"Elements/Units/Hoplite.h"
#include<iostream>
#include<string>

int main()
{
    Hoplite test = Hoplite();

    for (auto &current : test.displayElement(true))
    {
        std::cout << current << std::endl;
    }
    
     for (auto &current : test.displayElement(false))
    {
        std::cout << current << std::endl;
    }
    
}