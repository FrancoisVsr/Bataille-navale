/**
 * @file        game.cpp
 * @brief       Fichier contenant les fonctions qui gèrent le déroulement d'une partie
 * @author      Auffray
 * @date        25/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include <iostream>
#include "game.h"

/**
 * @fn void start()
 * @brief affiche le nom du jeu au lancement
 * */
void start() {
    std::cout << "*****************************" << std::endl;
    std::cout << "****** Bataille Navale ******" << std::endl;
    std::cout << "*****************************" << std::endl << std::endl;
}

/**
 * @fn void start()
 * @brief affiche le menu du jeu pour le choix du mode
 * 
 * @return choix de l'utilisateur, entier 1 ou 2
 * */
int menu() {
    int choix = 0;
    std::cout << "MENU :" << std::endl;
    do {
        std::cout << std::endl << "1. Un joueur (jouer contre une IA)" << std::endl;
        std::cout << "2. Deux joueurs" << std::endl << std::endl;
        std::cout << "Choisissez le mode (1 ou 2): ";
        std::cin >> choix;
    }
    while(!(choix == 1 || choix == 2));
    if(choix == 1) {
        std::cout << std::endl << "Mode un joueur !" << std::endl; 
    }
    else {
        std::cout << std::endl << "Mode deux joueur !" << std::endl;
    }
    return choix;
}