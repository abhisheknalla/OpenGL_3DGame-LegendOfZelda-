#include "land.h"
#include "main.h"

Land::Land(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    static const GLfloat vertex_buffer_data[] = {
        -10.0f,-10.0f,-10.0f, // triangle 1 : begin
        -10.0f,-10.0f, 10.0f,
        0, 0, 0, // triangle 1 : end


        10.0f,-10.0f, 10.0f,
        -10.0f,-10.0f,-10.0f,
        10.0f,-10.0f,-10.0f,

        0, 0, 0 ,
        10.0f,-10.0f,-10.0f,
        -10.0f,-10.0f,-10.0f,


        10.0f,-10.0f, 10.0f,
        -10.0f,-10.0f, 10.0f,
        -10.0f,-10.0f,-10.0f,

          0, 0, 0 ,
        -10.0f,-10.0f, 10.0f,
        10.0f,-10.0f, 10.0f,


        10.0f,-10.0f,-10.0f,
          0, 0, 0 ,
        10.0f,-10.0f, 10.0f,

    };
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    this->object[0] = create3DObject(GL_TRIANGLES, 18, vertex_buffer_data, COLOR_GREEN3, GL_FILL);
    GLfloat g_vertex_buffer_data[3240] = {};
      double angle = 0.0;
      int i;
  for(i=0;i<3240;){
      g_vertex_buffer_data[i] = (20 * cos(angle) - 0.0 * sin(angle));
      g_vertex_buffer_data[i + 1] = -8.9;
      g_vertex_buffer_data[i + 2] = (20 * sin(angle) + 0.0 * cos(angle));

      g_vertex_buffer_data[i + 3] = (20 * cos(angle + M_PI/180) - 0.0 * sin(angle + M_PI/180));
      g_vertex_buffer_data[i + 4] = -8.9;
      g_vertex_buffer_data[i + 5] = (20 * sin(angle + M_PI/ 180) + 0.0 * cos(angle + M_PI/ 180));

      g_vertex_buffer_data[i + 6] = 0;
      g_vertex_buffer_data[i + 7] = -8.9;
      g_vertex_buffer_data[i + 8] = 0;
      i+=9;
      angle = M_PI/180 + angle;
  }

  this->object[1] = create3DObject(GL_TRIANGLES, 1080, g_vertex_buffer_data, color, GL_FILL);
}

void Land::draw(glm::mat4 VP) {
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
}

void Land::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Land::tick() {
//    this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Land::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z,38 ,38};
    return bbox;
}
