#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "vector.h"
#include "ray.h"
#include "hitable_list.h"
#include "sphere.h"
#include "float.h"
#include "camera.h"
#include "material.h"
using namespace std;

// https://raytracing.github.io/v3/books/RayTracingInOneWeekend.html

vec3 color(const ray& r, hitable* list, int depth)
{
    hit_record rec;
    if (list->hit(r, 0.001, FLT_MAX, rec))
    {
        //vec3 random_reflect_direction = rec.normal + random_point_in_unit_radius_sphere();
        //return 0.5 * color(ray(rec.p, random_reflect_direction), list);
        ray r_scattered;
        vec3 attenuation;
        if (depth < 50 && rec.mat->scatter(r, rec, attenuation, r_scattered)) {
            return attenuation*color(r_scattered, list, depth + 1);
        }
        return vec3(0, 0, 0);
    }
    vec3 unitRay = r.get_direction().get_normalized();
    float t = 0.5 * (unitRay.y + 1);
    vec3 c = vec3(1, 1, 1) * (1 - t) + vec3(0.5, 0.7, 1) * t;
    return c;
}

hitable* get_world() {
    int n = 100;
    hitable **list = new hitable*[n];
    int k = 1;
    // ground
    list[0] = new sphere(vec3(0, -1000, 0), 1000, new lambertian(vec3(0.3, 0.3, 0.3)));
    for (int i = -5; i < 5; i++) {
        for (int j = -5; j < 5; j++) {
            float radius = 0.15 + 0.15 * rand01();
            float random_mat = rand01();
            vec3 center(i + 0.5 * rand01(), radius, j + 0.9 * rand01());
            vec3 random_color(vec3(rand01(), rand01(), rand01()));
            material* mat;
            if (random_mat < 0.35) {
                mat = new lambertian(random_color);
            } else if (random_mat < 0.7) {
                mat = new metal(random_color, rand01());
            } else {
                mat = new dielectric(rand01());
            }
            list[k++] = new sphere(center, radius, mat);
        }
    }
    return new hitable_list(list, k);
}

int main()
{
    // image
    const float aspect_ratio = 16.0 / 9.0;
    const int Width = 1600;
    const int Height = static_cast<int>(Width / aspect_ratio);
    const int SampleCount = 1000;
    const string OutputFileName = "output.ppm";

    // camera
    vec3 look_from(-1, 1, 1);
    vec3 look_at(0, 0, 0);
    vec3 up(0, 1, 0);
    float focus_dist = (look_from - look_at).magnitude();
    camera cam(look_from, look_at, up, 100, aspect_ratio, 0.1, focus_dist);

    // world
    hitable *world = get_world();

    // Render
    std::ofstream file(OutputFileName, std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        cout << "Failed to open file." << endl;
        return 0;
    }
    file << "P3\n" << Width << " " << Height << "\n" << "255\n";
    // right handed coordinate system
    for (int j = Height - 1; j >= 0; j--)
    {
        for (int i = 0; i < Width; i++)
        {
            vec3 temp_Color(0, 0, 0);
            for (int s = 0; s < SampleCount; s++) {
                float u = float(i + rand01()) / float(Width);
                float v = float(j + rand01()) / float(Height);
                ray r = cam.get_ray(u, v);
                temp_Color += color(r, world, 0);
            }
            temp_Color /= SampleCount;
            // color should be converted in gamma space pow(x, 2.2)
            // we use 2 for approximation and convenience
            temp_Color = vec3(sqrt(temp_Color.x), sqrt(temp_Color.y), sqrt(temp_Color.z));
            int ir = int(255.99 * temp_Color.x);
            int ig = int(255.99 * temp_Color.y);
            int ib = int(255.99 * temp_Color.z);
            file << ir << " " << ig << " " << ib << "\n";
        }
    } 
    system("pause");
    return 0;
}