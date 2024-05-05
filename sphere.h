#pragma once
#include "hitable.h"
#include "vector.h"
#include "material.h"

class sphere: public hitable {
    public:
        vec3 center;
        float radius;
        material* mat;
        sphere(vec3 center, float radius, material* mat): center(center), radius(radius), mat(mat){};
        bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;
};