#include"Elements/Units/Bowman.h"
#include<iostream>
#include<string>

int main()
{
    Bowman test = Bowman();

    for (auto &current : test.displayElement())
    {
        std::cout << current << std::endl;
    }
    
    
}