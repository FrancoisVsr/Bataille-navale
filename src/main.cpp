/**
 * @file        main.cpp
 * @brief       Fonction principale de notre jeu de bataille navale
 * @author      Auffray, Vasseur, Fave, Gauthier
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include <iostream>
#include "game.h"
#include "interface.h"

/**
 * @fn int main()
 * @brief Fonction pour jouer utilisant game.cpp
 * @return int 0
 */
void consolePlay() {
    char choice = 'n';
    do {
        start();
        int choix_mode = menu();
        if(choix_mode == 2) {
            if(GameLoop_2_player()) {
                std::cout << "Gagnant : Player1" << std::endl;
            }
            else{
                std::cout << "Gagnant : Player2" << std::endl;
            }
        }
        else {
            if(GameLoop_1_player()) {
                std::cout << "Gagnant : playeur" << std::endl;
            }
            else{
                std::cout << "Gagant : IA" << std::endl;
            }
        }
        do {
            std::cout << "Do you want to replay ? [y/n] : ";
            std::cin >> choice;
        }while(choice != 'n' && choice != 'y');
    }while(choice == 'y');    
}

int main(int argc, char **argv){
    if(argc < 2){
        mainInterface();
    }
    else if(strcmp(argv[1], "-cl") == 0){
        consolePlay(); 
    }
    else{
        std::cout << "Wrong argument !" << std::endl;
        std::cout << "-cl for console line, -ihm for graphic interface" << std::endl;
        std::cout << argv[1] << std::endl;
    }
    return 0;
}


