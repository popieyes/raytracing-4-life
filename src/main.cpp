#include "core/utils.h"
#include "core/hittable.h"
#include "core/hittable_list.h"
#include "core/sphere.h"
#include "core/camera.h"

int main() {
  // World
  hittable_list world;
  
  world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
  world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));
  
  camera camera;

  camera.aspect_ratio = 16.0 / 9.0;
  camera.img_width = 400;
  camera.samples_per_pixel = 100;
  camera.max_depth = 50;

  camera.render(world);
  
  return 0;
}