/**
 * @file        case.cpp
 * @brief       Class case pour la grille et l'état de nos bateaux / cases
 * @author      Vasseur, Fave, Auffray, Gauthier
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include <cstdlib>
#include <iostream>
#include "case.h"

/*******************************
 *       Public methods        *
 *******************************/
/**
 * @brief Constructeur utilisé pour une case
 * @details Set les coordonnées à 0 et l'état à eau
 */
Case_t::Case_t() {
    this->x = 0;
    this->y = 0;
    this->state = 0;
}

/**
 * @brief Constructeur utilisé pour une case avec coordonnées
 * @details Set les coordonnées à x et y et l'état à eau
 * @param[in] int x,y
 */
Case_t::Case_t(int x, int y) {
    this->x = x;
    this->y = y;
    this->state = 0;
}

/**
 * @brief Constructeur utilisé pour une case avec coordonnées et état
 * @details Set les coordonnées à x et y et l'état à state
 * @param[in] int x,y,state
 */
Case_t::Case_t(int x, int y, int state) {
    this->x = x;
    this->y = y;
    this->state = state;
}

/**
 * @brief Méthode de Case_t pour set les attributs avec une nouvelle case
 * @details Cette méthode permet de setter les attributs d'une case
 * @param[in] Case_t
 */
void Case_t::setCase(Case_t& new_case) {
    this->x = new_case.getX();
    this->y = new_case.getY();
    this->state = new_case.getState();
}