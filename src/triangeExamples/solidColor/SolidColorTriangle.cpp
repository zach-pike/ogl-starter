/*
class SolidColorTriangle {
private:
    GLuint vertexBuffer, colorBuffer;
    GLuint shader;
public:
    SolidColorTriangle();
    ~SolidColorTriangle();

    // Draw the triangle and put it on the cpu
    void drawBuffers();

    // Actual draw
    void glDraw();
};
*/

#include "SolidColorTriangle.hpp"
#include "glHelpers/shader/shader.hpp"

#include <glm/glm.hpp>

SolidColorTriangle::SolidColorTriangle() {
    glGenBuffers(1, &vertexBuffer);
    glGenBuffers(1, &colorBuffer);

    shader = loadShaders("solidTriangle/");
}

SolidColorTriangle::~SolidColorTriangle() {
    glDeleteProgram(shader);

    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &colorBuffer);
}

// Draw the triangle and put it on the gpu
void SolidColorTriangle::drawBuffers() {
    glm::vec2 coords[] = {
        glm::vec2(-1, -1),
        glm::vec2(0, 1),
        glm::vec2(1, -1),
    };

    glm::vec3 color[] = {
        glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0),
        glm::vec3(0, 0, 1),
    };

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(coords), coords, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);
}

// Actual draw
void SolidColorTriangle::glDraw() {
    glUseProgram(shader);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}