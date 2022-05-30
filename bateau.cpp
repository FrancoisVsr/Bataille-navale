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
Bateau_t::Bateau_t(int nom_bateau){

    // attributs set de base
    vie = true;                               //par defaut en vie
    for (int i = 0; i < longueur_bateau; i++) //par defaut pas touche
    {
        tab_touche[i] = false;
    }  

    switch (nom_bateau) // 0,1,2,3,4
    {
    case 0: //porte avion
        longueur_bateau = 5;
    break;
    case 1: //croiseur
        longueur_bateau = 4;
    break;
    case 2: //contre_torpilleur_1
        longueur_bateau = 3;
    break;
    case 3: //contre_torpilleur_2
        longueur_bateau = 3;
    break;
    case 4: //torpilleur
        longueur_bateau = 2;
    break;
    default:
    break;
    }
         
}

//constructeur pour un bateau donnee, avec ses coordonnees
Bateau_t::Bateau_t(int nom_bateau, coordinate tab_coord){
    
    //variable global au constructeur
    char* placementBateau_X;
    char* placementBateau_Y;
    string string_TO_int; // variable intermediaire

    // attributs set de base
    vie = true;                               //par defaut en vie
    for (int i = 0; i < longueur_bateau; i++) //par defaut pas touche
    {
        tab_touche[i] = false;
    }           

    switch(nom_bateau) // 0,1,2,3,4
    {
        case 0: //porte avion
            longueur_bateau = 5;
            // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
            std::cout << "Entrez vos coordonnées pour le porte-avion : " << std::endl;
            // entree des coordonnees
            input_coordinate(tab_coord);
        break;
        case 1: //croiseur
            longueur_bateau = 4;
            // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
            std::cout << "Entrez vos coordonnées pour le croisuer : " << std::endl;
            // entree des coordonnees
            input_coordinate(tab_coord);
        break;
        case 2: //contre_torpilleur_1
            longueur_bateau = 3;
            // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
            std::cout << "Entrez vos coordonnées pour le 1er contre torpilleur : " << std::endl;
            // entree des coordonnees
            input_coordinate(tab_coord);
        break;
        case 3: //contre_torpilleur_2
            longueur_bateau = 3;
            // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
            std::cout << "Entrez vos coordonnées pour le 2ème contre torpilleur : " << std::endl;
            // entree des coordonnees
            input_coordinate(tab_coord);
        break;
        case 4: //torpilleur
            longueur_bateau = 2;
            // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
            std::cout << "Entrez vos coordonnées pour le torpilleur : " << std::endl;
            // entree des coordonnees
            input_coordinate(tab_coord);
        break;
        default:
        break;
}

}


void Bateau_t::input_coordinate(coordinate coordonnee){
    //variable global au constructeur
    char* placementBateau_X;
    char* placementBateau_Y;
    string string_TO_int; // variable intermediaire

    std::cin >> placementBateau_X;
    coordonnee.coordX.assign(placementBateau_X);

    // Entree de la coordonnees Y (1 ... 10)
    std::cin >> placementBateau_Y; 
    string_TO_int.assign(placementBateau_Y);
    coordonnee.coordY = stoi(string_TO_int); //stoi : fonction String TO Int
}

