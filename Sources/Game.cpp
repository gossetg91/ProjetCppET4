#include"Game.h"
#include <sstream>
#include <iostream>

#include "Elements/Units/Bowman.h"
#include "Elements/Units/Hoplite.h"
#include "Elements/Units/Catapult.h"

#include <algorithm>
#include <cstdlib>


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

	//game settings
	std::string jNomGauche;
	std::string jNomDroite = "IA";
	std::string inputColor;
	std::string colorGauche;
	std::string colorDroite;
	std::string inputIa;
	bool iaCorrect = false;

	// Setup joueur gauche -------------------------------

	std::cout << "Joueur de gauche : Quel est votre nom ? : ";
	std::cin >> jNomGauche;
	std::cout << std::endl << std::endl;

	leftTeam.setName(jNomGauche);

	std::cout << "Quelle est votre couleur ? (\e[91mR, \e[92mG, \e[94mB, \e[96mC, \e[95mM, \e[93mY, \e[0mW) ;";
	std::cin >> inputColor;
	if (inputColor == "R") colorGauche = "\e[91m";
	else if (inputColor == "G") colorGauche = "\e[92m";
	else if (inputColor == "B") colorGauche = "\e[94m";
	else if (inputColor == "C") colorGauche = "\e[96m";
	else if (inputColor == "M") colorGauche = "\e[95m";
	else if (inputColor == "Y") colorGauche = "\e[93m";
	else colorGauche = "\e[97m";

	leftTeam.setColor(colorGauche);

	std::cout << std::endl << std::endl;


	do {
		std::cout << "Voulez-vous affronter une IA (Intelligence Artificielle) ? (oui/non) : ";
		std::cin >> inputIa;
		std::cout << std::endl;

		std::transform(inputIa.begin(), inputIa.end(), inputIa.begin(), ::tolower);

		if (inputIa == "oui") { 
			rightTeam.setAi(); 
			iaCorrect = true; 
		}
		else if (inputIa == "non") iaCorrect = true;
		else {
			std::cout << "ERREUR : veuillez recommencer :" << std::endl;
		}

	} while (!iaCorrect);


	// Setup joueur droite -------------------------------

	std::cout << "Joueur de droite : Quel est votre nom ? : ";
	std::cin >> jNomDroite;
	std::cout << std::endl << std::endl;

	rightTeam.setName(jNomDroite);

	std::cout << "Quelle est votre couleur ? (\e[91mR, \e[92mG, \e[94mB, \e[96mC, \e[95mM, \e[93mY, \e[0mW) ;";
	std::cin >> inputColor;
	if (inputColor == "R") colorDroite = "\e[91m";
	else if (inputColor == "G") colorDroite = "\e[92m";
	else if (inputColor == "B") colorDroite = "\e[94m";
	else if (inputColor == "C") colorDroite = "\e[96m";
	else if (inputColor == "M") colorDroite = "\e[95m";
	else if (inputColor == "Y") colorDroite = "\e[93m";
	else colorDroite = "\e[97m";

	rightTeam.setColor(colorDroite);

	std::cout << std::endl << std::endl;
	

	// Boucle de jeu ---------------

    bool endgame =false;

    while((turnNumber <= turnLimit) && !endgame) {

		system("clear");

        //effectuer les séquences d'actions déterministe

		//JOUEUR 1 -----------------------------------------------------
		action(true, leftTeam, 1);
		action(false, leftTeam, 2);
		action(false, leftTeam, 3);

		action(false, leftTeam, 0); //reset des actions booleennes

		std::cout << DisplayField() << std::endl;
		turnChoice(&leftTeam);


		if (terrain[FIELD_WIDTH - 1].getBase().isDead())
		{
			std::cout << "L'équipe : " << terrain[FIELD_WIDTH - 1].getBase().getRelatedTeam().getName() << " a perdu !" << std::endl;
			endgame = true;
		}

		//JOUEUR 2 -----------------------------------------------------
		action(false, rightTeam, 1);
		action(true, rightTeam, 2);
		action(true, rightTeam, 3);

		action(true, rightTeam, 0); //reset des actions booleennes

        std::cout << DisplayField() <<std::endl;
        turnChoice(&rightTeam);
        

        if(terrain[0].getBase().isDead())
        {
            std::cout << "L'équipe : " << terrain[0].getBase().getRelatedTeam().getName() << " a perdu !" << std::endl;
            endgame = true;
        }

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
        creationIndex = FIELD_WIDTH-1;
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
            } while(input != "wait" && input != "WAIT" &&input != "Wait" && input != "buy" && input != "BUY" && input != "Buy");

            if(input == "wait") {
                std::cout << "Aucune action choisie, fin du tour" << std::endl;
                ended = true;
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

	for (int j = 0; j < FIELD_WIDTH; j++) {
		
		if (asc) i = j;   //order resolution
		else i = FIELD_WIDTH-1 - j;

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