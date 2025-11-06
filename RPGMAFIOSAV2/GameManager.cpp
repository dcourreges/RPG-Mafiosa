#include "GameManager.h"
#include "PM.h"
#include "GN.h"
#include "mafieu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameManager::GameManager() : mafieu("Ange") {
    enemies.push_back(new Pm());
    enemies.push_back(new Gn());
    srand(static_cast<unsigned>(time(0)));
    mafieu.equipWeapon(nullptr);
}
 

GameManager::~GameManager() {
    for (auto e : enemies) delete e;
}

void GameManager::CombatPolice() {
    Character police("Police Municipale", 5, 2);

    std::cout << "\nCombat contre la Police Municipale engage !" << std::endl;

    while (mafieu.isAlive() && police.isAlive()) {
        std::cout << "\nQue voulez-vous faire ?\n1. Intimidation (-3 PV)\n2. Coup de fusil de chasse (-5 PV)\n3. Plasticage (-10)" << std::endl;
        int choix;
        std::cin >> choix;

        if (choix == 1) {
            mafieu.MAttack(&police);
            std::cout << "Vous attaquez la police !" << std::endl;
            police.takeDamage(3);
        }
        else if (choix == 2) {
            int dmg = mafieu.getAttack() + 2;
            police.takeDamage(5);
            std::cout << "Attaque spéciale inflige " << dmg << " dégâts !" << std::endl;
        }
        else if (choix == 3) {
            int dmg = mafieu.LanceAttack();
            police.takeDamage(10);
            std::cout << "Attaque au lance inflige " << dmg << " dégâts !" << std::endl;
        }

        if (police.isAlive()) {
            int attaque = rand() % 2;
            if (attaque == 0) {
                mafieu.takeDamage(2);
                std::cout << "La police vous frappe avec une matraque ! (-2 PV)" << std::endl;
            }
            else {
                mafieu.takeDamage(1);
                std::cout << "La police vous percute avec un vélo électrique ! (-1 PV)" << std::endl;
            }
        }

        std::cout << "\nPV Ange : " << mafieu.getHP() << " | PV Police : " << police.getHP() << std::endl;
    }

    if (!mafieu.isAlive()) {
        std::cout << "\n❌ Vous avez perdu le combat contre la Police Municipale..." << std::endl;
    }
    else {
        std::cout << "\n✅ Vous avez vaincu la Police Municipale !" << std::endl;
        mafieu.addXP(5);
        mafieu.addInfluence(5);
    }
}


void GameManager::Init()
{
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

    int bouteilledegaz = 0;
    while (mafieu.isAlive()) {
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
                    std::cout << "Vous marcher en direction de la mairie. (+2 XP)" << std::endl;






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

                if (mafieu.getCar() != 1) {
                    std::cout << "1. Marcher au village (+2 XP)" << std::endl;
                    std::cout << "2. Aller a la mairie (+2 XP)" << std::endl;
                    std::cout << "3. Voler une voiture (+4 XP, +3 Influence)" << std::endl;
                }
                else {
                    std::cout << "1. Marcher au village (+2 XP)" << std::endl;
                    std::cout << "2. Aller a la mairie (+2 XP)" << std::endl;
                    std::cout << "3. Rouler en ville (+4 XP)" << std::endl;
                }

                int choix;
                std::cin >> choix;

                if (choix == 1) {
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
                            mafieu.addInfluence(10);
                        }
                        else if (choixmaire == 2 && mafieu.getInfluence() >= 50) {
                            if (bouteilledegaz == 0) {
                                std::cout << "\nLe maire vous donne une bouteille de gaz !" << std::endl;
                                bouteilledegaz = 1;
                            }
                            else {
                                std::cout << "\nVous possedez deja une bouteille de gaz." << std::endl;
                            }
                        }
                        else {
                            std::cout << "\nLe maire vous ignore." << std::endl;
                        }
                    }
                    else if (rencontre < 50) {
                        std::cout << "\nLa Police Municipale vous interpelle !" << std::endl;
                        CombatPolice();
                    }

                }
                else if (choix == 2) {
                    mafieu.addXP(2);
                    mafieu.addLevel(0);
                    system("cls");
                    std::cout << "Vous allez à la mairie. (+2 XP)" << std::endl;
                    std::cout << "Le maire : Bonjour Ange !" << std::endl;
                    std::cout << "1. Bonjour\n2. Menacer\n3. Insulter" << std::endl;

                    int choixmaire;
                    std::cin >> choixmaire;

                    if (choixmaire == 1) {
                        std::cout << "\nVous obtenez un permis de construire. (+10 Influence)" << std::endl;
                        mafieu.addInfluence(10);
                    }
                    else if (choixmaire == 2 && mafieu.getInfluence() >= 50) {
                        if (bouteilledegaz == 0) {
                            std::cout << "\nLe maire vous donne une bouteille de gaz !" << std::endl;
                            bouteilledegaz = 1;
                        }
                        else {
                            std::cout << "\nVous possédez deja une bouteille de gaz." << std::endl;
                        }
                    }
                    else {
                        std::cout << "\nLe maire vous ignore." << std::endl;
                    }

                }
                else if (choix == 3) {
                    if (mafieu.getCar() != 1) {
                        mafieu.addXP(4);
                        mafieu.addInfluence(3);
                        mafieu.addLevel(2);
                        mafieu.setCar(1);
                        system("cls");
                        std::cout << "Vous avez vole une voiture ! (+4 XP, +3 Influence)" << std::endl;
                    }
                    else {
                        mafieu.addXP(4);
                        mafieu.addLevel(2);
                        system("cls");
                        std::cout << "Vous roulez en ville avec votre voiture. (+4 XP)" << std::endl;
                    }

                }
                else {
                    system("cls");
                    std::cout << "Choix invalide." << std::endl;
                }

                std::cout << "\nX===========================X" << std::endl;
                std::cout << " | Sante de Ange: " << mafieu.getHP() << std::endl;
                std::cout << " | XP: " << mafieu.getXP() << std::endl;
                std::cout << " | Level: " << mafieu.getLevel() << std::endl;
                std::cout << " | Influence: " << mafieu.getInfluence() << std::endl;
                std::cout << "X===========================X\n" << std::endl;
            }

            std::cout << "C'est terminé ! Vous avez ete placer en garde a vu. Ange a ete condamnee a deux ans de prison pour agression..." << std::endl;
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


    }
}
