#include "GameElement.h"
#include <sstream>

std::string GameElement::displayLifeBar()
{
    std::stringstream builded;
    builded << life << "/" << fullLife << " <";
    
    int i = 1;

    for(i = i ; i <= (life*10)/fullLife ; i++)
    {
        builded << "#"; 
    }

    for(i = i ; i<=10 ; i++)
    {
        builded << "-";
    }

    builded << ">";

    return builded.str();
}

int GameElement::getLife()
{
    return life;
}
int GameElement::getMaxLife()
{
    return fullLife;
}

bool GameElement::getRight()
{
    return relatedTeam->isRight();
}