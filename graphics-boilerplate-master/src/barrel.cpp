#include "barrel.h"
#include "main.h"

Barrel::Barrel(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y+0.1, z);
    this->rotation = 0;
    this->speed_x = 0;
    this->speed_z = 0;
    speed = 1;
    float angle = 0;
    float r =0.2;
    float height = 0.8;
    int top = 0;
    GLfloat vertex_buffer_data[7500];
    while(angle < 360.0f)
    {
          vertex_buffer_data[top++] = (r+0.01)*cos(angle*M_PI/180.0);
          vertex_buffer_data[top++] = (r+0.01)*sin(angle*M_PI/180.0);
          vertex_buffer_data[top++] = height;
          vertex_buffer_data[top++] = (r+0.01)*cos(angle*M_PI/180.0);
          vertex_buffer_data[top++] = (r+0.01)*sin(angle*M_PI/180.0);
          vertex_buffer_data[top++] = 0.0;
        angle += 1;
    }
    this->object[0] = create3DObject(GL_LINES, 720, vertex_buffer_data, COLOR_BARREL, GL_FILL);
    angle = 0.0;
    int i;
for(i=0;i<3240;){
    vertex_buffer_data[i] = (0.2 * cos(angle) - 0.0 * sin(angle));
    vertex_buffer_data[i + 1] = (0.2 * sin(angle) + 0.0 * cos(angle));
    vertex_buffer_data[i + 2] = 0.0;

    vertex_buffer_data[i + 3] = (0.2 * cos(angle + M_PI/180.0) - 0.0 * sin(angle + M_PI/180.0));
    vertex_buffer_data[i + 4] = (0.2 * sin(angle + M_PI/ 180.0) + 0.0 * cos(angle + M_PI/ 180.0));
    vertex_buffer_data[i + 5] = 0.0;

    vertex_buffer_data[i + 6] = 0;
    vertex_buffer_data[i + 7] = 0;
    vertex_buffer_data[i + 8] = 0.0;
    i+=9;
    angle = M_PI/180.0 + angle;
}
this->object[1] = create3DObject(GL_TRIANGLES, 1080, vertex_buffer_data, color, GL_FILL);


angle = 0.0;
for(i=0;i<3240;){
vertex_buffer_data[i] = (0.2 * cos(angle) - 0.0 * sin(angle));
vertex_buffer_data[i + 1] = (0.2 * sin(angle) + 0.0 * cos(angle));
vertex_buffer_data[i + 2] = 0.8;

vertex_buffer_data[i + 3] = (0.2 * cos(angle + M_PI/180.0) - 0.0 * sin(angle + M_PI/180.0));
vertex_buffer_data[i + 4] = (0.2 * sin(angle + M_PI/ 180.0) + 0.0 * cos(angle + M_PI/ 180.0));
vertex_buffer_data[i + 5] = 0.8;

vertex_buffer_data[i + 6] = 0;
vertex_buffer_data[i + 7] = 0;
vertex_buffer_data[i + 8] = 0.8;
i+=9;
angle = M_PI/180.0 + angle;
}
this->object[2] = create3DObject(GL_TRIANGLES, 1080, vertex_buffer_data, color, GL_FILL);

}

void Barrel::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1  , 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object[0]);
    draw3DObject(this->object[1]);
    draw3DObject(this->object[2]);
}

void Barrel::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y+0.1, z);
}

int barrel_wobble = 0;
void Barrel::tick() {
  int rot = rand()%2;
  if(rot==0)
    this->rotation += 2;
  else
    this->rotation -= 2;

  int number = rand()%4;
  if(number==0)
  {
    this->speed_x += 0.01;
    this->speed_z += 0.01;
  }
  if(number==1)
  {
    this->speed_x += 0.01;
    this->speed_z -= 0.01;
    //
    // this->position.x += 0.1;
    // this->position.z -= 0.1;
  }
  if(number==2)
  {
    this->speed_x -= 0.01;
    this->speed_z -= 0.01;
    //
    // this->position.x -= 0.1;
    // this->position.z -= 0.1;
  }
  if(number==3)
  {
    this->speed_x -= 0.01;
    this->speed_z += 0.01;
    //
    // this->position.x -= 0.1;
    // this->position.z += 0.1;
  }


  //
  // if(barrel_wobble==0)
  // {
  //   this->position.y += 0.5;
  //   barrel_wobble=1;
  // }
  // if(barrel_wobble==1)
  // {
  //   this->position.y -= 0.5;
  //   barrel_wobble=0;
  // }
//printf("%lf %lf\n",this->speed_x, this->speed_z);
     this->position.x += this->speed_x;
     this->position.z += this->speed_z;
}


bounding_box_t Barrel::bounding_box() {
    float x = this->position.x, z = this->position.z;
    bounding_box_t bbox = { x, z, 0.4 ,0.8};
    return bbox;
}
