/**
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

#ifndef CASE_H
#define CASE_H

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
    coule = 4,
    incorrect = 5
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
private:
    int x;
    int y;
    int state;
    
public:
    //Constructeurs
    /**
     * @brief Constructeur utilisé pour une case
     * @details Set les coordonnées à 0 et l'état à eau
     */
    Case_t();

    /**
     * @brief Constructeur utilisé pour une case avec coordonnées
     * @details Set les coordonnées à x et y et l'état à eau
     * @param[in] int x,y
     */
    Case_t(int, int);

    /**
     * @brief Constructeur utilisé pour une case avec coordonnées et état
     * @details Set les coordonnées à x et y et l'état à state
     * @param[in] int x,y,state
     */
    Case_t(int, int, int);

    //Accesseurs
    int getX() const { return this->x;}
    int getY() const { return this->y;}
    int getState() const { return this->state;}

    //Setteurs
    void setX(int x) { this->x = x;}
    void setY(int y) { this->y = y;}
    void setState(int state) { this->state = state;}

    /**
     * @brief Méthode de Case_t pour set les attributs avec une nouvelle case
     * @details Cette méthode permet de setter les attributs d'une case
     * @param[in] Case_t
     */
    void setCase(const Case_t&);
};

#endif