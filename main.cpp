#include <iostream>
#include "bateau.hpp"

void test_bateau(void){
    std::cout << "__func__" << std::endl;
    Bateau_t bat1(1);
    std::cout << bat1.getVivant() << std::endl;
}

int main(void)
{
    test_bateau();
    std::cout << "Ok ?" << std::endl;
    return 0;
}
