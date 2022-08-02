/**
 * @file        interface.c
 * @brief       Fichier pour créer et gérer l'interface graphique
 * @author      Vasseur
 * @date        30/07/2022
 * @version     v0.01
 */

/*******************************
 *          Includes           *
 *******************************/
#include "interface.h"
#include "plateau.h"
#include "joueur.hpp"


#include <iostream>

/*******************************
 *       Private variable      *
 *******************************/
SDL_Rect grid_middle[100];

/*******************************
 *       Private methods        *
 *******************************/
void initStruct(struct Input *input)
{
	input->quit = SDL_FALSE;
	for(int i = 0; i < SDL_NUM_SCANCODES; i++)
	{
		input->key[i] = SDL_FALSE;
	}
	for(int i = 0; i < 6; i++)
	{
		input->mouse[i] = SDL_FALSE;
	}
	
}

void updateEvent(struct Input *input)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {   
        if(event.type == SDL_QUIT)
            input->quit = SDL_TRUE;
        else if(event.type == SDL_KEYDOWN)
            input->key[event.key.keysym.scancode] = SDL_TRUE;
        else if(event.type == SDL_KEYUP)
            input->key[event.key.keysym.scancode] = SDL_FALSE;
        else if(event.type == SDL_MOUSEMOTION)
        {
            input->x = event.motion.x;
            input->y = event.motion.y;
            input->xrel = event.motion.xrel;
            input->yrel = event.motion.yrel;
        }
        else if(event.type == SDL_MOUSEWHEEL)
        {
            input->xwheel = event.wheel.x;
            input->ywheel = event.wheel.y;
        }
        else if(event.type == SDL_MOUSEBUTTONDOWN)
              input->mouse[event.button.button] = SDL_TRUE;
        else if(event.type == SDL_MOUSEBUTTONUP)
            input->mouse[event.button.button] = SDL_FALSE;
        
    }
}

int setWindowColor(SDL_Renderer *renderer, SDL_Color color)
{
    if(SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a) < 0)
        return -1;
    if(SDL_RenderClear(renderer) < 0)
        return -1;
    return 0;  
}

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h)
{
    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
    if(0 != SDL_CreateWindowAndRenderer(w, h, (SDL_WINDOW_SHOWN | SDL_WINDOW_MINIMIZED), window, renderer))
    {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return -1;
    }
    return 0;
}

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
    SDL_Surface *tmp = NULL; 
    SDL_Texture *texture = NULL;
    tmp = SDL_LoadBMP(path);
    if(NULL == tmp)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        return NULL;
    }
    texture = SDL_CreateTextureFromSurface(renderer, tmp);
    SDL_FreeSurface(tmp);
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        return NULL;
    }
    return texture;
}

int printMenu(SDL_Renderer *renderer)
{
	char PATH_LOGO[80] = "/home/etud/Documents/Bataille-navale/pic_sdl/menu.bmp";
	char PATH_TITLE[80] = "/home/etud/Documents/Bataille-navale/pic_sdl/title.bmp";
	char PATH_CHOICE[80] = "/home/etud/Documents/Bataille-navale/pic_sdl/choice.bmp";
	SDL_Texture *texture = NULL;
	SDL_Rect menu = {433, 200, 500, 468};
	SDL_Rect title = {133, 50, 1100, 100};
   	SDL_Rect btn_OnePlayer = {0,0,500,100};
   	SDL_Rect btn_TwoPlayer = {0,183, 500, 100};
   	SDL_Rect btn_Quit = {0, 368, 500, 100};

	struct Input in;
	initStruct(&in);

	/* fond d'écran du menu */
	texture = loadImage(PATH_LOGO, renderer);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderSetViewport(renderer, &title);
	texture = loadImage(PATH_TITLE, renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
   	SDL_RenderSetViewport(renderer, &menu);
   	SDL_RenderFillRect(renderer, &btn_OnePlayer);
   	SDL_RenderFillRect(renderer, &btn_TwoPlayer);
   	SDL_RenderFillRect(renderer, &btn_Quit);
	texture = loadImage(PATH_CHOICE, renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
   	
   	SDL_RenderPresent(renderer);
   	
   	if(NULL != texture)	SDL_DestroyTexture(texture);
   	
   	int numero_clique = 0;
   	while(!in.quit)
	{
    	updateEvent(&in);
    	if(in.mouse[SDL_BUTTON_LEFT] == SDL_TRUE)
    	{
    	    if (in.x >= (btn_OnePlayer.x + menu.x) 
    	    	&& in.x <= (btn_OnePlayer.x+btn_OnePlayer.w + menu.x)
    	    	&& in.y > (btn_OnePlayer.y + menu.y)
    	    	&& in.y < (btn_OnePlayer.y+btn_OnePlayer.h + menu.y))
    	    {
            	numero_clique = 0;
            	in.quit = SDL_TRUE;
            }
            else if(in.x >= (btn_TwoPlayer.x + menu.x) 
            		&& in.x <= (btn_TwoPlayer.x+btn_TwoPlayer.w + menu.x) 
            		&& in.y > (btn_TwoPlayer.y + menu.y)
            		&& in.y < (btn_TwoPlayer.y+btn_TwoPlayer.h + menu.y))
            {
            	numero_clique = 1;
            	in.quit = SDL_TRUE;
            }
            else if(in.x >= (btn_Quit.x + menu.x) 
            		&& in.x <= (btn_Quit.x+btn_Quit.w + menu.x) 
            		&& in.y > (btn_Quit.y + menu.y)
            		&& in.y < (btn_Quit.y+btn_Quit.h + menu.y))
            {
            	numero_clique = 2;
                in.quit = SDL_TRUE;
            }
    	}
	}
	SDL_RenderSetViewport(renderer, NULL);
	return numero_clique;
}

int print1Grid(SDL_Renderer *renderer)
{
    SDL_printFond(renderer);
    SDL_Rect zone = {433, 134, 500, 500};
    SDL_SetRenderDrawColor(renderer, 255, 229, 204, 255);
    SDL_RenderFillRect(renderer, &zone);
    size_t i = 0;
    int column = 0;
    for(i = 0; i < 100; i++)
    {
        if(((i % 10)  == 0) && (i != 0)) column++;
        grid_middle[i].w = 50;
        grid_middle[i].h = 50;
        grid_middle[i].x = 50*(i % 10) + zone.x;
        grid_middle[i].y = 50*column + zone.y;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRects(renderer, grid_middle, 100);
    
    SDL_RenderSetViewport(renderer, NULL);
    SDL_RenderPresent(renderer);
    return 0;
}

void transformClicToCoordandDir(int *x, int *y, char *dir)
{
    struct Input in;
	initStruct(&in);

    while(!in.quit)
    {
        updateEvent(&in);
    	if(in.mouse[SDL_BUTTON_LEFT] == SDL_TRUE)
	    {
    	    for(int i = 0; i < 100; i++)
    	    {
    	        if (in.x >= grid_middle[i].x && in.x <= (grid_middle[i].x + grid_middle[i].w)  
    	        	&& in.y > grid_middle[i].y && in.y < (grid_middle[i].y + grid_middle[i].h))
    	        {
    	            *y = (i / 10);
                	*x = (i % 10);
                	in.quit = SDL_TRUE;
                }
    	    }
	    } 
    }
    in.quit = SDL_FALSE;
    
    while(!in.quit)
    {
        updateEvent(&in);
    	if(in.key[SDL_SCANCODE_DOWN] == SDL_TRUE)
	    {
            *dir = 'b';
            in.quit = SDL_TRUE;
	    }
	    else if(in.key[SDL_SCANCODE_UP] == SDL_TRUE)
	    {
	        *dir = 'h';
	        in.quit = SDL_TRUE;
	    }
	    else if(in.key[SDL_SCANCODE_LEFT] == SDL_TRUE)
	    {
	        *dir = 'g';
	        in.quit = SDL_TRUE;
	    }
	    else if(in.key[SDL_SCANCODE_RIGHT] == SDL_TRUE)
	    {
	        *dir = 'd';
	        in.quit = SDL_TRUE;
	    }
    }   
}

void transformClicToCoord(int *x, int *y)
{
    struct Input in;
	initStruct(&in);

    while(!in.quit)
    {
        updateEvent(&in);
    	if(in.mouse[SDL_BUTTON_LEFT] == SDL_TRUE)
	    {
    	    for(int i = 0; i < 100; i++)
    	    {
    	        if (in.x >= grid_middle[i].x && in.x <= (grid_middle[i].x + grid_middle[i].w)  
    	        	&& in.y > grid_middle[i].y && in.y < (grid_middle[i].y + grid_middle[i].h))
    	        {
    	            *y = (i / 10);
                	*x = (i % 10);
                	in.quit = SDL_TRUE;
                }
    	    }
	    } 
    } 
}

int SDL_printFond(SDL_Renderer *renderer)
{
	char PATH_LOGO[80] = "/home/etud/Documents/Bataille-navale/pic_sdl/menu.bmp";
	SDL_Texture *texture = NULL;
	
	struct Input in;
	initStruct(&in);

	/* fond d'écran pendant la partie */
	texture = loadImage(PATH_LOGO, renderer);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
   	SDL_RenderPresent(renderer);
   	
   	if(NULL != texture)	SDL_DestroyTexture(texture);
   	return 0;
}

bool GameLoop_2_playerSDL(SDL_Renderer *renderer) {
    Joueur_t joueur1(renderer);
    Joueur_t joueur2(renderer);
    /*do {
        std::cout << "A " << joueur1.get_name() << " de jouer, appuyer sur entrer pour afficher les plateaux" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        while(std::cin.get() != '\n'){;}
        joueur1.display();
        int x = 0;
        int y = 0;
        joueur1.saisie_tir(&x, &y);
        joueur1.tir(&joueur2, x, y);
        joueur2.update_vie();
        std::cout << "Resultat plateau ennemi : " << std::endl;
        joueur1.get_plateau(1).display();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Fin du tour de " << joueur1.get_name() << ", appuyer sur entrer pour cacher les plateaux" << std::endl;
        while(std::cin.get() != '\n'){;}
        clean_display();
        if(joueur2.get_vie()) {
            std::cout << "A " << joueur2.get_name() << " de jouer, appuyer sur entrer pour afficher les plateaux" << std::endl;
            while(std::cin.get() != '\n'){;}
            joueur2.display();
            int x2 = 0;
            int y2 = 0;
            joueur2.saisie_tir(&x2, &y2);
            joueur2.tir(&joueur1, x2, y2);
            joueur1.update_vie();
            std::cout << "Resultat plateau ennemi : " << std::endl;
            joueur2.get_plateau(1).display();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Fin du tour de " << joueur2.get_name() << ", appuyer sur entrer pour cacher les plateaux" << std::endl;
            while(std::cin.get() != '\n'){;}
            clean_display();
        }
        std::cout << "[DEBUG] fin ? [y/n] : ";
        std::cin >> debug_fin;
    }while(joueur1.get_vie() && joueur2.get_vie() && debug_fin == 'n');

    if(joueur1.get_vie()) {
        return true;
    }
    else {
        return false;
    }*/
    return true;
}

int mainInterface()
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *Icon = NULL;
		
	struct Input in;
	
	int status = EXIT_FAILURE;
	
    if(0 != init(&window, &renderer, 1366, 768))
    {
    	fprintf(stderr, "Erreur init : %s", SDL_GetError());
    	goto Quit;
    }
    else
    {
	    Icon = SDL_LoadBMP("/home/etud/Documents/Bataille-navale/pic_sdl/icon.bmp");	        
    	SDL_SetWindowTitle(window, "Bataille navale v0.1");
    	SDL_SetWindowIcon(window, Icon);
Start:
		initStruct(&in);
    	if(printMenu(renderer) == 2)
    	{
    		status = EXIT_SUCCESS;
    		goto Quit;
    	}  	
    }
    
    print1Grid(renderer);
    
    GameLoop_2_playerSDL(renderer);
    
    while(!in.quit)
	{
    	updateEvent(&in);
    	if(in.mouse[SDL_BUTTON_MIDDLE] == SDL_TRUE) goto Start;
	} 
    
    status = EXIT_SUCCESS;
Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
    return status;
}


