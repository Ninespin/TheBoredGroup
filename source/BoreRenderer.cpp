#include "BoreRenderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <typeinfo>
#include "ShaderLoadFunc.h"


namespace Bore{
    BoreRenderer::BoreRenderer(){

        shaderProgram = LoadShaders("v.glsl","f.glsl");
        vpos_location = glGetAttribLocation(shaderProgram, "vertexPosition_modelspace");
        vcol_location = glGetAttribLocation(shaderProgram, "vertexColor");

    }
    BoreRenderer::~BoreRenderer(){

    }

    // main exposed render method
    //
    void BoreRenderer::Render(Scene::Scene* scene){
        std::map<std::string, std::shared_ptr<GameObjects::GameObject>>* objects = scene->getGameObjects();

        glUseProgram(shaderProgram);
        glEnableVertexAttribArray(vpos_location);
        glEnableVertexAttribArray(vcol_location);

        for(std::map<std::string, std::shared_ptr<GameObjects::GameObject>>::iterator it = objects->begin();
                it != objects->end(); it++)
        {
            std::map<std::string, std::shared_ptr<Component>>::iterator comp = it->second->components.find("RenderProperties");
            if(it->second->components.end() != comp){
                std::shared_ptr<RenderProperties::RenderProperties> rProp = std::dynamic_pointer_cast<RenderProperties::RenderProperties>(comp->second);
                glBindVertexArray(rProp->VAO);
                // VERTEX
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, rProp->vertexBuffer);
                glVertexAttribPointer(
                    vpos_location,
                    2,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);
                // COLORS
                glEnableVertexAttribArray(1);
                glBindBuffer(GL_ARRAY_BUFFER, rProp->colorBuffer);
                glVertexAttribPointer(
                    vcol_location,
                    3,
                    GL_FLOAT,
                    GL_FALSE,
                    0,
                    (void*) 0);
                glDrawArrays(GL_TRIANGLES, 0, 3);
            }
        }

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

    }
}
