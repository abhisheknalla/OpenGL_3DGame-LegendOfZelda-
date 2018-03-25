#include "flag.h"
#include "main.h"

Flag::Flag(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    static const GLfloat vertex_buffer_data5[] = {//SURROUNDING
      0.0, 1.1 , 0.0,
      0.0, 0.2 , 0.0,
      0.0, 0.2 , 0.40,
    };
    this->object = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data5, COLOR_FLAG, GL_FILL);
}

void Flag::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Flag::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Flag::tick() {
  //  this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
