Chocolate-Wolfenstein-3D
========================

Based on Wolf4SDL by Moritz "Ripper" Kroll (http://www.chaos-software.de.vu).

Original Wolfenstein 3D by id Software (http://www.idsoftware.com)

Chocolate Wolf3D removes all the crap that was added over the years 
(snow, rain ...) in order to recreate the experience from 1993. 

All other port display the framebuffer as 320x200 without accounting for the CRT 4:3
distortion. Chocolate Wolfenstien 3D has a CRT emulator based on OpenGL:

Most port just display the framebuffer as is: 320x200:

![alt tag](https://github.com/fabiensanglard/Chocolate-Wolfenstein-3D/blob/master/screenshots/crt_framebuffer.png)

But back in 1993, the CRT were 4:3 aspect ratio. Which mean image were streched to 320x240:

![alt tag](https://github.com/fabiensanglard/Chocolate-Wolfenstein-3D/blob/master/screenshots/crt_aspect.png)

Tested on Mac OS X. If anybody wants to make a Windows and Linux build, you are welcome.

Fabien Sanglard 
