#include "math.h"
#include <iostream>

class vector3
{
    public:
        vector3(float x, float y, float z) : x(x), y(y), z(z)
        {
        }
        float x;
        float y;
        float z;

        inline const vector3& operator-() const
        {
            return vector3(-x, -y, -z);
        }

        inline vector3& operator-=(const vector3& v);
        inline vector3& operator+=(const vector3& v);
        inline vector3& operator/=(const vector3& v);
        inline vector3& operator*=(const vector3& v);
        inline vector3 operator-(const vector3& v);
        inline vector3 operator+(const vector3& v);
        inline vector3 operator/(const vector3& v);
        inline vector3 operator*(const vector3& v);
        inline std::istream& operator>>(std::istream& is);
        inline std::ostream& operator<<(std::ostream& os);
        inline float dot(const vector3& v);
        inline vector3 cross(const vector3& v);
        inline vector3& operator-=(const float v);
        inline vector3& operator+=(const float v);
        inline vector3& operator/=(const float v);
        inline vector3& operator*=(const float v);
        inline vector3 operator-(const float s);
        inline vector3 operator+(const float s);
        inline vector3 operator/(const float s);
        inline vector3 operator*(const float s);
        inline void normalize();
        inline vector3 normalized();

        inline float magnitude()
        {
            return sqrt(squared_magnitude());
        }
        inline float squared_magnitude()
        {
            return x * x + y * y + z * z;
        }
};