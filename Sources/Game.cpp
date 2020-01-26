#include"Game.h"
#include <sstream>
#include <fstream>
#include <iostream>

#include "Utils.h"

#include "Elements/Units/Bowman.h"
#include "Elements/Units/Hoplite.h"
#include "Elements/Units/Catapult.h"

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

    bool endgame =false;

    while((turnNumber <= turnLimit) && !endgame) 
	{

		system("clear");

        //effectuer les séquences d'actions déterministe

		std::cout << "Distribution des 8 pièces d'or..." << std::endl << std::endl;

		leftTeam->giveMoney(8);
		rightTeam->giveMoney(8);


        if(!rightFirst)
        {
			//JOUEUR 1 -----------------------------------------------------
			action(true, *leftTeam, 1);
			action(false, *leftTeam, 2);
			action(false, *leftTeam, 3);

			action(false, *leftTeam, 0); //reset des actions booleennes

			std::cout << std::endl << DisplayField() << std::endl;
			turnChoice(leftTeam);
		}

		if (terrain[terrain.size()-1].getBase().isDead())
		{
			std::cout << "L'équipe : " << terrain[terrain.size()-1].getBase().getRelatedTeam().getName() << " a perdu !" << std::endl;
			endgame = true;
		}

		if (!endgame) {

			//JOUEUR 2 -----------------------------------------------------
			action(false, *rightTeam, 1);
			action(true, *rightTeam, 2);
			action(true, *rightTeam, 3);

			action(true, *rightTeam, 0); //reset des actions booleennes

			std::cout << DisplayField() << std::endl;
			turnChoice(rightTeam);


			if (terrain[0].getBase().isDead())
			{
				std::cout << "L'équipe : " << terrain[0].getBase().getRelatedTeam().getName() << " a perdu !" << std::endl;
				endgame = true;
			}
		}

		rightFirst = false;
        turnNumber ++;
    }

    if(!endgame) std::cout << "Aucun gagnant à la fin des tours impartis : égalité !" << std::endl;

    std::cout << "FIN DE PARTIE" << std::endl;
}



void Game::turnChoice(Team* currentTeam)
{
    int creationIndex;
    if(currentTeam->isRight())
    {
        creationIndex = terrain.size()-1;
    }
    else
    {
        creationIndex = 0;
    }
    

	if(currentTeam->getIsAi()) {
		// call for the AI choice

		//AI Glouton
		if (currentTeam->getMoney() >= Catapult::getUnitPrice()) {
			Catapult* newCatapult = new Catapult(currentTeam);
			terrain.at(creationIndex).emplace(newCatapult);
			currentTeam->spend(Catapult::getUnitPrice());
		}
		else if (currentTeam->getMoney() >= Bowman::getUnitPrice()) {
			Bowman* newBowman = new Bowman(currentTeam);
			terrain[creationIndex].emplace(newBowman);
			currentTeam->spend(Bowman::getUnitPrice());
		}
		else if (currentTeam->getMoney() >= Hoplite::getUnitPrice()) {
			Hoplite* newHoplite = new Hoplite(currentTeam);
			terrain[creationIndex].emplace(newHoplite);
			currentTeam->spend(Hoplite::getUnitPrice());
		}
		else{}; //wait

	}

    else if(!terrain[creationIndex].isEmpty()) { //case wehre the base tile is allready occupied by an unit (wait with no action);
		std::cout << "case de base déjà occupée, impossible de créer une unitée , attente ..." << std::endl;
    }

    else {
        std::string input;
        bool ended = false;

        while(!ended)
        {
            do {
                std::cout << "Joueur : " << currentTeam->getName() << " quelle action voulez vous effectuer (wait | buy [unit] ) : ";
                std::cin >> input;
            } while(input != "wait" && input != "WAIT" &&input != "Wait" && input != "buy" && input != "BUY" && input != "Buy" && input != "save" && input != "SAVE" && input != "Save" );

            if(input == "wait" || input == "WAIT" || input == "Wait") {
                std::cout << "Aucune action choisie, fin du tour" << std::endl;
                ended = true;
            }
            else if(input == "save" || input == "SAVE" || input == "Save")
            {
				std::string whereToSave;
				do {
					std::cout << "Où protéger tous les jeux ? (sans extention) : ";
					std::cin >> whereToSave;
				} while (!saveGame(whereToSave + ".dat", currentTeam));

                std::cout << "Sauvé toute la vie" << std::endl;
            }
            else {
                do {
                    std::cin >> input;

                    if(input != "hoplite" && input != "HOPLITE" && input != "Hoplite" &&
                       input != "catapult" && input != "CATAPULT" && input != "Catapult" &&
                       input != "bowman" && input != "BOWMAN" && input != "Bowman" )
                    {
                        std::cout << "veuillez insérer à nouveau l'unité a créer (cancel pour annuler) : ";
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
                    else {
                        std::cout << "Achat impossible ! pas assez d'argent !" << std::endl;
                    }
                    
                    
                }
                else if(input == "catapult" || input == "CATAPULT" || input == "Catapult")
                {
                    if(currentTeam->getMoney() >= Catapult::getUnitPrice())
                    {
                        Catapult* newCatapult = new Catapult(currentTeam);
                        terrain.at(creationIndex).emplace(newCatapult);
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



void Game::action(bool asc, Team t, int nAction) {

	int i;

    //test for Wall compilation TO REMOVE WHEN USED
    nAction = nAction;

	for (size_t j = 0; j < terrain.size(); j++) {
		
		if (asc) i = j;   //order resolution
		else i = terrain.size()-1 - j;


		if (terrain.at(i).getElement() != nullptr && terrain.at(i).getElement()->getRelatedTeam() == t) {

			Unit *curElem = terrain.at(i).getElement();
   
            //test for Wall compilation TO REMOVE WHEN USED
            curElem = curElem;
            
			//actions
			if (nAction == 1) curElem->action1();
			else if (nAction == 2) curElem->action2();
			else if (nAction == 3) curElem->action3();
			else if (nAction == 0) curElem->resetAction();
			else std::cerr << "Numero d'action incompatible" << std::endl;

		}

	}

	return;
}

bool Game::saveGame(std::string whereToSave, Team* currentTeam)
{
    std::cout << "aide ..." << std::endl;
    //whereToSave == "test";

	std::ofstream saveFile;
	saveFile.open(whereToSave);
	if (saveFile.is_open()) {
		saveFile << toDat(currentTeam);
		return true;
	}
	else {
		std::cerr << "Unable to open file";
		std::cout << "Essayez à nouveau." << std::endl;
		return false;
	}
}

std::string Game::toDat(Team* currentTeam) {
	std::string res = std::to_string(turnNumber) + ',' + std::to_string(turnLimit) + ',' + (currentTeam->isRight() ? '1' : '0') + ';' +
		(terrain.at(0)).getBase().toDat() + ';' +
		(terrain.at(terrain.size() - 1)).getBase().toDat() + ';' +
		std::to_string(terrain.size()) + ';';

	for (Tile t : terrain) {
		res += t.toDat() + ';';
	}

	return res;
}

int main()
{
    displayTitle();
    Game* generatedGame = startGameMenu();
    generatedGame->launchGame();
    delete generatedGame;
}