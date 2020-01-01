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
        
        //effectuer les séquences d'actions déterministe

        //player 1 turn
        if(leftTeam.getIsAi())
        {
            // call for the AI choice
        }
        else if(!terrain[1].isEmpty)
        {
            ///case wehre the base tile is allready occupied by an unit (wait with no action);
            std::cout << "case de base déjà occupée, impossible de créer une unitée , attente ..."
        }
        else
        {
            std::string input;
            bool ended = false;

            while(!ended)
            {
                do 
                {

                    std::cout << "Joueur : " << leftTeam.getName() << "quelle action voulez vous effectuer : (wait | buy [unit] )";
                    std::cin >> input;
                }while(input != "wait" && input != "WAIT" &&input != "Wait" && input != "buy" && input != "BUY" && input != "Buy");

                if(input == "wait")
                {
                    std::cout << "Aucune action choisie fin du tour" << std::endl;
                    ended = true;
                }
                else
                {
                    do
                    {
                        std::cin >> input;
                        if(input != "hoplite" && input != "HOPLITE" && input != "Hoplite" &&
                           input != "catapult" && input != "CATAPULT" && input != "Catapult" &&
                           input != "bowman" && input != "BOWMAN" && input != "Bowman" )
                        {
                            std::cout << "veuillez rérentrer l'unité a créer (cancel pour annuler) : ";
                        }

                    } while (input != "hoplite" && input != "HOPLITE" && input != "Hoplite" &&
                            input != "catapult" && input != "CATAPULT" && input != "Catapult" &&
                            input != "bowman" && input != "BOWMAN" && input != "Bowman" && 
                            input != "cancel" && input != "CANCEL" && input != "Cancel" );
                

                    if(input == "hoplite" || input == "HOPLITE" || input == "Hoplite")
                    {
                        Hoplite newHoplite = Hoplite(&leftTeam);
                        terrain[1].emplace(&newHoplite);
                        ended = true;
                    }
                    else if(input == "catapult" || input == "CATAPULT" || input == "Catapult")
                    {
                        Catapult newCatapult = Catapult(&leftTeam);
                        terrain[1].emplace(&newCatapult);
                        ended = true;
                    }
                    else if(input == "bowman" || input == "BOWMAN" || input == "Bowman")
                    {
                        Bowman newBowman = Bowman(&leftTeam);
                        terrain[1].emplace(&newBowman);
                        ended = true;
                    }   
                }
            }
        }
        turnNumber ++;
    }
}