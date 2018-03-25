#include "boss.h"
#include "main.h"

Boss::Boss(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y-0.2, z);
    this->rotation = 0;
    speed = 1;
    static const GLfloat vertex_buffer_data[] = {
        -1.5f,-1.0f,-1.5f, // triangle 1 : begin
        -1.5f,-1.0f, 1.5f,
        -1.0f, 2.0f, 1.5f, // triangle 1 : end

        1.0f, 2.0f,-1.5f, // triangle 2 : begin
        -1.5f,-1.0f,-1.5f,
        -1.0f, 2.0f,-1.5f, // triangle 2 : end

        1.5f,-1.0f, 1.5f,
        -1.5f,-1.0f,-1.5f,
        1.5f,-1.0f,-1.5f,

        1.0f, 2.0f,-1.5f,
        1.5f,-1.0f,-1.5f,
        -1.5f,-1.0f,-1.5f,

        -1.5f,-1.0f,-1.5f,
        -1.0f, 2.0f, 1.5f,
        -1.0f, 2.0f,-1.5f,

        1.5f,-1.0f, 1.5f,
        -1.5f,-1.0f, 1.5f,
        -1.5f,-1.0f,-1.5f,

        -1.0f, 2.0f, 1.5f,
        -1.5f,-1.0f, 1.5f,
        1.5f,-1.0f, 1.5f,

        1.0f, 2.0f, 1.5f,
        1.5f,-1.0f,-1.5f,
        1.0f, 2.0f,-1.5f,

        1.5f,-1.0f,-1.5f,
        1.0f, 2.0f, 1.5f,
        1.5f,-1.0f, 1.5f,

        1.0f, 2.0f, 1.5f,
        1.0f, 2.0f,-1.5f,
        -1.0f, 2.0f,-1.5f,

        1.0f, 2.0f, 1.5f,
        -1.0f, 2.0f,-1.5f,
        -1.0f, 2.0f, 1.5f,

        1.0f, 2.0f, 1.5f,
        -1.0f, 2.0f, 1.5f,
        1.5f,-1.0f, 1.5f
    };
    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
        -1.0f, 2.0f , 0.4f,
        -0.4f, 2.0f, 0.4f,
        -1.5f, 4.0f, 0.4f,

        1.0f, 2.0f , 0.4f,
        0.4f, 2.0f, 0.4f,
        1.5f, 4.0f, 0.4f,


        -1.0f, 1.0f , -0.4f,
        -0.4f, 1.0f, -0.4f,
        -0.25f, 2.0f, -0.4f,

        1.0f, 1.0f , -0.4f,
        0.4f, 1.0f, -0.4f,
        0.25f, 2.0f, -0.4f,

        -1.0f,1.8f,1.5f,
        -0.1f,1.3f,1.5f,
        -0.3f,1.0f,1.5f,

                1.0f,1.8f,1.5f,
                0.1f,1.3f,1.5f,
                0.3f,1.0f,1.5f,
    };
    this->object[1] = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data2, COLOR_HORN, GL_FILL);
}

void Boss::draw(glm::mat4 VP) {
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

void Boss::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Boss::tick(glm::vec3 boat_pos) {
  if(this->position.z >= 20)
  {
    this->position.z = -20;
  }
  float boat_x = boat_pos.x;
  float boat_z = boat_pos.z;
  // if(this->position.z - boat_z >= 10)
  //   this->rotation = 180;
  float rot = atan(((this->position.z - boat_z)/(this->position.x - boat_x)));
  this->position.x += 1.5*(sin(rot));
  rot = atan(abs((this->position.x - boat_x)/(this->position.z - boat_z)));
  this->position.z += 1.5*(cos(rot));
//  printf("roat :%f \n",rot);
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Boss::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 1.3 ,1.3};
    return bbox;
}
