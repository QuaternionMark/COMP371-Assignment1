#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include <vector>
#include <GL/glew.h>

#include "../Math/Vector.h"

class Cube;
class Shader;

class Car {
private:
    Vector3f position;
    Vector3f scale;
    Vector3f rotation;
    GLenum renderingMode;
    
    std::vector<Cube*> cubes;
    Cube* wheels[4];
    
public:
    Car(Shader* shd);
    
    enum class WalkInput {
        None = 0x0,
        Forward = 0x1,
        Backward = 0x2,
        Left = 0x4,
        Right = 0x8
    };
    
    void walk(WalkInput input, float speed);
    void addPositionXZ(const Vector2f& vect);
    void setScale(float x, float y, float z);
    void addScale(float sca);
    void addRotationX(float bruh);
    void addRotationY(float bruh);
    void addRotationZ(float bruh);
    void setRenderingMode(GLenum mode);
    
    void render();
};

const Car::WalkInput operator&(const Car::WalkInput& a, const Car::WalkInput& b);
const Car::WalkInput operator|(const Car::WalkInput& a, const Car::WalkInput& b);

#endif // CAR_H_INCLUDED
