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
 * @details     fichier cpp
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

/*code pour la class bateau*/

//constructeur par defaut pour un bateau auquel on donne le nom
Bateau_t::Bateau_t(int nom_bateau) {

    // attributs set de base
    this->vie = true;   //par defaut en vie

    switch (nom_bateau) // 0,1,2,3,4
    {
        case porte_avion: 
            this->longueur_bateau = 5;
            this->nom_bateau = "Porte avion";
        break;
        case croiseur:
            this->longueur_bateau = 4;
            this->nom_bateau = "croiseur";
        break;
        case contre_torpilleur_1: 
            this->longueur_bateau = 3;
            this->nom_bateau = "1er Contre torpilleur";
        break;
        case contre_torpilleur_2: 
            this->longueur_bateau = 3;
            this->nom_bateau = "2eme Contre torpilleur";
        break;
        case torpilleur: 
            this->longueur_bateau = 2;
            this->nom_bateau = "Torpilleur";
        break;
        default:
        break;
    }

    input_coordinate();
    input_direction();
/*
    if(direction = "ESC[64") //gauche
    {

    }    
    else if(direction = "ESC[65") //bas 
    {

    }
    else if(direction = "ESC[66") //droite
    {

    }
    else if(direction = "ESC[67") //droite
    {

    }
    */
}

void Bateau_t::input_coordinate(void) {
    int coordX;
    int coordY;
    // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
    std::cout << "Saisir l'extremité X du bateau (entre A et J) : " << std::endl; 
    char choixUserX;
    std::cin >> choixUserX;
    if(!(choixUserX >= 'A' && choixUserX <= 'J')) {
        do {
            std::cout << "Incorrect, saisir une lettre majuscule entre A et J" << std::endl;
            std::cin >> choixUserX;
        } while(!(choixUserX >= 'A' && choixUserX <= 'J'));
    }
    else {
        coordX = (choixUserX - 'A') + 1;
    }
    
    std::cout << "Saisir l'extremité X du bateau (entre A et J) : " << std::endl; 
    int choixUserY;
    std::cin >> choixUserY;
    if(!(choixUserY >= 1 && choixUserY <= 10)) {
        do {
            std::cout << "Incorrect, saisir un nombre entre 1 et 10" << std::endl;
            std::cin >> choixUserY;
        } while(!(choixUserY >= 1 && choixUserY <= 10));
    }
    else {
        coordY = choixUserY;
    }
    this->tab_coord[0].setX(coordX);
    this->tab_coord[0].setY(coordY);
    this->tab_coord[0].setEtat(etat::bateau);
}


void Bateau_t::input_direction(void) {

}