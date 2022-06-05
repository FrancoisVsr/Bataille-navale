/**
 * @file        plateau.cpp
 * @brief       Class plateau
 * @author      Gauthier, Vasseur, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include "plateau.h"
#include <cstdlib>
#include <typeinfo>
#include <time.h>

/*******************************
 *       Public methods        *
 *******************************/

/**
 * @fn void addLine(int tailleTab)
 * @brief Affichage d'une ligne de délimitation
 */
void addLine(int tailleTab) {
    for(int i = 0; i < tailleTab + 1; i++){
        std::cout << "|----";
    }
    std::cout << "|" << std::endl;;
}

/**
 * @fn char stateDisplay(int state)
 * @brief Traduction de l'affichage des cases en fonction de leur état
 */
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

/**
 * @brief Constructeur par défaut de plateau
 * @details Set la taille du tableau à 10
 */
Plateau_t::Plateau_t() {
    this->taille = 10;
}

/**
 * @brief Méthode de Plateau_t pour afficher la grille de l'objet
 * @details Cette méthode permet d'afficher la grille avec les bateaux et l'état de toutes les cases
 */
void Plateau_t::display() {
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

/**
 * @brief Méthode de Plateau_t pour set une case
 * @details Cette méthode permet de set une case du plateau à partir de coordonnées et du nouvel état
 * @param[in] int x,y,state
 * @return bool true si la case a été set
 */
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

/**
 * @brief Méthode de Plateau_t pour set une case
 * @details Cette méthode permet de set une case du plateau à partir d'une nouvelle case
 * @param[in] Case_t
 * @return bool true si la case a été set
 */
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

/**
 * @brief Méthode de Plateau_t pour ajouter un bateau
 * @details Cette méthode permet d'ajouter un bateau au plateau
 * @param[in] Bateau_t
 * @return bool si le bateau a été ajouté
 */
bool Plateau_t::addBateau(Bateau_t bateau) {
    for(int i = 0; i < bateau.getLength(); i++) {
        if(!(this->setCase(bateau.getCase(i)))) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Méthode de Plateau_t pour créer et ajouter un bateau au plateau
 * @details Cette méthode permet de créer un bateau en vérifiant si les coordonnées sont valides 
 * @param[in] int type
 * @return Bateau_t 
 */
Bateau_t Plateau_t::addBateau(int type) {
    int x_in, x_grid, y_in, y_grid, choixUserY;
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

/**
 * @brief Méthode de Plateau_t pour créer par l'IA un bateau et l'ajouter au plateau
 * @details Cette méthode permet de créer un bateau automatiquement
 * @param[in] int type
 * @return Bateau_t 
 */
Bateau_t Plateau_t::addBateauIA(int type) {
    int x_in, y_in;
    bool check;
    int dir, longueur;
    char direction = ' ';

    if(type == 0) longueur = 5;
    else if(type == 1) longueur = 4;
    else if((type == 2) || (type == 3)) longueur = 3;
    else longueur = 2;

    //Saisie de la coordonne X et Y du point d'origine du bateau
    do {
        check = true;
        srand(time(NULL));
        x_in = (rand() % 10) + 1;
        y_in = (rand() % 10) + 1;
        dir = (rand() % 4);

        //On vérifie que la coordonnée Y est bien sur la grille
        if((!(y_in >= 1 && y_in <= 10)) || (!(x_in >= 1 && x_in <= 10))) {
            check = false;
        }

        if(dir == 0) {
            direction = 'g';
            if(!((x_in - longueur) >= 1)) check = false;
        }
        else if(dir == 1) {
            direction = 'b';
            if(!((y_in + longueur) <= 10)) check = false;
        }
        else if(dir == 2) {
            direction = 'd';
            if(!((x_in + longueur) <= 10)) check = false;
        }
        else {
            direction = 'h';
            if(!((y_in - longueur) >= 1)) check = false;
        }

        if (this->checkBateau(x_in, y_in, direction, longueur)) { //si le bateau ne sera pas entourée par un autre
            check = false;
        }

    } while(check == false);

    //Creation du bateau après avoir vérifié son emplacement
    Bateau_t bateau0(type, x_in, y_in, direction);

    //On Maj la grille en fonction du bateau
    for(int i = 0; i < bateau0.getLength(); i++) {
        this->grid[bateau0.getCase(i).getX()][bateau0.getCase(i).getY()].setState(bateau);
    }

    return bateau0;
}

/**
 * @brief Méthode de Plateau_t pour afficher le plateau
 * @details ?
 */
void Plateau_t::displayShip() {
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

/**
 * @brief       Méthode checkBateau de la classe plateau
 * @details     Vérifie si lors de l'ajout d'un bateau celui ci ne sera pas collé ou proche d'un autre bateau
 * @param[in]   int x,y,longueur
 * @param[in]   char direction
 * @return      bool true si proche d'un autre bateau
 */
bool Plateau_t::checkBateau(int x, int y, char direction, int longueur) {
    if(this->grid[x][y].getState() == bateau) {
        return true;
    }
    else if((this->grid[x + 1][y].getState() == bateau) ||
            (this->grid[x + 1][y + 1].getState() == bateau) ||
            (this->grid[x][y + 1].getState() == bateau) ||
            (this->grid[x - 1][y + 1].getState() == bateau) ||
            (this->grid[x - 1][y].getState() == bateau) ||
            (this->grid[x - 1][y - 1].getState() == bateau) ||
            (this->grid[x][y - 1].getState() == bateau) ||
            (this->grid[x + 1][y - 1].getState() == bateau)) {
        return true;
    }
    else {
        if(direction == 'g') {
            for(int i = 0; i < longueur; i++) {
                if((x - i) == 0) break;
                if((this->grid[x - i - 1][y].getState() == bateau) ||
                   (this->grid[x - i - 1][y + 1].getState() == bateau) ||
                   (this->grid[x - i - 1][y - 1].getState() == bateau)) return true;
            }
        }
        else if(direction == 'b') {
            for(int i = 0; i < longueur; i++) {
                if((y + i) == 9) break;
                if((this->grid[x][y + i + 1].getState() == bateau) ||
                   (this->grid[x - 1][y + i + 1].getState() == bateau) ||
                   (this->grid[x + 1][y + i + 1].getState() == bateau)) return true;
            }
        }
        else if(direction == 'd') {
            for(int i = 0; i < longueur; i++) {
                if((x + i) == 9) break;
                if((this->grid[x + i + 1][y].getState() == bateau) ||
                   (this->grid[x + i + 1][y + 1].getState() == bateau) ||
                   (this->grid[x + i + 1][y - 1].getState() == bateau)) return true;
            }
        }
        else if(direction == 'h'){
            for(int i = 0; i < longueur; i++) {
                if((y - i) == 0) break;
                if((this->grid[x][y - i - 1].getState() == bateau) ||
                   (this->grid[x - 1][y - i - 1].getState() == bateau) ||
                   (this->grid[x + 1][y - i - 1].getState() == bateau)) return true;
            }
        }
    }
    return false;
}