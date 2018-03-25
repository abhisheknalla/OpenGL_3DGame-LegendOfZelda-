#include "link.h"
#include "main.h"

Link::Link(float x, float y,float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->speed_x = 0;
    this->speed_y = 0;
    this->speed_z = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data5[] = {
        -0.10f,0.3f,-0.10f, // triangle 1 : begin
        -0.10f,0.3f, 0.10f,
        -0.10f, 0.60f, 0.10f, // triangle 1 : end

        0.10f, 0.60f,-0.10f, // triangle 2 : begin
        -0.10f,0.3f,-0.10f,
        -0.10f, 0.60f,-0.10f, // triangle 2 : end

        0.10f,0.3f, 0.10f,
        -0.10f,0.3f,-0.10f,
        0.10f,0.3f,-0.10f,

        0.10f, 0.60f,-0.10f,
        0.10f,0.3f,-0.10f,
        -0.10f,0.3f,-0.10f,

        -0.10f,0.3f,-0.10f,
        -0.10f, 0.60f, 0.10f,
        -0.10f, 0.60f,-0.10f,

        0.10f,0.3f, 0.10f,
        -0.10f,0.3f, 0.10f,
        -0.10f,0.3f,-0.10f,

        -0.10f, 0.60f, 0.10f,
        -0.10f,0.3f, 0.10f,
        0.10f,0.3f, 0.10f,

        0.10f, 0.60f, 0.10f,
        0.10f,0.3f,-0.10f,
        0.10f, 0.60f,-0.10f,

        0.10f,0.3f,-0.10f,
        0.10f, 0.60f, 0.10f,
        0.10f,0.3f, 0.10f,

        0.10f, 0.60f, 0.10f,
        0.10f, 0.60f,-0.10f,
        -0.10f, 0.60f,-0.10f,

        0.10f, 0.60f, 0.10f,
        -0.10f, 0.60f,-0.10f,
        -0.10f, 0.60f, 0.10f,

        0.10f, 0.60f, 0.10f,
        -0.10f, 0.60f, 0.10f,
        0.10f,0.3f, 0.10f

        -0.10f, 0.40f, 0.0f,
        -0.20f, 0.20f, 0.0f,
        -0.10f, 0.20f, 0.0f,

              0.10f, 0.40f, 0.0f,
              0.20f, 0.20f, 0.0f,
              0.10f, 0.20f, 0.0f,
    };

    this->object[0] = create3DObject(GL_TRIANGLES, 36, vertex_buffer_data5, COLOR_LINK, GL_FILL);

    static const GLfloat vertex_buffer_data6[] = {
        -0.15f,0.60f,-0.15f, // triangle 1 : begin
        -0.15f,0.60f, 0.15f,
        -0.15f,  0.90f, 0.15f, // triangle 1 : end

        0.15f,  0.90f,-0.15f, // triangle 2 : begin
        -0.15f,0.60f,-0.15f,
        -0.15f,  0.90f,-0.15f, // triangle 2 : end

        0.15f,0.60f, 0.15f,
        -0.15f,0.60f,-0.15f,
        0.15f,0.60f,-0.15f,

        0.15f,  0.90f,-0.15f,
        0.15f,0.60f,-0.15f,
        -0.15f,0.60f,-0.15f,

        -0.15f,0.60f,-0.15f,
        -0.15f,  0.90f, 0.15f,
        -0.15f,  0.90f,-0.15f,

        0.15f,0.60f, 0.15f,
        -0.15f,0.60f, 0.15f,
        -0.15f,0.60f,-0.15f,

        -0.15f,  0.90f, 0.15f,
        -0.15f,0.60f, 0.15f,
        0.15f,0.60f, 0.15f,

        0.15f,  0.90f, 0.15f,
        0.15f,0.60f,-0.15f,
        0.15f,  0.90f,-0.15f,

        0.15f,0.60f,-0.15f,
        0.15f,  0.90f, 0.15f,
        0.15f,0.60f, 0.15f,

        0.15f,  0.90f, 0.15f,
        0.15f,  0.90f,-0.15f,
        -0.15f,  0.90f,-0.15f,

        0.15f,  0.90f, 0.15f,
        -0.15f,  0.90f,-0.15f,
        -0.15f,  0.90f, 0.15f,

        0.15f,  0.90f, 0.15f,
        -0.15f,  0.90f, 0.15f,
        0.15f,0.60f, 0.15f
    };
    this->object[1] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data6, COLOR_FACE, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
      0.1f, 0.6f , -0.1f,
      0.3f, 0.2f , -0.15f,
      0.1f, 0.4f , -0.1f,

      -0.1f, 0.6f , -0.1f,
      -0.3f, 0.2f , -0.15f,
      -0.1f, 0.4f , -0.1f,

      0.1f, 0.3f , -0.1f,
      0.15f, -0.2f , -0.15f,
      0.0f, 0.3f , -0.1f,

      -0.1f, 0.3f , -0.1f,
      -0.15f, -0.2f , -0.15f,
      -0.0f, 0.3f , -0.1f,
          };
    this->object[2] = create3DObject(GL_TRIANGLES, 24, vertex_buffer_data2, COLOR_FACE, GL_FILL);
}

void Link::draw(glm::mat4 VP) {
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
    draw3DObject(this->object[2]);
}

void Link::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Link::tick() {
  this->position.x = this->position.x + (this->speed_z)*(sin((this->rotation)*M_PI/180.0));
  this->position.z = this->position.z + (this->speed_z)*(cos((this->rotation)*M_PI/180.0));

  if(this->speed_z > 0)
   this->speed_z -= 0.00025;
  else if(this->speed_z < 0)
   this->speed_z += 0.00025;
//    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Link::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z,1 ,1};
    return bbox;
}
