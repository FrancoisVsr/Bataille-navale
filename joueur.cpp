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
    this->plateau_allie = plateau_ennemi;

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

/**
 * @brief       Accesseur pour la vie de l'objet Joueur
 * @return      bool
 */
bool Joueur_t::get_vie() const{
    return vie;
};

/**
 * @brief       Accesseur pour les plateaux de l'objet Joueur
 * @return      Plateau_t
 */
Plateau_t Joueur_t::get_plateau(int plateau){
    switch (plateau)
    {
        case 0:
            return plateau_allie;
            break;
        case 1:
            return plateau_ennemi;
            break
        default:
            return 0;
    }
};

/**
 * @brief       Accesseur pour les bateaux de l'objet Joueur
 * @return      Bateau_t
 */
Bateau_t get_bateau(int nb){
    switch (nb)
    {
        case 0:
            return porte_avion;
            break;
        case 1:
            return croiseur;
            break
        case 2:
            return contre_torpilleurs_1;
            break;
        case 3:
            return contre_torpilleurs_2;
            break
        case 4:
            return torpilleur;
            break
        default:
            return 0;
    }
};

/**
 * @brief       Setter pour la vie de l'objet Joueur
 * @return
 */
void Joueur_t::set_vie(bool life){
    this->vie = life;
};
void Joueur_t::set_plateau(Plateau_t plateau, char vs){

};
void Joueur_t::set_bateau(Bateau_t bateau, int nb){

};
  

bool Joueur_t::tir(Joueur_t *j, int x, int y){
    int etat;
    if((x >= 0) && (x <= 9) && (y >= 0) && (y <= 9))
    {
        etat = j->plateau_allie.getCase(x,y);
        if(etat == eau)
        {
            j->plateau_allie.setCase(x,y);
            etat = j->plateau_allie.getCase(x,y);
            switch(etat)
            {
                case touche:
                    std::cout << "Un bateau a été touché !" << std::endl << std::endl;
                    break;
                case coule:
                    std::cout << "Un bateau a été coulé !" << std::endl << std::endl;
                    break;
                case rate:
                    std::cout << "Sheh ! Essaie encore !" << std::endl << std::endl;
                    break;
                default:
                    break;
            }
            j->plateau_allie.Display();
            std::cout << std::endl << std::endl;
            j->plateau_ennemi.Display();
            std::cout << std::endl << std::endl;
            return true;
        }
        else
        {
            std::cout << "Sale bigleux sans mémoire t'as déjà tiré ici !" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Les coordonnées doivent être comprises entre 0 et 9 !" << std::endl;
        return false;
    }
}


/**
 * @brief       Destructeur d'un objet Joueur
 */
Joueur_t::~Joueur_t(){
}
