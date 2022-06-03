#include <iostream>

#include <vector>
#include "case.h"
#include "plateau.h"
#include "bateau.h"


int main() {

    Plateau_t plateau1;
    plateau1.display();
    //plateau1.setCase(3, 3, 4);

    Bateau_t porte_avion = plateau1.addBateau(nom_bateau::porte_avion);

    //Bateau_t bateau0(0, plateau1); //La saisie des valeurs se fait directement lors de l'appelle du constructeur
    //plateau1.addBateau(bateau0);
    plateau1.display();



    return 0;
}
