/**
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

#ifndef BATEAU_HPP
#define BATEAU_HPP

/*******************************
 *          Includes           *
 *******************************/
#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
#include "case.h"

class Plateau_t;

/*******************************
 *      Global definitions     *
 *******************************/
/**
 * @enum        nom_bateau
 * @brief       Il s'agit des noms des différents bateaux à disposer sur le plateau, il y en 5 différents avec chacun leurs taille
 */
enum nom_bateau {
    porte_avion = 0,
    croiseur = 1,
    contre_torpilleur_1 = 2,
    contre_torpilleur_2 = 3,
    torpilleur = 4
};

/**
 * @struct      coordinate
 * @brief       Elle contient une chaine pour la valeur en X et un entier pour la valeur en Y
 */
struct coordinate { 
    std::string coordX; // de A a J
    int coordY;         // de 1 a 10
};


/*******************************
 *       Public methods        *
 *******************************/
/**
 * @class       Bateau_t
 * @brief       classe bateau avec ses caracteristiques
 * @version     0.1
 * @date        2022
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application (attention au placement du bateau sur le plateau)
 */
class Bateau_t { 
private:
    int longueur_bateau;        //en fonction du bateau que lon choisit de placer
    bool vie;                   //sert a savoir si le bateau est coule ou pas 
    Case_t tab_coord[5];        //tableau des coord des cases occupees par le bateau
    std::string nom_bateau;     //nom du bateau(enum)

public:
    //Constructeur 
    Bateau_t(); // For IA
    Bateau_t(int, int, int, char);

    //Accesseurs
    std::string getNom_Bateau() const {return nom_bateau;}
    Case_t getCase1() const {return tab_coord[0];}
    Case_t getCase2() const {return tab_coord[1];}
    Case_t getCase3() const {return tab_coord[2];}
    Case_t getCase4() const {return tab_coord[3];}
    Case_t getCase5() const {return tab_coord[4];}
    Case_t getCase(int i) const {return tab_coord[i];}
    bool getVivant() const {return vie;}
    int getLength() const {return longueur_bateau;}

    //Mutateurs
    void setVivant(bool v) {this->vie = v;}
    void setBateau(Bateau_t const);
    void setState(int, int);
};

#endif // BATEAU_HPP