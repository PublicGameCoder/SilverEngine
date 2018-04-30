#ifndef SECONDIG_H
#define SECONDIG_H

#define USE3D false

#define TITLE "SilverEngine"
#define MAINSCENE "Scene1"
#define MAINCAMERA "MAIN_CAMERA"

#define FULLSCREEN false

#define SCREENWIDTH 800
#define SCREENHEIGHT 600

#define RESIZEABLE true

#define VSYNC true

#define DEFAULTFONT "fonts/arial.ttf"

#define DEFAULTMESHSHADERVERTEX "shaders/mesh.vert"
#define DEFAULTMESHSHADERFRAGMENT "shaders/mesh.frag"

#define DEFAULTTEXTSHADERVERTEX "shaders/text.vert"
#define DEFAULTTEXTSHADERFRAGMENT "shaders/text.frag"

#define DEFAULTCUBEMAPSHADERVERTEX "shaders/cubemap.vert"
#define DEFAULTCUBEMAPSHADERFRAGMENT "shaders/cubemap.frag"

//State defines
typedef int SE_ERROR;
#define SE_SUCCESS 0
#define SE_FAILED_UNDEFINED 1
#define SE_FAILED_NAMEDUPLICATE 2
#define SE_FAILED_NAMEDOESNOTEXIST 3
#define SE_FAILED_GLFWINITIALIZATION 4
#define SE_FAILED_GLFWCOULDNTCREATEWINDOW 5
#define SE_FAILED_GLEWINITIALIZATION 6
#define SE_FAILED_MAINSCENECANTBEREMOVED 7
#define SE_FAILED_NAMEALREADYEXISTSBUTGOTCHANGED 8
//End State defines

//Includes
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SETime.h>

#endif // !SECONDIG_H