#include "hitable.h"

class hitable_list: public hitable
{
    public:
        hitable **list;
        uint32_t size;
        hitable_list(hitable **list, uint16_t size): list(list), size(size){}
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
};