#pragma once
#include "ray.h"
#include "hitable.h"
#include <cmath>

class material {
    public:
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& r_scattered) const = 0;
};

class lambertian: public material {
    public:
        lambertian(vec3 albedo): albedo(albedo) {

        };

        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& r_scattered) const;
        vec3 albedo;
};

class metal: public material {
    public:
        metal(vec3 albedo, float fuziness): albedo(albedo), fuziness(fuziness) {};
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& r_scattered) const;
        vec3 albedo;
        float fuziness;
};

class dielectric: public material {
    public:
        dielectric(float index_of_refractive): ir(index_of_refractive){};
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& r_scattered) const;
        float ir;
    private:
        static float reflectance(float cosine, float ref_idx) {
            // Use Schlick's approximation for reflectance.
            float r0 = (1 - ref_idx) / (1 + ref_idx);
            r0 = r0 * r0;
            return r0 + (1 - r0) * pow((1 - cosine), 5);
        }
};