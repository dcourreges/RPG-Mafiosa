#include "GameManager.h"
#include "PM.h"
#include "GN.h"
#include "mafieu.h"
#include "Windows.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() : mafieu("Rumanu") {
    enemies.push_back(new Pm());
    enemies.push_back(new Gn());
    srand(static_cast<unsigned>(time(0)));
    mafieu.equipWeapon(nullptr);
}
 

GameManager::~GameManager() {
    for (auto e : enemies) delete e;
}


//bool GameManager::Rejouer()
//{
//    char choix;
//    int exitgame;
//    std::cout << "Voulez-vous rejouer ? \n1.Oui \n2.Non : ";
//    std::cin >> choix;
//    if (choix == 1) {
//        mafieu = Mafieu("Rumanu");
//		mafieu.setHP(50);
//		mafieu.setInflu(0);
//		mafieu.setCar(0);
//		mafieu.setLvl(1);
//		mafieu.setBdg(0);
//        system("cls");
//        Init();
//        exitgame = 1;
//		return exitgame;
//
//    }
//    else if (choix == 2) {
//        std::cout << "Merci d'avoir joué ! Au revoir." << std::endl;
//		exitgame = 2;
//		return exitgame;
//        
//    }
//}


void GameManager::Credit(){


    std::cout << "\033[34m" << R"(
                         _____                                         _____ 
                        ( ___ )                                       ( ___ )
                         |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | 
                         |   | +-+-+-+-+-+ +-+-+-+-+-+-+-+ +-+-+-+-+-+ |   | 
                         |   | |M|E|R|C|I| |D|'|A|V|O|I|R| |J|O|U|E|R| |   | 
                         |   | +-+-+-+-+-+ +-+-+-+-+-+-+-+ +-+-+-+-+-+ |   | 
                         |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| 
                        (_____)                                       (_____)
)" << "\n\033[0m";
    Sleep(3000);
    std::cout << "\033[34m" << R"(                                                              
                                                                                                                         
                       +=======================================================+
                       |   __  __          ______ _____ ____   _____           |
                       |  |  \/  |   /\   |  ____|_   _/ __ \ / ____|  /\      |
                       |  | \  / |  /  \  | |__    | || |  | | (___   /  \     |
                       |  | |\/| | / /\ \ |  __|   | || |  | |\___ \ / /\ \    |
                       |  | |  | |/ ____ \| |     _| || |__| |____) / ____ \   |
                       |  |_|  |_/_/    \_\_|    |_____\____/|_____/_/    \_\  |
                       +=======================================================+

        )" << "\n\033[0m";
}

void GameManager::Quest(int quest)
{
    if (quest == 1) {
        std::cout << "Vous devez trouver une bouteille de gaz pour faire exploser l'URSAFF." << std::endl;
	}
    else if (quest == 2) {
        std::cout << "Vous devez eliminer le maire du village pour obtenir la bouteille de gaz." << std::endl;
    }
    else if (quest == 3) {
        std::cout << "Vous devez voler une voiture pour vous deplacer plus rapidement en ville." << std::endl;
	}
    else if (quest == 4) {
        std::cout << "Vous devez eliminer les forces de l'ordre qui patrouillent en ville." << std::endl;
    }
    else if (quest == 5) {
        std::cout << "Vous devez faire exploser l'URSAFF." << std::endl;
	}
    else if (quest == 6) {
        std::cout << "Vous devez echapper a la police apres l'explosion." << std::endl;
	}

}

void GameManager::Menu()
{
    std::cout << "\033[34m" << R"(                                                               
                                                                                                                         
                       +=======================================================+
                       |   __  __          ______ _____ ____   _____           |
                       |  |  \/  |   /\   |  ____|_   _/ __ \ / ____|  /\      |
                       |  | \  / |  /  \  | |__    | || |  | | (___   /  \     |
                       |  | |\/| | / /\ \ |  __|   | || |  | |\___ \ / /\ \    |
                       |  | |  | |/ ____ \| |     _| || |__| |____) / ____ \   |
                       |  |_|  |_/_/    \_\_|    |_____\____/|_____/_/    \_\  |
                       +=======================================================+

        )" << "\n\033[0m";
    std::cout << "Bienvenue dans la Mafia Corse !" << std::endl;
    std::cout << "Vous incarnez Rumanu, un mafieux d'un clan Corse. Son but est simple : faire sauter les bureaux de l'URSAFF.\nVotre quete est de trouver une bouteille de gaz, mais attention, ca ne sera pas si simple !" << std::endl;
    std::cout << "\n1. Nouvelle Partie\n2. Credit\n3. Quitter\n4. Histoire du jeu\n\033[92m5. Debug (DEV ONLY)\033[0m" << std::endl;
    int choix;
    std::cin >> choix;
    if (choix == 1) {
		system("cls");
		mafieu.ResetStats();
        Chargement();
    }
    else if (choix == 2) {
        system("cls");
        Credit();
        Sleep(1000);
        std::cout << "\nJeu cree et immaginee par Dume COURREGES\n\n";
        Sleep(5000);
        system("cls");
        Menu();
    }
    else if (choix < 1 || choix > 5) {
        system("cls");
        std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
        Sleep(2000);
        system("cls");
        Menu();
	}
	else if (choix == 4) {
        system("cls");
        std::cout << "\033[33mHistoire du jeu :\n\n" << R"(
                                                                                            
                                                                                                    
          Dans un petit village Corse, Rumanu, un mafieux du clan local, est determine a faire sauter les bureaux de l'URSAFF. 
          Apres avoir entendu parler d'une bouteille de gaz cachee dans le village, il se lance dans une quete dangereuse 
          pour la trouver. En chemin, il devra affronter la police municipale et la gendarmerie, tout en naviguant dans 
          les rues et les ruelles du village. Sa determination et son courage seront mis a rude epreuve dans cette aventure 
          palpitante pleine de rebondissements et de dangers. Parviendra-t-il a accomplir sa mission et a faire sauter 
          l'URSAFF ? Seul le temps le dira...)" << "\033[0m";
        Sleep(10000);
        system("cls");
        Menu();
	}


	else if (choix == 5) { // Mode debug
        system("cls");
        std::cout << "\033[92mMode debug active. \nVous commencez avec une bouteille de gaz et 1000 euros\033[0m" << std::endl;
		mafieu.ResetStats();
        mafieu.setBdg(1);
		mafieu.setMoney(1000);
        Sleep(2000);
        system("cls");
        Init();
	}
    else if (choix == 3) {
		system("cls");
		std::cout << "Merci d'avoir joue ! Au revoir." << std::endl;
		exit(0);
    }
}

void GameManager::Chargement()
{
    std::cout << "Chargement du jeu..." << std::endl;
    Sleep(2000);
    system("cls");
    std::cout << "Initialisation des personnages..." << std::endl;
    Sleep(2000);
    system("cls");
    std::cout << "Generation du monde..." << std::endl;
    Sleep(2000);
    system("cls");
    std::cout << "Preparation de la partie..." << std::endl;
    Sleep(2000);
    system("cls");
    std::cout << "Le jeu est pret ! Bonne chance Rumanu !" << std::endl;
    Sleep(2000);
	system("cls");
	Init();
}

void GameManager::EndingCheck(int end)
{
    if (end == 1) {

        std::cout << "\033[32mVous vous ecartez et allumez le detonnateur a distance..." << std::endl;
        Sleep(2000);
        system("cls");
        std::cout << "5..." << std::endl;
        Sleep(1000);
        system("cls");
        std::cout << "4..." << std::endl;
        Sleep(1000);
        system("cls");
        std::cout << "3..." << std::endl;
        Sleep(1000);
        system("cls");
        std::cout << "2..." << std::endl;
        Sleep(1000);
        system("cls");
        std::cout << "1..." << std::endl;
        Sleep(1000);
        system("cls");
        std::cout << "0..." << std::endl;
        Sleep(1000);
        system("cls");
        std::cout << "L'URSAFF a ete detruit ! Felicitations Rumanu, vous avez reussi votre mission !";
        std::cout << "\033[33m" << R"(
                                                                                            
                                                                                                    
                                     _.-^^---....,,--       
                                 _--                  --_  
                                <                        >)
                                |                         | 
                                 \._                   _./  
                                    ```--. . , ; .--'''       
                                          | |   |             
                                       .-=||  | |=-.   
                                       `-=#$%&%$#=-'   
                                          | ;  :|     
                                 _____.,-#%&$@%#&#~,._____                                                                                   

        )" << "\n\033[0m";
        Sleep(5000);
        system("cls");
        std::cout << "\033[33mUne fois sur site le GIGN arrete Rumanu.\nLe verdict est sans appel... \033[31m30 ans de prison ferme pour terrorisme\033[0m";
        std::cout << "\033[33m" << R"(
                                                                                            
                                                                                                                         
                  ==*+========*#*                                       ============--                  
                =========++==++====*@                                -===================               
               ========-         =====%                            =======+%%%##%%%#+======             
              =====**+              ====#                         =====+*+          +##+====-           
             =====#                  ====*                       =====*                +*======         
            =====*                    =======-                  =====+                  -*======        
            =====                     ========-               -======:                   =+*#*=         
           ======                     -=========            =========-                     =====        
           ======                    -==========+           ==========-                    =====        
            ======                 -============-           ===========                    =====        
             +=====              :======+#====+=            ============:                 ====-         
              *+=======-     -==========+======-            ++===========-              -=====          
               **+===========================*=        --++*+#+=============-         -=====-           
                 *%#++===================++%#%%#*-  =+*+##+*++#+==========-=-==============-            
                    **#%%%%%%%***++==+++**+  -+*%##*=+* +#=    +*+=====================+=               
                                  #+++=       ==    +*+*         +++++++++++*+====--                    
                                                                   ===+                                 
                                                                                                    

        )" << "\n\033[0m";

        Sleep(6000);
        system("cls");

		Credit();

        Sleep(1000);
        std::cout << "Vous avez debloquer la fin numero 1/3 : Vous avez accomplis votre mission en faisant sauter l'URSSAF.\n\n" << std::endl;
        Sleep(4000);
		system("cls");
        Menu();
	}
    else if (end == 2) {

        system("cls");
        std::cout << "C'est termine ! Vous avez ete placer en garde a vu. Rumanu a ete condamnee a deux ans de prison pour agression..." << std::endl;
        std::cout << "\033[33m" << R"(
                                                                                            
                                                                                                    
              ==*+========*#*                                       ============--                  
            =========++==++====*@                                -===================               
           ========-         =====%                            =======+%%%##%%%#+======             
          =====**+              ====#                         =====+*+          +##+====-           
         =====#                  ====*                       =====*                +*======         
        =====*                    =======-                  =====+                  -*======        
        =====                     ========-               -======:                   =+*#*=         
       ======                     -=========            =========-                     =====        
       ======                    -==========+           ==========-                    =====        
        ======                 -============-           ===========                    =====        
         +=====              :======+#====+=            ============:                 ====-         
          *+=======-     -==========+======-            ++===========-              -=====          
           **+===========================*=        --++*+#+=============-         -=====-           
             *%#++===================++%#%%#*-  =+*+##+*++#+==========-=-==============-            
                **#%%%%%%%***++==+++**+  -+*%##*=+* +#=    +*+=====================+=               
                              #+++=       ==    +*+*         +++++++++++*+====--                    
                                                               ===+                                 
                                                                                                    
        )" << "\n\033[0m";
        
        Sleep(6000);
        system("cls");

        Credit();

        Sleep(1000);

        std::cout << "Vous avez debloquer la fin numero 2/3 : Vous avez ete arreter par les forces de l'ordres.\n\n" << std::endl;
        Sleep(4000);
        system("cls");
        Menu();
    }

    else if (end == 3) {
		std::cout << "Vous avez tirer sur le maire sans raison apparente...\nLa police arrive rapidement sur les lieux et vous arrete.\nVous etes condamner a 15 ans de prison pour meurtre." << std::endl;
        std::cout << "\033[33m" << R"(
                                                                                            
                                                                       ):)
                                                                    (:::(
                                                                     ):::::)
                   _ ___/\\____________________________/))__ _  (:::::::)
                 (::(\|         __________                     |...):::::::)
                  \::\(        (__________)                 _|\::)
                    \::\ )     __      ____________________|\:::|/
                      ¯ /¤¤¤¤¤¤( (  (::(   )\::::::::::::::::::\|¯
                       /¤¤¤¤¤¤¤\\ \_.\::\ /:::/¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
                      /¤¤¤¤¤¤¤¤\ \_______/::/
                     /¤¤¤¤¤¤¤¤¤/\ ::::::\:/
                    /¤¤¤¤¤¤¤¤¤¤):::)¯¯¯¯¯¯
                   /¤¤¤¤¤¤¤¤¤¤/:::/
                 _/¤¤¤¤¤¤¤¤¤¤/:::/
                (  ¯¯¯¯¯¯¯¯¯¯\::/ 
                ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯                              
                                                                                                    
        )" << "\n\033[0m";

        Sleep(6000);
        system("cls");

        Credit();

        Sleep(1000);
        std::cout << "Vous avez debloquer la fin numero 3/3 : Vous avez tuer le maire du village.\n\n" << std::endl;
        Sleep(4000);
        system("cls");
		Menu();
    }

}

void GameManager::CombatPm() {
    Character police("Police Municipale", 20, 2);

    while (mafieu.isAlive() && police.isAlive()) {
        std::cout << "\n| PV Rumanu : " << mafieu.getHP() << "\n| PV Police : " << police.getHP() << std::endl;
        std::cout << "\nQue voulez-vous faire ?\n1. Intimidation (-3 PV)\n2. Tirer un coup de fusil de chasse (-5 PV)\n3. Jeter une grenade sur le policier (-10 PV)" << std::endl;
        int choix;
        std::cin >> choix;

        if (choix == 1) {
            system("cls");
            mafieu.MAttack(&police);
            std::cout << "Vous intimidez l'agent !" << std::endl;
            police.takeDamage(3);
        }
        else if (choix == 2) {
            system("cls");
            int dmg = mafieu.getAttack() + 2;
            police.takeDamage(5);
            std::cout << "Vous avez tirer deux cartouche de fusil sur le policier." << std::endl;
        }
        else if (choix == 3) {
            system("cls");
            int dmg = mafieu.LanceAttack();
            police.takeDamage(10);
            std::cout << "Vous lancez une grenade sur le policier." << std::endl;
        }
        else {

            std::cout << "Vous avez manquer votre coup." << std::endl;

        }

        if (police.isAlive()) {
            int attaque = rand() % 2;
            if (attaque == 0) {
                mafieu.takeDamage(5);
                std::cout << "La police vous frappe avec une matraque ! (-5 PV)" << std::endl;
            }
            else {
                mafieu.takeDamage(2);
                std::cout << "La police vous percute avec un velo electrique ! (-2 PV)" << std::endl;
            }
        }
    }

    if (!mafieu.isAlive()) {
        std::cout << "\nVous avez perdu le combat contre la Police Municipale..." << std::endl;
        EndingCheck(2);
    }
    else {
        std::cout << "\nVous avez tuer un agent de la Police Municipale !" << std::endl;
        mafieu.addXP(5);
        mafieu.addInfluence(2);
        int choixpm;
        std::cout << "\nQue vouslez vous faire de son corps ?\n\n1. Le laisser sur le sol\n2. Le mettre dans le maquis\n3. Donner le corps aux cochons" << std::endl;
        std::cin >> choixpm;
        if (choixpm == 1) {
            system("cls");
            std::cout << "Vous avez laisser le corps de l'agent sur le sol ! (+ 5 INFLUENCE)\n" << std::endl;
            mafieu.addXP(10);
            mafieu.addInfluence(5);
        }
        else if (choixpm == 2) {
            system("cls");
            std::cout << "Vous avez mit le corps de l'agent dans le maquis ! (+ 10XP)\n" << std::endl;
            mafieu.addXP(10);
        }
        else if (choixpm == 3) {
			system("cls");
            std::cout << "Vous avez donner le corps aux cochons ! (+ 20XP) (+ 10 INFLUENCE)\n" << std::endl;
            mafieu.addXP(20);
            mafieu.addInfluence(10);
        }
    }
}


void GameManager::CombatGn() {
    Character gendarme("Gendarmerie", 50, 2);

    while (mafieu.isAlive() && gendarme.isAlive()) {
        std::cout << "\nQue voulez-vous faire ?\n1. Intimidation (-3 PV)\n2. Coup de fusil de chasse (-5 PV)\n3. Jeter une grenade sur le gendarme (-15 PV)" << std::endl;
        int choix;
        std::cin >> choix;

        if (choix == 1) {
            system("cls");
            mafieu.MAttack(&gendarme);
            std::cout << "Vous intimidez l'agent !" << std::endl;
            int attaque = rand() % 2;
            if (attaque == 0) {
                gendarme.takeDamage(3);
                std::cout << "Vous avez intimide l'agent (-3 PV)" << std::endl;
            }
            else {
                std::cout << "L'agent ignore votre intimidation." << std::endl;
            }
        }
        else if (choix == 2) {
            system("cls");
            int dmg = mafieu.getAttack() + 2;
            gendarme.takeDamage(7);
            std::cout << "Vous avez tirer deux cartouche de fusil sur le gendarme. (-7 PV)" << std::endl;
        }
        else if (choix == 3) {
            system("cls");
            int dmg = mafieu.LanceAttack();
            gendarme.takeDamage(15);
            std::cout << "Vous lancer une grenade sur le gendarme. (-15 PV)" << std::endl;
        }
        else {

            std::cout << "Vous avez manquer votre coup." << std::endl;

        }

        if (gendarme.isAlive()) {
            int attaque = rand() % 100;
            if (attaque <= 99) {
                mafieu.takeDamage(7);
                std::cout << "Le gendarme utilise son Glock 17 sur Rumanu ! (-7 PV)" << std::endl;
            }
            else {
                std::cout << "Le gendarme utilise ses menottes !\n\nVous etes arretez, cependant une obtion s'offre a vous. \nVous pouvez tentez de corrompre le gendarme." << std::endl;
                int choixgn;
                std::cout << "\nAcceptez vous cette tentative ?\n\n1. Oui\n2. Non (Prison)" << std::endl;
                std::cin >> choixgn;
                if (choixgn == 1) {
                    std::cout << "Vous tentez de corrompre le gendarme. (-3 INFLUENCE) (+20 XP)" << std::endl;
                    mafieu.addXP(20);
                    mafieu.subInfluence(3);
                    continue;
                }
                else if (choixgn == 2) {
                    std::cout << "Vous avez ete arreter !" << std::endl;
                    mafieu.takeDamage(mafieu.getHP());
                }
            
            }
        }

        std::cout << "\n| PV Rumanu : " << mafieu.getHP() << "\n| PV Gendarme : " << gendarme.getHP() << std::endl;
    }

    if (!mafieu.isAlive()) {
        std::cout << "\nVous avez ete arrete par la Gendarmerie..." << std::endl;
        EndingCheck(2);
    }
    else {
        std::cout << "\nVous avez tuer un agent de la Gendarmerie !" << std::endl;
        mafieu.addXP(5);
        mafieu.addInfluence(2);
        int choixgn;
        std::cout << "\nQue vouslez vous faire de son corps ?\n\n1. Le laisser sur le sol\n2. Le mettre dans le maquis\n3. Donner le corps aux cochons" << std::endl;
        std::cin >> choixgn;
        if (choixgn == 1) {
            system("cls");
            std::cout << "Vous avez laisser le corps de l'agent sur le sol ! (+ 5 INFLUENCE)\n" << std::endl;
            mafieu.addInfluence(5);
        }
        else if (choixgn == 2) {
            system("cls");
            std::cout << "Vous avez mit le corps de l'agent dans le maquis ! (+ 10XP)\n" << std::endl;
            mafieu.addXP(10);
        }
        else if (choixgn == 3) {
            system("cls");
            std::cout << "Vous avez donner le corps aux cochons ! (+ 20XP) (+ 10 INFLUENCE)\n" << std::endl;
            mafieu.addXP(20);
            mafieu.addInfluence(10);
        }
    }
}



void GameManager::Init()
{
    std::cout << R"(
                                                                                         
                              .                                                    
                        ....-**===:::...                                           
                     ..-#%%@@@@@@@@@@#**+..          -=-.                          
                  .-+#%@@@@@@@@@@@@@@@@@@@%*=-.     .+=*:   .                      
                  -@@@@@@@@@@@@@@@@@@@@@@@@@@@+   -+=+*#+: .=-.                    
                 :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:.+**+===+=-**-                    
                =+.:=+#@@@@@@@@@@@@@@@@@@@@@@@@@@+:+..+-=-:.-=                     
               .#:   .-.=*%@@@@@@@@@@@@@@@@@@@@@@#:-. -:.. .=                      
               =*.    .-:=-.+@@@@@@@@@@@@@@@@@@@@@*.- :... -.                      
              .+-==--:.     .:---=+#@@@@@@@@@@@@@@%:-::.  -:                       
               *@#*-=--=----:    --:-=*@@@@@@@@@@@#-:-.  .-                        
              .%@@@@@@*=+=::..   .:-+++=++%@@@@@@#+.::   -.                        
               #@@*%@@@@@@@@@*+::*#**#+===+*%@@@@*.:-.  :-                         
              =@@@+-++%@@@@@@@@@@*%#@=@.-===+*=%+*+=-:.:-                          
             =@@@@@###@@@@@@@@@@@@@+%#+#@#***%#+=#+--==-                           
            =@@@@@@@@@@@@@@@@@@@@*+%+#@@@@@@@@++=-==:.                             
           :@@@@@@@@@@@@@@@@@@@@@*@*%@@@@@@@@@%.=:.:-=-:.                          
           .=*#@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@#: :-:  .:-=.                         
            .-%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=.  :-::.  .=                         
            .+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*.   .:-=.::+                         
             .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=       -+#=:                        
              .:#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=.     -#.-:                        
               .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#. .:=- .-                         
               .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*-:=-:. .+                          
                .-+****++@@@@@@@@@@@@@@@@@@@@+.  .=.  .::                          
                         =%@@@@@@@@@@@@@@@@*.     -=:-=+.                          
                          .=%@@@@@@@@@@@@%:     :=-*=+-.                           
                            .*@@@@@@@@@@*.     ----++.                             
                             .#@@@@@@@#:       .==*=                               
                              :#%##*+:.         .::                                
                               .....                                               

)" << '\n';

    int bouteilledegaz = 0;
	int quest = 1;
    while (mafieu.isAlive()) {
        while (mafieu.isAlive()) {

            if (mafieu.isAlive()) {


				Quest(quest);

                std::cout << "\nX===========================X" << std::endl;
                std::cout << " | Sante de Rumanu: " << mafieu.getHP() << std::endl;
                std::cout << " | XP: " << mafieu.getXP() << " / 100" << std::endl;
                std::cout << " | Level: " << mafieu.getLevel() << std::endl;
                std::cout << " | Influence: " << mafieu.getInfluence() << std::endl;
				std::cout << " | Argent: " << mafieu.getMoney() << " euros" << std::endl;
                std::cout << "X===========================X\n" << std::endl;

                std::cout << "Que voulez-vous faire ?" << std::endl;
				std::cout << "0. Retourner au menu principal" << std::endl;
                std::cout << "1. Marcher au village (+ 2XP)" << std::endl;
                if (mafieu.getBdg() == 1)
                {
                    std::cout << "\033[33m2. Aller a la mairie (+3 XP)\033[0m" << std::endl;
                }
                else
                {
                    std::cout << "2. Aller a la mairie (+3 XP)" << std::endl;
                }
                if (mafieu.getCar() != 1)
                {
                    std::cout << "3. Voler une voiture (+2 XP) (+3 INFLUENCES)" << std::endl;
                }
                else
                {
                    std::cout << "3. Prendre la voiture (+2 XP)" << std::endl;
                }
                if (mafieu.getBdg() == 1) {
                    std::cout << "\033[31m4. Attaquer l'URSAFF (OBJECTIF)\033[0m" << std::endl;
                }
                int choix;
                std::cin >> choix;

                if (choix == 0) {
                    system("cls");
					std::cout << "Retour au menu principal..." << std::endl;
					Sleep(2000);
					system("cls");
                    Menu();
                }

                else if (choix == 1) {
                    mafieu.addXP(2);
                    mafieu.addLevel(0);
                    system("cls");
                    std::cout << "Vous vous promenez dans le village. (+2 XP)" << std::endl;

                    int rencontre = rand() % 100;

                    if (rencontre < 25) {
                        std::cout << "\nVous croisez le maire sur votre chemin !" << std::endl;
                        std::cout << "1. Bonjour\n2. Menacer\n3. Insulter" << std::endl;
                        int choixmaire;
                        std::cin >> choixmaire;

                        if (choixmaire == 1) {
                            std::cout << "\nVous obtenez un permis de construire. (+10 Influence)" << std::endl;
                            system("cls");
                            mafieu.addInfluence(10);
                        }
                        else if (choixmaire == 2 && mafieu.getInfluence() >= 50) {
                            if (bouteilledegaz == 0) {
                                system("cls");
                                std::cout << "\nLe maire vous donne une bouteille de gaz !" << std::endl;
                                mafieu.setBdg(1);
                            }
                            else {
                                system("cls");
                                std::cout << "\nVous possedez deja une bouteille de gaz." << std::endl;
                            }
                        }
                        else if (choixmaire == 3) {
                            std::cout << "X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X" << std::endl;
                            std::cout << "Rumanu : Ecoute moi bien O manghia merda ! Tu m'as pris pour qui ?\n" << std::endl;
                            std::cout << "Le maire : La police municipale est en route, vous devriez partir Rumanu !\n";
                            std::cout << "X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X" << std::endl;
                            CombatPm();
                        }
                        else {
                            std::cout << "\nLe maire vous ignore." << std::endl;
                        }
                    }
                    else if (rencontre < 50) {
                        std::cout << "\nLa Police Municipale vous interpelle !" << std::endl;
                        CombatPm();
                    }

                }
                else if (choix == 2) {
                    mafieu.addXP(2);
                    mafieu.addLevel(0);
                    system("cls");
                    if (mafieu.getCar() == 1)
                    {
                        std::cout << "Vous roulez en direction de la mairie. (+2 XP)" << std::endl;
                    }
                    else
                    {
                        std::cout << "Vous marchez en direction de la mairie. (+2 XP)" << std::endl;
                    }
                    std::cout << "Le maire : Bonjour Rumanu !" << std::endl;
                    if (mafieu.getBdg() == 1)
                    {
                        std::cout << "1. Bonjour\n2. Menacer\n3. Insulter\n\033[33m4. Eliminer le maire\033[0m" << std::endl;
                    }
                    else
                    {
                        std::cout << "1. Bonjour\n2. Menacer\n3. Insulter" << std::endl;
                    }

                    int choixmaire;
                    std::cin >> choixmaire;

                    if (choixmaire == 1) {
						system("cls");
                        std::cout << "\nVous obtenez un permis de construire. (+10 Influence)\n" << std::endl;
                        mafieu.addInfluence(10);
                    }
                    else if (choixmaire == 2 && mafieu.getInfluence() >= 50) {
                        if (bouteilledegaz == 0) {
                            system("cls");
                            std::cout << "\nLe maire vous donne une bouteille de gaz !" << std::endl;
                            mafieu.setBdg(1);
                        }
                        else {
                            system("cls");
                            std::cout << "\nVous possedez deja une bouteille de gaz." << std::endl;
                        }

                    }

                    else if (choixmaire == 4 && mafieu.getBdg() == 1) {
                        system("cls");
                        std::cout << "Vous venez de tuer le maire du village... sans aucune raison apparente." << std::endl;
                        int continuer;
                        std::cout << "\n1. Continuer" << std::endl;
                        std::cin >> continuer;
                        if (continuer == 1) {
                            system("cls");
                            EndingCheck(3);

                        }
                        Sleep(2000);

                        break;
                    }

                    else if (choixmaire == 3) {
                        std::cout << "X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X" << std::endl;
                        std::cout << "Rumanu : Ecoute moi bien O manghia merda ! Tu m'as pris pour qui ?\n" << std::endl;
                        std::cout << "Le maire : La police municipale est en route, vous devriez partir Rumanu !\n";
                        std::cout << "X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X" << std::endl;
                        CombatPm();
                    }
                    else {
                        std::cout << "\nLe maire vous ignore." << std::endl;
                    }

                }
                else if (choix == 3) {
                    system("cls");
                    if (mafieu.getCar() != 1)
                    {
                        std::cout << "Vous vevez de voler une voiture, la Police Municipale est en route. (+4 XP) (+3 Influence)" << std::endl;
                        CombatPm();
                        mafieu.addXP(4);
                        mafieu.addInfluence(3);
                        mafieu.addLevel(2);
                        mafieu.setCar(1);
                    }
                    else
                    {
                        mafieu.addXP(4);
                        mafieu.addLevel(2);
                        int rencontre = rand() % 2;

						std::cout << "1. Rouler sur la cote \n2. Se rendre a l'hopitale\n3. Se rendre sur un terrain vague (+4 XP)" << std::endl;

						int choix;
						std::cin >> choix;
						if (choix == 1) {
							system("cls");
							std::cout << "Vous roulez sur la cote avec votre voiture. (+4 XP)" << std::endl;
						}
                        else if (choix == 2) {
                            system("cls");
                            std::cout << "Vous vous rendez a l'hopitale avec votre voiture. (+4 XP)" << std::endl;
							std::cout << "\nVous pouvez etre soigne contre 100 euros.\n\n1. Oui\n2. Non" << std::endl;

                            int hostochoix;
                            std::cin >> hostochoix;
                            if (hostochoix == 1) {
                                if (mafieu.getMoney() < 100) {
                                    system("cls");
                                    std::cout << "Vous n'avez pas assez d'argent pour etre soigne." << std::endl;
                                    Sleep(2000);
                                    system("cls");
                                    continue;
								}
                                if (mafieu.getHP() < 25) {
                                    mafieu.setHP(100);
                                    system("cls");
                                    std::cout << "Vous avez ete soigne a l'hopitale. (+100 PV)" << std::endl;
                                    mafieu.subMoney(100);
                                }
                                else {
                                    system("cls");
                                    std::cout << "Vous etes deja en pleine sante." << std::endl;
                                    Sleep(2000);
                                    system("cls");
                                }

                            }
                            else {
                                system("cls");
                                std::cout << "Test hosto non" << std::endl;
                                Sleep(2000);
                                system("cls");

                            }
                        }
                        else if (choix == 3)
                        {
                            system("cls");
                            std::cout << "Terrain vage test" << std::endl;
                        }

                        


                        /*if (rencontre == 1) {
                            std::cout << "Vous roulez en ville avec votre voiture. (+4 XP)" << std::endl;
                            std::cout << "\nLa gendarmerie vous controle !" << std::endl;
                            CombatGn();
                        }
                        else
                        {
                            std::cout << "Vous roulez en ville avec votre voiture. (+4 XP)" << std::endl;
                        }*/
                    }
                }

                else if (choix == 4 && mafieu.getBdg() == 1) {
                    system("cls");
                    std::cout << "Vous avez placer la bouteille de gaz dans les locaux de l'URSAFF !";
                    int continuer;
                    std::cout << "\n1. Continuer" << std::endl;
                    std::cin >> continuer;
                    if (continuer == 1) {
                        system("cls");
                        EndingCheck(1);

                    }
                    Sleep(2000);

                }

                else if (choix == 5) {
					system("cls");
                    std::cout << "Vous avez choisi de quitter la partie. Au revoir !" << std::endl;
					Menu();
                }

                else if (choix == 20) {
                    system("cls");
                    int cheat = 0;
                    if (cheat == 0)
                    {
                        cheat = 1;
                        std::cout << "CHEAT ON\n" << std::endl;
                        std::cout << "Que voulez-vous faire ?" << std::endl;
                        std::cout << "1. Gain 50 XP" << std::endl;
                        std::cout << "2. Gain 50 influence" << std::endl;
                        std::cout << "3. Gain voiture\n" << std::endl;
                        std::cout << "20. CHEAT OFF" << std::endl;
                        int choixcheat;
                        std::cin >> choixcheat;
                        if (choixcheat == 1) {
                            mafieu.addXP(50);
                            system("cls");
                            std::cout << "Vous avez gagne 50 XP !" << std::endl;
                        }
                        else if (choixcheat == 2) {
                            mafieu.addInfluence(50);
                            system("cls");
                            std::cout << "Vous avez gagne 50 INFLUENCE !" << std::endl;
                        }
                        else if (choixcheat == 3) {
                            mafieu.setCar(1);
                            system("cls");
                            std::cout << "Vous avez une voiture !" << std::endl;
                        }

                    }
                }

                else {
                    system("cls");
                    std::cout << "Demande non conforme" << std::endl;

                }
            }
        }

        }
        return;
    }
	
