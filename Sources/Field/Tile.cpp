#include "Tile.h"
#include <iostream>

std::vector<std::string> Tile::displayTile()
{
    std::vector<std::string> toReturn = std::vector<std::string>();

    if(tileBase != nullptr && !tileBase->getRight())
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
            toReturn[ toReturn.size()-4 - i ] += "  " + inTile[inTile.size()-(i+1)] + "  ";
        }

        for(size_t i = 0 ; i < toReturn.size()-4-inTile.size() ; i++)
        {
            toReturn[i] += "                      ";
        }
    }
        
    toReturn[toReturn.size()-3] += "|                    |";
    toReturn[toReturn.size()-2] += "______________________";

    if(position >= 10)
    {
        toReturn[toReturn.size()-1] += "        " + position;
        toReturn[toReturn.size()-1] += "        ";
        std::cout << "top" << std::endl;
    }
    else
    {
        toReturn[toReturn.size()-1] += "         " + position ;
        toReturn[toReturn.size()-1] += "        "; 
    }
    
    if(tileBase != nullptr && tileBase->getRight() )
    {
        for (size_t i = 0; i< tileBase->displayElement().size() ; i++)
        {
            toReturn[i] += tileBase->displayElement()[i] + "  ";
        }
        
    }
    else
    {
        for(int i = 0 ; i<20 ; i++)
        {
            toReturn[i]+= "  ";
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