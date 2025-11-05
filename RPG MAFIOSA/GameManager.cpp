#include "GameManager.h"
#include "PM.h"
#include "GN.h"
#include "mafieu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Glock17.h"

GameManager::GameManager() : mafieu("Ange") {
    enemies.push_back(new Pm());
    enemies.push_back(new Gn());
    srand(static_cast<unsigned>(time(0)));
    mafieu.equipWeapon(nullptr);
}


void GameManager::pve(Enemy* ennemi) {
    std::cout << "\nCombat contre " << ennemi->getName() << " !" << std::endl;

    while (mafieu.isAlive() && ennemi->isAlive()) {
        std::cout << "\nTour du Mafieu :\n";
        mafieu.attack(ennemi);

        if (!ennemi->isAlive()) {
            std::cout << ennemi->getName() << " est vaincu ! 🏆\n";
            mafieu.addXP(5);
            mafieu.addInfluence(2);
            return;
        }

        std::cout << "\nTour de " << ennemi->getName() << " :\n";
        ennemi->attack(&mafieu);

        std::cout << "\nPV Mafieu : " << mafieu.getHP()
            << " | PV Ennemi : " << ennemi->getHP() << std::endl;
    }

    if (!mafieu.isAlive()) {
        std::cout << "Vous avez été vaincu par " << ennemi->getName() << " ! 😵\n";
    }
}

GameManager::~GameManager() {
    for (auto e : enemies) delete e;
}

void GameManager::Init() {
    std::cout << "Bienvenue dans la Mafia Corse !" << std::endl;
    std::cout << "Vous incarnez Ange, un mafieu Corse de la Brise de Mer, son but est simple faire saute les bureau de l'URSAFF.\nVotre quete est de trouve une bouteille de gaz, mais attention ca ne serra pas si simple !" << std::endl;
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


    while (mafieu.isAlive()) {


        if (mafieu.getCar() != 1) {

            std::cout << "Que voulez-vous faire ?" << std::endl;
            std::cout << "1. Marcher au village (+ 2XP)" << std::endl;
            std::cout << "2. Aller a la mairie (+3 XP)" << std::endl;
            std::cout << "3. Voler une voiture (+2 XP) (+3 INFLUENCES)" << std::endl;

            int choix;
            std::cin >> choix;

            if (choix == 1) {
                mafieu.addXP(2);
                mafieu.addLevel(2);
                system("cls");
                std::cout << "Vous vous promenez dans le village. (+2 XP)" << std::endl;
            }
            else if (choix == 2) {
                system("cls");







            }
            else if (choix == 3) {
                system("cls");
                std::cout << "Vous vevez de voler une voiture la Police Municipale est en route. (+4 XP) (+3 Influence)" << std::endl;
                mafieu.addXP(4);
                mafieu.addInfluence(3);
                mafieu.addLevel(2);
                mafieu.setCar(1);
            }

            else if (choix == 20) {
                system("cls");
                int cheat = 0;
                if (cheat == 0)
                {
                    std::cout << "CHEAT ON\n" << std::endl;
                    std::cout << "Que voulez-vous faire ?" << std::endl;
                    std::cout << "1. Gain d'XP" << std::endl;
                    std::cout << "2. Test" << std::endl;
                    std::cout << "3. Test 3\n" << std::endl;
                    std::cout << "20. CHEAT OFF" << std::endl;

                }
            }

            else {
                system("cls");
                std::cout << "Demande non conforme" << std::endl;

            }
        }
        
        else
        {
            std::cout << "\nQue voulez-vous faire ?" << std::endl;
            std::cout << "1. Marcher au village (+ 2XP)" << std::endl;
            std::cout << "2. Aller a la mairie (+ 3XP)" << std::endl;
            std::cout << "3. Rouler en ville (+ 4XP) " << std::endl;

            int choix;
            std::cin >> choix;

            if (choix == 1) {
                mafieu.addXP(2);
                mafieu.addLevel(2);
                system("cls");
                std::cout << "Vous vous promenez dans le village. (+2 XP)" << std::endl;
            }
            else if (choix == 2) {
                system("cls");

            }
            else if (choix == 3) {
                system("cls");
                std::cout << "Vous roulez en ville avec votre voiture. (+4 XP)" << std::endl;
                mafieu.addXP(4);
                mafieu.addLevel(2);


            }

            else if (choix == 20) {
                system("cls");
                std::cout << "CHEAT ON\n" << std::endl;
                std::cout << "Que voulez-vous faire ?" << std::endl;
                std::cout << "1. Gain d'XP" << std::endl;
                std::cout << "2. Test" << std::endl;
                std::cout << "3. Test 3\n" << std::endl;
                std::cout << "20. CHEAT OFF" << std::endl;

            }

            else {
                system("cls");
                std::cout << "\n" << std::endl;

            }

        }

        std::cout << " " << std::endl;
        std::cout << " | Sante de Ange: " << mafieu.getHP() << std::endl;
        std::cout << " | XP: " << mafieu.getXP()<< std::endl;
        std::cout << " | Level: " << mafieu.getLevel() << std::endl;
        std::cout << " | Influence: " << mafieu.getInfluence()<< std::endl;
        std::cout << " " << std::endl;
    }

    if (!mafieu.isAlive())
        std::cout << "C'est terminer ! Vous avez ete condamnee a la perpetuite. Vous resterez en prison pendant 30 ans..." << std::endl;
        std::cout << R"(
                                                                                            
                                                                                                    
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
                                                                                                    

)" << '\n';
}

