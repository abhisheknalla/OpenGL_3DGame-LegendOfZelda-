#include "boat.h"
#include "main.h"

Boat::Boat(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->speed_x = 0;
    this->speed_y = 0;
    this->speed_z = 0;
    this->in_air = 0;
    this->heading = 0;
    speed = 1;
    head = 0;
    static const GLfloat vertex_buffer_data[] = {//BASE
        -0.35f,0.0f,-0.4f, // triangle 1 : begin
        -0.25f,0.0f, 0.6f,
        -0.25f, 0.1f, 0.6f, // triangle 1 : end

        0.0f, 0.1f,-0.6f, // triangle 2 : begin
        -0.35f,0.0f,-0.4f,
        -0.35f, 0.1f,-0.4f, // triangle 2 : end

        0.35f, 0.1f,-0.4f, // triangle 2 : begin
        0.35f,0.0f,-0.4f,//EXTRA
        0.0f, 0.0f,-0.6f, // triangle 2 : end

      //   0.0f, 0.2f,-0.6f, // triangle 2 : begin
      //   -0.35f,0.1f,-0.4f,
      //   -0.35f, 0.2f,-0.4f,
       //
      //          0.0f, 0.2f,-0.6f, // triangle 2 : begin
      //          -0.35f,0.1f,-0.4f,
      //          -0.0f, 0.1f,-0.6f,
      //    // triangle 2 : end
      //  0.35f, 0.2f,-0.4f,
      //   0.35f,0.1f,-0.4f,
      //  0.0f,0.1f,-0.6f,
       //
       //
      //  0.35f, 0.2f,-0.4f,
      //  0.0f,0.2f,-0.6f,
      //  0.0f,0.1f,-0.6f,
       //
        0.25f,0.0f, 0.6f,
        -0.35f,0.0f,-0.4f,
        0.35f,0.0f,-0.4f,

        0.0f, 0.1f,-0.6f,
        -0.35f,0.0f,-0.4f,
        -0.0f,0.0f,-0.6f,

                0.35f, 0.1f,-0.4f,
                -0.0f,0.1f,-0.6f,//EXTRA
                -0.0f,0.0f,-0.6f,

        -0.35f,0.0f,-0.4f,
        -0.25f, 0.1f, 0.6f,
        -0.35f, 0.1f,-0.4f,

        0.25f,0.0f, 0.6f,
        -0.25f,0.0f, 0.6f,
        -0.35f,0.0f,-0.4f,

        -0.25f, 0.1f, 0.6f,
        -0.25f,0.0f, 0.6f,
        0.25f,0.0f, 0.6f,

        0.25f, 0.1f, 0.6f,
        0.35f,0.0f,-0.4f,
        0.35f, 0.1f,-0.4f,

        0.35f,0.0f,-0.4f,
        0.25f, 0.1f, 0.6f,
        0.25f,0.0f, 0.6f,

        0.25f, 0.1f, 0.6f,
        0.35f, 0.1f,-0.4f,
        -0.35f, 0.1f,-0.4f,

        0.25f, 0.1f, 0.6f,
        -0.35f, 0.1f,-0.4f,
        -0.25f, 0.1f, 0.6f,

        0.25f, 0.1f, 0.6f,
        -0.25f, 0.1f, 0.6f,
        0.25f,0.0f, 0.6f,

        -0.35f, 0.1f,-0.4f,
        0.0f, 0.1f, -0.6f,
        0.35f, 0.1f , -0.4f,
    };
    this->object[0] = create3DObject(GL_TRIANGLES, 12*3 + 6 + 3, vertex_buffer_data, COLOR_BROWN, GL_FILL);

    static const GLfloat vertex_buffer_data2[] = {//HOST LONG
        -0.025f,0.0f,-0.025f, // triangle 1 : begin
        -0.025f,0.0f, 0.025f,
        -0.025f, 1.1f, 0.025f, // triangle 1 : end

        0.025f, 1.1f,-0.025f, // triangle 2 : begin
        -0.025f,0.0f,-0.025f,
        -0.025f, 1.1f,-0.025f, // triangle 2 : end

        0.025f,0.0f, 0.025f,
        -0.025f,0.0f,-0.025f,
        0.025f,1.1f,-0.025f,

        0.025f, 1.1f,-0.025f,
        0.025f,0.0f,-0.025f,
        -0.025f,1.1f,-0.025f,

        -0.025f,0.0f,-0.025f,
        -0.025f, 1.1f, 0.025f,
        -0.025f, 1.1f,-0.025f,

        0.025f,0.0f, 0.025f,
        -0.025f,0.0f, 0.025f,
        -0.025f,0.0f,-0.025f,

        -0.025f, 1.1f, 0.025f,
        -0.025f,0.0f, 0.025f,
        0.025f,0.0f, 0.025f,

        0.025f, 1.1f, 0.025f,
        0.025f,0.0f,-0.025f,
        0.025f, 1.1f,-0.025f,

        0.025f,0.0f,-0.025f,
        0.025f, 1.1f, 0.025f,
        0.025f,0.0f, 0.025f,

        0.025f, 1.1f, 0.025f,
        0.025f, 1.1f,-0.025f,
        -0.025f, 1.1f,-0.025f,

        0.025f, 1.1f, 0.025f,
        -0.025f, 1.1f,-0.025f,
        -0.025f, 1.1f, 0.025f,

        0.025f, 1.1f, 0.025f,
        -0.025f, 1.1f, 0.025f,
        0.025f,0.0f, 0.025f
    };

    this->object[1] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data2, COLOR_GREEN2, GL_FILL);


  static const GLfloat vertex_buffer_data3[] = {//SAIL
      -0.4f,0.5f,-0.2f, // triangle 1 : begin
      0.0f, 0.5f,-0.3f,
      0.0f, 1.1f, -0.1f, // triangle 1 : end

      0.4f, 0.5f,-0.2f, // triangle 2 : begin
      0.0f,0.5f,-0.3f,
      0.0f, 1.1f,-0.1f, // triangle 2 : end

      -0.4f,0.5f,-0.2f,
      0.0f,0.5f,-0.3f,
      0.0f,0.1f,-0.1f,

      0.4f, 0.5f,-0.2f,
      0.0f,0.5f,-0.3f,
      0.0f,0.1f,-0.1f,
  };

  this->object[2] = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data3, COLOR_WHITE, GL_FILL);

  static const GLfloat vertex_buffer_data4[] = {//SURROUNDING
      -0.35f,0.1f,-0.4f, // triangle 1 : begin
      -0.25f,0.1f, 0.6f,
      -0.25f, 0.2f, 0.6f, // triangle 1 : end

       0.0f, 0.2f,-0.6f, // triangle 2 : begin
       -0.35f,0.1f,-0.4f,
       -0.35f, 0.2f,-0.4f,

              0.0f, 0.2f,-0.6f, // triangle 2 : begin
              -0.35f,0.1f,-0.4f,
              -0.0f, 0.1f,-0.6f,
        // triangle 2 : end
      0.35f, 0.2f,-0.4f,
       0.35f,0.1f,-0.4f,
     0.0f,0.1f,-0.6f,


   0.35f, 0.2f,-0.4f,
    0.0f,0.2f,-0.6f,
  0.0f,0.1f,-0.6f,


      -0.35f,0.1f,-0.4f,
      -0.25f, 0.2f, 0.6f,
      -0.35f, 0.2f,-0.4f,

       -0.25f, 0.2f, 0.6f,
       -0.25f,0.1f, 0.6f,
       0.25f,0.1f, 0.6f,

      0.25f, 0.2f, 0.6f,
       0.35f,0.1f,-0.4f,
       0.35f, 0.2f,-0.4f,
      //
       0.35f,0.1f,-0.4f,
       0.25f, 0.2f, 0.6f,
       0.25f,0.1f, 0.6f,

       0.25f, 0.2f, 0.6f,
       -0.25f, 0.1f, 0.6f,
       0.25f,0.1f, 0.6f
  };
  this->object[3] = create3DObject(GL_TRIANGLES, 30, vertex_buffer_data4, COLOR_RED, GL_FILL);

  static const GLfloat vertex_buffer_data5[] = {
        };

  this->object[4] = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, COLOR_LINK, GL_FILL);

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

  this->object[5] = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data6, COLOR_FACE, GL_FILL);
}


void Boat::draw(glm::mat4 VP, int no) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    if(no==0 || no==1)
    {
      draw3DObject(this->object[0]);
      draw3DObject(this->object[1]);
      draw3DObject(this->object[2]);
      draw3DObject(this->object[3]);
    }
}

void Boat::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}
int count = 0;
void Boat::tick() {
   //this->rotation += speed;
  if(this->speed_y <= 0 && this->in_air==1)
  {
    this->in_air = 2;
  }
  if(this->position.y < 1 && this->in_air == 2)
  {
    this->in_air = 0;
    this->speed_y = 0;
    this->position.y = 1;
  }
  if(this->in_air == 1)
  {
    this->position.y += this->speed_y;
    this->speed_y -= 0.01;
  }
  if(this->in_air==2)
  {
    this->speed_y += 0.01;
    this->position.y -= this->speed_y;
  }

  this->position.x = this->position.x + (this->speed_z)*(sin((this->rotation)*M_PI/180.0));
  this->position.z = this->position.z + (this->speed_z)*(cos((this->rotation)*M_PI/180.0));

  // if(this->speed_x > 0)
  //   this->speed_x -= 0.00025;
  // else
  //   this->speed_x += 0.00025;
   if(this->speed_z > 0)
    this->speed_z -= 0.00025;
   else if(this->speed_z < 0)
    this->speed_z += 0.00025;

    float diff_x = this->position.x - this->prev_x;
    float diff_z = this->position.z - this->prev_z;

    if(diff_x > 0 && diff_z > 0)
    {//SE
      this->heading = 1;
    }
    if(diff_x > 0 && diff_z < 0)
    {//NE
      this->heading = 2;
    }
    if(diff_x < 0 && diff_z > 0)
    {//SW
      this->heading = 3;
    }
    if(diff_x < 0 && diff_z < 0)
    {//NW
      this->heading = 4;
    }
    if(diff_x > 0 && diff_z == 0)
    {//E
      this->heading = 5;
    }
    if(diff_x < 0 && diff_z == 0)
    {//W
      this->heading = 6;
    }
    if(diff_x == 0 && diff_z > 0)
    {//S
      this->heading = 7;
    }
    if(diff_x == 0 && diff_z < 0)
    {//N
      this->heading = 8;
    }

    this->prev_x = this->position.x;
    this->prev_z = this->position.z;
}

bounding_box_t Boat::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x,z, 0.5 , 1.0 };
    return bbox;
}
