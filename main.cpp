#include <iostream>
#include <fstream>
#include "vector.h"
using namespace std;


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
    file << "P3\n" << Width << " " << Height << "\n" << "255\n";
    for (int j = 0; j < Height; j++)
    {
        for (int i = 0; i < Width; i++)
        {
            float r = float(i) / float(Width);
            float g = float(j) / float(Height);
            float b = 0.2;
            vector3 rgb(r, g, b);
            int ir = int(255.99 * rgb.x);
            int ig = int(255.99 * rgb.y);
            int ib = int(255.99 * rgb.z);
            file << ir << " " << ig << " " << ib << "\n";
        }
    } 

    return 0;
}