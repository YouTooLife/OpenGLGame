//
//  SimpleBox.hpp
//  OpenGLGame
//
//  Created by YouTooLife on 21/09/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef SimpleBox_hpp
#define SimpleBox_hpp

//-------------------//
#include <iostream>
#include <memory>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include <glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//-----------------------//
#include "Shader.hpp"
#include "SimpleObject.hpp"
#include "FileHandler.hpp"


class SimpleBox
{
private:
    const GLuint WIDTH = 800, HEIGHT = 600;
    
    std::shared_ptr<SimpleObject> simpleObject;
    
public:
    SimpleBox(GLuint VAO);
    ~SimpleBox();
    
    void Draw(Camera &camera);
};


#endif /* SimpleBox_hpp */
