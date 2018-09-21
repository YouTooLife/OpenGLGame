//
//  SimpleBox.cpp
//  OpenGLGame
//
//  Created by YouTooLife on 21/09/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include "SimpleBox.hpp"


SimpleBox::SimpleBox(GLuint VAO)
{
    std::shared_ptr<Shader> shader = std::make_shared<Shader>("/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/Shader/GLSL/light.vert", "/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/Shader/GLSL/boxML.frag");
    
    unsigned int diffuseMap = FileHandler::loadTexture("/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/container2.png");
    unsigned int  specularMap = FileHandler::loadTexture("/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/container2_specular.png");
    unsigned int  emissionMap = FileHandler::loadTexture("/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/matrix.jpg");
    
    shader->Use();
    shader->setInt("material.diffuse", 0);
    shader->setInt("material.specular", 1);
    //shader->setInt("material.emission", 2);
    
    simpleObject = std::make_shared<SimpleObject>(VAO, shader, diffuseMap, specularMap, emissionMap);
}

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f),
    glm::vec3( 2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3( 2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3( 1.3f, -2.0f, -2.5f),
    glm::vec3( 1.5f,  2.0f, -2.5f),
    glm::vec3( 1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};

/*
glm::vec3 pointLightPositions[] = {
    glm::vec3( 0.7f,  0.2f,  2.0f),
    glm::vec3( 2.3f, -3.3f, -4.0f),
    glm::vec3(-4.0f,  2.0f, -12.0f),
    glm::vec3( 0.0f,  0.0f, -3.0f)
};

glm::vec3 pointLightColors[] = {
    glm::vec3(0.2f, 0.2f, 0.6f),
    glm::vec3(0.3f, 0.3f, 0.7f),
    glm::vec3(1.0f, 0.0f, 0.3f),
    glm::vec3(0.4f, 0.4f, 0.4f)
};
 */


void SimpleBox::Draw(Camera &camera)
{
    glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };
    
    glm::vec3 pointLightColors[] = {
        glm::vec3(0.2f, 0.2f, 0.6f),
        glm::vec3(0.3f, 0.3f, 0.7f),
        glm::vec3(1.0f, 0.0f, 0.3f),
        glm::vec3(0.4f, 0.4f, 0.4f)
    };
    
    
    
    auto lightShader = simpleObject->shader;
    
    //lightShader->Use();
    //glBindVertexArray(VAO);
    simpleObject->BeginDraw();
    lightShader->setVec3("viewPos", camera.Position);
    lightShader->setFloat("material.shininess", 32.0f);
    
    // directional light
    lightShader->setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
    lightShader->setVec3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
    lightShader->setVec3("dirLight.diffuse", 0.1f, 0.1f, 0.5f);
    lightShader->setVec3("dirLight.specular", 0.7f, 0.7f, 0.7f);
    
    // point light
    for (int i = 0; i < 4; i++)
    {
        std::string str0 = "pointLights["+ std::to_string(i)+ "].";
        lightShader->setVec3(str0+"position", pointLightPositions[i]);
        lightShader->setVec3(str0+"ambient", 0.1f*glm::vec3(pointLightColors[i]));
        lightShader->setVec3(str0+"diffuse", glm::vec3(pointLightColors[i]));
        lightShader->setVec3(str0+"specular", glm::vec3(pointLightColors[i]));
        lightShader->setFloat(str0+"constant", 1.0f);
        lightShader->setFloat(str0+"linear", 0.09);
        lightShader->setFloat(str0+"quadratic", 0.032);
    }
    
    // spotLight
    lightShader->setVec3("spotLight.position", camera.Position);
    lightShader->setVec3("spotLight.direction", camera.Front);
    lightShader->setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
    lightShader->setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
    lightShader->setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
    lightShader->setFloat("spotLight.constant", 1.0f);
    lightShader->setFloat("spotLight.linear", 0.09);
    lightShader->setFloat("spotLight.quadratic", 0.032);
    lightShader->setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    lightShader->setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
    
    // Create camera transformations
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
    lightShader->setMat4("projection", projection);
    lightShader->setMat4("view", view);
    
    // world transformation
    glm::mat4 model(1.f);
    lightShader->setMat4("model", model);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, simpleObject->diffuseMap);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, simpleObject->specularMap);
    
    for (unsigned int i = 0; i < 10; i++)
    {
        // calculate the model matrix for each object and pass it to shader before drawing
        glm::mat4 model(1.f);
        model = glm::translate(model, cubePositions[i]);
        float angle = 20.0f * i;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        lightShader->setMat4("model", model);
        
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
    this->simpleObject->EndDraw();
}

SimpleBox::~SimpleBox()
{
    std::cout << "SimpleBox has been destroyed!" << "\n";
}
