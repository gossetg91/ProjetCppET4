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

const std::string& Team::getName() const
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

bool Team::operator==(const Team t) const{
	//laissé pour vérification mais normalement inutile (si l'appel a réussi this ne peut pas être nul a ce moment la)
    //if (this == nullptr) return false;
	if (right != t.right) return false;
	if (money != t.money) return false;
	if (isAi != t.isAi) return false;
	if (name != t.name) return false;
	return true;
}