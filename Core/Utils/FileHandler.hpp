//
//  FileHandler.hpp
//  OpenGLGame
//
//  Created by YouTooLife on 21/09/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef FileHandler_hpp
#define FileHandler_hpp

//-------------------//
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include <SOIL.h>
#include <GLFW/glfw3.h>



class FileHandler
{
private:
    
public:
    static unsigned int loadTexture(char const * path);
    
};

#endif /* FileHandler_hpp */
