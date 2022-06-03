/**
 * @file        joueur.cpp
 * @brief       Fichier contenant la classe Joueur et ses fonctions
 * @author      Vasseur
 * @date        20/05/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include "joueur.hpp"

/*******************************
 *      Global definitions     *
 *******************************/


/*******************************
 *       Public methods        *
 *******************************/


/*******************************
 *       Private methods       *
 *******************************/


/**
 * @enum        nom de l'enum
 * @brief       Description de l'enum
 */

/**
 * @struct      nom de la structure
 * @brief       Description de la structure
 */

/**
 * @brief       Constructeur d'un objet Joueur pour l'IA
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux
 */
Joueur_t::Joueur_t() {
    int x;
    int y;
    char dir;

    this->name = "IA";
    this->vie = true;

    Plateau_t plateau_allie;
    this->plateau_allie = plateau_allie;

    Plateau_t plateau_ennemi;
    this->plateau_allie = plateau_ennemi;


    for(int i = 0; i < 5; i++) {
        do {
            srand(time(NULL));
            x = (rand() % 10) + 1;
            y = (rand() % 10) + 1;
            dir = (rand() % 4);
            if(dir == 0) dir = 'g';
            else if(dir == 1) dir = 'b';
            else if(dir == 2) dir = 'd';
            else dir = 'h';

            Bateau_t new_bateau(i, x, y, dir);
        } while(1);

        switch(i) {
            case nom_bateau::porte_avion:
                this->porte_avion = new_bateau;
                break;
            case nom_bateau::croiseur:
                this->croiseur = new_bateau;
                break;
            case nom_bateau::contre_torpilleur_1:
                this->contre_torpilleurs_1 = new_bateau;
                break;
            case nom_bateau::contre_torpilleur_2:
                this->contre_torpilleurs_2 = new_bateau;
                break;
            case nom_bateau::torpilleur:
                this->torpilleur = new_bateau;
                break;
            default:
                break;
        }
    }
}

/**
 * @brief       Constructeur d'un objet Joueur
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux
 */
Joueur_t::Joueur_t(std::string name_p) {
    this->name = name_p;
    this->vie = true;

    Plateau_t plateau_allie;
    this->plateau_allie = plateau_allie;

    Plateau_t plateau_ennemi;
    this->plateau_allie = plateau_ennemi;


    Bateau_t porte_avion(nom_bateau::porte_avion);
    this->porte_avion = porte_avion;
    Bateau_t croiseur(nom_bateau::croiseur);
    this->croiseur = croiseur;
    Bateau_t contre_torpilleurs_1(nom_bateau::contre_torpilleur_1);
    this->contre_torpilleurs_1 = contre_torpilleurs_1;
    Bateau_t contre_torpilleurs_2(nom_bateau::contre_torpilleur_2);
    this->contre_torpilleurs_2 = contre_torpilleurs_2;
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
 * @param       int plateau (0 allie, 1 ennemi, autre plateau vide)
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
 * @return
 */
void Joueur_t::set_vie(bool life) {
    this->vie = life;
}
void Joueur_t::set_case_allie(int x, int y, int etat) {
    plateau_allie.setCase(x, y, etat);
}


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

void Joueur_t::display() {
    std::cout << "Plateau de " << this->name << " : " << std::endl;
    plateau_allie.display();
    std::cout << std::endl << "Plateau de l adversaire : " << std::endl;
    plateau_ennemi.display();
}

void Joueur_t::saisie_tir(int* x, int* y) {

}

void Joueur_t::update_vie() {
    if(porte_avion.getVivant() || croiseur.getVivant() || torpilleur.getVivant() || contre_torpilleurs_1.getVivant() || contre_torpilleurs_2.getVivant()) {
        return;
    }
    else {
        this->set_vie(false);
        return;
    }
}

void Joueur_t::add_flotte() {
    plateau_allie.addBateau(porte_avion);
    plateau_allie.addBateau(croiseur);
    plateau_allie.addBateau(torpilleur);
    plateau_allie.addBateau(contre_torpilleurs_1);
    plateau_allie.addBateau(contre_torpilleurs_2);
}

bool Joueur_t::check_bateau() {
    return true;
}

/**
 * @brief       Destructeur d'un objet Joueur
 */
Joueur_t::~Joueur_t() {
}