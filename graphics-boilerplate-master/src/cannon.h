#include "main.h"

#ifndef Cannon_H
#define Cannon_H


class Cannon {
public:
    Cannon() {}
    Cannon(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP, int no);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object[2];
};

#endif // Cannon_H
