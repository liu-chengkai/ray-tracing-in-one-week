#pragma once
#include "vector.h"
#include "ray.h"

class camera {
    public:
        camera(vec3 look_from, vec3 look_at, vec3 vup, float vfov, float aspect_ratio, float aperture, float focus_dist) {
            float theta = vfov * M_PI / 180;
            float half_height = tan(theta / 2);
            float viewport_height = half_height * 2;
            float viewport_width = aspect_ratio * viewport_height;
            
            w = (look_from - look_at).get_normalized();
            u = cross(vup, w).get_normalized();
            v = cross(w, u);

            origin = look_from;
            horizontal = focus_dist * viewport_width * u;
            vertical = focus_dist * viewport_height * v;
            lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;
            lens_radius = aperture / 2;
        }

        ray get_ray(float s, float t) {
            vec3 random_point = lens_radius * random_in_unit_disk();
            vec3 offset = u * random_point.x + v * random_point.y;
            return ray(origin + offset, lower_left_corner + horizontal * s + vertical * t - origin - offset);
        }

        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 u, v, w;
        float lens_radius;
};