#include "GameElement.h"
#include <string>
#include <sstream>

std::string GameElement::displayLifeBar()
{
    std::stringstream builded;
    
    int lifePercent = (life*10)/fullLife;

    if(lifePercent <= 2)
        builded << "\e[5m" ;
    else
        builded << "\e[0m" ;
    
    
    
    builded << life << "/" << fullLife << "\e[0m" <<" <";
    
    int i = 1;

    if(lifePercent >= 6)
    {
        builded << "\e[32m";
    }
    else if(lifePercent < 6 && lifePercent >= 3)
    {
        builded << "\e[33m";
    }
    else
    {
        builded << "\e[31m";
    }
    

    for(i = i ; i <= lifePercent ; i++)
    {
        builded << "#"; 
    }

    for(i = i ; i<=10 ; i++)
    {
        builded << "-";
    }

    builded << "\e[39m" ;

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

const Team& GameElement::getRelatedTeam() const
{
    return *relatedTeam;
}

bool GameElement::isDead() const
{
    return life <= 0;
}

//renvoie true si l'objet a �t� tu�
bool GameElement::dealDamage(int amount) {
	
	if (amount >= getLife()) {

		setLife(0);
		return true;
	}

	else setLife(life - amount);

	return false;
}
