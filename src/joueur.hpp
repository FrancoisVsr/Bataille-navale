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
#include <string>
#include <assert.h>
#include <time.h>
#include "bateau.h"
#include "plateau.h"
#include "case.h"

/*******************************
 *      Global definitions     *
 *******************************/
int letter_to_int(std::string str);

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
class Joueur_t {
private:
	Plateau_t plateau_allie;
    Plateau_t plateau_ennemi;
    Bateau_t porte_avion;
    Bateau_t croiseur;
    Bateau_t contre_torpilleurs_1;
    Bateau_t contre_torpilleurs_2;
    Bateau_t torpilleur;
    bool vie;
    std::string name;

public:
    //Constructeur
    Joueur_t(bool); // Pour l'IA
  	Joueur_t(std::string);

    // getters
    /**
     * @brief       Accesseur pour la vie de l'objet Joueur
     * @return      bool
     */
	bool get_vie() const {return vie;}
    Plateau_t get_plateau(int) const;
    Bateau_t get_bateau(int) const;
    std::string get_name()const {return name;}

    // setters
	/**
	 * @brief       Setter pour la vie de l'objet Joueur
	 * @param[in]   bool life
	 */
	void set_vie(bool life) {this->vie = life;}
	/**
	 * @brief       Setter pour une case du plateau allie du joueur
	 * @param[in]   int x,y,etat
	 */
    void set_case_allie(int x, int y, int etat) {plateau_allie.setCase(x, y, etat);}

    // methodes
    void tir(Joueur_t*, int, int);
    void tir(Joueur_t*); // Pour l'IA
    void display();
    void saisie_tir(int*, int*);
    void update_vie();
    int check_tir(int, int);
    bool check_bateau(int);
	void add_flotte();
};

#endif /*JOUEUR_HPP*/