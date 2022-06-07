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
 *       Public methods        *
 *******************************/
/**
 * @brief Constructeur par défaut de la class Bateau_t
 * @details Set la vie à true et la longueur à 0
 */
Bateau_t::Bateau_t() {
    this->vie = true;
    this->longueur_bateau = 0;
    
}

/**
 * @brief Constructeur utilisé pour l'IA et pour joueur
 * @details Set la vie à true et les différents paramètres d'un bateau
 * @param[in] int type,x,y
 * @param[in] char direction
 */
Bateau_t::Bateau_t(int type, int x, int y, char direction) {

    // attributs set de base
    this->vie = true;   //par defaut en vie

    switch (type) // 0,1,2,3,4
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

    this->tab_coord[0].setX(x);
    this->tab_coord[0].setY(y);
    this->tab_coord[0].setState(etat_t::bateau);

    //Maj des cases du bateau en fonction de la direction choisi
    if(direction == 'g') //gauche
    {
        for (int i = 1; i < this->longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX() - 1);
            this->tab_coord[i].setY(this->tab_coord[i-1].getY());
        }
    }
    else if(direction == 'b') //bas 
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX());
            this->tab_coord[i].setY(this->tab_coord[i-1].getY() + 1);
        }
    }
    else if(direction == 'd') //droite
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX() + 1);
            this->tab_coord[i].setY(this->tab_coord[i-1].getY());
        }
    }
    else if(direction == 'h') //haut
    {
        for (int i = 1; i < longueur_bateau; i++)
        {
            this->tab_coord[i].setState(etat_t::bateau);
            this->tab_coord[i].setX(this->tab_coord[i-1].getX());
            this->tab_coord[i].setY(this->tab_coord[i-1].getY() - 1);
        }
    }
}

/**
 * @brief Methode utilisé pour mettre à jour les valeur d'un bateau
 * @param[in] Bateau_t valeur à set
 */
void Bateau_t::setBateau(Bateau_t bateau) {
    this->longueur_bateau = bateau.getLength();
    this->vie = bateau.getVivant();
    this->nom_bateau = bateau.getNom_Bateau();
    for(int i = 0; i < this->longueur_bateau; i++) {
        Case_t temp(bateau.getCase(i));
        this->tab_coord[i].setX(temp.getX());
        this->tab_coord[i].setY(temp.getY());
        this->tab_coord[i].setState(temp.getState());
    }
}

/**
 * @brief Methode utilisé pour mettre à jour l'état d'une case d'un bateau
 * @param[in] int position (case du bateau à modifier
 * @param[in] int state (valeur à set)
 */
void Bateau_t::setState(int position, int state) {
    this->tab_coord[position].setState(state);
}

