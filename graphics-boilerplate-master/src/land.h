#include "main.h"

#ifndef Land_H
#define Land_H


class Land {
public:
    Land() {}
    Land(float x, float y, float z,color_t color);
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

#endif // Land_H
