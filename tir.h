/**
 * @author      Auffray
 * @date        25/05/2022
 * @version     v0.01
 * @brief       Librairie pour la classe tir
 */

#ifndef TIR_H
#define TIR_H

/*******************************
 *          Includes           *
 *******************************/
#include <string>

/**
 * @class       tir_t
 * @brief       Classe pour gérer les tirs
 * @version     0.1
 * @date        25/05/2022
 * @pre         Initialisez d'abord le système
 * @post        L'objet est initialisé ou pas 
 * @warning     Une mauvaise utilisation peut faire planter votre application
 */
class tir_t {
private:
    int x;              // coordonées du tir
    int y;
    std::string name;   // nom du tir

public:
    tir_t();                                    // constructor
    void set(const std::string);                // set tir
    int getX()const {return x;}                 // get x
    int getY()const {return y;}                 // get y
    std::string getName()const {return name;}   // get name
};

#endif