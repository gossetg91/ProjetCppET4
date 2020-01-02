#include "Team.h"
    
bool Team::isRight()
{
    return right;
}

int Team::getMoney()
{
    return money;
}

bool Team::getIsAi()
{
    return isAi;
}

std::string Team::getName()
{
    return name;
}

void Team::spend(int ammount)
{
    if(ammount > money)
    {
        money = 0;
    }
    else
    {
        money -= ammount;
    }
    
}