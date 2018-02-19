#pragma once
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace RenderProperties{
    struct RenderProperties{
    public:
        std::vector<float> vertex;
        std::vector<float> colors;
        std::vector<float> normals;
        std::vector<float> uv;
        GLuint vertexBuffer;
        GLuint colorBuffer;
        GLuint VAO;
    public:
        RenderProperties();
        ~RenderProperties();
    };

}
