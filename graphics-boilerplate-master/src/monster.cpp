#include "monster.h"
#include "main.h"

Monster::Monster(float x, float y, float z, color_t color, int type) {
    this->position = glm::vec3(x, y-0.2, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
  if(type==0)
  {
    static const GLfloat vertex_buffer_data[] = {
        -0.4f,-1.0f,-0.4f, // triangle 1 : begin
        -0.4f,-1.0f, 0.4f,
        -1.0f, 1.0f, 0.4f, // triangle 1 : end

        1.0f, 1.0f,-0.4f, // triangle 2 : begin
        -0.4f,-1.0f,-0.4f,
        -1.0f, 1.0f,-0.4f, // triangle 2 : end

        0.4f,-1.0f, 0.4f,
        -0.4f,-1.0f,-0.4f,
        0.4f,-1.0f,-0.4f,

        1.0f, 1.0f,-0.4f,
        0.4f,-1.0f,-0.4f,
        -0.4f,-1.0f,-0.4f,

        -0.4f,-1.0f,-0.4f,
        -1.0f, 1.0f, 0.4f,
        -1.0f, 1.0f,-0.4f,

        0.4f,-1.0f, 0.4f,
        -0.4f,-1.0f, 0.4f,
        -0.4f,-1.0f,-0.4f,

        -1.0f, 1.0f, 0.4f,
        -0.4f,-1.0f, 0.4f,
        0.4f,-1.0f, 0.4f,

        1.0f, 1.0f, 0.4f,
        0.4f,-1.0f,-0.4f,
        1.0f, 1.0f,-0.4f,

        0.4f,-1.0f,-0.4f,
        1.0f, 1.0f, 0.4f,
        0.4f,-1.0f, 0.4f,

        1.0f, 1.0f, 0.4f,
        1.0f, 1.0f,-0.4f,
        -1.0f, 1.0f,-0.4f,

        1.0f, 1.0f, 0.4f,
        -1.0f, 1.0f,-0.4f,
        -1.0f, 1.0f, 0.4f,

        1.0f, 1.0f, 0.4f,
        -1.0f, 1.0f, 0.4f,
        0.4f,-1.0f, 0.4f
    };
    this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {
        -1.0f, 1.0f , 0.4f,
        -0.4f, 1.0f, 0.4f,
        -0.25f, 2.0f, 0.4f,

        1.0f, 1.0f , 0.4f,
        0.4f, 1.0f, 0.4f,
        0.25f, 2.0f, 0.4f,


                -1.0f, 1.0f , -0.4f,
                -0.4f, 1.0f, -0.4f,
                -0.25f, 2.0f, -0.4f,

                1.0f, 1.0f , -0.4f,
                0.4f, 1.0f, -0.4f,
                0.25f, 2.0f, -0.4f,
    };
    this->object[1] = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data2, COLOR_HORN, GL_FILL);
}
else
{
  static const GLfloat vertex_buffer_data[] = {
      -0.2f,-1.0f,-0.4f, // triangle 1 : begin
      -0.2f,-1.0f, 0.4f,
      -0.6f, 1.0f, 0.4f, // triangle 1 : end

      0.6f, 1.0f,-0.4f, // triangle 2 : begin
      -0.2f,-1.0f,-0.4f,
      -0.6f, 1.0f,-0.4f, // triangle 2 : end

      0.2f,-1.0f, 0.4f,
      -0.2f,-1.0f,-0.4f,
      0.2f,-1.0f,-0.4f,

      0.6f, 1.0f,-0.4f,
      0.2f,-1.0f,-0.4f,
      -0.2f,-1.0f,-0.4f,

      -0.2f,-1.0f,-0.4f,
      -0.6f, 1.0f, 0.4f,
      -0.6f, 1.0f,-0.4f,

      0.2f,-1.0f, 0.4f,
      -0.2f,-1.0f, 0.4f,
      -0.2f,-1.0f,-0.4f,

      -0.6f, 1.0f, 0.4f,
      -0.2f,-1.0f, 0.4f,
      0.2f,-1.0f, 0.4f,

      0.6f, 1.0f, 0.4f,
      0.2f,-1.0f,-0.4f,
      0.6f, 1.0f,-0.4f,

      0.2f,-1.0f,-0.4f,
      0.6f, 1.0f, 0.4f,
      0.2f,-1.0f, 0.4f,

      0.6f, 1.0f, 0.4f,
      0.6f, 1.0f,-0.4f,
      -0.6f, 1.0f,-0.4f,

      0.6f, 1.0f, 0.4f,
      -0.6f, 1.0f,-0.4f,
      -0.6f, 1.0f, 0.4f,

      0.6f, 1.0f, 0.4f,
      -0.6f, 1.0f, 0.4f,
      0.2f,-1.0f, 0.4f
  };
  this->object[0] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);

  static const GLfloat vertex_buffer_data2[] = {
    0.6f, 1.0f , 0.4f,
    1.5f, 0.2f , 0.8f,
    0.6f, 0.7f , 0.4f,

    -0.6f, 1.0f , 0.4f,
    -1.5f, 0.2f , 0.8f,
    -0.6f, 0.7f , 0.4f,

    0.6f, 1.0f , -0.4f,
    1.5f, 0.2f , -0.8f,
    0.6f, 0.7f , -0.4f,

    -0.6f, 1.0f , -0.4f,
    -1.5f, 0.2f , -0.8f,
    -0.6f, 0.7f , -0.4f,
        };
  this->object[1] = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data2, COLOR_HORN, GL_FILL);

}
}

void Monster::draw(glm::mat4 VP) {
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

void Monster::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Monster::tick() {
  this->rotation+=2;
    int x_move = rand()%2;
    int y_move = rand()%2;
    if(x_move == 0 && y_move == 0)//SE
    {
      this->position.x += 1;
      this->position.z += 1;
    }
    if(x_move == 0 && y_move == 1)//NE
    {
      this->position.x += 1;
      this->position.z -= 1;
    }
    if(x_move == 1 && y_move == 0)//NW
    {
      this->position.x -= 1;
      this->position.z -= 1;
    }
    if(x_move == 1 && y_move == 1)//SW
    {
      this->position.x -= 1;
      this->position.z += 1;
    }
    //this->rotation += speed;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

bounding_box_t Monster::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 1.0 ,1.0};
    return bbox;
}
