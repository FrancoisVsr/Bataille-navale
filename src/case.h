/**
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

#ifndef CASE_H
#define CASE_H

/*******************************
 *          Includes           *
 *******************************/
#include <string>

/**
 * @enum        etat_t
 * @brief       Etat de la case actuelle (eau, rate, touche, bateau, coule)
 */
enum etat_t { 
    eau = 0,
    rate = 1,
    touche = 2,
    bateau = 3,
    coule = 4
};

/**
 * @class       Case_t
 * @brief       classe case avec ses caracteristiques
 * @version     0.1
 * @date        2022
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application
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
        void setCase(Case_t&);
};

#endif /*CASE_H*/