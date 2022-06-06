/**
 * @file        case.cpp
 * @author      Vasseur, Gauthier, Auffray, Fave
 * @date        20/05/2022
 * @version     v0.01
 * @brief       
 */

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