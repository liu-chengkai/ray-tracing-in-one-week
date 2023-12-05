#include "ray.h"

ray::ray(const vec3 &origin, const vec3 &direction) : origin(origin), direction(direction)
{
}

vec3 ray::get_origin() const
{
    return origin;
}

vec3 ray::get_direction() const
{
    return direction;
}

vec3 ray::get_point_at_parameter(float t)
{
    return origin + direction * t;
}
