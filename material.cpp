#include "material.h"

vec3 reflect(const vec3& r_in, const vec3& normal) {
    return r_in - dot(r_in, normal) * 2 * normal;
}

// eta is the refractive index
vec3 refract(const vec3& r_in, const vec3& normal, double etai_over_etat){
    vec3 r = r_in.get_normalized();
    float costheta = fmin(dot(-r, normal), 1.0);
    vec3 r_out_perp = etai_over_etat * (r + costheta * normal);
    vec3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.squared_magnitude())) * normal;
    return r_out_perp + r_out_parallel;
}

bool lambertian::scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &r_scattered) const
{
    vec3 random_reflect_direction = rec.normal + random_point_in_unit_radius_sphere();
    r_scattered = ray(rec.p, random_reflect_direction);
    attenuation = albedo;
    return true;
}

bool metal::scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &r_scattered) const
{
    vec3 r_reflected = reflect(r_in.get_direction().get_normalized(), rec.normal);
    r_scattered = ray(rec.p, r_reflected + fuziness * random_point_in_unit_radius_sphere());
    attenuation = albedo;
    return dot(r_scattered.get_direction(), rec.normal) > 0;
}

bool dielectric::scatter(const ray &r_in, const hit_record &rec, vec3 &attenuation, ray &r_scattered) const
{
    attenuation = vec3(1.0, 1.0, 1.0);
    double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

    // total internal reflection
    vec3 in_dir_normalized = r_in.get_direction().get_normalized();
    float costheta = fmin(dot(-in_dir_normalized, rec.normal), 1.0);
    float sintheta = sqrt(1.0 - costheta * costheta);

    vec3 direction;
    bool cannot_refract = refraction_ratio * sintheta > 1.0;
    if (cannot_refract || reflectance(costheta, refraction_ratio) > rand01()) {
        direction = reflect(in_dir_normalized, rec.normal); 
    } else {
        direction = refract(in_dir_normalized, rec.normal, refraction_ratio);
    }

    r_scattered = ray(rec.p, direction);
    return true;
}