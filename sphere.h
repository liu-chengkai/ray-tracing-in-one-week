#include "hitable.h"
#include "vector.h"

class sphere: public hitable {
    public:
        vec3 center;
        float radius;
        sphere(vec3 center, float radius): center(center), radius(radius){};
        bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const override;
};