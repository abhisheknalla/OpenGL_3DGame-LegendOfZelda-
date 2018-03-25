#include "main.h"

#ifndef Barrel_H
#define Barrel_H

class Barrel{
public:
    Barrel() {}
    Barrel(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float speed_x;
    float speed_z;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t bounding_box();
    double speed;
private:
    VAO *object[3];
};

#endif // Barrel_H
