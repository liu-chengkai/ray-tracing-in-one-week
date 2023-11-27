#pragma once
#include "vector.h"

class ray
{
    public:
        ray(const vec3& origin, const vec3& direction);
        vec3 get_origin() const;
        vec3 get_direction();
        vec3 get_point_at_parameter(float t);

    private:
        vec3 origin;
        vec3 direction;
};