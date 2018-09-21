//
//  core.hpp
//  OpenGLGame
//
//  Created by YouTooLife on 9/14/18.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

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
#include "FileHandler.hpp"
#include "SimpleBox.hpp"



class Core
{
public:
    // Window dimensions
    const GLuint WIDTH = 800, HEIGHT = 600;
    GLFWwindow* window = NULL;
    
    Core();
    ~Core();
    int initCore();
    
private:
    GLuint VBO, VAO, EBO;
    GLuint containerVAO;
    GLuint lightVAO;
    
    unsigned int diffuseMap = 0;
    unsigned int specularMap = 0;
    unsigned int emissionMap = 0;
    
    std::shared_ptr<Shader> ourShader;
    std::shared_ptr<Shader> lightShader;
    std::shared_ptr<Shader> lampShader;
    
    std::shared_ptr<SimpleBox> boxes;
    
    
    //Time
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    
    void render();
    
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
};

#endif /* core_hpp */
