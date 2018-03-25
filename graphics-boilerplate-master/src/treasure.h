#include "main.h"

#ifndef Treasure_H
#define Treasure_H


class Treasure {
public:
    Treasure() {}
    Treasure(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object[3];
};

#endif // Treasure_H
