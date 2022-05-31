#include <cstdlib>
#include <iostream>
#include "case.h"

Case_t::Case_t(int x, int y) {
    this->x = x;
    this->y = y;
    this->etat = "    ";
}

Case_t::Case_t(int x, int y, std::string etat) {
    this->x = x;
    this->y = y;
    this->etat = etat;
}