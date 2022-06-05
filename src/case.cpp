#include <cstdlib>
#include <iostream>
#include "case.h"

Case_t::Case_t() {
    this->x = 0;
    this->y = 0;
    this->state = 0;
}

Case_t::Case_t(int x, int y) {
    this->x = x;
    this->y = y;
    this->state = 0;
}

Case_t::Case_t(int x, int y, int state) {
    this->x = x;
    this->y = y;
    this->state = state;
}

void Case_t::setCase(const Case_t& new_case) {
    this->x = new_case.getX();
    this->y = new_case.getY();
    this->state = new_case.getState();
}