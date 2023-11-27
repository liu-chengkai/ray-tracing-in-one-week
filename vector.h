#pragma once
#include "math.h"
#include <iostream>

class vec3
{
    public:
        vec3(float x, float y, float z) : x(x), y(y), z(z)
        {
        }
        float x;
        float y;
        float z;

        inline const vec3 operator-() const
        {
            return vec3(-x, -y, -z);
        }

        inline vec3& operator-=(const vec3& v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            return *this;
        }

        inline vec3& operator+=(const vec3& v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        inline vec3& operator/=(const vec3& v)
        {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            return *this;
        }

        inline vec3& operator*=(const vec3& v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            return *this;
        }

        inline vec3 operator-(const vec3& v)
        {
            return vec3(x - v.x, y - v.y, z - v.z);
        }

        inline vec3 operator+(const vec3& v)
        {
            return vec3(x + v.x, y + v.y, z + v.z);
        }

        inline vec3 operator/(const vec3& v)
        {
            return vec3(x / v.x, y / v.y, z / v.z);
        }

        inline vec3 operator*(const vec3& v)
        {
            return vec3(x * v.x, y * v.y, z * v.z);
        }

        inline std::istream& operator>>(std::istream& is)
        {
            is >> x >> y >> z;
            return is;
        }

        inline std::ostream& operator<<(std::ostream& os)
        {
            os << x << " " << y << " " << z;
            return os;
        }

        inline float dot(const vec3& v)
        {
            return x * v.x + y * v.y + z * v.z;
        }

        inline vec3 cross(const vec3& v)
        {
            return vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
        }

        inline vec3& operator-=(const float v)
        {
            x -= v;
            y -= v;
            z -= v;
            return *this;
        }

        inline vec3& operator+=(const float v)
        {
            x += v;
            y += v;
            z += v;
            return *this;
        }

        inline vec3& operator/=(const float v)
        {
            x /= v;
            y /= v;
            z /= v;
            return *this;
        }

        inline vec3& operator*=(const float v)
        {
            x *= v;
            y *= v;
            z *= v;
            return *this;
        }

        inline vec3 operator-(const float s)
        {
            return vec3(x - s, y - s, z - s);
        }

        inline vec3 operator+(const float s)
        {
            return vec3(x + s, y + s, z + s);
        }

        inline vec3 operator/(const float s)
        {
            return vec3(x / s, y / s, z / s);
        }

        inline vec3 operator*(const float s)
        {
            return vec3(x * s, y * s, z * s);
        }

        inline void normalize()
        {
            *this /= magnitude();
        }

        inline vec3 get_normalized()
        {
            return vec3(x, y, z) / magnitude();
        }

        inline float magnitude()
        {
            return sqrt(squared_magnitude());
        }
        
        inline float squared_magnitude()
        {
            return x * x + y * y + z * z;
        }
};

inline std::ostream& operator<<(std::ostream& os, const vec3& v)
{
    os << v.x << " " << v.y << " " << v.z;
    return os;
}