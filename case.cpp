#include <cstdlib>
#include <iostream>
#include "case.h"

Case_t::Case_t() {
    this->x = 0;
    this->y = 0;
    this->etat = 0;
}

Case_t::Case_t(int _x, int _y) {
    this->x = _x;
    this->y = _y;
    this->etat = 0;
}

Case_t::Case_t(int _x, int _y, int _etat) {
    this->x = _x;
    this->y = _y;
    this->etat = _etat;
}