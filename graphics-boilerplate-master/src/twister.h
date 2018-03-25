#include "main.h"

#ifndef Twister_H
#define Twister_H


class Twister {
public:
    Twister() {}
    Twister(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object[2];
};

#endif // Twister_H
