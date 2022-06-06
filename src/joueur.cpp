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
 * @brief       Constructeur d'un objet Joueur
 * @details     Le constructeur de la classe joueur créé et initialise les plateaux et bateaux
 */
Joueur_t::Joueur_t(std::string name_p) {
    this->name = name_p;
    this->vie = true;

    std::cout << "Saisie du porte-avion : " << std::endl;
    Bateau_t B1(plateau_allie.addBateau(nom_bateau::porte_avion));
    this->porte_avion.setBateau(B1);
    std::cout << "Saisie du croiseur : " << std::endl;
    Bateau_t B2(plateau_allie.addBateau(nom_bateau::croiseur));
    this->croiseur.setBateau(B2);
    std::cout << "Saisie du premier contretorpilleur : " << std::endl;
    Bateau_t B3(plateau_allie.addBateau(nom_bateau::contre_torpilleur_1));
    this->contre_torpilleurs_1.setBateau(B3);
    std::cout << "Saisie du deuxieme contre torpilleur : " << std::endl;
    Bateau_t B4(plateau_allie.addBateau(nom_bateau::contre_torpilleur_2));
    this->contre_torpilleurs_2.setBateau(B4);
    std::cout << "Saisie du torpilleur : " << std::endl;
    Bateau_t B5(plateau_allie.addBateau(nom_bateau::torpilleur));
    this->torpilleur.setBateau(B5);
    // this->add_flotte();
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

void Joueur_t::tir(Joueur_t *j, int x, int y) {
    int result = j->check_tir(x, y);
    if(result == 5) {
        std::cout << "Rate !" << std::endl;
        plateau_ennemi.setCase(x, y, etat_t::rate);
        j->set_case_allie(x, y, etat_t::rate);
    }
    else {
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

void Joueur_t::display() {
    std::cout << "Plateau de " << this->name << " : " << std::endl;
    plateau_allie.display();
    std::cout << std::endl << "Plateau de l adversaire : " << std::endl;
    plateau_ennemi.display();
}

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

void Joueur_t::update_vie() {
    if(porte_avion.getVivant() || croiseur.getVivant() || torpilleur.getVivant() || contre_torpilleurs_1.getVivant() || contre_torpilleurs_2.getVivant()) {
        return;
    }
    else {
        this->set_vie(false);
        return;
    }
}

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