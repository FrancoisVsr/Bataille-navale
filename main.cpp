#include <iostream>

#include <vector>
#include "case.h"
#include "plateau.h"


int main() {

    Plateau_t plateau1;
    plateau1.display();

    plateau1.setCase(3, 3, 4);
    plateau1.display();
    

    return 0;
}
