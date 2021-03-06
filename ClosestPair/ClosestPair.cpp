#include <utility>
#include <algorithm>
#include <float.h>
#include <random>
#include <ctime>
#include <time.h>
#include <sstream>

struct Point {
  double x, y;

  Point(double _x, double _y) : x(_x), y(_y) {}
};


struct by_xval {
  bool operator() (Point &first, Point &second) { return (first.x < second.x);  }
};


struct by_yval {
  bool operator() (Point &first, Point &second) { return (first.y < second.y);  }
};



inline double distance (Point p1, Point p2) {
  ///DO NOT MOVE OR MODIFY
  ///This function is used by unit tests
  return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}



class Solution {
 private:

  std::pair<Point, Point> closest_pair (std::vector<Point>& Px, std::vector<Point>& Py) {

    int n = Px.size();
    if (n <= 3) {
      //Base Case => "Brute force"
      return brute_force(Px);
    }

    auto m = n >> 1;

    // split Px into left and right halves
    std::vector<Point> Lx (Px.begin(), Px.begin() + m);
    std::vector<Point> Ly (Px.begin(), Px.begin() + m);
    std::vector<Point> Rx (Px.begin() + m, Px.end());
    std::vector<Point> Ry (Px.begin() + m, Px.end());

    // sort one set by y
    std::sort(Ly.begin(), Ly.end(), by_yval());
    std::sort(Ry.begin(), Ry.end(), by_yval());

    //recursively compute closest pair on each side
    std::pair<Point, Point> closeL = closest_pair(Lx, Ly);
    std::pair<Point, Point> closeR = closest_pair(Rx, Ry);

    // get the minimum distance from the two closest points
    auto lDistance = distance(closeL.first, closeL.second);
    auto rDistance = distance(closeR.first, closeR.second);

    // smallest distance, left pair or right pair
    double delta = std::min(lDistance, rDistance);

    // find the closest split pair
    std::pair<Point, Point> closeSp = closest_split_pair(Px, Py, delta);
    auto spDistance = distance(closeSp.first, closeSp.second);

    if (spDistance < delta){
      // split distance is better than either half
      return closeSp;

    } else {
      // determine which half has the closer pair
      return lDistance < rDistance ? closeL : closeR;
    }

  }

  std::pair<Point, Point> closest_split_pair (std::vector<Point>& Px, std::vector<Point>& Py, double delta) {
    
    // get largest x coord in left half
    auto n = Px.size();
    auto xBar = Px[(n - 1) / 2].x;

    // determine min and max values
    auto min = xBar - delta;
    auto max = xBar + delta;

    // get point whos x-coordinate is xBar +- delta
    std::vector<Point> Sy;
    for (int i = 0; i < n; ++i) {
      auto xCoord = Px[i].x;
      if ((min <= xCoord) && (max >= xCoord)) {
        Sy.push_back(Px[i]);
      }
    }

    double best = delta;
    std::pair<Point, Point> bestPair = std::make_pair(Px[0], Px[1]);

    int l = Sy.size();

    // corner cases
    if (l < 2) {
      return bestPair;
    }
    if (l == 2) {
      return std::make_pair(Sy[0], Sy[1]);
    }

    // bruce force to find best distance in Sy
    for (int i = 0; i < (l - 1); ++i) {
      for (int j = i + 1; j < std::min(7, l); ++j) {
        auto currentDist = distance(Sy[i], Sy[j]);
        if (currentDist < best) {
          best = currentDist;
          bestPair = std::make_pair(Sy[i], Sy[j]);
        }
      }
    }
    return bestPair;
  }


 public:

  std::pair<Point, Point> find_closest_pair (const std::vector<Point>& P) {

    //Make two copies of P
    std::vector<Point> Px(P), Py(P);
    //Sort Px by x-value
    sort(Px.begin(), Px.end(), by_xval());
    //Sort Py by y-value
    sort(Py.begin(), Py.end(), by_yval());
    //Compute recursively
    return closest_pair(Px, Py);
  }


  std::pair<Point, Point> brute_force (std::vector<Point>& P) {
    ///DO NOT MOVE OR MODIFY
    ///This function is used by unit tests
    int n = P.size();
    double best = 100000.0;
    auto best_pair = std::make_pair(P[0], P[1]);
    for (auto i = 0; i < n - 1; ++i) {
      for (auto j = i + 1; j < n; ++j) {
        auto cur_dist = distance(P[i], P[j]);
        if (cur_dist < best) {
          best = cur_dist;
          best_pair = std::make_pair(P[i], P[j]);
        }
      }
    }
    return best_pair;
  }

  void fill_Point_vect (std::vector<Point>& pv) {
    ///DO NOT MODIFY
    ///This function is used by unit tests
    //srand(time(NULL)); //-- uncomment this line for a consistently random selection of numbers
    for (auto& p: pv) {
      double x = (rand() - rand()) % 100,
      y = (rand() - rand()) % 100;
      x += (double)((rand() - rand()) % 100) / 100;
      y += (double)((rand() - rand()) % 100) / 100;
      p = Point(x, y);
    }
  }
};
