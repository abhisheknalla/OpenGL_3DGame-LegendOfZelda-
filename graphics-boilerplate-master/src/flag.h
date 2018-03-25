#include "main.h"

#ifndef Flag_H
#define Flag_H


class Flag {
public:
    Flag() {}
    Flag(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // Flag_H
