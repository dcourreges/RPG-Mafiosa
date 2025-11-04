#include "GameManager.h"
#include "PM.h"
#include "GN.h"
#include <iostream>

GameManager::GameManager() : mafieu("Ange") {
    enemies.push_back(new Pm());
    enemies.push_back(new Gn());
}

GameManager::~GameManager() {
    for (auto e : enemies) delete e;
}

void GameManager::run() {
    std::cout << "Bienvenue dans la Mafia Corse !" << std::endl;
    std::cout << "Vous incarnez Ange un mafieu Corse, son but est simple faire saute les bureau de l'URSAFF.\nVotre quete est de trouve une bouteille de gaz, mais attention ca ne serra pas si simple !" << std::endl;
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

	int getCar = 0;

    while (mafieu.isAlive()) {


        if (getCar != 1) {

            std::cout << "\nQue voulez-vous faire ?" << std::endl;
            std::cout << "1. Marcher au village (+2XP)" << std::endl;
            std::cout << "2. Aller a la mairie (+3XP)" << std::endl;
            std::cout << "3. Voler une voiture (+2XP) (+3INFLUENCES)" << std::endl;

            int choix;
            std::cin >> choix;

            if (choix == 1) {
                mafieu.addXP(2);
                system("cls");
                std::cout << "Vous vous promenez dans le village. (+2XP)" << std::endl;
            }
            else if (choix == 2) {
                system("cls");

            }
            else if (choix == 3) {
                system("cls");
                std::cout << "Vous vevez de voler une voiture la Police Municipale est en route. (+2XP) (+3 Influence)" << std::endl;
                mafieu.addXP(2);
                mafieu.addInfluence(3);
                getCar = 1;
            }

            else if (choix == 20) {
                system("cls");
                std::cout << "CHEAT ACTIVER" << std::endl;
            }

            else {
                break;
            }
        }
        
        else
        {
            std::cout << "\nQue voulez-vous faire ?" << std::endl;
            std::cout << "1. Marcher au village (+2XP)" << std::endl;
            std::cout << "2. Aller a la mairie (+3XP)" << std::endl;
            std::cout << "3. Rouler en ville (+4XP) " << std::endl;

            int choix;
            std::cin >> choix;

            if (choix == 1) {
                mafieu.addXP(2);
                system("cls");
                std::cout << "Vous vous promenez dans le village. (+2XP)" << std::endl;
            }
            else if (choix == 2) {
                system("cls");

            }
            else if (choix == 3) {
                system("cls");
                std::cout << "Vous roulez en ville avec votre voiture. (+4XP)" << std::endl;
                mafieu.addXP(4);


            }

            else if (choix == 20) {
                system("cls");
                std::cout << "CHEAT ACTIVER" << std::endl;
            }

            else {
                break;
            }
        }

        std::cout << " " << std::endl;
        std::cout << " | Sante de Ange: " << mafieu.getHP() << std::endl;
        std::cout << " | XP: " << mafieu.getXP()<< std::endl;
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

