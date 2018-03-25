#include "main.h"


#ifndef CONTROLS_HPP
#define CONTROLS_HPP

void computeMatricesFromInputs(GLFWwindow *window, glm::vec3 boat_position);
glm::mat4 getViewMatrix(GLFWwindow *window);
glm::mat4 getProjectionMatrix(GLFWwindow *window);

#endif
