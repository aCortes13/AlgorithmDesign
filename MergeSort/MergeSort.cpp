//
// Created by Greg LaKomski on 1/17/19.
//


#include<iostream>
#include<cmath>
#include<cstdio>
#include <vector>
using std::cout;
using std::endl;

class Solution{

 private:

  std::vector<int> merge(std::vector<int> a, std::vector<int> b) {

    auto outsize = a.size() + b.size();
    std::vector<int> out;

    if (outsize <= 2) { // if one of the vectors has an element
      if (a.empty()) { // return b, its the only element
        return b;
      }
      else if (b.empty()) {
        return a;
      }
      else if (a.front() > b.front()) { // if they're not in order, return them in order
        out.push_back(b.front());
        out.push_back(a.front());
        return out;
      }
      else {
        out.push_back(a.front());
        out.push_back(b.front());
        return out;
      }
    }
    else {


      auto aHalfSize = a.size() / 2;
      std::vector<int> aLeftHalf(a.begin(), a.begin() + aHalfSize);
      std::vector<int> aRightHalf(a.begin() + aHalfSize, a.end());

      auto bHalfSize = b.size() / 2;
      std::vector<int> bLeftHalf(b.begin(), b.begin() + bHalfSize);
      std::vector<int> bRightHalf(b.begin() + bHalfSize, b.end());

      a = merge(aLeftHalf, aRightHalf);
      b = merge(bLeftHalf, bRightHalf);

      auto sizeofA = a.size();
      auto sizeofB = b.size();
      auto i = 0; // keeps track of vectorA
      auto j = 0; // keeps track of vectorB
      for (auto k = 0; k < outsize; ++k) { // k = index of out vector
        if (i == sizeofA) {
          out.push_back(b.at(j));
          j++;
        } else if (j == sizeofB) {
          out.push_back(a.at(i));
          i++;
        } else if (a.at(i) <= b.at(j)) {
          out.push_back(a.at(i));  // output array
          i++;
        } else {  // D[j] <C[i]  note the less than artifact of distinct elements
          out.push_back(b.at(j));
          j++;
        }
      }
    }
    return out;
  }


 public:


  std::vector<int> mergeSort (std::vector<int> input){

    std::vector<int> out;

    if(input.size()<=1){
      return input;
    }

    auto inputHalfSize = input.size()/2;
    std::vector<int> leftHalf(input.begin(),input.begin() + inputHalfSize);
    std::vector<int> rightHalf(input.begin() + inputHalfSize, input.end());
    return merge(leftHalf, rightHalf);
  }


};
