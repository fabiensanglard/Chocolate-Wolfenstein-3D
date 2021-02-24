//
//  crt.h
//  Chocolate Wolfenstein 3D
//
//  Created by fabien sanglard on 2014-08-26.
//
//
#ifndef Chocolate_Wolfenstein_3D_crt_h
#define Chocolate_Wolfenstein_3D_crt_h

#include "SDL.h"

extern SDL_Color curpal[256];

/*
 *   Trigger the Digital To Analogic convertion
 */
void CRT_DAC(void);

void CRT_Screenshot(void);
#endif
