// Santa is delivering gifts to houses
// He first delivers to the house in his starting location
// He thens moves either north (`^`), south (`v`), east (`>`) or west ('<').
// After each move he dilivers a present at that current location.

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>

int main() {
  std::string dir_test{"^v^v^v^v^v"};
  int houses_delivered_to{1};
  std::pair<int, int> curr_location{0, 0};
  std::set<std::pair<int, int>> locations;

  // Add starting location
  locations.insert(curr_location);

  // The Cartesian Plane strat.
  // The starting house is at (0,0)
  // North move => (x,y+1)
  // South move => (x,y-1)
  // East move => (x+1,y)
  // West move => (x-1,y)

  // Read input from file
  std::ifstream file("input.txt");

  if (!file.is_open()) {
    std::cerr << "Unable to open file.\n";
    return 1;
  }

  std::string line{};
  while (std::getline(file, line)) {
    for (char c : line) {
      if (c == '^') {
        curr_location.second += 1;
        auto r_pair1 = locations.insert(curr_location);
        if (!r_pair1.second) {
          continue;
        } else {
          houses_delivered_to++;
        }
      } else if (c == 'v') {
        curr_location.second -= 1;
        auto r_pair2 = locations.insert(curr_location);
        if (!r_pair2.second)
          continue;
        else
          houses_delivered_to++;
      } else if (c == '>') {
        curr_location.first += 1;
        auto r_pair3 = locations.insert(curr_location);
        if (!r_pair3.second) {
          continue;
        } else {
          houses_delivered_to++;
        }
      } else if (c == '<') {
        curr_location.first -= 1;
        auto r_pair4 = locations.insert(curr_location);
        if (!r_pair4.second) {
          continue;
        } else {
          houses_delivered_to++;
        }
      }
    }
  }

  std::cout << "Houses delivered to: " << houses_delivered_to << '\n';

  return 0;
}
