#include "sphere.h"

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) const 
{
    vec3 oc = r.get_origin() - center;
    float a = dot(r.get_direction(), r.get_direction());
    float b = 2.0 * dot(r.get_direction(), oc);
    float c = dot(oc, oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    rec.mat = mat;
    if (discriminant > 0)
    {
        float temp = (-b - sqrt(discriminant)) / (2 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.get_point_at_parameter(temp);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
        temp = (-b + sqrt(discriminant)) / (2 * a);
        if (temp < t_max && temp > t_min) {
            rec.t = temp;
            rec.p = r.get_point_at_parameter(temp);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }
    return false;
};