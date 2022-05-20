/**
 * @author      Vasseur
 * @date        20/05/2022
 * @version     v0.01
 * @brief       Librairie pour la classe joueur
 */

#ifndef JOUEUR_HPP
#define JOUEUR_HPP

/*******************************
 *          Includes           *
 *******************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <stdbool.h>
#include <assert.h>
using namespace std;

/*******************************
 *       Public methods        *
 *******************************/

/**
 * @class       Joueur_t
 * @brief       Classe pour gérer la création et les jeux des joueurs
 * @version     0.1
 * @date        20/05/2022
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application (c'est votre faute)
 */
class Joueur_t{
    private :
		Plateau_t plateau_allie;
        Plateau_t plateau_ennemi;
        Bateau_t porte_avion;
        Bateau_t croiseur;
        Bateau_t contre_torpilleurs_1;
        Bateau_t contre_torpilleurs_2;
        Bateau_t torpilleur;
        bool vie;
        char * name;

    public :
      	//Constructeur
  	    Joueur_t(char * name);

    	//getter
	    bool get_bool();
        Plateau_t get_plateau(int plateau);
        Bateau_t get_bateau(int nb);

        //setter
	    bool set_bool(bool vie);
        Plateau_t set_plateau(Plateau_t plateau, char vs);
        Bateau_t set_bateau(Bateau_t bateau, int nb);
  
  	    //Destructeur 
  	    ~Joueur_t();
}

#endif /*JOUEUR_HPP*/