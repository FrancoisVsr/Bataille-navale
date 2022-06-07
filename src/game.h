/**
 * @author      Auffray, Vasseur, Fave, Gauthier
 * @date        25/05/2022
 * @version     v0.01
 * @brief       Librairie pour les fonctions de jeux
 */

#ifndef GAME_H
#define GAME_H


/**
 * @fn void start()
 * @brief affiche le nom du jeu au lancement
 * */
void start();

/**
 * @fn int menu()
 * @brief affiche le menu du jeu pour le choix du mode
 * @return choix de l'utilisateur, entier 1 pour un joueur ou 2 pour deux joueurs
 */
int menu();

/**
 * @fn bool GameLoop_1_player()
 * @brief boucle de jeu pour jouer contre l'ordinateur
 * @return gagnant de la partie (joueur1 ou IA)
 */
bool GameLoop_1_player();

/**
 * @fn bool GameLoop_2_player()
 * @brief boucle de jeu pour 2 joueurs
 * @return gagnant de la partie (joueur1 ou joueur2)
 */
bool GameLoop_2_player();

/**
 * @fn void clean_display()
 * @brief permet de clean le terminal pour l'affichage
 */
void clean_display();

#endif