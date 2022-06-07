/**
 * @author      Auffray, Vasseur, Fave, Gauthier
 * @date        25/05/2022
 * @version     v0.01
 * @brief       Librairie pour les fonctions de jeux
 */

#ifndef GAME_H
#define GAME_H

// Fonctions qui gère le déroulement d'une partie

void start();
int menu();
bool GameLoop_1_player();
bool GameLoop_2_player();
void clean_display();

#endif