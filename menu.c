#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
    SDL_Surface *screenMenu = NULL, *playCase = NULL, *ruleCase = NULL, *quitCase = NULL, *mainChar = NULL, *quitButton = NULL, *playButton = NULL, *goalButton = NULL;
    SDL_Rect playCasePos, ruleCasePos, quitCasePos, positionChar, mainCharGo, quitButtonPos, playButtonPos, goalButtonPos;
    SDL_Event event;
    int endMenu = 1, i, j, speed, authorizedX = 1, authorizedY = 1, orientation = 2, movement = 1;
    int tabCollide[600][400];

    SDL_Init(SDL_INIT_VIDEO);
    screenMenu = SDL_SetVideoMode(600, 400, 32,SDL_HWSURFACE);
    SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));

    playCasePos.x = 200;
    playCasePos.y = 100;

    ruleCasePos.x = 200;
    ruleCasePos.y = 200;

    quitCasePos.x = 200;
    quitCasePos.y = 300;

    positionChar.x = 0;
    positionChar.y = 0;

    quitButtonPos.x = 200;
    quitButtonPos.y = 300;

    playButtonPos.x = 200;
    playButtonPos.y = 100;

    goalButtonPos.x = 200;
    goalButtonPos.y = 200;

    playCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
    SDL_FillRect(playCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

    ruleCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
    SDL_FillRect(ruleCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

    quitCase = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0 ,0 ,0);
    SDL_FillRect(quitCase, NULL, SDL_MapRGB(screenMenu->format, 160, 220, 40));

    mainChar = SDL_LoadBMP("hero.bmp");
    SDL_SetColorKey(mainChar, SDL_SRCCOLORKEY, SDL_MapRGB(mainChar->format, 255, 255, 255));

    quitButton = SDL_LoadBMP("boutonQuitter.bmp");
    SDL_SetColorKey(quitButton, SDL_SRCCOLORKEY, SDL_MapRGB(quitButton->format, 255, 255, 255));

    playButton = SDL_LoadBMP("boutonJouer.bmp");
    SDL_SetColorKey(playButton, SDL_SRCCOLORKEY, SDL_MapRGB(playButton->format, 255, 255, 255));

    goalButton = SDL_LoadBMP("boutonBut.bmp");
    SDL_SetColorKey(goalButton, SDL_SRCCOLORKEY, SDL_MapRGB(goalButton->format, 255, 255, 255));

    for (i = 0; i < 600; i++){
      for (j = 0; j < 400; j++){
	       tabCollide[i][j] = 0;					// il n'y a pas de collision
      }
    }

    for (i = playCasePos.x - 33; i <= playCasePos.x + 200; i++){
      for (j = playCasePos.y /*- 36*/; j <= playCasePos.y + 50; j++){
	       tabCollide[i][j] = 2;					// il y a une collision
      }
    }

    for (i = ruleCasePos.x - 33; i <= ruleCasePos.x + 200; i++){
      for (j = ruleCasePos.y /*- 36*/; j <= ruleCasePos.y + 50; j++){
	       tabCollide[i][j] = 2;					// il y a une collision
      }
    }

    for (i = quitCasePos.x - 33; i <= quitCasePos.x + 200; i++){
      for (j = quitCasePos.y/* - 36*/; j <= quitCasePos.y + 50; j++){
	       tabCollide[i][j] = 2;					// il y a une collision
      }
    }

    while(endMenu){
    SDL_PollEvent(&event);
    mainCharGo.x = 33 * movement;
    mainCharGo.y = 36 * orientation;
    mainCharGo.h = 36;
    mainCharGo.w = 30;

    switch(event.type)
      {
	    case SDL_MOUSEBUTTONUP:
      if (event.button.button == SDL_BUTTON_LEFT){
         if ((positionChar.x != event.button.x) && authorizedX){
           if (tabCollide[positionChar.x + 1][positionChar.y] == 0 ){
             if (abs(event.button.x - (positionChar.x + 1)) < abs(event.button.x - (positionChar.x - 1))){
               orientation = 1;
               if (movement < 2){
                 movement += 1;
               }else{
                 movement = 0;
               }
               speed = 1;
               positionChar.x += speed;

             }
           }
           if (tabCollide[positionChar.x - 1][positionChar.y] == 0 ){
             if (abs(event.button.x - (positionChar.x - 1)) < abs(event.button.x - (positionChar.x + 1))){
               orientation = 3;
               if (movement < 2){
                 movement += 1;
               }else{
                 movement = 0;
               }
               speed = 1;
               positionChar.x -= speed;
             }
           }
           if ((tabCollide[positionChar.x + 1][positionChar.y] != 0 ) || (tabCollide[positionChar.x - 1][positionChar.y] != 0)){
             speed = 0;
           }
           if (speed < 1){
             authorizedY = 0;
             speed = 1;
             if ((event.button.x - positionChar.x) < 0){
               speed = 1;
             }
             if ((event.button.x - positionChar.x) > 0){
               speed = -1;
             }
             positionChar.y += speed;
           }
         }
         authorizedX = 1;



  	     if ((positionChar.y != event.button.y) && (authorizedY)){
           if (tabCollide[positionChar.x][positionChar.y + 1] == 0 ){
             if (abs(event.button.y - (positionChar.y + 1)) < abs(event.button.y - (positionChar.y - 1))){
               orientation = 2;
               if (movement < 2){
                 movement += 1;
               }else{
                 movement = 0;
               }
               speed = 1;
               positionChar.y += speed;
             }
           }
           if (tabCollide[positionChar.x][positionChar.y - 1] == 0 ){
             if (abs(event.button.y - (positionChar.y - 1)) < abs(event.button.y - (positionChar.y + 1))){
               orientation = 0;
               if (movement < 2){
                 movement += 1;
               }else{
                 movement = 0;
               }
               speed = 1;
               positionChar.y -= speed;
             }
           }
           if (tabCollide[positionChar.x][positionChar.y + 1] != 0 ){
             speed = 0;
           }
           if (tabCollide[positionChar.x][positionChar.y - 1] != 0 ){
             speed = 0;
           }
           if (speed < 1){
             authorizedX = 0;
             speed = 1;
             if ((event.button.y - positionChar.y) < 0){
               speed = -1;
             }
             if ((event.button.y - positionChar.y) > 0){
               speed = 1;
             }
             positionChar.x += speed;
           }
         }
         authorizedY = 1;

         if (event.button.x > playCasePos.x - 33 && event.button.x < playCasePos.x + 199 &&
             event.button.y > playCasePos.y - 1 && event.button.y < playCasePos.y + 49){
           if (positionChar.x >= playCasePos.x - 34 && positionChar.x <= playCasePos.x + 201 &&
             positionChar.y >= playCasePos.y - 1 && positionChar.y <= playCasePos.y + 51){
               endMenu = 0;
           }
 		    }
        if (event.button.x > ruleCasePos.x - 33 && event.button.x < ruleCasePos.x + 199 &&
            event.button.y > ruleCasePos.y - 1 && event.button.y < ruleCasePos.y + 49){
          if (positionChar.x >= ruleCasePos.x - 34 && positionChar.x <= ruleCasePos.x + 201 &&
            positionChar.y >= ruleCasePos.y - 1 && positionChar.y <= ruleCasePos.y + 51){
              endMenu = 0;
          }
		    }
        if (event.button.x > quitCasePos.x - 33 && event.button.x < quitCasePos.x + 199 &&
		        event.button.y > quitCasePos.y - 1 && event.button.y < quitCasePos.y + 49){
          if (positionChar.x >= quitCasePos.x - 34 && positionChar.x <= quitCasePos.x + 201 &&
      		  positionChar.y >= quitCasePos.y - 1 && positionChar.y <= quitCasePos.y + 51){
              endMenu = 0;
            }
	      }
	    }
	    break;
	    case SDL_QUIT:
	       endMenu = 0;
	    break;
      }
      SDL_BlitSurface(mainChar, &mainCharGo, screenMenu, &positionChar);
      SDL_BlitSurface(playCase, NULL, screenMenu, &playCasePos);
      SDL_BlitSurface(ruleCase, NULL, screenMenu, &ruleCasePos);
      SDL_BlitSurface(quitCase, NULL, screenMenu, &quitCasePos);

      SDL_BlitSurface(quitButton, NULL, screenMenu, &quitButtonPos);
      SDL_BlitSurface(playButton, NULL, screenMenu, &playButtonPos);
      SDL_BlitSurface(goalButton, NULL, screenMenu, &goalButtonPos);
      SDL_UpdateRect(screenMenu, 0, 0, 0, 0);
      SDL_Flip(screenMenu);
      SDL_FillRect(screenMenu, NULL, SDL_MapRGB(screenMenu->format, 70, 180, 55));
    }

    SDL_FreeSurface(playCase);
    SDL_FreeSurface(ruleCase);
    SDL_FreeSurface(quitCase);
    SDL_FreeSurface(mainChar);
    SDL_FreeSurface(screenMenu);
    SDL_FreeSurface(quitButton);
    SDL_FreeSurface(playButton);
    SDL_FreeSurface(goalButton);
    SDL_Quit();
    return 0;
}
