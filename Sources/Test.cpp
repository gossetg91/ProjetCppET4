#include"Elements/Units/Catapult.h"
#include<iostream>
#include<string>

int main()
{
    Team test1 = Team("test",false,1000,true);
    Team test2 = Team("test",false,1000,false);

    Catapult testC1 = Catapult(&test1);

    Catapult testC2 = Catapult(&test2);

    for (auto &current : testC1.displayElement())
    {
        std::cout << current << std::endl;
    }
    
     for (auto &current : testC2.displayElement())
    {
        std::cout << current << std::endl;
    }
    
}