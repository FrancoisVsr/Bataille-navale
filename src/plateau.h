/**
 * @file
 * @brief    
 * @details
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        XX/XX/XXXX
 * @version     v0.01
 */

#ifndef PLATEAU_H
#define PLATEAU_H

/*******************************
 *          Includes           *
 *******************************/
#include "bateau.h"
#include "case.h"
#include <vector>

void addLine(int tailleTab);
char stateDisplay(int state);

/*******************************
 *      Classe plateau permettant d'afficher un tableau de jeu dynamique   *
 *******************************/
class Plateau_t {

    protected:
        int taille;
        Case_t grid[10][10];
        Bateau_t flotte[5];

    /*******************************
     *       Public methods        *
     *******************************/
    public:
        //Constructeur
        Plateau_t();

        //Accesseurs
        int getTaille() const { return this->taille;}
        Case_t getCase(int x, int y) const { return this->grid[x][y];}

        //Setteurs
        bool setCase(int, int, int);
        bool setCase(Case_t);

        //Méthodes
        void display();
        void displayShip();
        bool addBateau(Bateau_t);
};


#endif








/**
 * @enum        nom de l'enum
 * @brief       Description de l'enum
 */

/**
 * @struct      nom de la structure
 * @brief       Description de la structure
 */

/**
 * @class       nom de la classe
 * @brief       Description de la classe
 * @details     details
 * @version     0.1
 * @date        2020
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application (c'est votre faute)
 */

/**
 * @brief
 * @details
 * @param[in,out]   
 * @return 
 */
