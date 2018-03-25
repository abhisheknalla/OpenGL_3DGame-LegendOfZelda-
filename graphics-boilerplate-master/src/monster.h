#include "main.h"

#ifndef Monster_H
#define Monster_H


class Monster {
public:
    Monster() {}
    Monster(float x, float y, float z, color_t color, int type);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t bounding_box();
    double speed;
private:
    VAO *object[3];
};

#endif // Monster_H
