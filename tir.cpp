/**
 * @file        joueur.cpp
 * @brief       Fichier contenant la classe tir et ses fonctions
 * @author      Auffray
 * @date        25/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include <iostream>
#include "tir.h"

/**
 * @fn tir_t::tir_t()
 * @brief constructeur de tir, saisi et cré le tir
 */
tir_t::tir_t() {
    std::cout << "Saisir les coordonnées de la cible (par exemple A1 ou E8) : ";
    std::cin >> this->name;

}