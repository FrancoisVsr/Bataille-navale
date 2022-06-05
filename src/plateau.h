/**
 * @author      Gauthier, Vasseur, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

#ifndef PLATEAU_H
#define PLATEAU_H

/*******************************
 *          Includes           *
 *******************************/
#include "bateau.h"
#include "case.h"
#include <vector>

/*******************************
 *      Global definitions     *
 *******************************/
void addLine(int tailleTab);
char stateDisplay(int state);

/*******************************
 *       Public methods        *
 *******************************/
/**
 * @class       Plateau_t
 * @brief       classe plateau avec ses caracteristiques
 * @version     0.1
 * @date        2022
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application
 */
class Plateau_t {
    protected:
        int taille;
        Case_t grid[10][10];
        Bateau_t flotte[5];

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
        Bateau_t addBateau(int);
        Bateau_t addBateauIA(int);
        bool checkBateau(int, int, char, int);
};

#endif /*PLATEAU_H*/