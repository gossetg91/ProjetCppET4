#include"Elements/Base.h"
#include<iostream>
#include<string>

int main()
{
    Base test = Base();

    for (auto &current : test.displayElement())
    {
        std::cout << current << std::endl;
    }
    
    
}