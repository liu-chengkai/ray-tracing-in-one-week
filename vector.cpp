#include "vector.h"
#include "math.h"

inline vector3& vector3::operator-=(const vector3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline vector3& vector3::operator+=(const vector3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline vector3& vector3::operator/=(const vector3& v)
{
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}

inline vector3& vector3::operator*=(const vector3& v)
{
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}

inline vector3 vector3::operator-(const vector3 &v)
{
    return vector3(x - v.x, y - v.y, z - v.z);
}

inline vector3 vector3::operator+(const vector3 &v)
{
    return vector3(x + v.x, y + v.y, z + v.z);
}

inline vector3 vector3::operator/(const vector3 &v)
{
    return vector3(x / v.x, y / v.y, z / v.z);
}

inline vector3 vector3::operator*(const vector3 &v)
{
    return vector3(x * v.x, y * v.y, z * v.z);
}

inline std::istream &vector3::operator>>(std::istream &is)
{
    is >> x >> y >> z;
    return is;
}

inline std::ostream &vector3::operator<<(std::ostream &os)
{
    os << x << " " << y << " " << z;
    return os;
}

inline float vector3::dot(const vector3 &v)
{
    return x * v.x + y * v.y + z * v.z;
}

inline vector3 vector3::cross(const vector3 &v)
{
    return vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

inline vector3& vector3::operator-=(const float v)
{
    x -= v;
    y -= v;
    z -= v;
    return *this;
}

inline vector3& vector3::operator+=(const float v)
{
    x += v;
    y += v;
    z += v;
    return *this;
}

inline vector3& vector3::operator/=(const float v)
{
    x /= v;
    y /= v;
    z /= v;
    return *this;
}

inline vector3& vector3::operator*=(const float v)
{
    x *= v;
    y *= v;
    z *= v;
    return *this;
}

inline vector3 vector3::operator-(const float s)
{
    return vector3(x - s, y - s, z - s);
}

inline vector3 vector3::operator+(const float s)
{
    return vector3(x + s, y + s, z + s);
}

inline vector3 vector3::operator/(const float s)
{
    return vector3(x + s, y + s, z + s);
}

inline vector3 vector3::operator*(const float s)
{
    return vector3(x * s, y * s, z * s);
}

inline void vector3::normalize()
{
    *this /= magnitude();
}

inline vector3 vector3::normalized()
{
    return vector3(x, y, z) / magnitude();
}

