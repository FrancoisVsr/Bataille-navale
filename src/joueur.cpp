/**
 * @file        joueur.cpp
 * @brief       Fichier contenant la classe Joueur et ses fonctions
 * @author      Vasseur, Auffray, Gauthier, Fave
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include "joueur.hpp"
#include "interface.h"


SDL_Rect middle = {433, 134, 500, 500};
SDL_Rect zone1 = {122, 134, 500, 500};
SDL_Rect zone2 = {744, 134, 500, 500};

/*******************************
 *       Public methods        *
 *******************************/
/**
 * @brief       Constructeur d'un objet Joueur pour la sdl
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux, il ajoute aussi les bateaux à la grille
 * @param[in]   string name_p
 */
Joueur_t::Joueur_t(SDL_Renderer *renderer) {
    
    /*todo interface graphique en gtk pour le nom et les infos pour placer ses bateaux*/
    //this->name = ;
    this->vie = true;
    
    size_t i = 0;
    int column = 0;
    for(i = 0; i < 100; i++)
    {
        if(((i % 10)  == 0) && (i != 0)) column++;
        this->grid_allie[i].w = this->grid_ennemi[i].w = this->grid_middle[i].w = 50;
        this->grid_allie[i].h = this->grid_ennemi[i].h = this->grid_middle[i].h = 50;
        this->grid_allie[i].x = 50*(i % 10) + zone1.x;
        this->grid_ennemi[i].x = 50*(i % 10) + zone2.x;
        this->grid_middle[i].x = 50*(i % 10) + middle.x;
        this->grid_allie[i].y = 50*column + zone1.y;
        this->grid_ennemi[i].y = 50*column + zone2.y;
        this->grid_middle[i].y = 50*column + middle.y;
        
    }
    
    Bateau_t B1(plateau_allie.addBateauSDL(nom_bateau::porte_avion));
    this->porte_avion.setBateau(B1);
    this->add_BoatSDL(renderer, B1, 0);
    Bateau_t B2(plateau_allie.addBateauSDL(nom_bateau::croiseur));
    this->croiseur.setBateau(B2);
    this->add_BoatSDL(renderer, B2, 0);
    Bateau_t B3(plateau_allie.addBateauSDL(nom_bateau::contre_torpilleur_1));
    this->contre_torpilleurs_1.setBateau(B3);
    this->add_BoatSDL(renderer, B3, 0);
    Bateau_t B4(plateau_allie.addBateauSDL(nom_bateau::contre_torpilleur_2));
    this->contre_torpilleurs_2.setBateau(B4);
    this->add_BoatSDL(renderer, B4, 0);
    Bateau_t B5(plateau_allie.addBateauSDL(nom_bateau::torpilleur));
    this->torpilleur.setBateau(B5);
    this->add_BoatSDL(renderer, B5, 0);
    
    this->displaySDL(renderer, 1);
    this->add_BoatSDL(renderer, B1, 1);
    this->add_BoatSDL(renderer, B2, 1);
    this->add_BoatSDL(renderer, B3, 1);
    this->add_BoatSDL(renderer, B4, 1);
    this->add_BoatSDL(renderer, B5, 1);
}

/**
 * @brief       Constructeur d'un objet Joueur
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux, il ajoute aussi les bateaux à la grille
 * @param[in]   string name_p
 */
Joueur_t::Joueur_t(std::string name_p) {
    this->name = name_p;
    this->vie = true;

    std::cout << "Saisie du porte-avion : " << std::endl;
    Bateau_t B1(plateau_allie.addBateau(nom_bateau::porte_avion));
    this->porte_avion.setBateau(B1);
    std::cout << "Grille mise a jour : " << std::endl;
    plateau_allie.display();
    std::cout << "Saisie du croiseur : " << std::endl;
    Bateau_t B2(plateau_allie.addBateau(nom_bateau::croiseur));
    this->croiseur.setBateau(B2);
    std::cout << "Grille mise a jour : " << std::endl;
    plateau_allie.display();
    std::cout << "Saisie du premier contretorpilleur : " << std::endl;
    Bateau_t B3(plateau_allie.addBateau(nom_bateau::contre_torpilleur_1));
    this->contre_torpilleurs_1.setBateau(B3);
    std::cout << "Grille mise a jour : " << std::endl;
    plateau_allie.display();
    std::cout << "Saisie du deuxieme contre torpilleur : " << std::endl;
    Bateau_t B4(plateau_allie.addBateau(nom_bateau::contre_torpilleur_2));
    this->contre_torpilleurs_2.setBateau(B4);
    std::cout << "Grille mise a jour : " << std::endl;
    plateau_allie.display();
    std::cout << "Saisie du torpilleur : " << std::endl;
    Bateau_t B5(plateau_allie.addBateau(nom_bateau::torpilleur));
    this->torpilleur.setBateau(B5);
    std::cout << "Grille mise a jour : " << std::endl;
    plateau_allie.display();
}

/**
 * @brief       Constructeur d'un objet Joueur pour l'IA
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux, il ajoute aussi les bateaux à la grille
 * @param[in]   bool vie
 */
Joueur_t::Joueur_t(bool _vie) {
    this->name = "IA";
    this->vie = _vie;

    Bateau_t B1 = plateau_allie.addBateauIA(nom_bateau::porte_avion);
    this->porte_avion.setBateau(B1);
    Bateau_t B2 = plateau_allie.addBateauIA(nom_bateau::croiseur);
    this->croiseur.setBateau(B2);
    Bateau_t B3 = plateau_allie.addBateauIA(nom_bateau::contre_torpilleur_1);
    this->contre_torpilleurs_1.setBateau(B3);
    Bateau_t B4 = plateau_allie.addBateauIA(nom_bateau::contre_torpilleur_2);
    this->contre_torpilleurs_2.setBateau(B4);
    Bateau_t B5 = plateau_allie.addBateauIA(nom_bateau::torpilleur);
    this->torpilleur.setBateau(B5);
    this->plateau_allie.display();
}

/**
 * @brief       Accesseur pour les plateaux de l'objet Joueur
 * @param[in]   int plateau (0 allie, 1 ennemi, autre plateau vide)
 * @return      Plateau_t
 */
Plateau_t Joueur_t::get_plateau(int plateau) const {
    Plateau_t plateau_vide;
    switch (plateau)
    {
        case 0:
            return this->plateau_allie;
            break;
        case 1:
            return this->plateau_ennemi;
            break;
        default:
            return plateau_vide;
            break;
    }
}

/**
 * @brief       Accesseur pour les bateaux de l'objet Joueur
 * @param[in]   int nb  
 * @return      Bateau_t
 */
Bateau_t Joueur_t::get_bateau(int nb) const {
    Bateau_t bateau_vide;
    switch (nb)
    {
        case nom_bateau::porte_avion:
            return this->porte_avion;
            break;
        case nom_bateau::croiseur:
            return this->croiseur;
            break;
        case nom_bateau::contre_torpilleur_1:
            return this->contre_torpilleurs_1;
            break;
        case nom_bateau::contre_torpilleur_2:
            return this->contre_torpilleurs_2;
            break;
        case nom_bateau::torpilleur:
            return this->torpilleur;
            break;
        default:
            return bateau_vide;
    }
}

/**
 * @brief       Méthode pour saisir les coordonnées des tirs
 * @details     La méthode permet de vérifier que les coordonnées sont bien valides
 * @param[in]   int* x,y
 */
void Joueur_t::saisie_tir(int* x, int* y) {
    char x_saisie = ' ';
    std::string y_saisie = "";
    bool flag = true;
    do {
        std::cout << "Saisie des coordonees du tir" << std::endl;
        std::cout << "Rentrer l'abscisse (lettre majuscule entre A et J) : ";
        std::cin >> x_saisie;
        while(!(x_saisie >= 'A' && x_saisie <= 'J')) {
            std::cout << "Incorrecte, ressaisir l'abscisse (lettre majuscule entre A et J) : ";
            std::cin >> x_saisie;
        }
        *x = ((x_saisie - 'A') + 1);
        std::cout << "Rentrer l'ordonnee (nombre entre 1 et 10) : ";
        std::cin >> y_saisie;
        while(y_saisie != "1" && y_saisie != "2" && y_saisie != "3" && y_saisie != "4" && y_saisie != "5" && y_saisie != "6" && y_saisie != "7" && y_saisie != "8" && y_saisie != "9" && y_saisie != "10") {
            std::cout << "Incorrecte, ressaisir l'ordonee (nombre entre 1 et 10) : ";
            std::cin >> y_saisie;
        }
        *y = stoi(y_saisie);
        Case_t case_enemie(plateau_ennemi.getCase(*x - 1, *y - 1));
        if(case_enemie.getState() != etat_t::eau) {
            std::cout << "Attention tu as deja tire ici ! Joisie une autre case : " << std::endl;
            flag = true;
        }
        else {
            flag = false;
        }
    }while(flag);
}

void Joueur_t::SaisieTirSDL(int *x, int *y)
{
    struct Input in;
	initStruct(&in);

    while(!in.quit)
    {
        updateEvent(&in);
    	if(in.mouse[SDL_BUTTON_LEFT] == SDL_TRUE)
	    {
    	    for(int i = 0; i < 100; i++)
    	    {
    	        if (in.x >= this->grid_ennemi[i].x && in.x <= (this->grid_ennemi[i].x + this->grid_ennemi[i].w)  
    	        	&& in.y > this->grid_ennemi[i].y && in.y < (this->grid_ennemi[i].y + this->grid_ennemi[i].h))
    	        {
    	            *y = (i / 10) + 1;
                	*x = (i % 10) + 1;
                	
                	Case_t case_enemie(plateau_ennemi.getCase(*x - 1, *y - 1));
                    if(case_enemie.getState() == etat_t::eau) in.quit = SDL_TRUE;
                }
    	    }
	    } 
    }
}

/**
 * @brief       Méthode pour tirer sur un joueur à partir de coordonnées
 * @param[in]   Joueur_t
 * @param[in]   int x,y
 * @return      bool si les coordonnées sont valides donc si tir
 */
void Joueur_t::tir(Joueur_t *j, int x, int y) {
    int result = j->check_tir(x, y);
    if(result == 5) {
        std::cout << "Rate !" << std::endl;
        plateau_ennemi.setCase(x, y, etat_t::rate);
        j->set_case_allie(x, y, etat_t::rate);
    }
    else{
        std::cout << "Touche !" << std::endl;
        plateau_ennemi.setCase(x, y, etat_t::touche);
        j->set_case_allie(x, y, etat_t::touche);
        if(j->check_bateau(result)) {
            std::cout << "Coule !" << std::endl;
            plateau_ennemi.addBateau(j->get_bateau(result));
            j->plateau_allie.addBateau(j->get_bateau(result));
        }
    }
}

void Joueur_t::tirSDL(SDL_Renderer *renderer, Joueur_t *j, int x, int y) {
    int result = j->check_tir(x, y);
    if(result == 5) {
        plateau_ennemi.setCase(x, y, etat_t::rate);
        j->set_case_allie(x, y, etat_t::rate);
        this->changeCaseSDL(renderer, x, y, etat_t::rate);
    }
    else {
        plateau_ennemi.setCase(x, y, etat_t::touche);
        j->set_case_allie(x, y, etat_t::touche);
        if(j->check_bateau(result)) {
            /*plateau_ennemi.addBateau(j->get_bateau(result));
            j->plateau_allie.addBateau(j->get_bateau(result));*/
            this->changeCaseSDL(renderer, x, y, etat_t::coule);
        }
        else this->changeCaseSDL(renderer, x, y, etat_t::touche);
    }
}

/**
 * @brief       Méthode pour tirer sur un joueur pour l'IA
 * @details     Les coordonnées sont générées aléatoirement par l'ordinateur
 * @param[in]   Joueur_t
 */
void Joueur_t::tir(Joueur_t *j) {
    int x = 0, y = 0;
    Case_t case_ennemi;
    do {
        do {
            srand(time(NULL));
            x = (rand() % 10);
            y = (rand() % 10);
        } while(!(y >= 0 && y <= 9 && x >= 0 && x <= 9));
        case_ennemi.setCase(plateau_ennemi.getCase(x, y));
    } while(case_ennemi.getState() != etat_t::eau);

    std::cout << "L'" << this->get_name() << " tire en " << (char)(x + 'A') << y + 1 << std::endl << std::endl;

    this->tir(j, x + 1, y + 1);
}
    
void Joueur_t::tirSDL(SDL_Renderer *renderer, Joueur_t *j){
    int x = 0, y = 0;
    int num_rect = 0;
    Case_t case_ennemi;
    do {
        do {
            srand(time(NULL));
            x = (rand() % 10);
            y = (rand() % 10);
        } while(!(y >= 0 && y <= 9 && x >= 0 && x <= 9));
        case_ennemi.setCase(plateau_ennemi.getCase(x, y));
    } while(case_ennemi.getState() != etat_t::eau);
    this->tir(j, x + 1, y + 1);
    
    num_rect = y * 10 + x;
    SDL_SetRenderDrawColor(renderer, 119, 136, 153, 100);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_RenderFillRect(renderer, &(j->grid_allie[num_rect]));
    SDL_RenderPresent(renderer);
    
}

/**
 * @brief       Méthode pour afficher les plateaux alliés et ennemis d'un joueur
 * @details     Pour afficher, appel du display de chaque plateau
 */
void Joueur_t::display() {
    std::cout << "Plateau de " << this->name << " : " << std::endl;
    plateau_allie.display();
    std::cout << std::endl << "Plateau de l'adversaire : " << std::endl;
    plateau_ennemi.display();
}

void Joueur_t::displaySDL(SDL_Renderer *renderer, int nb)
{
    SDL_printFond(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 229, 204, 255);
    
    if(nb == 0){
        SDL_RenderFillRect(renderer, &middle);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRects(renderer, this->grid_middle, 100);
        SDL_RenderPresent(renderer);  
    }
    else{
        SDL_RenderFillRect(renderer, &zone1);
        SDL_RenderFillRect(renderer, &zone2);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRects(renderer, this->grid_allie, 100);
        SDL_RenderDrawRects(renderer, this->grid_ennemi, 100);
        SDL_RenderPresent(renderer);
    }
}

/**
 * @brief       Méthode pour mettre à jour la vie d'un joueur
 * @details     MAJ de la vie si tous les bateaux ne sont plus vivants, pour cela bateau.getVivant()
 */
void Joueur_t::update_vie() {
    if(porte_avion.getVivant() || croiseur.getVivant() || torpilleur.getVivant() || contre_torpilleurs_1.getVivant() || contre_torpilleurs_2.getVivant()) {
        return;
    }
    else {
        this->set_vie(false);
        return;
    }
}

/**
 * @brief       Méthode pour vérifier si un tir touche un bateau
 * @param[in]   int x, y (coordonnée du tir)
 * @param[out]  int le type de bateau touché ou 5 si pas de bateau touché
 */
int Joueur_t::check_tir(int x, int y) {
    for(int i = 0; i < porte_avion.getLength(); i++) {
        Case_t temp(porte_avion.getCase(i));
        if(temp.getX() == x && temp.getY() == y) {
            porte_avion.setState(i, etat_t::touche);
            return nom_bateau::porte_avion;
        }
    }
    for(int i = 0; i < croiseur.getLength(); i++) {
        Case_t temp(croiseur.getCase(i));
        if(temp.getX() == x && temp.getY() == y) {
            croiseur.setState(i, etat_t::touche);
            return nom_bateau::croiseur;
        }
    }
    for(int i = 0; i < contre_torpilleurs_1.getLength(); i++) {
        Case_t temp(contre_torpilleurs_1.getCase(i));
        if(temp.getX() == x && temp.getY() == y) {
            contre_torpilleurs_1.setState(i, etat_t::touche);
            return nom_bateau::contre_torpilleur_1;
        }
    }
    for(int i = 0; i < contre_torpilleurs_2.getLength(); i++) {
        Case_t temp(contre_torpilleurs_2.getCase(i));
        if(temp.getX() == x && temp.getY() == y) {
            contre_torpilleurs_2.setState(i, etat_t::touche);
            return nom_bateau::contre_torpilleur_2;
        }
    }
    for(int i = 0; i < torpilleur.getLength(); i++) {
        Case_t temp(torpilleur.getCase(i));
        if(temp.getX() == x && temp.getY() == y) {
            torpilleur.setState(i, etat_t::touche);
            return nom_bateau::torpilleur;
        }
    }
    return 5;
}

/**
 * @brief       Méthode pour vérifier si un bateau touché est coulé
 * @param[in]   int type (le type de bateau touché)
 * @param[out]  bool true si coulé, false sinon
 */
bool Joueur_t::check_bateau(int type) {
    bool flag = true;
    switch (type) {
    case nom_bateau::porte_avion:
        for(int i = 0; i < porte_avion.getLength(); i++) {
            Case_t temp(porte_avion.getCase(i));
            if(temp.getState() == etat_t::bateau) {
                flag = false;
                i = 10;
            }
        }
        if(flag) {
            for(int i = 0; i < porte_avion.getLength(); i++) {
                porte_avion.setState(i, etat_t::coule);
            }
            porte_avion.setVivant(false);
        }
        break;
    case nom_bateau::croiseur:
        for(int i = 0; i < croiseur.getLength(); i++) {
            Case_t temp(croiseur.getCase(i));
            if(temp.getState() == etat_t::bateau) {
                flag = false;
                i = 10;
            }
        }
        if(flag) {
            for(int i = 0; i < croiseur.getLength(); i++) {
                croiseur.setState(i, etat_t::coule);
            }
            croiseur.setVivant(false);
        }
        break;
    case nom_bateau::contre_torpilleur_1:
        for(int i = 0; i < contre_torpilleurs_1.getLength(); i++) {
            Case_t temp(contre_torpilleurs_1.getCase(i));
            if(temp.getState() == etat_t::bateau) {
                flag = false;
                i = 10;
            }
        }
        if(flag) {
            for(int i = 0; i < contre_torpilleurs_1.getLength(); i++) {
                contre_torpilleurs_1.setState(i, etat_t::coule);
            }
            contre_torpilleurs_1.setVivant(false);
        }
        break;
    case nom_bateau::contre_torpilleur_2:
        for(int i = 0; i < contre_torpilleurs_2.getLength(); i++) {
            Case_t temp(contre_torpilleurs_2.getCase(i));
            if(temp.getState() == etat_t::bateau) {
                flag = false;
                i = 10;
            }
        }
        if(flag) {
            for(int i = 0; i < contre_torpilleurs_2.getLength(); i++) {
                contre_torpilleurs_2.setState(i, etat_t::coule);
            }
            contre_torpilleurs_2.setVivant(false);
        }
        break;
    case nom_bateau::torpilleur:
        for(int i = 0; i < torpilleur.getLength(); i++) {
            Case_t temp(torpilleur.getCase(i));
            if(temp.getState() == etat_t::bateau) {
                flag = false;
                i = 10;
            }
        }
        if(flag) {
            for(int i = 0; i < torpilleur.getLength(); i++) {
                torpilleur.setState(i, etat_t::coule);
            }
            torpilleur.setVivant(false);
        }
        break;
    default:
        break;
    }
    return flag;
}

/**
 * @brief       Méthode pour ajouter les bateaux sur le plateau allié
 * @details     Pour cela, utilisation de la méthode de plateau addBateau()
 */
void Joueur_t::add_flotte() {
    plateau_allie.addBateau(porte_avion);
    plateau_allie.addBateau(croiseur);
    plateau_allie.addBateau(torpilleur);
    plateau_allie.addBateau(contre_torpilleurs_1);
    plateau_allie.addBateau(contre_torpilleurs_2);
}


void Joueur_t::add_BoatSDL(SDL_Renderer *renderer, Bateau_t b, int grid)
{
    int xStart = 0, yStart = 0, xEnd = 0, yEnd = 0;
    int loop = 0;
    
    xStart = b.getCase1().getX();
    yStart = b.getCase1().getY();
        
    if(b.getNom_Bateau() == "Porte avion")
    {
        xEnd = b.getCase5().getX();
        yEnd = b.getCase5().getY();   
    }
    else if(b.getNom_Bateau() == "croiseur")
    {
        xEnd = b.getCase4().getX();
        yEnd = b.getCase4().getY();   
    }
    else if((b.getNom_Bateau() == "1er Contre torpilleur") || (b.getNom_Bateau() == "2eme Contre torpilleur"))
    {
        xEnd = b.getCase3().getX();
        yEnd = b.getCase3().getY();   
    }
    else if(b.getNom_Bateau() == "Torpilleur")
    {
        xEnd = b.getCase2().getX();
        yEnd = b.getCase2().getY();        
    }
    
    if(xStart == xEnd)
    {
        if(yStart > yEnd){
            int tmp = yStart;
            yStart = yEnd;
            yEnd = tmp;
        }
        for(int i = yStart; i <= yEnd; i++)
        {
            this->setCaseSDL(renderer, xStart, i, b.getNom_Bateau(), 'v', loop, grid);
            loop++;
        }
    }
    else
    {
        if(xStart > xEnd){
            int tmp = xStart;
            xStart = xEnd;
            xEnd = tmp;
        }
        for(int i = xStart; i <= xEnd; i++)
        {
            this->setCaseSDL(renderer, i, yStart, b.getNom_Bateau(), 'h', loop, grid);
            loop++;
        }
    }
}

std::string generatePATH(std::string name, char sens, int nb)
{
    char PATH[100];
    if(sens == 'v'){
        if(name == "Porte avion"){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/vertical/pa1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/vertical/pa2.bmp", 100);
                    break;
                case 2:
                    strncpy(PATH, "../boat_sdl/vertical/pa3.bmp", 100);
                    break;
                case 3:
                    strncpy(PATH, "../boat_sdl/vertical/pa4.bmp", 100);
                    break;
                case 4:
                    strncpy(PATH, "../boat_sdl/vertical/pa5.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
        else if(name == "croiseur"){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/vertical/croiseur1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/vertical/croiseur2.bmp", 100);
                    break;
                case 2:
                    strncpy(PATH, "../boat_sdl/vertical/croiseur3.bmp", 100);
                    break;
                case 3:
                    strncpy(PATH, "../boat_sdl/vertical/croiseur4.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
        else if((name == "1er Contre torpilleur") || (name == "2eme Contre torpilleur")){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/vertical/ct1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/vertical/ct2.bmp", 100);
                    break;
                case 2:
                    strncpy(PATH, "../boat_sdl/vertical/ct3.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
        else if(name == "Torpilleur"){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/vertical/t1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/vertical/t2.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
    }
    else{
        if(name == "Porte avion"){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/horizontal/pa1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/horizontal/pa2.bmp", 100);
                    break;
                case 2:
                    strncpy(PATH, "../boat_sdl/horizontal/pa3.bmp", 100);
                    break;
                case 3:
                    strncpy(PATH, "../boat_sdl/horizontal/pa4.bmp", 100);
                    break;
                case 4:
                    strncpy(PATH, "../boat_sdl/horizontal/pa5.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
        else if(name == "croiseur"){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/horizontal/croiseur1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/horizontal/croiseur2.bmp", 100);
                    break;
                case 2:
                    strncpy(PATH, "../boat_sdl/horizontal/croiseur3.bmp", 100);
                    break;
                case 3:
                    strncpy(PATH, "../boat_sdl/horizontal/croiseur4.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
        else if((name == "1er Contre torpilleur") || (name == "2eme Contre torpilleur")){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/horizontal/ct1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/horizontal/ct2.bmp", 100);
                    break;
                case 2:
                    strncpy(PATH, "../boat_sdl/horizontal/ct3.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
        else if(name == "Torpilleur"){
            switch(nb){
                case 0:
                    strncpy(PATH, "../boat_sdl/horizontal/t1.bmp", 100);
                    break;
                case 1:
                    strncpy(PATH, "../boat_sdl/horizontal/t2.bmp", 100);
                    break;
                default:
                    std::cout << "Error at " << __func__ << ":" << __LINE__ << std::endl;
            }
        }
    }
    return PATH;
}

void Joueur_t::setCaseSDL(SDL_Renderer *renderer, int x, int y, std::string name, char sens, int nb, int grid)
{
    char PATH[100];

    SDL_Texture *texture = NULL;
    int num_rect = 0;
    
    strncpy(PATH, generatePATH(name, sens, nb).c_str(), 100);
    
    texture = loadImage(PATH, renderer);
    num_rect = (y-1) * 10 + (x-1);
    
    if(grid == 0){    
        SDL_RenderSetViewport(renderer, &(this->grid_middle[num_rect]));
        SDL_RenderCopy(renderer, texture, NULL, NULL);    
        SDL_RenderPresent(renderer);
    }
    else{
        SDL_RenderSetViewport(renderer, &(this->grid_allie[num_rect]));
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    
    SDL_RenderSetViewport(renderer, NULL);
    if(NULL != texture)	SDL_DestroyTexture(texture);
}

void Joueur_t::changeCaseSDL(SDL_Renderer *renderer, int x, int y, etat_t etat)
{
    int num_rect = (y-1) * 10 + (x-1);
    SDL_Texture *texture = NULL;
    
    if(etat == etat_t::rate){    
        SDL_SetRenderDrawColor(renderer, 119, 136, 153, 100);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_RenderFillRect(renderer, &(this->grid_ennemi[num_rect]));
        SDL_RenderPresent(renderer);
    }
    else if(etat == etat_t::touche){
        char PATH[100] = "../etat/touche.bmp";
        texture = loadImage(PATH, renderer);
        SDL_RenderSetViewport(renderer, &(this->grid_ennemi[num_rect]));
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    else if(etat == etat_t::coule){
        char PATH[100] = "../etat/coule.bmp";
        texture = loadImage(PATH, renderer);
        SDL_RenderSetViewport(renderer, &(this->grid_ennemi[num_rect]));
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    
    SDL_RenderSetViewport(renderer, NULL);
    if(NULL != texture)	SDL_DestroyTexture(texture);
}



