#include "treasure.h"
#include "main.h"

Treasure::Treasure(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data[] = {
        -0.8f,-0.5f,-0.4f, // triangle 1 : begin
        -0.8f,-0.5f, 0.4f,
        -0.8f, 0.5f, 0.4f, // triangle 1 : end

        0.8f, 0.5f,-0.4f, // triangle 2 : begin
        -0.8f,-0.5f,-0.4f,
        -0.8f, 0.5f,-0.4f, // triangle 2 : end

        0.8f,-0.5f, 0.4f,
        -0.8f,-0.5f,-0.4f,
        0.8f,-0.5f,-0.4f,

        0.8f, 0.5f,-0.4f,
        0.8f,-0.5f,-0.4f,
        -0.8f,-0.5f,-0.4f,

        -0.8f,-0.5f,-0.4f,
        -0.8f, 0.5f, 0.4f,
        -0.8f, 0.5f,-0.4f,

        0.8f,-0.5f, 0.4f,
        -0.8f,-0.5f, 0.4f,
        -0.8f,-0.5f,-0.4f,

        -0.8f, 0.5f, 0.4f,
        -0.8f,-0.5f, 0.4f,
        0.8f,-0.5f, 0.4f,

        0.8f, 0.5f, 0.4f,
        0.8f,-0.5f,-0.4f,
        0.8f, 0.5f,-0.4f,

        0.8f,-0.5f,-0.4f,
        0.8f, 0.5f, 0.4f,
        0.8f,-0.5f, 0.4f,

        0.8f, 0.5f, 0.4f,
        0.8f, 0.5f,-0.4f,
        -0.8f, 0.5f,-0.4f,

        0.8f, 0.5f, 0.4f,
        -0.8f, 0.5f,-0.4f,
        -0.8f, 0.5f, 0.4f,

        0.8f, 0.5f, 0.4f,
        -0.8f, 0.5f, 0.4f,
        0.8f,-0.5f, 0.4f
    };
    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
        -0.9f,-0.6f,-0.5f, // triangle 1 : begin
        -0.9f,-0.6f, 0.5f,
        -0.9f, 0.6f, 0.5f, // triangle 1 : end

        0.9f, 0.6f,-0.5f, // triangle 2 : begin
        -0.9f,-0.6f,-0.5f,
        -0.9f, 0.6f,-0.5f, // triangle 2 : end

        0.9f,-0.6f, 0.5f,
        -0.9f,-0.6f,-0.5f,
        0.9f,-0.6f,-0.5f,

        0.9f, 0.6f,-0.5f,
        0.9f,-0.6f,-0.5f,
        -0.9f,-0.6f,-0.5f,

        -0.9f,-0.6f,-0.5f,
        -0.9f, 0.6f, 0.5f,
        -0.9f, 0.6f,-0.5f,

        0.9f,-0.6f, 0.5f,
        -0.9f,-0.6f, 0.5f,
        -0.9f,-0.6f,-0.5f,

        -0.9f, 0.6f, 0.5f,
        -0.9f,-0.6f, 0.5f,
        0.9f,-0.6f, 0.5f,

        0.9f, 0.6f, 0.5f,
        0.9f,-0.6f,-0.5f,
        0.9f, 0.6f,-0.5f,
        //
        0.9f,-0.6f,-0.5f,
        0.9f, 0.6f, 0.5f,//1
        0.9f,-0.6f, 0.5f,

        0.9f, 0.6f, 0.5f,
        -0.9f, 0.6f, 0.5f,
        0.9f,-0.6f, 0.5f
    };
    this->object[1] = create3DObject(GL_TRIANGLES, 30, vertex_buffer_data2, COLOR_BROWN, GL_FILL);
    //
    // float angle = 0.0;
    // float r =0.2;
    // float height = 1.6;
    // int top = 0;
    // static const GLfloat vertex_buffer_data3[750];
    // while(angle < 180.0f)
    // {
    //       vertex_buffer_data[top++] = (r)*cos(angle*M_PI/180.0);
    //       vertex_buffer_data[top++] = (r)*sin(angle*M_PI/180.0) + 0.5;
    //       vertex_buffer_data[top++] = height/2;
    //       vertex_buffer_data[top++] = (r)*cos(angle*M_PI/180.0);
    //       vertex_buffer_data[top++] = (r)*sin(angle*M_PI/180.0) + 0.5;
    //       vertex_buffer_data[top++] = 0.0;
    //     angle += 1;
    // }
    // angle = 0.0;
    // while(angle < 180.0f)
    // {
    //       vertex_buffer_data[top++] = (r)*cos(angle*M_PI/180.0);
    //       vertex_buffer_data[top++] = (r)*sin(angle*M_PI/180.0) + 0.5;
    //       vertex_buffer_data[top++] = -height/2;
    //       vertex_buffer_data[top++] = (r)*cos(angle*M_PI/180.0);
    //       vertex_buffer_data[top++] = (r)*sin(angle*M_PI/180.0) + 0.5;
    //       vertex_buffer_data[top++] = 0.0;
    //     angle += 1;
    // }
    // this->object[2] = create3DObject(GL_LINES, 720, vertex_buffer_data3, COLOR_BARREL, GL_FILL);

}

void Treasure::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object[0]);
    draw3DObject(this->object[1]);
  //  draw3DObject(this->object[2]);
}

void Treasure::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Treasure::tick() {
    this->rotation += 1;
}

bounding_box_t Treasure::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z,0.5 ,0.5};
    return bbox;
}
