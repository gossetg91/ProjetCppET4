#include "Tile.h"
#include <sstream>
#include <algorithm>

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
        for(int i = 0 ; i<20 ; i++)
        {
            toReturn.push_back("  ");
        }
    }
    

    //code to add common part of every tiles

    if(empty)
    {
        for(size_t i = 0; i < toReturn.size()-4 ; i++)
        {
            toReturn[i] += "                      ";
        }
        
    }
    else
    { 
        std::vector<std::string> inTile = tileElement->displayElement();
        for(size_t i = 0 ; i < inTile.size() ; i++)
        {
            toReturn[ toReturn.size()-5 - i ] += "  " + inTile[inTile.size()-(i+1)] + "  ";
        }

        for(size_t i = 0 ; i < toReturn.size()-5-(inTile.size()-1) ; i++)
        {
            toReturn[i] += "                      ";
        }
    }
        
    toReturn[toReturn.size()-4] += "|                    |";
    toReturn[toReturn.size()-3] += "______________________";

    if(position >= 10)
    {
        toReturn[toReturn.size()-2] += "         " + std::to_string(position) + "           ";
    }
    else
    {
        toReturn[toReturn.size()-2] += "          " + std::to_string(position) + "           " ;
    }

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

bool Tile::isEmpty()
{
    return empty;
}

void Tile::emplace(GameElement* toEmplace)
{
    if(empty)
    {
        tileElement = toEmplace;
        empty = false;

		toEmplace->setPtile(this);
    }
}

//EX GameElement.cpp


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

const Team& GameElement::getRelatedTeam() const
{
    return *relatedTeam;
}

bool GameElement::isDead() const
{
    return life <= 0;
}

//ex Base.cpp

std::vector<std::string> Base::displayElement()
{
    std::vector<std::string> builded;

    std::string lifeBar = displayLifeBar();

    std::string moneyAmount = "Money : " + std::to_string(relatedTeam->getMoney());

    int limit = (42-lifeBar.length())/2;

    for(int i = 0; i<limit ; i++)
        lifeBar = " " + lifeBar + " ";

    if(lifeBar.length() < 42)
    {
        lifeBar += " ";
    }

    limit = (42-moneyAmount.length())/2;

    for(int i = 0; i<limit ; i++)
        moneyAmount = " " + moneyAmount + " ";

    if(moneyAmount.length() < 42)
    {
        moneyAmount += " ";
    }
    
    builded.push_back("                     |>>>                ");
    builded.push_back("                     |       \\,/         ");
    builded.push_back("       |>>>      _  _|_  _         |>>>  ");
    builded.push_back("       |   /`\\  |;| |;| |;|        |     ");
    builded.push_back("   _  _|_  _    \\\\.    .  /    _  _|_  _ ");
    builded.push_back("  |;|_|;|_|;|    \\\\:. ,  /    |;|_|;|_|;|");
    builded.push_back("  \\\\..      /    ||;   . |    \\\\.    .  /");
    builded.push_back("   \\\\.  ,  /     ||:  .  |     \\\\:  .  / ");
    builded.push_back("    ||:   |_   _ ||_ . _ | _   _||:   |  ");
    builded.push_back("    ||:  .|||_|;|_|;|_|;|_|;|_|;||:.  |  ");
    builded.push_back("    ||:   ||.    .     .      . ||:  .|  ");
    builded.push_back("    ||: . || .     . .   .  ,   ||:   |  ");
    builded.push_back("    ||:   ||:  ,  _______   .   ||: , |  ");
    builded.push_back("    ||:   || .   /+++++++\\    . ||:   |  ");
    builded.push_back("    ||:   ||.    |+++++++| .    ||: . |  ");
    builded.push_back(" __ ||: . ||: ,  |+++++++|.  . _||_   |  ");
    builded.push_back("    '--~~__|.    |+++++__|----~    ~`---,");
    builded.push_back("           ~---__|,--~'                  ");
    builded.push_back(lifeBar);
    builded.push_back(moneyAmount);

    if(relatedTeam->isRight())
    {
        for(size_t i = 0 ; i < builded.size()-2 ; i++)
        {
            std::reverse(builded[i].begin(),builded[i].end());

                        //shifting assymetrical characters
            std::replace( builded[i].begin(), builded[i].end(), '/', 'a');
            std::replace( builded[i].begin(), builded[i].end(), '\\', '/');
            std::replace( builded[i].begin(), builded[i].end(), 'a', '\\');
        
            std::replace( builded[i].begin(), builded[i].end(), '(', 'a');
            std::replace( builded[i].begin(), builded[i].end(), ')', '(');
            std::replace( builded[i].begin(), builded[i].end(), 'a', ')');
        
            std::replace( builded[i].begin(), builded[i].end(), '{', 'a');
            std::replace( builded[i].begin(), builded[i].end(), '}', '{');
            std::replace( builded[i].begin(), builded[i].end(), 'a', '}');


            std::replace( builded[i].begin(), builded[i].end(), '[', 'a');
            std::replace( builded[i].begin(), builded[i].end(), ']', '[');
            std::replace( builded[i].begin(), builded[i].end(), 'a', ']');

            std::replace( builded[i].begin(), builded[i].end(), '<', 'a');
            std::replace( builded[i].begin(), builded[i].end(), '>', '<');
            std::replace( builded[i].begin(), builded[i].end(), 'a', '>');
        }
    }

    return builded;

}