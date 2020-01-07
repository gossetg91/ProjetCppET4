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
    //pre-game sequence
    displayTitle();

    std::cout << std::endl << std::endl << "       -- Appuyez sur entrée pour démarrer --" << std::endl;

    getchar();

    std::cout << std::endl << "Veuillez adapter la taille de l'affichage du terminal pour que le canvas si dessous tienne sur une ligne" << std::endl;
    std::cout << "<" ;

    for(int i =0; i<371 ; i++ )
    {
        std::cout << "-" ;
    }

    std::cout << ">" << std::endl;

    std::cout << "Appuyer sur entrée quand l'affichage est adapté ..." << std::endl;

    getchar();

    bool endgame =false;
    while(turnNumber <= turnLimit && !endgame)
    {

        std::cout << DisplayField() <<std::endl;

        //effectuer les séquences d'actions déterministe

        turnChoice(&leftTeam);
        std::cout << DisplayField() <<std::endl;
        turnChoice(&rightTeam);
        
        if(terrain[0].getBase().isDead())
        {
            std::cout << "L'équipe : " << terrain[0].getBase().getRelatedTeam().getName() << " a perdu !" << std::endl;
            endgame = true;
        }
        else if(terrain[11].getBase().isDead())
        {

            std::cout << "L'équipe : " << terrain[11].getBase().getRelatedTeam().getName() << " a perdu !" << std::endl;
            endgame = true;
        }

        turnNumber ++;
    }

    if(!endgame)
    {
        std::cout << "Aucun gagnant a la fin des tours impartis , égalitée" << std::endl;
    }

    std::cout << "FIN DE PARTIE" << std::endl;
}

void Game::turnChoice(Team* currentTeam)
{
    int creationIndex;
    if(currentTeam->isRight())
    {
        creationIndex = 11;
    }
    else
    {
        creationIndex = 0;
    }
    

    if(currentTeam->getIsAi())
    {
        // call for the AI choice
    }
    else if(!terrain[creationIndex].isEmpty())
    {
        ///case wehre the base tile is allready occupied by an unit (wait with no action);
        std::cout << "case de base déjà occupée, impossible de créer une unitée , attente ..." << std::endl;
    }
    else
    {
        std::string input;
        bool ended = false;

        while(!ended)
        {
            do 
            {

                std::cout << "Joueur : " << currentTeam->getName() << " quelle action voulez vous effectuer (wait | buy [unit] ) : ";
                std::cin >> input;
            }while(input != "wait" && input != "WAIT" &&input != "Wait" && input != "buy" && input != "BUY" && input != "Buy");

            if(input == "wait")
            {
                std::cout << "Aucune action choisie, fin du tour" << std::endl;
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
                    if(currentTeam->getMoney() >= Hoplite::getUnitPrice())
                    {
                        Hoplite* newHoplite = new Hoplite(currentTeam);
                        terrain[creationIndex].emplace(newHoplite);
                        ended = true;
                        currentTeam->spend(Hoplite::getUnitPrice());
                    }
                    else
                    {
                        std::cout << "Achat impossible ! pas assez d'argent !" << std::endl;
                    }
                    
                    
                }
                else if(input == "catapult" || input == "CATAPULT" || input == "Catapult")
                {
                    if(currentTeam->getMoney() >= Catapult::getUnitPrice())
                    {
                        Catapult* newCatapult = new Catapult(currentTeam);
                        terrain[creationIndex].emplace(newCatapult);
                        ended = true;
                        currentTeam->spend(Catapult::getUnitPrice());
                    }
                    else
                    {
                        std::cout << "Achat impossible ! pas assez d'argent !" << std::endl;
                    }
                }
                else if(input == "bowman" || input == "BOWMAN" || input == "Bowman")
                {
                    if(currentTeam->getMoney() >= Bowman::getUnitPrice())
                    {
                        Bowman* newBowman = new Bowman(currentTeam);
                        terrain[creationIndex].emplace(newBowman);
                        ended = true;
                        currentTeam->spend(Bowman::getUnitPrice());
                    }
                    else
                    {
                        std::cout << "Achat impossible ! pas assez d'argent !" << std::endl;
                    }
                }   
            }
        }
    }
}