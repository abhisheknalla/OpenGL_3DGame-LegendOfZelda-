#include "main.h"

#ifndef Link_H
#define Link_H


class Link {
public:
    Link() {}
    Link(float x, float y, float z,color_t color);
    glm::vec3 position;
    float rotation;
    float speed_x;
    float speed_y;
    float speed_z;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object[5];
};

#endif // Link_H
