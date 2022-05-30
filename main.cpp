#include <iostream>

#include <vector>
#include "case.h"

int main() {

    int taille = 10;

    Case_t plateau[taille][taille];

    for (int line = 0; line < taille; line++) {
        for (int row = 0; row < taille; row++){
            plateau[line][row].setEtat("    ");
        }
    }

    //le plateau va prendre en paramètre un tableau à 2 dimensions contenant les 5 états possibles des cases
    //on affichera ensuite le tableau de manière graphique en mettant i et j en paramètre

    //Gestion affichage grille vide
    for(int j = 0; j < 2 * taille + 3; j++) {   // j = numéro de ligne
            for (int i = 0; i < taille + 1; i++) {  // i = numéro de colonne

                //Gestion affichage numéro colonnes
                if((j == 1) && (i != 0)) {
                    if (i < 10){
                        std::cout << "|" << i << "   ";
                    } 
                    else {
                        std::cout << "|" << i << "  ";
                    }
                    
                }
                else if (j % 2 == 0){
                    //Délimiteur d'entre lignes
                    std::cout << "|----";
                } 
                else {
                    //Gestion affichage numéro ligne
                    if ((i == 0) and (j > 2)) {
                        if (j <= 20){
                            std::cout << "|" << j/2 << "   ";
                        } 
                        else {
                            std::cout << "|" << j/2 << "  ";
                        }
                    } 
                    else {
                        //Délimiteur d'entre colonnes
                        std::cout <<"|" << plateau[i][j/2].getEtat();
                    } 
                }
                //Gestion retour à la ligne
                if (i == taille) {
                    std::cout <<"|\n";
                }  
            }
        }

    return 0;
}