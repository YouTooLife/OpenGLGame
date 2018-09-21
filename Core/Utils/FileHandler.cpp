//
//  FileHandler.cpp
//  OpenGLGame
//
//  Created by YouTooLife on 21/09/2018.
//  Copyright © 2018 YouTooLife. All rights reserved.
//

#include "FileHandler.hpp"


unsigned int FileHandler::loadTexture(char const * path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);
    
    int width, height, nrComponents;
    unsigned char *data = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
    //stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        
        GLenum format;
        
        /*
        if (nrComponents == 1)
        format = GL_RED;
        else if (nrComponents == 3)
        format = GL_RGB;
        else if (nrComponents == 4)
         */
        format = GL_RGB;
        
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        //stbi_image_free(data);
        SOIL_free_image_data(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        //stbi_image_free(data);
        SOIL_free_image_data(data);
    }
    std::cout << "Texture ID" << textureID << std::endl;
    return textureID;
}



//char imgName[] = "/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/container.jpg";
//loadPngImage(imgName, width, height, alpha, &image);
//image = //SOIL_load_image("/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);

/*
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
 glGenerateMipmap(GL_TEXTURE_2D);
 SOIL_free_image_data(image);
 glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
 // ===================
 // Texture 2
 // ===================
 glGenTextures(1, &texture2);
 glBindTexture(GL_TEXTURE_2D, texture2);
 // Set our texture parameters
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
 // Set texture filtering
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
 // Load, create texture and generate mipmaps
 //delete [] image;
 //char imgName2[] = "/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/awesomeface.png";
 //loadPngImage(imgName2, width, height, alpha, &image);
 image = SOIL_load_image("/Users/youtoolife/Documents/Developing/XCODE/OpenGLGame/OpenGLGame/img/awesomeface.png", &width, &height, 0, SOIL_LOAD_RGB);
 glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
 glGenerateMipmap(GL_TEXTURE_2D);
 SOIL_free_image_data(image);
 glBindTexture(GL_TEXTURE_2D, 0);
 */
