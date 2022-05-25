/**
 * @file        bateau.cpp
 * @brief       Class bateau a disposer sur nos plateaux
 * @details     on veut sa taille, ses coordonnees, savoir s il est en vie ou non, savoir s il est touche ou non
 * @author      Fave
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include "bateau.hpp"

/*******************************
 *      Global definitions     *
 *******************************/


/*******************************
 *       Public methods        *
 *******************************/


/*******************************
 *       Private methods       *
 *******************************/


/**
 * @enum        nom de l'enum
 * @brief       Description de l'enum
 */

/**
 * @struct      nom de la structure
 * @brief       Description de la structure
 */

/**
 * @class       Bateau_t
 * @brief       classe bateau avec ses caracteristiques
 * @details     details
 * @version     0.1
 * @date        2022
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application (attention au placement du bateau sur le plateau)
 */

/**
 * @brief
 * @details
 * @param[in,out]   
 * @return 
 */

//code pour la class bateau 
//constructeur 
Bateau_t::Bateau_t(int nom_bateau){
switch (nom_bateau)
{
case 0: //porte avion
    longueur_bateau = 5;
    vie = true;
    break;
case 1: //croiseur
    longueur_bateau = 4;
    vie = true;
    break;
case 2: //contre_torpilleur_1
    longueur_bateau = 3;
    vie = true;
    for (int i = 0; i < 5; i++)
    {
        tab_touche[i] = false;
    }
    break;
case 3: //contre_torpilleur_2
    longueur_bateau = 3;
    vie = true;
    break;
case 4: //torpilleur
    longueur_bateau = 2;
    vie = true;
    break;
default:
    break;
}

}