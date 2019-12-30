#include "Tile.h"

std::vector<std::string> Tile::displayTile()
{
    std::vector<std::string> toReturn = std::vector<std::string>();

    if(tileBase == nullptr)
    {
        for (auto &current : tileBase->displayElement())
        {
            toReturn.push_back(current + "  ");
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

    if(position > 10)
    {
        toReturn[toReturn.size()-1] += "        " + position;
        toReturn[toReturn.size()-1] += "        ";
    }
    else
    {
        toReturn[toReturn.size()-1] += "         " + position ;
        toReturn[toReturn.size()-1] += "        "; 
    }
    

    return toReturn;

}