#pragma once 
#include "core/ray.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t; // Root where the collision happened
};
class hittable {

public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& ray, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};