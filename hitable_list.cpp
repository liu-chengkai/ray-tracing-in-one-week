#include "hitable_list.h"

bool hitable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;
    for (uint32_t i = 0; i < size; i++)
    {
        // Opaque closest object block the ones behind.
        if (list[i]->hit(r, t_min, closest_so_far, temp_rec))
        {
            hit_anything = true;
            rec = temp_rec;
            closest_so_far = temp_rec.t;
        }
    }
    return hit_anything;
};