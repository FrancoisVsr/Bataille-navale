/**
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

/*******************************
 *          Includes           *
 *******************************/
#ifndef BATEAU_HPP
#define BATEAU_HPP

#include <iostream>
#include <cstring>
#include <cstdbool>
#include <cassert>
#include <cstdio>
#include <errno.h>
using namespace std;

/*******************************
 *       Public methods        *
 *******************************/

/**
 * @enum        nom_bateau
 * @brief       Il s'agit des noms des différents bateaux à disposer sur le plateau, il y en 5 différents avec chacun leurs taille
 */

enum nom_bateau { //enumeration des nom de bateau sous forme de int
    porte_avion = 0,
    croiseur = 1,
    contre_torpilleur_1 = 2,
    contre_torpilleur_2 = 3,
    torpilleur = 4
};

struct coordinate //structure coordonnees d'un bateau sur plateau
{
    string coordX; // de A a J
    int coordY;    // de 1 a 10
};

class Bateau_t{ 

    private:

        int longueur_bateau;        //en fonction du bateau que lon choisit de placer
        bool vie;                   //sert a savoir si le bateau est coule ou pas 
        coordinate tab_coord[5];    //tableau des coord des cases occupees par le bateau
        bool tab_touche[5];         //sert a savoir si le bateau est touche
        string nom_bateau;          //nom du bateau(enum)
        char* direction;            //direction donnee par utilisateur

    public:

        //Constructeur 
        Bateau_t(int nom_bateau);  
        Bateau_t(int nom_bateau, coordinate tab_coord);

	    //Accesseurs
	    string getNom_Bateau() const;
        int *getCoord() const;
        bool *getTouche() const;
        bool getVivant() const;
        int getLongueur_Bateau() const;
 
        //Mutateurs
        void setVivant(bool v);

	    //Méthodes
        void input_coordinate(coordinate coordonnee);   //fonction entree des coordonnees d'un bateau
        //void Bateau_t::input_coordinate(void);

        //Destructeur
        ~Bateau_t();

};

#endif //BATEAU_HPP