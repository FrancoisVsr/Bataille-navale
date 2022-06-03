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
    plateau1.display();
    Bateau_t contre_torpilleur_1 = plateau1.addBateau(nom_bateau::contre_torpilleur_1);
    plateau1.display();
    Bateau_t contre_torpilleur_2 = plateau1.addBateau(nom_bateau::contre_torpilleur_2);
    plateau1.display();

    return 0;
}
