//
//  SimpleObject.hpp
//  OpenGLGame
//
//  Created by YouTooLife on 21/09/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef SimpleObject_hpp
#define SimpleObject_hpp

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
#include "Camera.hpp"


class SimpleObject
{
private:
    
public:
    
    GLuint VAO;
    
    unsigned int diffuseMap;
    unsigned int specularMap;
    unsigned int emissionMap;
    
    std::shared_ptr<Shader> shader;
    
    SimpleObject(GLuint VAO, std::shared_ptr<Shader> shader, unsigned int diffuseMap = 0, unsigned int specularMap = 0, unsigned int emissionMap = 0);
    ~SimpleObject();
    
    void BeginDraw();
    void EndDraw();
};

#endif /* SimpleObject_hpp */
