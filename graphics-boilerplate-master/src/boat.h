#include "main.h"

#ifndef Boat_H
#define Boat_H


class Boat {
public:
    Boat() {}
    Boat(float x, float y, float z, color_t color);
    glm::vec3 position;
  float rotation;
  int in_air;
    int head;
    float speed_x;
    float speed_y;
    float speed_z;
    float prev_x;
    float prev_z;
    int heading;
    void draw(glm::mat4 VP, int no);
  //  void rot(int number, float angle);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t bounding_box();
    double speed;
    VAO *object[6];
private:
};

#endif // Boat_H
