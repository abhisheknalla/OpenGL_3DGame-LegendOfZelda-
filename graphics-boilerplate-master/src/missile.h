#include "main.h"

#ifndef Missile_H
#define Missile_H


class Missile {
public:
    Missile() {}
    Missile(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float speed_x;
    float speed_z;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(float a);
    bounding_box_t bounding_box();
    double speed;
private:
    VAO *object;
};

#endif // Missile_H
