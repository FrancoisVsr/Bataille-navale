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
 * @return choix de l'utilisateur, entier 1 pour un joueur ou 2 pour deux joueurs
 * */
int menu() {
    int choix = 0;
    char saisie = ' ';
    std::cout << "MENU :" << std::endl;
    do {
        std::cout << std::endl << "1. Un joueur (jouer contre une IA)" << std::endl;
        std::cout << "2. Deux joueurs" << std::endl << std::endl;
        std::cout << "Choisissez le mode (1 ou 2): ";
        std::cin >> saisie;
    }
    while(saisie != '1' && saisie != '2');
    if(saisie == '1') {
        std::cout << std::endl << "Mode un joueur !" << std::endl; 
        choix = 1;
    }
    else {
        std::cout << std::endl << "Mode deux joueur !" << std::endl;
        choix = 2;
    }
    return choix;
}