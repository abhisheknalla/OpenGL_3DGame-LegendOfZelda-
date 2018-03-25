#include "main.h"

#ifndef Boss_H
#define Boss_H


class Boss {
public:
    Boss() {}
    Boss(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick(glm::vec3 a);
    bounding_box_t bounding_box();
    double speed;
private:
    VAO *object[3];
};

#endif // Boss_H
