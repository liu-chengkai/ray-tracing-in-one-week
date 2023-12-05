#include <iostream>
#include <fstream>
#include "stdlib.h"
#include "vector.h"
#include "ray.h"
using namespace std;

bool hit_sphere(const vec3& center, float radius, const ray& r)
{
    vec3 oc = r.get_origin() - center;
    float a = r.get_direction().dot(r.get_direction());
    float b = r.get_direction().dot(oc) * 2;
    float c = oc.dot(oc) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    return discriminant > 0;
}

vec3 color(ray& r)
{
    if (hit_sphere(vec3(0, 0, -1), 0.5, r))
    {
        return vec3(1, 0, 0);
    }
    vec3 unitRay = r.get_direction().get_normalized();
    float t = 0.5 * (unitRay.y + 1);
    vec3 c = vec3(1, 1, 1) * (1 - t) + vec3(0.5, 0.7, 1) * t;
    return c;
}

int main()
{
    std::ofstream file("RayTracing.ppm", std::ios::out | std::ios::binary);
    if (!file.is_open())
    {
        cout << "Failed to open file." << endl;
        return 0;
    }
    const int Width = 200;
    const int Height = 100;
    vec3 origin(0, 0, 0);
    vec3 lower_left_corner(-2, -1, -1);
    vec3 horizontal(4, 0, 0);
    vec3 vertical(0, 2, 0);
    file << "P3\n" << Width << " " << Height << "\n" << "255\n";
    // right handed coordinate system
    for (int j = Height - 1; j >= 0; j--)
    {
        for (int i = 0; i < Width; i++)
        {
            float u = float(i) / float(Width);
            float v = float(j) / float(Height);
            ray r(origin, lower_left_corner + horizontal * u + vertical * v);
            vec3 c = color(r);
            int ir = int(255.99 * c.x);
            int ig = int(255.99 * c.y);
            int ib = int(255.99 * c.z);
            file << ir << " " << ig << " " << ib << "\n";
        }
    } 
    system("pause");
    return 0;
}