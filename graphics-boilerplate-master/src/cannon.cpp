#include "cannon.h"
#include "main.h"

Cannon::Cannon(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y+0.195, z);
    this->rotation = 0;
    speed = 1;
    static const GLfloat vertex_buffer_data[] = {
        -0.0250f,0.1650f,-0.3f - 0.5f, // triangle 1 : begin
        -0.0250f,0.1650f, 0.3f - 0.5f,
        -0.0250f, 0.2250f, 0.3f - 0.5f, // triangle 1 : end

        0.0250f, 0.2250f,-0.3f - 0.5f, // triangle 2 : begin
        -0.0250f,0.1650f,-0.3f - 0.5f,
        -0.0250f, 0.2250f,-0.3f - 0.5f, // triangle 2 : end

        0.0250f,0.1650f, 0.3f - 0.5f,
        -0.0250f,0.1650f,-0.3f - 0.5f,
        0.0250f,0.1650f,-0.3f - 0.5f,

        0.0250f, 0.2250f,-0.3f - 0.5f,
        0.0250f,0.1650f,-0.3f - 0.5f,
        -0.0250f,0.1650f,-0.3f - 0.5f,

        -0.0250f,0.1650f,-0.3f - 0.5f,
        -0.0250f, 0.2250f, 0.3f - 0.5f,
        -0.0250f, 0.2250f,-0.3f - 0.5f,

        0.0250f,0.1650f, 0.3f - 0.5f,
        -0.0250f,0.1650f, 0.3f - 0.5f,
        -0.0250f,0.1650f,-0.3f - 0.5f,

        -0.0250f, 0.2250f, 0.3f - 0.5f,
        -0.0250f,0.1650f, 0.3f - 0.5f,
        0.0250f,0.1650f, 0.3f - 0.5f,

        0.0250f, 0.2250f, 0.3f - 0.5f,
        0.0250f,0.1650f,-0.3f - 0.5f,
        0.0250f, 0.2250f,-0.3f - 0.5f,

        0.0250f,0.1650f,-0.3f - 0.5f,
        0.0250f, 0.2250f, 0.f - 0.5f,
        0.0250f,0.1650f, 0.3f - 0.5f,

        0.0250f, 0.2250f, 0.3f - 0.5f,
        0.0250f, 0.2250f,-0.3f - 0.5f,
        -0.0250f, 0.2250f,-0.3f - 0.5f,

        0.0250f, 0.2250f, 0.3f - 0.5f,
        -0.0250f, 0.2250f,-0.3f - 0.5f,
        -0.0250f, 0.2250f, 0.3f - 0.5f,

        0.0250f, 0.2250f, 0.3f - 0.5f,
        -0.0250f, 0.2250f, 0.3f - 0.5f,
        0.0250f,0.1650f, 0.3f - 0.5f
    };
    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
        -0.0250f,0.45f,-0.3f - 0.5f, // triangle 1 : begin
        -0.0250f,0.45f, 0.3f - 0.5f,
        -0.0250f, 0.50f, 0.3f - 0.5f, // triangle 1 : end

        0.0250f, 0.50f,-0.3f - 0.5f, // triangle 2 : begin
        -0.0250f,0.45f,-0.3f - 0.5f,
        -0.0250f, 0.50f,-0.3f - 0.5f, // triangle 2 : end

        0.0250f,0.45f, 0.3f - 0.5f,
        -0.0250f,0.45f,-0.3f - 0.5f,
        0.0250f,0.45f,-0.3f - 0.5f,

        0.0250f, 0.50f,-0.3f - 0.5f,
        0.0250f,0.45f,-0.3f - 0.5f,
        -0.0250f,0.45f,-0.3f - 0.5f,

        -0.0250f,0.45f,-0.3f - 0.5f,
        -0.0250f, 0.50f, 0.3f - 0.5f,
        -0.0250f, 0.50f,-0.3f - 0.5f,

        0.0250f,0.45f, 0.3f - 0.5f,
        -0.0250f,0.45f, 0.3f - 0.5f,
        -0.0250f,0.45f,-0.3f - 0.5f,

        -0.0250f, 0.50f, 0.3f - 0.5f,
        -0.0250f,0.45f, 0.3f - 0.5f,
        0.0250f,0.45f, 0.3f - 0.5f,

        0.0250f, 0.50f, 0.3f - 0.5f,
        0.0250f,0.45f,-0.3f - 0.5f,
        0.0250f, 0.50f,-0.3f - 0.5f,

        0.0250f,0.45f,-0.3f - 0.5f,
        0.0250f, 0.50f, 0.f - 0.5f,
        0.0250f,0.45f, 0.3f - 0.5f,

        0.0250f, 0.50f, 0.3f - 0.5f,
        0.0250f, 0.50f,-0.3f - 0.5f,
        -0.0250f, 0.50f,-0.3f - 0.5f,

        0.0250f, 0.50f, 0.3f - 0.5f,
        -0.0250f, 0.50f,-0.3f - 0.5f,
        -0.0250f, 0.50f, 0.3f - 0.5f,

        0.0250f, 0.50f, 0.3f - 0.5f,
        -0.0250f, 0.50f, 0.3f - 0.5f,
        0.0250f,0.45f, 0.3f - 0.5f
    };
    this->object[1] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data2, color, GL_FILL);
}

void Cannon::draw(glm::mat4 VP ,int no) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(no==0)
      draw3DObject(this->object[0]);
    else
      draw3DObject(this->object[1]);
}

void Cannon::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y+0.195, z);
}

void Cannon::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
