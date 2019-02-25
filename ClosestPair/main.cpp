#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <float.h>
#include <random>
#include <ctime>
#include "ClosestPair.cpp"

int main () {

    freopen("../testfile.txt","r",stdin);

    double x = 0;
    double y = 0;

    std::vector<Point> P;// (10000, Point(0, 0));

//    while(scanf("%lf %lf",&x,&y)== 2){
//        Point p(x,y);
//        P.push_back(p);
//
//    }

    Solution solution; // instantiate Solution class to create a Solution object

    solution.fill_Point_vect(P);
    auto brute_pair = solution.brute_force(P);
    auto brute_distance = distance(brute_pair.first, brute_pair.second);

    auto non_brute = solution.find_closest_pair(P);
    auto non_brute_distance = distance(non_brute.first, non_brute.second);

    std::cout << "Brute Force Distance: " << brute_distance << std::endl
              << "Non-Brute Force Distance: " << non_brute_distance << std::endl;

   return 0;
}