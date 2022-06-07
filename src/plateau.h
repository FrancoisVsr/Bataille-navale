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
#include <string>

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

public:
    //Constructeur
    Plateau_t();

    //Accesseurs
    int getTaille() const { return this->taille;}
    Case_t getCase(int x, int y) const {return this->grid[x][y];}

    //Setteurs
    bool setCase(int, int, int);
    bool setCase(Case_t);

    //Méthodes
    void display() const;
    Bateau_t addBateau(int);
    void addBateau(Bateau_t);
    Bateau_t addBateauIA(int);
    bool checkBateau(int, int, char, int);
};

#endif /*PLATEAU_H*/








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
