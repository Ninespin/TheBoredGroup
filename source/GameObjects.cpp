#include "GameObjects.h"

namespace GameObjects{

    GameObject::GameObject(std::string name)
        : name(name)
    {
    }
    GameObject::~GameObject()
    {
    }

    RenderableObject::RenderableObject(std::string name)
        : GameObject(name)
    {
        RenderProperties::RenderProperties r = RenderProperties::RenderProperties();
        r.vertex.push_back(0.0);
        r.vertex.push_back(0.0);
        r.vertex.push_back(0.0);
        r.vertex.push_back(1.0);
        r.vertex.push_back(1.0);
        r.vertex.push_back(1.0);

        r.colors.push_back(0.0);
        r.colors.push_back(0.0);
        r.colors.push_back(1.0);
        r.colors.push_back(1.0);
        r.colors.push_back(0.0);
        r.colors.push_back(0.0);
        r.colors.push_back(0.0);
        r.colors.push_back(1.0);
        r.colors.push_back(0.0);

        glGenVertexArrays(1, &r.VAO);
        glBindVertexArray(r.VAO);

    	glGenBuffers(1, &r.vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, r.vertexBuffer);
        glBufferData(
            GL_ARRAY_BUFFER,
            r.vertex.size()*sizeof(float),
            &r.vertex.front(),
            GL_STATIC_DRAW);
        glGenBuffers(1, &r.colorBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, r.colorBuffer);
        glBufferData(
            GL_ARRAY_BUFFER,
            r.colors.size()*sizeof(float),
            &r.colors.front(),
            GL_STATIC_DRAW);
        renderProperties.push_back(r);

    }
    RenderableObject::~RenderableObject()
    {
    }
};
