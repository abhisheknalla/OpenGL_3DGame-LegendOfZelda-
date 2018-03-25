#include "rocks.h"
#include "main.h"

Rocks::Rocks(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    static const GLfloat vertex_buffer_data[] = {
        -0.25f,-0.25f,-0.25f, // triangle 1 : begin
        -0.25f,-0.25f, 0.25f,
        -0.25f, 0.40f, 0.25f, // triangle 1 : end

        0.25f, 0.40f,-0.25f, // triangle 2 : begin
        -0.25f,-0.25f,-0.25f,
        -0.25f, 0.40f,-0.25f, // triangle 2 : end

        0.25f,-0.30f, 0.25f,
        -0.25f,-0.25f,-0.25f,
        0.25f,-0.25f,-0.25f,

        0.25f, 0.40f,-0.25f,
        0.25f,-0.25f,-0.25f,
        -0.25f,-0.25f,-0.25f,

        -0.25f,-0.25f,-0.25f,
        -0.25f, 0.40f, 0.25f,
        -0.25f, 0.40f,-0.25f,

        0.25f,-0.25f, 0.25f,
        -0.25f,-0.25f, 0.25f,
        -0.25f,-0.25f,-0.25f,

        -0.25f, 0.40f, 0.25f,
        -0.25f,-0.25f, 0.25f,
        0.25f,-0.25f, 0.25f,

        0.25f, 0.40f, 0.25f,
        0.25f,-0.25f,-0.25f,
        0.25f, 0.40f,-0.25f,

        0.25f,-0.25f,-0.25f,
        0.25f, 0.40f, 0.25f,
        0.25f,-0.25f, 0.25f,

        0.25f, 0.40f, 0.25f,
        0.25f, 0.40f,-0.25f,
        -0.25f, 0.40f,-0.25f,

        0.25f, 0.40f, 0.25f,
        -0.25f, 0.40f,-0.25f,
        -0.25f, 0.40f, 0.25f,

        0.25f, 0.40f, 0.25f,
        -0.25f, 0.40f, 0.25f,
        0.25f,-0.25f, 0.25f,

  };

    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);
//#####################################################
static const GLfloat vertex_buffer_data2[] = {
-0.20f,-0.35f,-0.20f, // triangle 1 : begin
-0.20f,-0.35f, 0.20f,
-0.20f, 0.45f, 0.20f, // triangle 1 : end

0.20f, 0.45f,-0.20f, // triangle 2 : begin
-0.20f,-0.35f,-0.20f,
-0.20f, 0.45f,-0.20f, // triangle 2 : end

0.20f,-0.35f, 0.20f,
-0.20f,-0.35f,-0.20f,
0.20f,-0.35f,-0.20f,

0.20f, 0.45f,-0.20f,
0.20f,-0.35f,-0.20f,
-0.20f,-0.35f,-0.20f,

-0.20f,-0.35f,-0.20f,
-0.20f, 0.45f, 0.20f,

-0.20f, 0.45f,-0.20f,
0.20f,-0.35f, 0.20f,
-0.20f,-0.35f, 0.20f,
-0.20f,-0.35f,-0.20f,

-0.20f, 0.45f, 0.20f,
-0.20f,-0.35f, 0.20f,
0.20f,-0.35f, 0.20f,

0.20f, 0.45f, 0.20f,
0.20f,-0.35f,-0.20f,
0.20f, 0.45f,-0.20f,

0.20f,-0.35f,-0.20f,
0.20f, 0.45f, 0.20f,
0.20f,-0.35f, 0.20f,

0.20f, 0.45f, 0.20f,
0.20f, 0.45f,-0.20f,
-0.20f, 0.45f,-0.20f,

0.20f, 0.45f, 0.20f,
-0.20f, 0.45f,-0.20f,
-0.20f, 0.45f, 0.20f,

0.20f, 0.45f, 0.20f,
-0.20f, 0.45f, 0.20f,
0.20f,-0.35f, 0.20f,
};
this->object[1] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data2, color, GL_FILL);
//############################################
static const GLfloat vertex_buffer_data3[] = {
-0.15f,-0.40f,-0.15f, // triangle 1 : begin
-0.15f,-0.40f, 0.15f,
-0.15f, 0.50f, 0.15f, // triangle 1 : end

0.15f, 0.50f,-0.15f, // triangle 2 : begin
-0.15f,-0.40f,-0.15f,
-0.15f, 0.50f,-0.15f, // triangle 2 : end

0.15f,-0.40f, 0.15f,
-0.15f,-0.40f,-0.15f,
0.15f,-0.40f,-0.15f,

0.15f, 0.50f,-0.15f,
0.15f,-0.40f,-0.15f,
-0.15f,-0.40f,-0.15f,

-0.15f,-0.40f,-0.15f,
-0.15f, 0.50f, 0.15f,

-0.15f, 0.50f,-0.15f,
0.15f,-0.40f, 0.15f,
-0.15f,-0.40f, 0.15f,
-0.15f,-0.40f,-0.15f,

-0.15f, 0.50f, 0.15f,
-0.15f,-0.40f, 0.15f,
0.15f,-0.40f, 0.15f,

0.15f, 0.50f, 0.15f,
0.15f,-0.40f,-0.15f,
0.15f, 0.50f,-0.15f,

0.15f,-0.40f,-0.15f,
0.15f, 0.50f, 0.15f,
0.15f,-0.40f, 0.15f,

0.15f, 0.50f, 0.15f,
0.15f, 0.50f,-0.15f,
-0.15f, 0.50f,-0.15f,

0.15f, 0.50f, 0.15f,
-0.15f, 0.50f,-0.15f,
-0.15f, 0.40f, 0.15f,

0.15f, 0.50f, 0.15f,
-0.15f, 0.50f, 0.15f,
0.15f,-0.40f, 0.15f,

    };
    this->object[2] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data3, COLOR_GREEN3, GL_FILL);
}

void Rocks::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object[0]);
    draw3DObject(this->object[1]);
    draw3DObject(this->object[2]);
}

void Rocks::set_position(float x, float y, float z) {
    //this->position = glm::vec3(x, y, 0);
}

void Rocks::tick() {
//    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Rocks::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 0.5 ,0.5};
    return bbox;
}
