#ifndef CASE_H
#define CASE_H


enum etat_t { 
    eau = 0,
    rate = 1,
    touche = 2,
    bateau = 3,
    coule = 4
};

class Case_t {

    protected:
        int x;
        int y;
        int etat;

    public:
        //Constructeurs
        Case_t();
        Case_t(int, int);
        Case_t(int, int, int);

        //Accesseurs
        int getX() const {return this->x;}
        int getY() const {return this->y;}
        int getEtat() const {return this->etat;}

        //Setteurs
        void setX(int _x) {this->x = _x;}
        void setY(int _y) {this->y = _y;}
        void setEtat(int _etat) {this->etat = _etat;}
};

#endif //CASE_H