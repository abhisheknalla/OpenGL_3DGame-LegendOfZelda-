#include "main.h"

#ifndef Booster_H
#define Booster_H


class Booster {
public:
    Booster() {}
    Booster(float x, float y, float z,color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    double speed;
    bounding_box_t bounding_box();
private:
    VAO *object;
};

#endif // Booster_H
