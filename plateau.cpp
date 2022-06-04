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
#include <typeinfo>

 //Affichage d'une ligne de délimitation
void addLine(int tailleTab) {
    for(int i = 0; i < tailleTab + 1; i++){
        std::cout << "|----";
    }
    std::cout << "|" << std::endl;;
}

//Traduction de l'affichage des cases en fonction de leur état
char stateDisplay(int state){
    char caseContent = ' ';
    switch (state)
    {
        case 0: //Vide
            caseContent = ' ';
            break;
        case 1: //Rate
            caseContent = 'x';
            break;
        case 2: //Touche
            caseContent = '.';
            break;
        case 3: //Bateau
            caseContent = 'B';
            break;
        case 4: //Coule
            caseContent = 'O';
            break;
        default:
            caseContent = 'E';
            break;
    }
    return caseContent;
}

//Constructeurs
Plateau_t::Plateau_t() {
    this->taille = 10;
}


/*******************************
 *       Public methods        *
 *******************************/
void Plateau_t::display() const {

    //Gestion affichage grille vide
    std::cout << "Affichage de la grille" << std::endl;
    addLine(this->taille);
    for(int line = 0; line < this->taille + 1; line++) {   
            for (int row = 0; row < this->taille + 1; row++) {  

                //Gestion affichage numéro colonnes
                if((line == 0) && (row != 0)) {
                    //Gestion affichage lettres avec decalage pour récupérer tablea ASCII (A=65)
                    std::cout << "|" << char(row + 64) << "   "; 
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
                        std::cout <<"| " << stateDisplay(this->grid[row-1][line-1].getState()) << "  ";
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

bool Plateau_t::setCase(int x, int y, int state) {
    if (1 <= x && x <= 10 && 1 <= y && y <= 10) {
        this->grid[x - 1][y - 1].setState(state);
        return true;
    }
    else {
        std::cout <<"ERREUR Coordonnes : Case non modifiee";
        return false;
    }
}

bool Plateau_t::setCase(Case_t new_case) {
    if (1 <= new_case.getX() && new_case.getX() <= 10 && 1 <= new_case.getY() && new_case.getY() <= 10) {
        this->grid[new_case.getX() - 1][new_case.getY() - 1].setState(new_case.getState());
        return true;
    }
    else {
        std::cout <<"ERREUR Coordonnes : Case non modifiee";
        return false;
    }
}



Bateau_t Plateau_t::addBateau(int type) {
    int x_in, x_grid, y_in, y_grid, choixUserY, testInt = 1;
    char choixUserX;

    //Saisie de la coordonne X du point d'origine du bateau
    do {
        std::cout << "Saisir la coordonne d'origine X du bateau (entre A et J) : " << std::endl; 
        std::cin >> choixUserX;

        //On vérifie que la coordonnée X est bien sur la grille
        if(!(choixUserX >= 'A' && choixUserX <= 'J')) {
            std::cout << "Incorrect, saisir une lettre majuscule entre A et J" << std::endl;
        }

    } while(!(choixUserX >= 'A' && choixUserX <= 'J'));
    x_in = (choixUserX - 'A') + 1;
    x_grid = x_in - 1;


    //Saisie de la coordonne Y du point d'origine du bateau
    bool check = true;
    do {
        std::cout << "Saisir la coordonne d'origine Y du bateau (entre 1 et 10) : " << std::endl; 
        std::cin >> choixUserY;
        y_in = choixUserY;
        y_grid = y_in - 1;
        check = true;

        //On vérifie que la coordonnée Y est bien sur la grille
        if(!(choixUserY >= 1 && choixUserY <= 10)) {
            std::cout << "Y : " << choixUserY << std::endl;
            std::cout << "Incorrect, saisir un nombre entre 1 et 10" << std::endl;
            check = false;
        }

        //On vérifie si la case ciblée n'est pas déjà prise par un autre bateau
        else if (this->grid[x_grid][y_grid].getState() == bateau) {
            std::cout << "Incorrect, la case est deja prise par un autre bateau" << std::endl;
            check = false;
        }

        //On vérifie qu'il n'y a pas de bateau autour de la case ciblée
        else if ((this->grid[x_grid + 1][y_grid].getState() == bateau) ||
                 (this->grid[x_grid + 1][y_grid + 1].getState() == bateau) ||
                 (this->grid[x_grid][y_grid + 1].getState() == bateau) ||
                 (this->grid[x_grid - 1][y_grid + 1].getState() == bateau) ||
                 (this->grid[x_grid - 1][y_grid].getState() == bateau) ||
                 (this->grid[x_grid - 1][y_grid - 1].getState() == bateau) ||
                 (this->grid[x_grid][y_grid - 1].getState() == bateau) ||
                 (this->grid[x_grid + 1][y_grid - 1].getState() == bateau)) {

            std::cout << "Incorrect, bateau a moins d'une case" << std::endl;
            check = false;
        }

    } while(check == false);


    //Saisie de la direction du bateau à partir du point d'origine
    std::cout << "Saisir la direction de votre bateau (d, g, b, h) :" << std::endl;
    char direction = ' ';
    std::cin >> direction;

    //Creation du bateau après avoir vérifié son emplacement
    Bateau_t bateau0(type, x_grid, y_grid, direction);

    //On Maj la grille en fonction du bateau
    for(int i = 0; i < bateau0.getLength(); i++) {
        this->grid[bateau0.getCase(i).getX()][bateau0.getCase(i).getY()].setState(bateau);
    }

    return bateau0;
}