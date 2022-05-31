#ifndef CASE_H
#define CASE_H

#include <string>

class Case_t {

    protected:
        int x;
        int y;
        int state;
        
    public:
        //Constructeurs
        Case_t();
        Case_t(int, int);
        Case_t(int, int, int);

        //Accesseurs
        int getX() const { return this->x;}
        int getY() const { return this->y;}
        int getState() const { return this->state;}

        //Setteurs
        void setX(int x) { this->x = x;}
        void setY(int y) { this->y = y;}
        void setState(int state) { this->state = state;}
};

#endif