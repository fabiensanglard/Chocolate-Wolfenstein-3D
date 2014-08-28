//
//  crt.h
//  Chocolate Wolfenstein 3D
//
//  Created by fabien sanglard on 2014-08-26.
//
//

#ifndef Chocolate_Wolfenstein_3D_crt_h
#define Chocolate_Wolfenstein_3D_crt_h

#include "SDL/SDL.h"
#ifdef __linux__
#include <GL/gl.h>
#else
#include <OpenGL/gl.h>
#endif

/*
 * CRT aspect ratio is 4:3, height will be infered.
 */
void CRT_Init(int width);

/*
 *   Trigger the Digital To Analogic convertion
 */
void CRT_DAC();


#endif
