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
  // Turn to move, 0 -> Santa, 1 -> Robo-Santa
  int turn_to_move{0};

  // Santa and Robo-Santa locations
  std::pair<int, int> santa_location{0, 0};
  std::pair<int, int> robo_santa_location{0, 0};

  // Keep track of visited locations
  std::set<std::pair<int, int>> locations;

  // Add starting location
  locations.insert(santa_location);

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

  std::string test_input{"^>v<"};

  std::string line{};
  while (std::getline(file, line)) {
    for (char c : test_input) {
      if (c == '^') {
        if (turn_to_move == 0) {
          santa_location.second += 1;
          auto r_pair1 = locations.insert(santa_location);
          if (!r_pair1.second) {
            continue;
          } else {
            houses_delivered_to++;
          }
          turn_to_move = 1;
        } else if (turn_to_move == 1) {
          robo_santa_location.second += 1;
          auto r_pair1 = locations.insert(robo_santa_location);
          if (!r_pair1.second) {
            continue;
          } else {
            houses_delivered_to++;
          }
          turn_to_move = 0;
        }
      } else if (c == 'v') {
        if (turn_to_move == 0) {
          santa_location.second -= 1;
          auto r_pair2 = locations.insert(santa_location);
          if (!r_pair2.second)
            continue;
          else
            houses_delivered_to++;
          turn_to_move = 1;
        } else if (turn_to_move == 1) {
          robo_santa_location.second -= 1;
          auto r_pair2 = locations.insert(robo_santa_location);
          if (!r_pair2.second)
            continue;
          else
            houses_delivered_to++;
          turn_to_move = 0;
        }
      } else if (c == '>') {
        if (turn_to_move == 0) {
          santa_location.first += 1;
          auto r_pair3 = locations.insert(santa_location);
          if (!r_pair3.second) {
            continue;
          } else {
            houses_delivered_to++;
          }
          turn_to_move = 1;
        } else if (turn_to_move == 1) {
          robo_santa_location.first += 1;
          auto r_pair3 = locations.insert(robo_santa_location);
          if (!r_pair3.second) {
            continue;
          } else {
            houses_delivered_to++;
          }
          turn_to_move = 0;
        }
      } else if (c == '<') {
        if (turn_to_move == 0) {
          santa_location.first -= 1;
          auto r_pair4 = locations.insert(santa_location);
          if (!r_pair4.second) {
            continue;
          } else {
            houses_delivered_to++;
          }
          turn_to_move = 1;
        } else if (turn_to_move == 1) {
          robo_santa_location.first -= 1;
          auto r_pair4 = locations.insert(robo_santa_location);
          if (!r_pair4.second) {
            continue;
          } else {
            houses_delivered_to++;
          }
          turn_to_move = 0;
        }
      }
    }
  }

  std::cout << "Houses delivered to: " << houses_delivered_to << '\n';

  return 0;
}
