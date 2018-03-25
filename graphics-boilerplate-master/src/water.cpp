#include "water.h"
#include "main.h"

Water::Water(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    //this->rotation = 0;
    //speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -100.0f,-10.0f,-100.0f, // triangle 1 : begin
        -100.0f,-10.0f, 100.0f,//LEFT FACE LOWER TRIANGLE
        -100.0f, 1.05f, 100.0f, // triangle 1 : end

        100.0f, 1.05f,-100.0f, // triangle 2 : begin
        -100.0f,-10.0f,-100.0f,//BACK FACE UPPER TRIANGLE
        -100.0f, 1.05f,-100.0f, // triangle 2 : end

        100.0f,-10.0f, 100.0f,
        -100.0f,-10.0f,-100.0f,//DOWN FACE RIGHT TRIANGLE
        100.0f,-10.0f,-100.0f,

        100.0f, 1.05f,-100.0f,
        100.0f,-10.0f,-100.0f,//BACK FACE LOWER TRIANGLE
        -100.0f,-10.0f,-100.0f,

        -100.0f,-10.0f,-100.0f,
        -100.0f, 1.05f, 100.0f,//LEFT FACE UPPER TRIANGLE
        -100.0f, 1.05f,-100.0f,

        100.0f,-10.0f, 100.0f,
        -100.0f,-10.0f, 100.0f,//DOWN FACE LEFT TRIANGLE
        -100.0f,-10.0f,-100.0f,

        -100.0f, 1.05f, 100.0f,
        -100.0f,-10.0f, 100.0f,//FRONT FACE LOWER TRIANGLE
        100.0f,-10.0f, 100.0f,

        100.0f, 1.05f, 100.0f,
        100.0f,-10.0f,-100.0f,//RIGHT FACE UPPER TRIANGLE
        100.0f, 1.05f,-100.0f,

        100.0f,-10.0f,-100.0f,
        100.0f, 1.05f, 100.0f,//RIGHT FACE LOWER TRIANGLE
        100.0f,-10.0f, 100.0f,

        100.0f, 1.05f, 100.0f,
        100.0f, 1.05f,-100.0f,//UPPER FACE RIGHT TRIANGLE
        -100.0f, 1.05f,-100.0f,

        100.0f, 1.05f, 100.0f,
        -100.0f, 1.05f,-100.0f,//UPPER FACE LEFT TRIANGLE
        -100.0f, 1.05f, 100.0f,

        100.0f, 1.05f, 100.0f,
        -100.0f, 1.05f, 100.0f,//FRONT FACE UPPER TRIANGLE
        100.0f,-10.0f, 100.0f
    };
    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_WATERBLUE2, GL_FILL);
    //
    // static const GLfloat vertex_buffer_data2[] = {
    //     -100.0f,-10.0f,-100.0f, // triangle 1 : begin
    //     -100.0f,-10.0f, 100.0f,//LEFT FACE LOWER TRIANGLE
    //     -100.0f, 1.1f, 100.0f, // triangle 1 : end
    //
    //     100.0f, 1.1f,-100.0f, // triangle 2 : begin
    //     -100.0f,-10.0f,-100.0f,//BACK FACE UPPER TRIANGLE
    //     -100.0f, 1.1f,-100.0f, // triangle 2 : end
    //
    //     100.0f,-10.0f, 100.0f,
    //     -100.0f,-10.0f,-100.0f,//DOWN FACE RIGHT TRIANGLE
    //     100.0f,-10.0f,-100.0f,
    //
    //     100.0f, 1.1f,-100.0f,
    //     -100.0f,-10.0f,-100.0f,
    //
    //     100.0f,-10.0f,-100.0f,//BACK FACE LOWER TRIANGLE
    //     -100.0f,-10.0f,-100.0f,
    //     -100.0f, 1.1f, 100.0f,//LEFT FACE UPPER TRIANGLE
    //     -100.0f, 1.1f,-100.0f,
    //
    //     100.0f,-10.0f, 100.0f,
    //     -100.0f,-10.0f, 100.0f,//DOWN FACE LEFT TRIANGLE
    //     -100.0f,-10.0f,-100.0f,
    //
    //     -100.0f, 1.1f, 100.0f,
    //     -100.0f,-10.0f, 100.0f,//FRONT FACE LOWER TRIANGLE
    //     100.0f,-10.0f, 100.0f,
    //
    //     100.0f, 1.1f, 100.0f,
    //     100.0f,-10.0f,-100.0f,//RIGHT FACE UPPER TRIANGLE
    //     100.0f, 1.1f,-100.0f,
    //
    //     100.0f,-10.0f,-100.0f,
    //     100.0f, 1.1f, 100.0f,//RIGHT FACE LOWER TRIANGLE
    //     100.0f,-10.0f, 100.0f,
    //
    //     100.0f, 1.1f, 100.0f,
    //     100.0f, 1.1f,-100.0f,//UPPER FACE RIGHT TRIANGLE
    //     -100.0f, 1.1f,-100.0f,
    //
    //     100.0f, 1.1f, 100.0f,
    //     -100.0f, 1.1f,-100.0f,//UPPER FACE LEFT TRIANGLE
    //     -100.0f, 1.1f, 100.0f,
    //
    //     100.0f, 1.1f, 100.0f,
    //     -100.0f, 1.1f, 100.0f,//FRONT FACE UPPER TRIANGLE
    //     100.0f,-10.0f, 100.0f
    // };
    // this->object[1] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data2, COLOR_WATERBLUE2, GL_FILL);
}

void Water::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    //glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    //rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);// * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object[0]);
//      draw3DObject(this->object[1]);
}

void Water::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Water::tick() {
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}
