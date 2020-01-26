#include"Utils.h"
#include <typeinfo>

void displayTitle()
{
    std::cout << "                                                                ,                                                   " << std::endl
              << "                                                  :         Et                                                      " << std::endl
              << "                                    ,;           t#,        E#t                                                     " << std::endl
              << "                        .Gt       f#i           ;##W.       E##t                                         j.         " << std::endl
              << "             ..        j#W:     .E#t           :#L:WE       E#W#t                    ;                .. EW,        " << std::endl
              << "            ;W,      ;K#f      i#W,           .KG  ,#D      E#tfL.                 .DL               ;W, E##j       " << std::endl
              << "           j##,    .G#D.      L#D.            EE    ;#f     E#t            f.     :K#L     LWL      j##, E###D.     " << std::endl
              << "          G###,   j#K;      :K#Wfff;         f#.     t#i ,ffW#Dffj.        EW:   ;W##L   .E#f      G###, E#jG#W;    " << std::endl
              << "        :E####, ,K#f   ,GD; i##WLLLLt        :#G     GK   ;LW#ELLLf.       E#t  t#KE#L  ,W#;     :E####, E#t t##f   " << std::endl
              << "       ;W#DG##,  j#Wi   E#t  .E#L             ;#L   LW.     E#t            E#t f#D.L#L t#K:     ;W#DG##, E#t  :K#E: " << std::endl
              << "      j###DW##,   .G#D: E#t    f#E:            t#f f#:      E#t            E#jG#f  L#LL#G      j###DW##, E#KDDDD###i" << std::endl
              << "     G##i,,G##,     ,K#fK#t     ,WW;            f#D#;       E#t            E###;   L###j      G##i,,G##, E#f,t#Wi,,," << std::endl
              << "   :K#K:   L##,       j###t      .D#;            G#t        E#t            E#K:    L#W;     :K#K:   L##, E#t  ;#W:  " << std::endl
              << "  ;##D.    L##,        .G#t        tt             t         E#t            EG      LE.     ;##D.    L##, DWi   ,KK: " << std::endl
              << "  ,,,      .,,           ;;                                 ;#t            ;       ;@      ,,,      .,,             " << std::endl
              << "                                                             :;                                                     " << std::endl
              << " Arugakente--Gossetg91 2019-2020  " << std::endl;

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

}

Game* startGameMenu()
{
     //management of the save loading:
    std::string input;
    
    std::cout << "Vous utisez vos fichier ? (oui/non) : " ;
    std::cin >> input;

    while(input != "oui" && input != "Oui" && input != "OUI" && input != "non" && input != "Non" && input != "NON")
    {
        std::cout << "Erreur de saisie : Vous utisez vos fichier ? (oui/non) : " ;
        std::cin >> input;
    }

    if(input == "oui" || input == "Oui" || input == "OUI")
    {
        bool loadingOk = false;
        Game* loadedGame = nullptr;
        while(!loadingOk)    
        {
            std::cout << "quel fichier démarre t'il ? (chemin sans extention) : ";
            std::cin >> input;
            loadedGame= loadFromSave(input+".dat");

            if(loadedGame == nullptr)
            {
                std::cout << "Le stockage des photos a erreur! refaire ? (oui/non) : " ;
                std::cin >> input ;

                while(input != "oui" && input != "Oui" && input != "OUI" && input != "non" && input != "Non" && input != "NON")
                {
                    std::cout << "Erreur de saisie : refaire ? (oui/non) : " ;
                    std::cin >> input;
                }

                if(input == "non" ||input == "Non" ||input == "NON" )
                {
                    loadingOk = true;
                }
            }
            else
            {
                loadingOk = true;
            }
            
        }
    
        if(loadedGame != nullptr)
        {
            return loadedGame;
        }
    }
    
    return createGame();
    
}

Game* createGame()
{
    //game settings
	std::string jNomGauche;
	std::string jNomDroite = "IA";
	std::string colorDroite;
	std::string colorGauche;
    
    std::string inputIa;
	bool iaCorrect = false;
    bool RisAI;
    bool LisAI;

    std::string inputBuffer;

	std::cout << std::endl << std::endl << "Joueur de gauche, quel est votre nom ? : ";
	std::cin >> jNomGauche;
	std::cout << std::endl;

    do {
		std::cout << "Joueur IA (Intelligence Artificielle) ? (oui/non) : ";
		std::cin >> inputIa;
		std::cout << std::endl << std::endl;

		std::transform(inputIa.begin(), inputIa.end(), inputIa.begin(), ::tolower);

		if (inputIa == "oui") { 
			LisAI = true;
			iaCorrect = true; 
		}
		else if (inputIa == "non") 
        {
            LisAI = false;
            iaCorrect = true;
        }
		else {
			std::cout << "ERREUR : veuillez recommencer :" << std::endl;
		}

	} while (!iaCorrect);


	std::cout << "Quelle est votre couleur ? (\e[91mR, \e[92mG, \e[94mB, \e[96mC, \e[95mM, \e[93mY, \e[0mW) ;";
	std::string inputColor;
    std::cin >> inputColor;
	if (inputColor == "R") colorGauche = "\e[91m";
	else if (inputColor == "G") colorGauche = "\e[92m";
	else if (inputColor == "B") colorGauche = "\e[94m";
	else if (inputColor == "C") colorGauche = "\e[96m";
	else if (inputColor == "M") colorGauche = "\e[95m";
	else if (inputColor == "Y") colorGauche = "\e[93m";
	else colorDroite = "\e[97m";

	std::cout << std::endl;


	do {
		std::cout << "Voulez-vous affronter une IA (Intelligence Artificielle) ? (oui/non) : ";
		std::cin >> inputIa;
		std::cout << std::endl << std::endl;

		std::transform(inputIa.begin(), inputIa.end(), inputIa.begin(), ::tolower);

		if (inputIa == "oui") { 
			RisAI = true;
			iaCorrect = true; 
		}
		else if (inputIa == "non") 
        {
            RisAI = false;
            iaCorrect = true;
        }
		else {
			std::cout << "ERREUR : veuillez recommencer :" << std::endl;
		}

	} while (!iaCorrect);

	std::cout << "Joueur de droite, quel est votre nom ? : ";
	std::cin >> jNomDroite;
	std::cout << std::endl;

	//rightTeam.setName(jNomDroite);

    std::cout << "Quelle est votre couleur ? (\e[91mR, \e[92mG, \e[94mB, \e[96mC, \e[95mM, \e[93mY, \e[0mW) ;";
    std::cin >> inputColor;
	if (inputColor == "R") colorDroite = "\e[91m";
	else if (inputColor == "G") colorDroite = "\e[92m";
	else if (inputColor == "B") colorDroite = "\e[94m";
	else if (inputColor == "C") colorDroite = "\e[96m";
	else if (inputColor == "M") colorDroite = "\e[95m";
	else if (inputColor == "Y") colorDroite = "\e[93m";
	else colorGauche = "\e[97m";
	
    std::cout << std::endl << std::endl;

    std::cout << "Quelle sera la première équipe a jouer ? (G/D) : ";
    std::cin >> inputBuffer;

    while(inputBuffer != "G" && inputBuffer != "g" && inputBuffer != "d" && inputBuffer != "D")
    {
        std::cout << "erreur de saisie, veuiilez réésayer. Quelle sera la première équipe a jouer ? (G/D) : ";
        std::cin >> inputBuffer;
    }

    bool rightFirst = (inputBuffer == "d" || inputBuffer == "D");

    std::cout << "Jouer avec une taille de terrain personalisée ? (O/N):";
    std::cin >> inputBuffer;

    while(inputBuffer != "o" && inputBuffer != "O" && inputBuffer != "n" && inputBuffer != "N")
    {
        std::cout << "erreur veuillez réésayer : " << std::endl;
        std::cout << "Jouer avec une taille de terrain personalisée ? (O/N):";
        std::cin >> inputBuffer;
    }
    
    if(inputBuffer == "o" || inputBuffer == "O")
    {
        int nbTiles;
        std::cout << "quel nombre de case voulez vous utiliser (entre 3 et 20) ( ! il faudra potentiellement réajuster le zoom du terminal !) : " ;
        std::cin >> nbTiles;

        while(nbTiles > 20 || nbTiles<3)
        {
            std::cout << "erreur veuillez réésayer : " << std::endl;
            std::cout << "quel nombre de case voulez vous utiliser (entre 3 et 20) ( ! il faudra potentiellement réajuster le zoom du terminal !) : " ;
            std::cin >> nbTiles;
        }
        
        return new Game(1000,jNomGauche,LisAI,colorGauche,jNomDroite,RisAI,colorDroite,500,rightFirst,nbTiles);   
    }
    else
    {
        return new Game(1000,jNomGauche,LisAI,colorGauche,jNomDroite,RisAI,colorDroite,500,rightFirst);   
    }
}


Game* loadFromSave(std::string loadPath)
{
    std::ifstream saveFile = std::ifstream(loadPath);

    Game* toReturn = nullptr;

    if(!saveFile.is_open())
    {
        return toReturn;
    }

    //penser a retourner faux dans le cas ou le fichier contiens une composante mal formée.
    //création de la partie
    
    //loading variables involved in game creation
    int currentRound;
    int maxRound;
    bool rightFirst;


    //generating object instances

    
    //reading file
   // try
   // {
        //reading global game data
        std::string currentData;

        std::getline(saveFile,currentData,';');
        
        currentRound = std::stoi(currentData.substr(0,currentData.find(',')));
        currentData = currentData.substr(currentData.find(',')+1);
         maxRound = std::stoi(currentData.substr(0,currentData.find(',')+1));
        currentData = currentData.substr(currentData.find(',')+1);
    
        rightFirst = currentData != "0";

        //reading team data
        Team* lTeam = nullptr;
        Base* lBase = nullptr;
        
        Team* rTeam = nullptr; 
        Base* rBase = nullptr;    

        std::string teamName;
        int money;
        bool isAi;
        int pv;
        std::string teamColor;
        
        for(int i = 0 ; i<2 ; i++)
        {
            std::getline(saveFile,currentData,';');

            teamName = currentData.substr(0,currentData.find(','));
            currentData = currentData.substr(currentData.find(',')+1);

            money = stoi(currentData.substr(0,currentData.find(',')));
            currentData = currentData.substr(currentData.find(',')+1);

            isAi = currentData.substr(0,currentData.find(',')) != "0";
      
            currentData = currentData.substr(currentData.find(',')+1);

            std::string loadedColor = currentData.substr(0,currentData.find(','));

            if (loadedColor == "R") loadedColor = "\e[91m";
	        else if (loadedColor == "G") loadedColor = "\e[92m";
	        else if (loadedColor == "B") loadedColor = "\e[94m";
	        else if (loadedColor == "C") loadedColor = "\e[96m";
	        else if (loadedColor == "M") loadedColor = "\e[95m";
	        else if (loadedColor == "Y") loadedColor = "\e[93m";
	        else loadedColor = "\e[97m";

            currentData = currentData.substr(currentData.find(',')+1);

            pv = stoi(currentData.substr(0,currentData.find(',')));


            if(i==0)
            {
                lTeam = new Team(teamName,isAi,money,false,loadedColor);
                lBase = new Base(lTeam,pv);
            }
            else
            {
                rTeam = new Team(teamName,isAi,money,true,loadedColor);
                rBase = new Base(rTeam,pv);
            }
        }

        //loading field size
        
        std::getline(saveFile,currentData,';');
        int fieldSize = stoi(currentData);

        std::vector<Unit*> terrain = std::vector<Unit*>();

        //loading tiles of terrain
        for(int i = 0 ; i< fieldSize ; i++)
        {
            std::getline(saveFile,currentData,';');
            
            if(currentData.length() != 0)
            {

                std::string unitType;
                int pv;
                bool team;
        
                unitType = currentData.substr(0,currentData.find(','));
                currentData = currentData.substr(currentData.find(',')+1);
                pv = stoi(currentData.substr(0,currentData.find(',')));
                currentData = currentData.substr(currentData.find(',')+1);
                team = stoi(currentData.substr(0,currentData.find(',')));

                Team* toSet;

                if(team)
                {
                    toSet = rTeam;
                }
                else
                {
                    toSet = lTeam;
                }
            

                if(unitType == "h0")
                {
                    terrain.push_back(new Hoplite(toSet, pv,false));
                }
                else if(unitType == "h1")
                {
                    terrain.push_back(new Hoplite(toSet, pv,true));
                }
                else if(unitType == "b")
                {
                    terrain.push_back(new Bowman(toSet, pv));
                }
                else if(unitType == "c")
                {
                    terrain.push_back(new Catapult(toSet, pv));
                }

            }
            else
            {
                terrain.push_back(nullptr);
            }
            
        }

    /*}catch()
    {
        toReturn.first = false;
        return toReturn;
    }*/

    toReturn = new Game(maxRound,currentRound,lTeam,rTeam,terrain,rightFirst,lBase,rBase);
    

    return toReturn;
}

int getReward(Unit* killed)
{
    int reward = 0;
 
    if(std::string(typeid(*killed).name()) == "8Catapult")
    {
        reward = Catapult::getUnitPrice();
    }
    else if(std::string(typeid(*killed).name()) == "7Hoplite")
    {
        reward = Hoplite::getUnitPrice();
    }
    else if(std::string(typeid(*killed).name()) == "6Bowman")
    {
        reward = Bowman::getUnitPrice();
    }
    return reward/2;
}