#pragma once

#include <GL/glew.h>

class SolidColorTriangle {
private:
    GLuint vertexBuffer, colorBuffer;
    GLuint shader;
public:
    SolidColorTriangle();
    ~SolidColorTriangle();

    // Draw the triangle and put it on the gpu
    void drawBuffers();

    // Actual draw
    void glDraw();
};