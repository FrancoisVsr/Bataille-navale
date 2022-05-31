#ifndef CASE_H
#define CASE_H

#include <string>

enum etat { 
    eau = 0,
    vague = 1,
    touche = 2,
    occupe = 3,
    coule = 4
};

class Case_t {

    protected:
        int x;
        int y;
        std::string etat;
        

    public:
        //Constructeurs
        Case_t();
        Case_t(int, int);
        Case_t(int, int, std::string);

        //Accesseurs
        int getX() const { return this->x;}
        int getY() const { return this->y;}
        std::string getEtat() const { return this->etat;}

        //Setteurs
        void setX(int x) { this->x = x;}
        void setY(int y) { this->y = y;}
        void setEtat(int etat) { this->etat = etat;}
};

#endif //CASE_H