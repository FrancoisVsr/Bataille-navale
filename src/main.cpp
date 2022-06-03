#include <iostream>
#include "game.h"

int main() {
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
    return 0;
}