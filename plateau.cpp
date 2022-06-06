/**
 * @file        plateau.cpp
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
//Affichage graphique de la grille mise à jour sur le terminal
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

//Ajout d'un bateau après avoir vérifié son placement
Bateau_t Plateau_t::addBateau(int type) {
    int x_in, x_grid, y_in, y_grid, choixUserY, testInt = 1;
    char choixUserX;

    //*****Saisie de la coordonne X du point d'origine du bateau*****
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


    //*****Saisie de la coordonne Y du point d'origine du bateau*****
    bool checkY = true;
    do {
        std::cout << "Saisir la coordonne d'origine Y du bateau (entre 1 et 10) : " << std::endl; 
        std::cin >> choixUserY;
        y_in = choixUserY;
        y_grid = y_in - 1;
        checkY = true;

        //On vérifie que la coordonnée Y est bien sur la grille
        if(!(choixUserY >= 1 && choixUserY <= 10)) {
            std::cout << "Y : " << choixUserY << std::endl;
            std::cout << "Incorrect, saisir un nombre entre 1 et 10" << std::endl;
            checkY = false;
        }

        //On vérifie si la case ciblée n'est pas déjà prise par un autre bateau
        else if (this->grid[x_grid][y_grid].getState() == bateau) {
            std::cout << "Incorrect, la case est deja prise par un autre bateau" << std::endl;
            checkY = false;
        }

        //On vérifie qu'il n'y a pas de bateau autour de la case ciblée
        else if ((this->grid[x_grid + 1][y_grid].getState() == bateau) || //d
                 (this->grid[x_grid + 1][y_grid + 1].getState() == bateau) || //dh
                 (this->grid[x_grid][y_grid + 1].getState() == bateau) || //h
                 (this->grid[x_grid - 1][y_grid + 1].getState() == bateau) || //hg
                 (this->grid[x_grid - 1][y_grid].getState() == bateau) || //g
                 (this->grid[x_grid - 1][y_grid - 1].getState() == bateau) || //gb
                 (this->grid[x_grid][y_grid - 1].getState() == bateau) || //b
                 (this->grid[x_grid + 1][y_grid - 1].getState() == bateau)) { //bd

            std::cout << "Incorrect, bateau a moins d'une case" << std::endl;
            checkY = false;
        }

    } while(checkY == false);



    //*****Saisie de la direction du bateau à partir du point d'origine*****
    int longueur_bateau = 0;
    switch (type) // 0,1,2,3,4
        {
            case porte_avion: 
                longueur_bateau = 5; break;
            case croiseur:
                longueur_bateau = 4; break;
            case contre_torpilleur_1: 
                longueur_bateau = 3; break;
            case contre_torpilleur_2: 
                longueur_bateau = 3; break;
            case torpilleur: 
                longueur_bateau = 2; break;
            default: longueur_bateau = 3; break;
        }

    bool checkDir = true;
    char direction = ' ';
    do {
        std::cout << "Saisir la direction de votre bateau (d, g, b, h) de taille ";
        std::cout << longueur_bateau << " :" << std::endl;
        std::cin >> direction;
        checkDir = true;

        //Maj des cases du bateau en fonction de la direction choisie
        if(direction == 'g') //gauche
        {
            for (int i = 1; i <= longueur_bateau; i++) {
                //std::cout << "(" << x_grid - i + 1 << ", " << y_grid + 1 << ")." << std::endl;
                if (x_grid - i + 1 < 0) // X < A
                {
                    checkDir = false;
                    std::cout << "Erreur, bordure gauche depassee case : (";
                    std::cout << x_grid - i + 2 << ", " << y_grid + 1 << ")." << std::endl;
                }
                else if (((this->grid[x_grid - i][y_grid + 1].getState() == bateau) || //bat hg
                        (this->grid[x_grid - i][y_grid].getState() == bateau) || //bat g
                        (this->grid[x_grid - i][y_grid - 1].getState() == bateau)) && //bat gb
                        (x_grid - i + 1 > 0))
                { 
                    checkDir = false;
                    std::cout << "Erreur, bateau a proximite de la case : (";
                    std::cout << x_grid - i + 2 << ", " << y_grid + 1 << ")." << std::endl;
                }
            }
        }
        else if(direction == 'b') //bas 
        {
            for (int i = 1; i <= longueur_bateau; i++)
            {
                //std::cout << "(" << x_grid + 1 << ", " << y_grid + i + 1 << ")." << std::endl;
                if (y_grid + i - 1 > 9) 
                {
                    checkDir = false;
                    std::cout << "Erreur, bordure basse depassee case : (";
                    std::cout << x_grid + 1 << ", " << y_grid + i << ")." << std::endl;
                }
                else if ( (this->grid[x_grid - 1][y_grid + i].getState() == bateau) || //gb
                        (this->grid[x_grid][y_grid + i].getState() == bateau) || //b
                        (this->grid[x_grid + 1][y_grid + i].getState() == bateau)) //bd
                { 
                    checkDir = false;
                    std::cout << "Erreur, bateau a proximite de la case : (";
                    std::cout << x_grid + 1 << ", " << y_grid + i << ")." << std::endl; 
                }
            }
        }
        else if(direction == 'd') //droite
        {
            for (int i = 1; i <= longueur_bateau; i++)
            {
                //std::cout << "(" << x_grid + i + 1 << ", " << y_grid + 1 << ")." << std::endl;
                if (x_grid + i - 1 > 9)
                {
                    checkDir = false;
                    std::cout << "Erreur, bordure droite depassee case : (";
                    std::cout << x_grid + i << ", " << y_grid + 1 << ")." << std::endl;
                }
                else if ((this->grid[x_grid + i][y_grid].getState() == bateau) || //d
                        (this->grid[x_grid + i][y_grid + 1].getState() == bateau) || //dh
                        (this->grid[x_grid + i][y_grid - 1].getState() == bateau)) //bd
                { 
                    checkDir = false;
                    std::cout << "Erreur, bateau a proximite de la case : (";
                    std::cout << x_grid + i << ", " << y_grid + 1 << ")." << std::endl; 
                }
                
            }
        }
        else if(direction == 'h') //haut
        {
            for (int i = 1; i <= longueur_bateau; i++)
            {
                //std::cout << "(" << x_grid + 1 << ", " << y_grid - i + 1 << ")." << std::endl;   
                if (y_grid - i + 1 < 0)
                {
                    checkDir = false;
                    std::cout << "Erreur, bordure haute depassee case : (";
                    std::cout << x_grid + 1 << ", " << y_grid - i + 1 << ")." << std::endl;
                }
                else if ( (this->grid[x_grid + 1][y_grid - i].getState() == bateau) || //dh
                        (this->grid[x_grid][y_grid - i].getState() == bateau) || //h
                        (this->grid[x_grid - 1][y_grid - i].getState() == bateau)) //hg
                {
                    checkDir = false;
                    std::cout << "Erreur, bateau a proximite de la case : (";
                    std::cout << x_grid + 1 << ", " << y_grid - i + 2 << ")." << std::endl; 
                }
            }
        }
        else
        {
            checkDir = false;
            std::cout << "Erreur, aucune des lettres en minuscule n'a ete saisie !" << std::endl;  
        }

    } while(checkDir == false);

    //Creation du bateau après avoir vérifié son emplacement
    Bateau_t bateau0(type, x_grid, y_grid, direction);

    //On Maj la grille en fonction du bateau
    for(int i = 0; i < bateau0.getLength(); i++) {
        this->grid[bateau0.getCase(i).getX()][bateau0.getCase(i).getY()].setState(bateau);
    }

    return bateau0;
}