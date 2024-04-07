#pragma once
#include "math.h"
#include <iostream>

class vec3
{
    public:
        vec3(){
            x = 0;
            y = 0;
            z = 0;
        }
        vec3(float x, float y, float z) : x(x), y(y), z(z)
        {
        }
        float x;
        float y;
        float z;

        inline const vec3 operator+() const
        {
            return *this;
        }

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

        friend vec3 operator-(const vec3& v1, const vec3& v2)
        {
            return vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
        }

        friend vec3 operator+(const vec3& v1, const vec3& v2)
        {
            return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
        }

        friend vec3 operator/(const vec3& v1, const vec3& v2)
        {
            return vec3(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
        }

        friend vec3 operator*(const vec3& v1, const vec3& v2)
        {
            return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
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

        friend inline vec3 operator-(const vec3 &vec, const float s)
        {
            return vec3(vec.x - s, vec.y - s, vec.z - s);
        }

        friend inline vec3 operator-(const float s, const vec3 &vec)
        {
            return -vec + s;
        }

        friend inline vec3 operator+(const vec3 &vec, const float s)
        {
            return vec3(vec.x + s, vec.y + s, vec.z + s);
        }

        friend inline vec3 operator+(const float s, const vec3 &vec)
        {
            return vec + s;
        }

        friend inline vec3 operator/(const vec3 &vec, const float s)
        {
            return vec3(vec.x / s, vec.y / s, vec.z / s);
        }

        friend vec3 operator*(const vec3 &vec, const float s)
        {
            return vec3(vec.x * s, vec.y * s, vec.z * s);
        }

        friend vec3 operator*(const float s, const vec3 &vec)
        {
            return vec * s;
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

inline float dot(const vec3& v1, const vec3& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline vec3 cross(const vec3& v1, const vec3& v2)
{
    return vec3(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}