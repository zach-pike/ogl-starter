#include <bits/stdc++.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "glHelpers/utils/basicGfxInit.hpp"
#include "glHelpers/utils/dotenv.h"
#include "triangeExamples/solidColor/SolidColorTriangle.hpp"

int main() {
    // Load dotenv for shader and textures
    dotenv::init();

    // Make window && sets glfw context
    GLFWwindow* window = gfxInit();

    // Set background color
    glClearColor(0, 0, 0, 1.f);

    // Set some OpenGL settingss
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    // Create our VAO
    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    glBindVertexArray(vertexArrayID);

    SolidColorTriangle a;
    a.drawBuffers();

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw code here
        a.glDraw();
        
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    glDeleteVertexArrays(1, &vertexArrayID);
    glfwTerminate();
}