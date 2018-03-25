#include "main.h"

#ifndef Shark_H
#define Shark_H


class Shark {
public:
    Shark() {}
    Shark(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float speed_x;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t bounding_box();
    double speed;
private:
    VAO *object;
};

#endif // Shark_H
