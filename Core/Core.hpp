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
#include "Model.hpp"



class Core
{
public:
    const GLuint WIDTH = 800, HEIGHT = 600;
    
    Core();
    ~Core();
    int initCore();
    
private:
    GLFWwindow *window;
    
    const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
    unsigned int depthMapFBO;
    unsigned int depthMap;
    
    unsigned int planeVAO;
    /*
    GLuint VBO, VAO, EBO;
    GLuint containerVAO;
    GLuint lightVAO;
     */
    
    unsigned int woodTexture = 0;
    
    unsigned int diffuseMap = 0;
    unsigned int specularMap = 0;
    unsigned int emissionMap = 0;
    
    std::shared_ptr<Shader> simpleDepthShader;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Shader> debugDepthQuad;
    std::shared_ptr<Shader> lampShader;
    
    /*
    std::shared_ptr<SimpleBox> boxes;
    
    std::shared_ptr<Shader> modelShader;
    std::shared_ptr<Model> ourModel;
     */
    
    
    //Time
    GLfloat deltaTime = 0.0f;
    GLfloat lastFrame = 0.0f;
    
    void render();
    void renderScene(shared_ptr<Shader> shader);
    
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};

#endif /* core_hpp */
