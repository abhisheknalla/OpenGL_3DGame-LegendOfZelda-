#include "twister.h"
#include "main.h"

Twister::Twister(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    static const GLfloat vertex_buffer_data[] = {
        -0.2f,-0.2f,-0.2f, // triangle 1 : begin
        -0.2f,-0.2f, 0.2f,
        -0.2f, 0.2f, 0.2f, // triangle 1 : end

        0.2f, 0.2f,-0.2f, // triangle 2 : begin
        -0.2f,-0.2f,-0.2f,
        -0.2f, 0.2f,-0.2f, // triangle 2 : end

        0.2f,-0.2f, 0.2f,
        -0.2f,-0.2f,-0.2f,
        0.2f,-0.2f,-0.2f,

        0.2f, 0.2f,-0.2f,
        0.2f,-0.2f,-0.2f,
        -0.2f,-0.2f,-0.2f,

        -0.2f,-0.2f,-0.2f,
        -0.2f, 0.2f, 0.2f,
        -0.2f, 0.2f,-0.2f,

        0.2f,-0.2f, 0.2f,
        -0.2f,-0.2f, 0.2f,
        -0.2f,-0.2f,-0.2f,

        -0.2f, 0.2f, 0.2f,
        -0.2f,-0.2f, 0.2f,
        0.2f,-0.2f, 0.2f,

        0.2f, 0.2f, 0.2f,
        0.2f,-0.2f,-0.2f,
        0.2f, 0.2f,-0.2f,

        0.2f,-0.2f,-0.2f,
        0.2f, 0.2f, 0.2f,
        0.2f,-0.2f, 0.2f,

        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f,-0.2f,
        -0.2f, 0.2f,-0.2f,

        0.2f, 0.2f, 0.2f,
        -0.2f, 0.2f,-0.2f,
        -0.2f, 0.2f, 0.2f,

        0.2f, 0.2f, 0.2f,
        -0.2f, 0.2f, 0.2f,
        0.2f,-0.2f, 0.2f
    };

    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_DARKGREEN, GL_FILL);
    static const GLfloat vertex_buffer_data2[] = {//SURROUNDING
      0.0, 0.2 , 0.0,
      2.0, 0.2 , 0.0,
      1.0, 0.2 , -0.5,

      -0.0, 0.2 , 0.0,
      -2.0, 0.2 , 0.0,
      -1.0, 0.2 , 0.5,
    };
    this->object[1] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data2,COLOR_HORN, GL_FILL);
}

void Twister::draw(glm::mat4 VP) {
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
}

void Twister::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Twister::tick() {
    this->rotation += 15;
    int x_move = rand()%2;
    int y_move = rand()%2;
    if(x_move == 0 && y_move == 0)//SE
    {
      this->position.x += 0.3;
      this->position.z += 0.3;
    }
    if(x_move == 0 && y_move == 1)//NE
    {
      this->position.x += 0.3;
      this->position.z -= 0.3;
    }
    if(x_move == 1 && y_move == 0)//NW
    {
      this->position.x -= 0.3;
      this->position.z -= 0.3;
    }
    if(x_move == 1 && y_move == 1)//SW
    {
      this->position.x -= 0.3;
      this->position.z += 0.3;
    }
    if((this->position.x < -20 && this->position.x > -30)||(this->position.x > 20 && this->position.x < 30))
    {
      this->position.x = 0.5;
    }
    if((this->position.z < -45 && this->position.z > -50)||(this->position.z > -15 && this->position.z < -10))
    {
      this->position.z = -30;
    }
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Twister::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 1 ,1};
    return bbox;
}
