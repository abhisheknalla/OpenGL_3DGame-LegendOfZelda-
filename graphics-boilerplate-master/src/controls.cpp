// Include GLFW
// #include <GLFW/glfw3.h>
// extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.
//
// // Include GLM
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
//
#include "controls.hpp"
#include "main.h"



using namespace glm;


glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(GLFWwindow *window){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(GLFWwindow *window){
	return ProjectionMatrix;
}

float x = 0;
float y = 2;
float z = 5;
float radius = 2.0;
float angle = 0.0;
float vangle = 0.0;
// Initial position : on +Z
glm::vec3 position = glm::vec3( 0, 2, 5 );
glm::vec3 position2 = glm::vec3( 0, 1, 3 );
// Initial horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// Initial vertical angle : none
float verticalAngle = 0.0f;
// Initial Field of View
float initialFoV = 90.0f;

float speed = 3.0f; // 3 units / second
float mouseSpeed = 0.005f;



void computeMatricesFromInputs(GLFWwindow *window, glm::vec3 boat_position){

	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1024/2, 768/2);

	// Compute new orientation
	horizontalAngle += mouseSpeed * float(1024/2 - xpos );
	verticalAngle   += mouseSpeed * float( 768/2 - ypos );

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f),
		0,
		//0
		cos(horizontalAngle - 3.14f/2.0f)
	);

	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	// Move forward
	if (glfwGetKey( window, GLFW_KEY_W ) == GLFW_PRESS){
		//position += direction * deltaTime * speed;
		radius = radius - 0.2;
		x = radius*sin(angle); z = radius*cos(angle) + 3;
		position = glm::vec3( x, y, z );
	}
	// Move backward
	if (glfwGetKey( window, GLFW_KEY_S ) == GLFW_PRESS){
		radius = radius + 0.2;
		x = radius*sin(angle); z = radius*cos(angle) + 3;
		position = glm::vec3( x, y, z );
	}
	// Rotate right
	if (glfwGetKey( window, GLFW_KEY_D ) == GLFW_PRESS){
		angle += 0.01;
		x = radius*sin(angle); z = radius*cos(angle) + 3;
		position = glm::vec3( x, y, z );
	}
	// Rotate left
	if (glfwGetKey( window, GLFW_KEY_A ) == GLFW_PRESS){
	//	position -= right * deltaTime; * speed;
	angle -= 0.01;
	x = radius*sin(angle); z = radius*cos(angle) + 3;
	position = glm::vec3( x, y, z );
	}
	// Rotate down
	if (glfwGetKey( window, GLFW_KEY_Z ) == GLFW_PRESS){
	//	position -= right * deltaTime; * speed;
	angle -= 0.01;
	y = radius*sin(angle) + 1;
	z = radius*cos(angle) + 3;
	position = glm::vec3( x, y, z );
	}
	// Rotate up
	if (glfwGetKey( window, GLFW_KEY_X ) == GLFW_PRESS){
	//	position -= right * deltaTime; * speed;
	angle += 0.01;
	y = radius*sin(angle) + 1;
	z = radius*cos(angle) + 3;
	position = glm::vec3( x, y, z );
	}
	// // Rotate up
	// if (glfwGetKey( window, GLFW_KEY_X ) == GLFW_	PRESS){
	// //	position -= right * deltaTime; * speed;
	// vangle += 0.01;
	// y = radius*sin(vangle) + 1;
	// z = radius*cos(vangle) + 3;
	// position = glm::vec3( x, y, z );
	// }
	//Back to Normal
	if (glfwGetKey( window, GLFW_KEY_E ) == GLFW_PRESS){
	position = glm::vec3(0, 2, 5);
	}


	position2 = boat_position;
	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45� Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix       = glm::lookAt(
								position,           // Camera is here
								position2, // and looks here : at the same position, plus "direction"
								up                  // Head is up (set to 0,-1,0 to look upside-down)
						   );

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
}
