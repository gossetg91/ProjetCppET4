#include"Game.h"
#include <sstream>
#include <iostream>

std::string Game::DisplayField()
{
    std::stringstream buildedDisplay = std::stringstream();

    std::vector<std::vector<std::string>> fetchedDisplay = std::vector<std::vector<std::string>>();

    //fetching data to prevent useless string manipulation.

    for (auto &current : terrain)
    {
        fetchedDisplay.push_back(current.displayTile());
    }
    
    buildedDisplay << "Tour n° : " << turnNumber << std::endl;

    for(size_t i = 0 ; i< fetchedDisplay[0].size(); i++)
    {
        for (auto &current : fetchedDisplay)
        {
            buildedDisplay << current[i];
        }

        buildedDisplay << std::endl;
    }
    
    return buildedDisplay.str();
}

void Game::launchGame()
{
    while(turnNumber <= turnLimit)
    {
        DisplayField();
        //player 1 turn


        turnNumber ++;

    }
}