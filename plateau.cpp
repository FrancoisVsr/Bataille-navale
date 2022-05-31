/**
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

/*******************************
 *          Includes           *
 *******************************/
#include "plateau.h"
#include <cstdlib>

 //Affichage d'une ligne de délimitation
void addLine(int tailleTab) {
    for(int i = 0; i < tailleTab + 1; i++){
        std::cout << "|----";
    }
    std::cout << "|" << std::endl;;
}

//Constructeurs
Plateau_t::Plateau_t() {

    this->taille = 10;
}


/*******************************
 *       Public methods        *
 *******************************/
void Plateau_t::display() {

    //Gestion affichage grille vide
    addLine(this->taille);
    for(int line = 0; line < this->taille + 1; line++) {   
            for (int row = 0; row < this->taille + 1; row++) {  

                //Gestion affichage numéro colonnes
                if((line == 0) && (row != 0)) {
                    //Gestion affichage chiffre ou nombre
                    if (row < 10){
                        std::cout << "|" << row << "   ";
                    } 
                    else {
                        std::cout << "|" << row << "  ";
                    }  
                }
               
                else {
                    //Gestion affichage numéro ligne
                    if ((row == 0) and (line >= 0)) {
                        if (line == 0){
                            std::cout << "|GRID"; 
                        }
                        else if (line < 10){
                            std::cout << "|" << line << "   ";
                        } 
                        else {
                            std::cout << "|" << line << "  ";
                        }
                    } 
                    else {
                        //Affichage du délimiteur + du contenu de la case
                        std::cout <<"| " << this->grid[row-1][line-1].getState() << "  ";
                    } 
                }

                //Gestion fin de ligne et insertion ligne
                if (row == this->taille) {
                    std::cout <<"|\n";
                    addLine(this->taille);
                }  
            }
        }
}

void Plateau_t::setCase(int x, int y, int state) {
    if ((1 < x < 10) && (1 < y < 10)) {
        this->grid[x-1][y-1].setState(state);
    }
    else {
        std::cout <<"ERREUR Coordonnes : Case non modifiee";
    }
}