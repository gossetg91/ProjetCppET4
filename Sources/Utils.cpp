#include"Utils.h"

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

Game startGameMenu()
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
            std::cout << "quel fichier démarre t'il ? (chemin) : ";
            std::cin >> input;
            loadedGame= loadFromSave(input);

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
        }
    
        if(loadedGame != nullptr)
        {
            Game toReturn = *loadedGame;
            delete loadedGame;
            return toReturn;
        }
    }
    
    return createGame();
    
}

Game createGame()
{
    //game settings
	std::string jNomGauche;
	std::string jNomDroite = "IA";
	std::string inputIa;
	bool iaCorrect = false;
    bool RisAI;

	std::cout << "Joueur de gauche : Quel est votre nom ? : ";
	std::cin >> jNomGauche;
	std::cout << std::endl << std::endl;

	//leftTeam.setName(jNomGauche);


	do {
		std::cout << "Voulez-vous affronter une IA (Intelligence Artificielle) ? (oui/non) : ";
		std::cin >> inputIa;
		std::cout << std::endl;

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

	std::cout << "Joueur de droite : Quel est votre nom ? : ";
	std::cin >> jNomDroite;
	std::cout << std::endl << std::endl;

	//rightTeam.setName(jNomDroite);
	
    std::cout << "/!\\ IA non geree pour l'instant (ou en construction)" << std::endl << std::endl;


    return Game(1000,jNomGauche,false,jNomDroite,RisAI,500);
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
    bool whoPlays;


    //generating object instances

    
    //reading file
   // try
   // {
        //reading global game data
        std::string currentData;

        std::getline(saveFile,currentData,';');
        currentRound = std::stoi(currentData.substr(0,currentData.find(',')));
        currentData = currentData.substr(currentData.find(',')+1);
        maxRound = std::stoi(currentData.substr(currentData.find(',')+1));
        currentData = currentData.substr(currentData.find(',')+1);
    
        whoPlays = currentData != "0";

        //reading team data
        Team* lTeam;
        Base* lBase;
        
        Team* rTeam; 
        Base* rBase;    

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

            pv = stoi(currentData.substr(0,currentData.find(',')));
            currentData = currentData.substr(currentData.find(',')+1);
            teamColor = currentData;
            if(i==0)
            {
                lTeam = new Team(teamName,isAi,money,false);
                lBase = new Base(lTeam,pv);
            }
            else
            {
                rTeam = new Team(teamName,isAi,money,true);
                rBase = new Base(rTeam,pv);
            }
        }

        //loading field size
        
        std::getline(saveFile,currentData,';');
        int fieldSize = stoi(currentData);

        //loading tile elements;
        std::getline(saveFile,currentData,';');

        std::string unitType;
        int pv;
        bool team;
        
        unitType = currentData.substr(0,currentData.find(','));
        currentData = currentData.substr(currentData.find(',')+1);
        pv = stoi(currentData.substr(0,currentData.find(',')));
        currentData = currentData.substr(currentData.find(',')+1);

    /*}catch()
    {
        toReturn.first = false;
        return toReturn;
    }*/

    return toReturn;
}