#include <iostream>
#include "game.h"

int main() {
    char choice = 'n';
    do {
        start();
        int choix_mode = menu();
        if(choix_mode == 2) {
            GameLoop_2_player();
        }
        else {
            GameLoop_1_player();
        }
        do {
            std::cout << "Do you want to replay ? [y/n] : ";
            std::cin >> choice;
        }while(choice == 'n' || choice == 'y');
    }while(choice == 'y');    
    return 0;
}