/**
 * @author      Vasseur
 * @date        30/07/2022
 * @version     v0.01
 * @brief       library for graphic interface
 */

#ifndef INTERFACE_H
#define INTERFACE_H

/*******************************
 *          Includes           *
 *******************************/
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************
 *      Global definitions     *
 *******************************/
#define SDL_BUTTON_LEFT     1
#define SDL_BUTTON_MIDDLE   2
#define SDL_BUTTON_RIGHT    3
#define SDL_BUTTON_X1       4
#define SDL_BUTTON_X2       5  

/**
 * @struct      Input
 * @brief       Il s'agit d'une structure pour gérer les évènements de la fenêtre
 */
struct Input
{
    SDL_bool key[SDL_NUM_SCANCODES];
    SDL_bool quit;
    int x, y, xrel, yrel;
    int xwheel, ywheel;
    SDL_bool mouse[6];
};

/**
 * @struct      carre
 * @brief       Pour gérer un rectangle de couleur
 */
struct carre {
   SDL_Rect rect;
   Uint32 couleur;
};


/*******************************
 *       Public methods        *
 *******************************/
/**
 * @brief       Function to play a game with Ihm
 */
int mainInterface();

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer);

void transformClicToCoordandDir(int *x, int *y, char *dir);

int SDL_printFond(SDL_Renderer *renderer);

#endif /* INTERFACE_H */
