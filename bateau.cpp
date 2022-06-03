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
#include "bateau.h"
#include "plateau.h"


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
Bateau_t::Bateau_t() {
    this->vie = true;
    this->longueur_bateau = 0;
    
}
//constructeur par defaut pour un bateau auquel on donne le nom
Bateau_t::Bateau_t(int _nom_bateau, Plateau_t plateau) {

    // attributs set de base
    this->vie = true;   //par defaut en vie

    switch (_nom_bateau) // 0,1,2,3,4
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

    input_coordinate(plateau);
    input_direction();
}

void Bateau_t::input_coordinate(Plateau_t plateau) {
    int coordX;
    int coordY;
    // Message lorsque le joueur souhaite mettre les coordonnees de son porte avion
    std::cout << "Saisir l'extremite X du bateau (entre A et J) : " << std::endl; 
    char choixUserX;
    std::cin >> choixUserX;

    //On vérifie que la case ciblée est bien sur la grille
    if(!(choixUserX >= 'A' && choixUserX <= 'J')) {
        do {
            std::cout << "Incorrect, saisir une lettre majuscule entre A et J" << std::endl;
            std::cin >> choixUserX;
        } while(!(choixUserX >= 'A' && choixUserX <= 'J'));
    }
    else {
        coordX = (choixUserX - 'A') + 1;
    }
    
    std::cout << "Saisir l'extremite Y du bateau (entre 1 et 10) : " << std::endl; 
    int choixUserY;
    std::cin >> choixUserY;
    //On vérifie que la case ciblée est bien sur la grille
    if(!(choixUserY >= 1 && choixUserY <= 10)) {
        do {
            std::cout << "Incorrect, saisir un nombre entre 1 et 10" << std::endl;
            std::cin >> choixUserY;
        } while(!(choixUserY >= 1 && choixUserY <= 10));   
    }
    //On vérifie que le point d'origine est sur une case vide
    else if (!(plateau.getCase(coordX, choixUserY).getState() == 0)) {
        do {
            std::cout << "Incorrect, la case est deja prise par un autre bateau" << std::endl;
            std::cout << "X : " << plateau.getCase(coordX, choixUserY).getX();
            std::cout << "Y : " << plateau.getCase(coordX, choixUserY).getY();
            std::cout << "Etat : " << plateau.getCase(coordX, choixUserY).getState();
            std::cin >> choixUserY;
        } while((plateau.getCase(coordX, choixUserY).getState() == 0));
    }
    //On vérifie qu'il n'y a pas d'autres bateaux à proximité du pt d'origine
    else if ((plateau.getCase(coordX+1, choixUserY).getState() != 0) ||
             (plateau.getCase(coordX+1, choixUserY+1).getState() != 0) ||
             (plateau.getCase(coordX, choixUserY+1).getState() != 0) ||
             (plateau.getCase(coordX-1, choixUserY+1).getState() != 0) ||
             (plateau.getCase(coordX-1, choixUserY).getState() != 0) ||
             (plateau.getCase(coordX-1, choixUserY-1).getState() != 0) ||
             (plateau.getCase(coordX, choixUserY-1).getState() != 0) ||
             (plateau.getCase(coordX+1, choixUserY-1).getState() != 0)) {
        do {
            std::cout << "Incorrect, bateau a moins d'une case de celle ciblee, ressaisissez Y :" << std::endl;
            std::cout << "X : " << coordX << ", Y : " << choixUserY << std::endl; 
            std::cin >> choixUserY;
        } while((plateau.getCase(coordX+1, choixUserY).getState() != 0) ||
             (plateau.getCase(coordX+1, choixUserY+1).getState() != 0) ||
             (plateau.getCase(coordX, choixUserY+1).getState() != 0) ||
             (plateau.getCase(coordX-1, choixUserY+1).getState() != 0) ||
             (plateau.getCase(coordX-1, choixUserY).getState() != 0) ||
             (plateau.getCase(coordX-1, choixUserY-1).getState() != 0) ||
             (plateau.getCase(coordX, choixUserY-1).getState() != 0) ||
             (plateau.getCase(coordX+1, choixUserY-1).getState() != 0));
    }
    //Si tout est ok on prend la coordonnée
    else {
        coordY = choixUserY;
    }
    coordY = choixUserY;

    this->tab_coord[0].setX(coordX);
    this->tab_coord[0].setY(coordY);
    this->tab_coord[0].setState(etat_t::bateau);
    std::cout << "cccX : " << coordX;
    std::cout << "cccY : " << coordY;
    std::cout << "cccX : " << plateau.getCase(coordX, coordY).getX();
    std::cout << " cccY : " << plateau.getCase(coordX, coordY).getY() << std::endl;
    
}


void Bateau_t::input_direction(void) {
    //Message utilisateur
    std::cout << "Saisir la direction de votre bateau (d, g, b, h) :" << std::endl;

    std::string direction = "";
    std::cin >> direction;
    if(direction == "g") //gauche
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX() - 1);
            this->tab_coord[i].setY(this->tab_coord[i-1].getY());
        }
    }
    else if(direction == "b") //bas 
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX());
            this->tab_coord[i].setY(this->tab_coord[i-1].getY() + 1);
        }
    }
    else if(direction == "d") //droite
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX() + 1);
            this->tab_coord[i].setY(this->tab_coord[i-1].getY());
        }
    }
    else if(direction == "h") //haut
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX());
            this->tab_coord[i].setY(this->tab_coord[i-1].getY() - 1);
        }
    }
}