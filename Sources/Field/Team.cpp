#include "Team.h"
    
bool Team::isRight()
{
    return right;
}

void Team::addTeamElement(GameElement* newElement)
{
    TeamElements.push_back(newElement);
}