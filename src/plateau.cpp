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
#include "interface.h"
#include <cstdlib>
#include <typeinfo>

/*******************************
 *       Public methods        *
 *******************************/
/**
 * @fn void addLine(int tailleTab)
 * @brief Affichage d'une ligne de délimitation
 * @param[in]   int tailletab
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
 * @param[in]   int state
 */
char stateDisplay(int state) {
    char caseContent = ' ';
    switch (state) {
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
        std::cout << __func__ << __LINE__ <<"ERREUR Coordonnes : Case non modifiee";
        return false;
    }
}

/**
 * @brief Méthode de Plateau_t pour set une case
 * @details Cette méthode permet de set une case du plateau à partir d'une nouvelle case
 * @param[in] Case_t new_case
 * @return bool true si la case a été set
 */
bool Plateau_t::setCase(Case_t new_case) {
    if (1 <= new_case.getX() && new_case.getX() <= 10 && 1 <= new_case.getY() && new_case.getY() <= 10) {
        this->grid[new_case.getX() - 1][new_case.getY() - 1].setState(new_case.getState());
        return true;
    }
    else {
        std::cout << __func__ << __LINE__ <<"ERREUR Coordonnes : Case non modifiee";
        return false;
    }
}

/**
 * @brief Méthode de Plateau_t pour créer et ajouter un bateau au plateau
 * @details Cette méthode permet de créer un bateau en vérifiant si les coordonnées sont valides 
 * @param[in] int type
 * @return Bateau_t 
 */
Bateau_t Plateau_t::addBateau(int type) {
    int x_in, x_grid, y_in, y_grid, testInt = 1;
    std::string choixUserY = "";
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

        //On vérifie que la coordonnée Y est bien sur la grille
        while(choixUserY != "1" && choixUserY != "2" && choixUserY != "3" && choixUserY != "4" && choixUserY != "5" && choixUserY != "6" && choixUserY != "7" && choixUserY != "8" && choixUserY != "9" && choixUserY != "10") {
            std::cout << "Incorrect, saisir un nombre entre 1 et 10" << std::endl;
            std::cin >> choixUserY;
        }

        y_in = stoi(choixUserY);
        y_grid = y_in - 1;
        checkY = true;

        //On vérifie si la case ciblée n'est pas déjà prise par un autre bateau
        if(this->grid[x_grid][y_grid].getState() == bateau) {
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
            std::cout << "Erreur, aucune des lettres en minuscule n a ete saisie !" << std::endl;  
        }

    } while(checkDir == false);

    //Creation du bateau après avoir vérifié son emplacement
    // Bateau_t bateau0(type, x_grid, y_grid, direction);
    Bateau_t bateau0(type, x_in, y_in, direction);

    //On Maj la grille en fonction du bateau
    for(int i = 0; i < bateau0.getLength(); i++) {
        // this->grid[bateau0.getCase(i).getX()][bateau0.getCase(i).getY()].setState(bateau);
        this->grid[bateau0.getCase(i).getX() - 1][bateau0.getCase(i).getY() - 1].setState(bateau);
    }

    return bateau0;
}


/**
 * @brief Méthode de Plateau_t pour créer et ajouter un bateau au plateau avec sdl
 * @details Cette méthode permet de créer un bateau en vérifiant si les coordonnées sont valides 
 * @param[in] int type
 * @return Bateau_t 
 */
Bateau_t Plateau_t::addBateauSDL(int type) {
    int x_grid, y_grid;
    char direction = ' ';
    bool checkBateau = true;
    
    int longueur_bateau = 0;
    switch (type) /*0,1,2,3,4*/
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
        default: 
            longueur_bateau = 3; break;
    }

    do{
        transformClicToCoordandDir(&x_grid, &y_grid, &direction);
        checkBateau = this->checkBateau((x_grid-1), (y_grid-1), direction, longueur_bateau);
    } while(checkBateau == true);

    /*Creation du bateau après avoir vérifié son emplacement*/
    Bateau_t bateau0(type, x_grid, y_grid, direction);

    /*On Maj la grille en fonction du bateau*/
    for(int i = 0; i < bateau0.getLength(); i++) {
        this->grid[bateau0.getCase(i).getX() - 1][bateau0.getCase(i).getY() -1].setState(bateau);
    }
    
    return bateau0;
}


/**
 * @brief Méthode de Plateau_t pour ajouter un bateau
 * @details Cette méthode permet d'ajouter un bateau au plateau
 * @param[in] Bateau_t
 * @return bool si le bateau a été ajouté
 */
void Plateau_t::addBateau(Bateau_t bateau) {
    for(int i = 0; i < bateau.getLength(); i++) {
        if(!(this->setCase(bateau.getCase(i)))) {
            std::cout << "ERROR dans Plateau_t::addBateau(Bateau_t)" << std::endl;
            return;
        }
    }
    return;
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
    int dir, longueur_bateau;
    char direction = ' ';

    switch (type) /*0,1,2,3,4*/
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
        default: 
            longueur_bateau = 3; break;
    }

    //Saisie de la coordonne X et Y du point d'origine du bateau
    do {
        check = true;
        srand(time(NULL));
        x_in = (rand() % 10) + 1;
        y_in = (rand() % 10) + 1;
        dir = (rand() % 4);

        switch(dir){
            case 0:
                direction = 'h';
                break;
            case 1:
                direction = 'b';
                break;
            case 2:
                direction = 'g';
                break;
            case 3:
                direction = 'd';
                break;
        }        
        
        if (this->checkBateau((x_in-1), (y_in-1), direction, longueur_bateau)) { //si le bateau ne sera pas entourée par un autre
            check = false;
        }

    } while(check == false);

    //Creation du bateau après avoir vérifié son emplacement
    Bateau_t bateau0(type, x_in, y_in, direction);

    //On Maj la grille en fonction du bateau
    for(int i = 0; i < bateau0.getLength(); i++) {
        this->grid[bateau0.getCase(i).getX()-1][bateau0.getCase(i).getY()-1].setState(bateau);
    }
    return bateau0;
}

/**
 * @brief       Méthode checkBateau de la classe plateau
 * @details     Vérifie si lors de l'ajout d'un bateau celui ci ne sera pas collé ou proche d'un autre bateau
 * @param[in]   int x,y,longueur
 * @param[in]   char direction
 * @return      bool true si proche d'un autre bateau
 */
bool Plateau_t::checkBateau(int x, int y, char direction, int longueur) {
    if((0 <= x <= 9) && (0 <= y <= 9)){    
        if(this->grid[x][y].getState() == bateau) {
            return true;
        }
    }
    
    if(x == 9){
        if(y == 9){
            if((this->grid[x - 1][y].getState() == bateau) ||
               (this->grid[x - 1][y - 1].getState() == bateau) ||
               (this->grid[x][y - 1].getState() == bateau)){
                return true;
            }
        }
        else if(y == 0){
            if((this->grid[x - 1][y].getState() == bateau) ||
               (this->grid[x - 1][y + 1].getState() == bateau) ||
               (this->grid[x][y + 1].getState() == bateau)){
                return true;
            }
        }
        else{
            if((this->grid[x][y + 1].getState() == bateau) ||
               (this->grid[x - 1][y + 1].getState() == bateau) ||
               (this->grid[x - 1][y].getState() == bateau) ||
               (this->grid[x - 1][y - 1].getState() == bateau) ||
               (this->grid[x][y - 1].getState() == bateau)){
                return true;
            }
        }
    }
    else if(x == 0){
        if(y == 9){
            if((this->grid[x + 1][y].getState() == bateau) ||
               (this->grid[x + 1][y - 1].getState() == bateau) ||
               (this->grid[x][y - 1].getState() == bateau)){
                return true;
            }
        }
        else if(y == 0){
            if((this->grid[x + 1][y].getState() == bateau) ||
               (this->grid[x + 1][y + 1].getState() == bateau) ||
               (this->grid[x][y + 1].getState() == bateau)){
                return true;
            }
        }
        else{
            if((this->grid[x][y + 1].getState() == bateau) ||
               (this->grid[x + 1][y + 1].getState() == bateau) ||
               (this->grid[x + 1][y].getState() == bateau) ||
               (this->grid[x + 1][y - 1].getState() == bateau) ||
               (this->grid[x][y - 1].getState() == bateau)){
                return true;
            }
        }
    }
    else{
        if(y == 9){
            if((this->grid[x + 1][y].getState() == bateau) ||
               (this->grid[x - 1][y].getState() == bateau) ||
               (this->grid[x - 1][y - 1].getState() == bateau) ||
               (this->grid[x][y - 1].getState() == bateau) ||
               (this->grid[x + 1][y - 1].getState() == bateau)){
                return true;
            }
        }
        else if(y == 0){
            if((this->grid[x + 1][y].getState() == bateau) ||
               (this->grid[x + 1][y + 1].getState() == bateau) ||
               (this->grid[x][y + 1].getState() == bateau) ||
               (this->grid[x - 1][y + 1].getState() == bateau) ||
               (this->grid[x - 1][y].getState() == bateau)){
                return true;
            }
        }
        else{
            if((this->grid[x + 1][y].getState() == bateau) ||
               (this->grid[x + 1][y + 1].getState() == bateau) ||
               (this->grid[x][y + 1].getState() == bateau) ||
               (this->grid[x - 1][y + 1].getState() == bateau) ||
               (this->grid[x - 1][y].getState() == bateau) ||
               (this->grid[x - 1][y - 1].getState() == bateau) ||
               (this->grid[x][y - 1].getState() == bateau) ||
               (this->grid[x + 1][y - 1].getState() == bateau)){
                return true;
            }
        }
    }     

    if(direction == 'g') {
        if((x - longueur) < 0) return true;
        if(longueur != 1){
            if(checkBateau((x - 1), y, direction, (longueur - 1))) return true;
        }
    }
    else if(direction == 'b') {
        if((y + longueur) > 9) return true;
        if(longueur != 1){
            if(checkBateau(x, (y + 1), direction, (longueur - 1))) return true;
        }
    }
    else if(direction == 'd') {
        if((x + longueur) > 9) return true;
        if(longueur != 1){
            if(checkBateau((x + 1), y, direction, (longueur - 1))) return true;
        }
    }
    else if(direction == 'h'){
        if((y - longueur) < 0) return true;
        if(longueur != 1){
            if(checkBateau(x, (y - 1), direction, (longueur - 1))) return true;
        }
    }

    return false;
}
