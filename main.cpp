#include <iostream>

#include <vector>
#include "case.h"
#include "plateau.h"
#include "bateau.h"


int main() {

    Plateau_t plateau1;
    plateau1.display();
    //plateau1.setCase(3, 3, 4);

    Bateau_t bateau0(0, plateau1); //La saisie des valeurs se fait directement lors de l'appelle du constructeur
    plateau1.addBateau(bateau0);
    plateau1.display();

    Bateau_t bateau1(1, plateau1);
    plateau1.addBateau(bateau1);
    plateau1.display();

    Bateau_t bateau2(2, plateau1);
    plateau1.addBateau(bateau2);
    plateau1.display();


    return 0;
}
