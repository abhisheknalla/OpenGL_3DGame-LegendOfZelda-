#include "shark.h"
#include "main.h"

Shark::Shark(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y-0.2, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices

    static const GLfloat vertex_buffer_data[] = {
        -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f,

        -0.3f, 0.75f, 0.0f,
        0.5f, 1.25f, 0.0f,
        -0.1f, 0.60f, 0.0f,
    };
    this->object = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data, COLOR_GREY, GL_FILL);
}

void Shark::draw(glm::mat4 VP) {
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

void Shark::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

int head=0;
void Shark::tick() {
    //this->rotation+=2;
    // if(this->rotation==0)
    // else
    //   this->position.x += this->speed_x;
    if(head==0)
    {
      this->speed_x=-0.05;
      this->rotation=0;

    }
    if(head==1)
    {
      this->speed_x=0.05;
      this->rotation=180;
    }
    if(this->position.x > 10)
    {
      head=0;
      //this->speed_x=-0.05;
      this->position.x = 10;
    }
    else if(this->position.x < -10)
    {
      head=1;
      //this->speed_x=0.05;
      this->position.x = -10;
      //this->rotation+=180;
    }
    this->position.x += this->speed_x;


    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Shark::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 1.0 ,1.0};
    return bbox;
}
