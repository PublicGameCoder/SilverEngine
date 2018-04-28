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

//State defines
typedef int SE_ERROR;
#define SE_SUCCESS 0
#define SE_FAILED_UNDEFINED 1
#define SE_FAILED_NAMEDUPLICATE 2
#define SE_FAILED_NAMEDOESNOTEXIST 3
#define SE_FAILED_GLFWINITIALIZATION 4
#define SE_FAILED_GLFWCOULDNTCREATEWINDOW 5
#define SE_FAILED_GLEWINITIALIZATION 6
//End State defines

//Includes
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <SETime.h>

#endif // !SECONDIG_H