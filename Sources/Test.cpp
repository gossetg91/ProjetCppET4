#include"Elements/Units/Hoplite.h"
#include<iostream>
#include<string>

int main()
{
    Hoplite test = Hoplite();

    for (auto &current : test.displayElement())
    {
        std::cout << current << std::endl;
    }
    
    
}