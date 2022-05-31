#include <iostream>
#include "bateau.hpp"
#include "case.h"

void test_bateau(void){
    std::cout << "__func__" << std::endl;
    Bateau_t bat1(nom_bateau::croiseur);
    std::cout << bat1.getNom_Bateau() << std::endl;
    Case_t cas1(bat1.getCase2());
    std::cout << cas1.getX() << std::endl;
    std::cout << cas1.getY() << std::endl;
}

int main(void)
{
    test_bateau();
    return 0;
}
