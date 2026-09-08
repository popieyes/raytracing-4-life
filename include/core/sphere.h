#pragma once

#include "core/hittable.h"
#include "core/vec3.h"

class sphere : public hittable {

public:
    sphere(const point3& center, double radius) : center(center), radius(std::fmax(0,radius)) {}
    
    bool hit(const ray& ray, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        vec3 oc = center - ray.origin();
        // Solving the sphere intersection equation is a quadratic formula of the type (-b +-sqrt(b^2 -4*a*c))/2a
        auto a = ray.direction().length_squared();
        auto h = dot(ray.direction(), oc);
        auto c = oc.length_squared() - radius*radius;
            
        auto discriminant = h*h - a*c;
        // If the squared root is non-negative there will be a solution, therefore there will be a hit with the sphere
         
        if (discriminant < 0) 
            return false;
        
        auto sqrtd = std::sqrt(discriminant);

        // Find the nearest root that lies in an acceptable range
        auto root = (h - sqrtd) / a;

        if (root <= ray_tmin || ray_tmax <= root) {
            root = (h + sqrtd) / a;
            if (root <= ray_tmin || ray_tmax <= root)
                return false;
        }

        rec.t = root;
        rec.p = ray.at(rec.t);
        rec.normal = (rec.p - center) / radius; // Return the normal in unit vector format.

        return true;
        
    }

private:
    point3 center;
    double radius;
};