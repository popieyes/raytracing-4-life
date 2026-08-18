#include <iostream>

int main() {
  
  // Image properties
  int img_width = 256, img_height = 256;

  // Render in PPM format. An RGB image in PPM format follows the following structure:
  /*
    P3
    # The P3 means colors are in ASCII, then number of columns (e.g. 3) and number of rows
    (e.g. 2), then for 255 for max color, then RGB triplets
    
    3 2
    255
    255   0   0     0 255   0     0   0 255
    255 255   0   255 255 255     0   0   0
  
  */

  std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

  for (int j = 0; j < img_width; j++) {
    for (int i = 0; i < img_width; i++) {
      // Normalize color values to values between 0.0 to 1.0. This is done by convention
      auto r = double(i) / (img_width - 1);
      auto g = double(j) / (img_height - 1);
      auto b = 0.0f;
      
      // Recast the values to pixel values between 0-255
      int ir = int(255.999 * r);
      int ig = int (255.999 * g);
      int ib = int(255.999 * b);
      
      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  
  return 0;
}