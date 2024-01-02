// The list of dimensions: length `l`, width `w`, height `h`
// The formula for surface area: 2*l*w + 2*w*h + 2*h*l
// Also the extra paper, the area of the smalled side (`l*w` or `w*h` or `h*l`)
// is added to the total surface area
#include <algorithm>
#include <iostream>

struct Dimensions {
  int length{};
  int width{};
  int height{};
};

int main() {
  Dimensions dim{1, 1, 10};

  int length_width = dim.length * dim.width;
  int width_height = dim.width * dim.height;
  int height_length = dim.height * dim.length;

  int surface_area = 2 * length_width + 2 * width_height + 2 * height_length;

  std::cout << "Surface area: " << surface_area << '\n';

  int total_wrapping_paper =
      surface_area + std::min({length_width, width_height, height_length});

  std::cout << "Total wrapping paper: " << total_wrapping_paper << '\n';

  return 0;
}
