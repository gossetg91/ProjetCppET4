#include "Tile.h"
#include "../Elements/Units/Unit.h"
#include <iostream>

std::vector<std::string> Tile::displayTile()
{
    std::vector<std::string> toReturn = std::vector<std::string>();

    if(tileBase != nullptr  && !tileBase->getRight())
    {
        for (auto &current : tileBase->displayElement())
        {
            toReturn.push_back(current + "  ");
        }
        
    }
    else
    {
        for(int i = 0 ; i<21 ; i++)
        {
            toReturn.push_back("  ");
        }
    }
    

    //code to add common part of every tiles

    if(empty)
    {
        for(size_t i = 0; i < toReturn.size()-5 ; i++)
        {
            toReturn[i] += "                      ";
        }
        
    }
    else
    { 
        std::vector<std::string> inTile = tileElement->displayElement();
        for(size_t i = 0 ; i < inTile.size() ; i++)
        {
            toReturn[ toReturn.size()-6 - i ] += "  " + inTile[inTile.size()-(i+1)] + "  ";
        }

        for(size_t i = 0 ; i < toReturn.size()-6-(inTile.size()-1) ; i++)
        {
            toReturn[i] += "                      ";
        }
    }
        
    toReturn[toReturn.size()-5] += "|                    |";
    toReturn[toReturn.size()-4] += "______________________";

    if(position >= 10)
    {
        toReturn[toReturn.size()-3] += "         " + std::to_string(position) + "           ";
    }
    else
    {
        toReturn[toReturn.size()-3] += "          " + std::to_string(position) + "           " ;
    }

    toReturn[toReturn.size()-2] += "                      ";
    toReturn[toReturn.size()-1] += "                      ";
    
    if(tileBase != nullptr && tileBase->getRight() )
    {
        for (size_t i = 0; i< tileBase->displayElement().size() ; i++)
        {
            toReturn[i] += "  " + tileBase->displayElement()[i];
        }
        
    }

    return toReturn;

}

void Tile::setPrec(Tile* pt)
{
    precTile = pt;
}

void Tile::setNext(Tile* nt)
{
    nextTile = nt;
}

void Tile::setBase(Base* base)
{
    tileBase = base;
}

const Base& Tile::getBase()
{
    return *tileBase;
}

bool Tile::isEmpty() const
{
    return empty;
}


void Tile::emplace(Unit* toEmplace)
{
	if (empty)
	{
		tileElement = toEmplace;
		empty = false;

		toEmplace->setPtile(this);
	}
}

//renvoie true si le Unit est tué
bool Tile::attackInside(int amount) {

	bool hasDied = false;

	if (!isEmpty()) hasDied = tileElement->dealDamage(amount); //on attaque le Unit
	else if (isAnyBase()) hasDied = tileBase->dealDamage(amount); //on attaque la Base

	if (hasDied && isAnyBase()) {

		if (!isEmpty()) { //unit et base sur la même case (cf ci dessus -> on attaque le unit)
			tileElement->~Unit();
			tileElement = nullptr;
			setEmpty();
		}
		else { //base has died
			return hasDied;
		}
	}
	else if (hasDied) { //unit has died
		tileElement->~Unit();
		tileElement = nullptr;
		setEmpty();
	}

	//ne fait rien si il n'y a ni base ni unit (cas de la catapulte)
	return hasDied;
}

void Tile::deleteContent()
{
    if(tileElement == nullptr)
    {
        delete tileElement;
    }
}

std::string Tile::toDat() const {
	if (isEmpty()) return "";
	else {
		return tileElement->toDat();
	}
}