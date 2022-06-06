#ifndef CASE_H
#define CASE_H

#include <string>

enum etat_t { 
    eau = 0,
    rate = 1,
    touche = 2,
    bateau = 3,
    coule = 4
};

/**
 * @class       Case_t
 * @brief       Instancie un case contenant des coordonnees et un etat parmi 5 possibles.
 * @details     Les cases structure la grille du plateau et les bateaux
 * @version     0.1
 * @date        2022
 * @pre         Saisir X, Y et l'état
 * @post        Renvoie l'objet qui peut êtr emodifié via les setteurs
 * @warning     les coordonées sont bornée par la taille de la grille et il existe 5 états
 */
class Case_t {

    protected:
        int x;
        int y;
        int state;
        
    public:
        //Constructeurs
        Case_t();
        Case_t(int, int);
        Case_t(int, int, int);

        //Accesseurs
        int getX() const { return this->x;}
        int getY() const { return this->y;}
        int getState() const { return this->state;}

        //Setteurs
        void setX(int x) { this->x = x;}
        void setY(int y) { this->y = y;}
        void setState(int state) { this->state = state;}
};

#endif