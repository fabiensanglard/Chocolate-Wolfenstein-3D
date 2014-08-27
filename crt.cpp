//
//  crt.c
//  Chocolate Wolfenstein 3D
//
//  Created by fabien sanglard on 2014-08-26.
//
//

#include "crt.h"


static int width;
static int height;

GLuint crtTexture;

unsigned char coloredFrameBuffer[320*200*3];

void CRT_Init(int _width){
    width  = _width;
    height = _width * 3.0/4.0;
    
    //Alloc the OpenGL texture were
    glGenTextures(1, &crtTexture);
    glBindTexture(GL_TEXTURE_2D, crtTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(
                 GL_TEXTURE_2D,         // target
                 0,                     // level, 0 = base, no minimap,
                 GL_RGB,                // internalformat
                 320,     // width
                 200,    // height
                 0,                     // border, always 0 in OpenGL ES
                 GL_RGB,                // format
                 GL_UNSIGNED_BYTE,      // type
                 0
                 );
    
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
    
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
 
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapBuffers();
}

#include "id_vl.h"
void CRT_DAC(SDL_Surface *screen){
    
    // Grab the color from SDL
    // Gab the pallete from SDL
    // SDL_Color gamepal
    
    screen = screenBuffer ;
    
    byte* pixelPointer = coloredFrameBuffer;
    for (int i=0; i < 320*200; i++) {
        unsigned char paletteIndex;
        paletteIndex = ((byte*)screen->pixels)[i];
        *pixelPointer++ = gamepal[paletteIndex].r;
        *pixelPointer++ = gamepal[paletteIndex].g;
        *pixelPointer++ = gamepal[paletteIndex].b;
    }
    
    //Upload texture
    glBindTexture(GL_TEXTURE_2D, crtTexture);
    glTexSubImage2D(GL_TEXTURE_2D,
                    0,
                    0,
                    0,
                    320,
                    200,
                    GL_RGB,
                    GL_UNSIGNED_BYTE,
                    coloredFrameBuffer);
    
    glClearColor((SDL_GetTicks() & 0xFF0000 >> 16) /255.0f,
                 (SDL_GetTicks() & 0x00FF00 >>  8) /255.0f,
                 (SDL_GetTicks() & 0x0000FF >>  0) /255.0f, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    //Draw a quad with the texture
    
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3i(0,0,0);
        glTexCoord2f(0, 0); glVertex3i(0,height,0);
        glTexCoord2f(1, 0); glVertex3i(width,height,0);
        glTexCoord2f(1, 1); glVertex3i(width,0,0);
    glEnd();
    
    
    //Flip buffer
    SDL_GL_SwapBuffers();
}
