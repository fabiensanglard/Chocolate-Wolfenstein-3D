//
//  crt.c
//  Chocolate Wolfenstein 3D
//
//  Created by fabien sanglard on 2014-08-26.
//
//

#include "crt.h"
#include "SDL.h"
#include "id_vl.h"


void CRT_DAC(void){
  /*
    github repo is archived, so I cannot reply in github.

    Scaling now happens over in id_vl.cpp
    The window is made with the correct aspect ratio and set to do nearest neighbor scaling
    with SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

    Still using this to present the screen, and to look for screenshot keypress.
  */
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, screenBuffer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);
  SDL_DestroyTexture(texture);

	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	static int wasPressed = 0;
	if ( keystate[SDL_SCANCODE_I] ){
		if (!wasPressed){
			wasPressed = 1;
			CRT_Screenshot();
		}
	}
	else
		wasPressed = 0;	
}

void CRT_Screenshot(void){
  const char* filename = "screenshot.bmp";

  int aspectWidth = 640;
  int aspectHeight = 480;

  printf("Screenshot.\n");

  SDL_Surface *correctAspect = SDL_CreateRGBSurface(0, aspectWidth, aspectHeight, 32, 0, 0, 0, 0);

  SDL_Surface *incorrectAspect = SDL_CreateRGBSurface(0, screenBuffer->w, screenBuffer->h, 32, 0, 0, 0, 0);

  SDL_BlitSurface(screenBuffer, NULL, incorrectAspect, NULL);

  SDL_BlitScaled(incorrectAspect, NULL, correctAspect, NULL);

  SDL_SaveBMP(correctAspect, filename);

  SDL_FreeSurface(correctAspect);
  SDL_FreeSurface(incorrectAspect);
}
