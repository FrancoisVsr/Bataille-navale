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

/*******************************
 *       Public methods        *
 *******************************/

/**
 * @brief       Constructeur d'un objet Joueur pour l'IA
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux, il ajoute aussi les bateaux à la grille
 */
Joueur_t::Joueur_t(bool vie) {
    this->name = "IA";
    this->vie = vie;

    Plateau_t plateau_allie;
    this->plateau_allie = plateau_allie;

    Plateau_t plateau_ennemi;
    this->plateau_allie = plateau_ennemi;

    Bateau_t porte_avion = plateau_allie.addBateauIA(nom_bateau::porte_avion);
    this->porte_avion = porte_avion;
    Bateau_t croiseur = plateau_allie.addBateauIA(nom_bateau::croiseur);
    this->croiseur = croiseur;
    Bateau_t contre_torp_1 = plateau_allie.addBateauIA(nom_bateau::contre_torpilleur_1);
    this->contre_torpilleurs_1 = contre_torp_1;
    Bateau_t contre_torp_2 = plateau_allie.addBateauIA(nom_bateau::contre_torpilleur_2);
    this->contre_torpilleurs_2 = contre_torp_2;
    Bateau_t torpilleur = plateau_allie.addBateauIA(nom_bateau::torpilleur);
    this->torpilleur = torpilleur;
    this->add_flotte();
}

/**
 * @brief       Constructeur d'un objet Joueur
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux, il ajoute aussi les bateaux à la grille
 */
Joueur_t::Joueur_t(std::string name_p) {
    this->name = name_p;
    this->vie = true;

    Plateau_t plateau_allie;
    this->plateau_allie = plateau_allie;

    Plateau_t plateau_ennemi;
    this->plateau_allie = plateau_ennemi;

    std::cout << "Saisie du porte-avion : " << std::endl;
    Bateau_t porte_avion(nom_bateau::porte_avion);
    this->porte_avion = porte_avion;
    std::cout << "Saisie du croiseur : " << std::endl;
    Bateau_t croiseur(nom_bateau::croiseur);
    this->croiseur = croiseur;
    std::cout << "Saisie du premier contretorpilleur : " << std::endl;
    Bateau_t contre_torpilleurs_1(nom_bateau::contre_torpilleur_1);
    this->contre_torpilleurs_1 = contre_torpilleurs_1;
    std::cout << "Saisie du deuxieme contre torpilleur : " << std::endl;
    Bateau_t contre_torpilleurs_2(nom_bateau::contre_torpilleur_2);
    this->contre_torpilleurs_2 = contre_torpilleurs_2;
    std::cout << "Saisie du torpilleur : " << std::endl;
    Bateau_t torpilleur(nom_bateau::torpilleur);
    this->torpilleur = torpilleur;
    this->add_flotte();
}

/**
 * @brief       Accesseur pour la vie de l'objet Joueur
 * @return      bool
 */
bool Joueur_t::get_vie() const {
    return vie;
};

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
 * @brief       Setter pour la vie de l'objet Joueur
 * @param[in]   bool life
 */
void Joueur_t::set_vie(bool life) {
    this->vie = life;
}

/**
 * @brief       Setter pour une case du plateau allie du joueur
 * @param[in]   int x,y,etat
 */
void Joueur_t::set_case_allie(int x, int y, int etat) {
    plateau_allie.setCase(x, y, etat);
}

/**
 * @brief       Méthode pour tirer sur un joueur à partir de coordonnées
 * @param[in]   Joueur_t
 * @param[in]   int x,y
 * @return      bool si les coordonnées sont valides donc si tir
 */
bool Joueur_t::tir(Joueur_t *j, int x, int y) {
    Plateau_t plateau_vise(j->get_plateau(0));
    Case_t case_vise(plateau_vise.getCase(x, y));
    Case_t case_enemie(plateau_ennemi.getCase(x, y));
    if((x >= 1) && (x <= 10) && (y >= 1) && (y <= 10))
    {
        if(case_enemie.getState() == etat_t::eau)
        {
            switch(case_vise.getState())
            {
                case etat_t::bateau:
                    std::cout << "Un bateau a été touché !" << std::endl << std::endl;
                    plateau_ennemi.setCase(x, y, etat_t::touche);
                    j->set_case_allie(x, y, etat_t::touche);
                    std::cout << "Un bateau a été coulé !" << std::endl << std::endl;
                    break;
                case etat_t::eau:
                    std::cout << "Sheh ! Essaie encore !" << std::endl << std::endl;
                    plateau_ennemi.setCase(x, y, etat_t::rate);
                    j->set_case_allie(x, y, etat_t::rate);
                    break;
                default:
                    std::cerr << "error in state case, x = " << x << "\ty = " << y << std::endl;
                    break;
            }
            j->plateau_allie.display();
            std::cout << std::endl << std::endl;
            j->plateau_ennemi.display();
            std::cout << std::endl << std::endl;
            return true;
        }
        else
        {
            std::cout << "Sale bigleux sans mémoire t'as déjà tiré ici !" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Les coordonnées doivent être comprises entre 1 et 10 !" << std::endl;
        return false;
    }
}

/**
 * @brief       Méthode pour tirer sur un joueur pour l'IA
 * @details     Les coordonnées sont générées aléatoirement par l'ordinateur
 * @param[in]   Joueur_t
 */
void Joueur_t::tir(Joueur_t *j) {
    int x,y;
    int state = etat_t::bateau;

    do {
        do {
            srand(time(NULL));
            x = (rand() % 10) + 1;
            y = (rand() % 10) + 1;
        } while((!(y >= 1 && y <= 10)) || (!(x >= 1 && x <= 10)));
        x-=1;
        y-=1;
        Case_t case_ennemi(plateau_ennemi.getCase(x,y));
        state = case_ennemi.getState();
    } while (state != etat_t::eau);

    std::cout << "L'" << this->get_name() << " tire en " << (char)(x + 65) << y << std::endl << std::endl;

    Plateau_t plateau_vise(j->get_plateau(0));
    Case_t case_vise(plateau_vise.getCase(x, y));
    Case_t case_enemie(plateau_ennemi.getCase(x, y));

    switch(case_vise.getState())
    {
        case etat_t::bateau:
            std::cout << "Un bateau a été touché !" << std::endl << std::endl;
            plateau_ennemi.setCase(x, y, etat_t::touche);
            j->set_case_allie(x, y, etat_t::touche);
            std::cout << "Un bateau a été coulé !" << std::endl << std::endl;
            break;
        case etat_t::eau:
            std::cout << "Sheh ! Essaie encore !" << std::endl << std::endl;
            plateau_ennemi.setCase(x, y, etat_t::rate);
            j->set_case_allie(x, y, etat_t::rate);
            break;
        default:
            std::cerr << "error in state case, x = " << x << "\ty = " << y << std::endl;
            break;
    }
    std::cout << std::endl;
}

/**
 * @brief       Méthode pour afficher les plateaux alliés et ennemis d'un joueur
 * @details     Pour afficher, appel du display de chaque plateau
 */
void Joueur_t::display() {
    std::cout << "Plateau de " << this->name << " : " << std::endl;
    plateau_allie.display();
    std::cout << std::endl << "Plateau de l adversaire : " << std::endl;
    plateau_ennemi.display();
}

/**
 * @brief       Méthode pour afficher un ou deux plateaux de l'IA
 * @param[in]   int choix (0 pour ennemi et 1 pour les deux)
 */
void Joueur_t::displayIA(int choix) {
    if(choix == 1) {
       std::cout << std::endl << "Plateau de l adversaire : " << std::endl;
    plateau_ennemi.display(); 
    }
    else {
        std::cout << "Plateau de " << this->name << " : " << std::endl;
    plateau_allie.display();
        std::cout << std::endl << "Plateau de l adversaire : " << std::endl;
    plateau_ennemi.display();
    }
}

/**
 * @brief       Méthode pour saisir les coordonnées des tirs
 * @details     La méthode permet de vérifier que les coordonnées sont bien valides
 * @param[in]   int *x,y
 */
void Joueur_t::saisie_tir(int* x, int* y) {
    char x_saisie = ' ';
    std::string y_saisie = "";
    bool flag = true;
    do {
        std::cout << "Saisie des coordonees du tir" << std::endl;
        std::cout << "Rentrer l abscisse (lettre majuscule entre A et J) : ";
        std::cin >> x_saisie;
        while(!(x_saisie >= 'A' && x_saisie <= 'J')) {
            std::cout << "Incorrecte, ressaisir abscisse (lettre majuscule entre A et J) : ";
            std::cin >> x_saisie;
        }
        *x = ((x_saisie - 'A') + 1);
        std::cout << "Rentrer l ordonnee (nombre entre 1 et 10) : ";
        std::cin >> y_saisie;
        while(y_saisie != "1" && y_saisie != "2" && y_saisie != "3" && y_saisie != "4" && y_saisie != "5" && y_saisie != "6" && y_saisie != "7" && y_saisie != "8" && y_saisie != "9" && y_saisie != "10") {
            std::cout << "Incorrecte, ressaisir ordonee (nombre entre 1 et 10) : ";
            std::cin >> y_saisie;
        }
        *y = stoi(y_saisie);
        Case_t case_enemie(plateau_ennemi.getCase(*x, *y));
        if(case_enemie.getState() != etat_t::eau) {
            std::cout << "Attention tu as deja tire ici ! Joisie une autre case : " << std::endl;
            flag = true;
        }
        else {
            flag = false;
        }
    }while(flag);
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

/**
 * @brief       Destructeur d'un objet Joueur
 */
Joueur_t::~Joueur_t() {
}