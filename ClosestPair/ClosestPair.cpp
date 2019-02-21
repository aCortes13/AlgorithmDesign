#include <utility>
#include <float.h>
#include <random>
#include <ctime>
#include <sstream>

struct Point {
  double x, y;

  Point(double _x, double _y) : x(_x), y(_y) {}
};


struct by_xval {
  
 // .........  implement functor  ............... returns bool defines sort comparison

};


struct by_yval {

  // .........  implement functor  ............... returns bool defines sort comparison
  
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
    
    
    /* Your code here */

    
    return /* best of left, right, split */;
  }

  std::pair<Point, Point> closest_split_pair (std::vector<Point>& Px, std::vector<Point>& Py, double delta) {
    
    
    /* Your code here */

    return best_pair;
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
    for (auto& p: pv) {
      double x = (rand() - rand()) % 100,
          y = (rand() - rand()) % 100;
      x += (double)((rand() - rand()) % 100) / 100;
      y += (double)((rand() - rand()) % 100) / 100;
      p = Point(x, y);
    }
  }
};
