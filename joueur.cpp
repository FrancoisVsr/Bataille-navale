/**
 * @file        joueur.cpp
 * @brief       Fichier contenant la classe Joueur et ses fonctions
 * @author      Vasseur
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include "joueur.hpp"

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
 * @brief       Constructeur d'un objet Joueur
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux
 */
Joueur_t::Joueur_t(char * name){
    assert(name != NULL);
    this->name = name;
    this->vie = true;
    
    Plateau_t plateau_allie;
    this->plateau_allie = plateau_allie;
    Plateau_t plateau_ennemi;
    this->plateau_ennemi = plateau_ennemi;

    Bateau_t porte_avion(0);
    this->porte_avion = porte_avion;
    Bateau_t croiseur(1);
    this->croiseur = croiseur;
    Bateau_t contre_torpilleurs_1(2);
    this->contre_torpilleurs_1 = contre_torpilleurs_1;
    Bateau_t contre_torpilleurs_2(3);
    this->contre_torpilleurs_1 = contre_torpilleurs_2;
    Bateau_t torpilleur(4);
    this->torpilleur = torpilleur;   
}



bool Joueur_t::get_bool(){

};
Plateau_t Joueur_t::get_plateau(int plateau){

};
Bateau_t get_bateau(int nb){
    
};

/**
 * @brief       Destructeur d'un objet Joueur
 */
Joueur_t::~Joueur_t(){
}
