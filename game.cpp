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
#include <string>
#include <cstdlib>
#include <limits>
#include <sstream>
#include "game.h"
#include "joueur.hpp"

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
 * @fn int menu()
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
        std::cout << "Choisissez le mode [1/2] : ";
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

bool GameLoop_2_player() {
    char debug_fin = 'n';
    std::string name_joueur1 = "";
    std::string name_joueur2 = "";
    std::cout << "Entrer le nom du premier joueur : ";
    std::cin >> name_joueur1;
    Joueur_t joueur1(name_joueur1);
    std::cout << "Entrer le nom du deuxieme joueur : ";
    std::cin >> name_joueur2;
    Joueur_t joueur2(name_joueur2);
    do {
        std::cout << "A " << joueur1.get_name() << " de jouer, appuyer sur entrer pour afficher les plateaux" << std::endl;
        //std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        joueur1.display();
        int x = 0;
        int y = 0;
        joueur1.saisie_tir(&x, &y);
        joueur1.tir(&joueur2, x, y);
        joueur2.update_vie();
        std::cout << "Fin du tour de " << joueur1.get_name() << ", appuyer sur entrer pour cacher les plateaux" << std::endl;
        std::cin.get();
        clean_display();
        if(joueur2.get_vie()) {
            std::cout << "A " << joueur2.get_name() << " de jouer, appuyer sur entrer pour afficher les plateaux" << std::endl;
            std::cin.get();
            joueur2.display();
            int x2 = 0;
            int y2 = 0;
            joueur2.saisie_tir(&x2, &y2);
            joueur2.tir(&joueur1, x2, y2);
            joueur1.update_vie();
            std::cout << "Fin du tour de " << joueur2.get_name() << ", appuyer sur entrer pour cacher les plateaux" << std::endl;
            std::cin.get();
            clean_display();
        }
        std::cout << "[DEBUG] fin ? [y/n] : ";
        std::cin >> debug_fin;
    }while(joueur1.get_vie() && joueur2.get_vie() && debug_fin == 'n');
    if(joueur1.get_vie()) {
        return true;
    }
    else {
        return false;
    }
}

bool GameLoop_1_player() {
    std::string name_joueur = "";
    std::cout << "Entrer le nom du joueur : ";
    std::cin >> name_joueur;
    Joueur_t joueur(name_joueur);
    Joueur_t joueur();
    return true;
}

void clean_display() {
    #ifdef __linux__ 
        system("clear");
    #elif _WIN32
        system("cls");
    #else
        std::cout << "OS not supported ! Please use Linux or Windows"
    #endif
}