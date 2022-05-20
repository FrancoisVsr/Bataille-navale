/*******************************************************************************************
*   Projet de bataille navale SMP SEC 2024
*
*   Partie de programmation pour la class bateau 
*
*   Jonathan
********************************************************************************************/

//bibliotheques
#include <iostream>

using namespace std;

/* ce que l on veut dans Bateau 

variable longueur 
bool : vie 
tab coord [lxL]
tab touche 
*/

class bateau
{
private:
int longueur_bateau;
bool vie;
int tab_coord[];
int tab_touche[];

public:
	bateau();
	~bateau();
};


int main(void)
{
    cout << "Hello World ! " << endl;
    return 0;
}
