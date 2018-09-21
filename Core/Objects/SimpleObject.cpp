//
//  SimpleObject.cpp
//  OpenGLGame
//
//  Created by YouTooLife on 21/09/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include "SimpleObject.hpp"

SimpleObject::SimpleObject(GLuint VAO, std::shared_ptr<Shader> shader, unsigned int diffuseMap, unsigned int specularMap, unsigned int emissionMap)
{
    this->VAO = VAO;
    this->shader = shader;
    this->diffuseMap = diffuseMap;
    this->specularMap = specularMap;
    this->emissionMap = emissionMap;
}

void SimpleObject::BeginDraw()
{
    this->shader->Use();
    glBindVertexArray(this->VAO);
}

void SimpleObject::EndDraw()
{
    glBindVertexArray(0);
}

SimpleObject::~SimpleObject()
{
    std::cout << "Simple Object has been destroyed!" << "\n";
}
