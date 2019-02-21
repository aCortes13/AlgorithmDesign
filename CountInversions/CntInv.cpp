//
// Created by Greg LaKomski on 2/8/19.
//


#include<iostream>
#include<cmath>
#include<cstdio>
#include <vector>
class Solution{

 private:

 std::vector<int> mergeCountInv(std::vector<int> a, std::vector<int> b, int & numInv) {
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
       numInv++;
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

     a = mergeCountInv(aLeftHalf, aRightHalf, numInv);
     b = mergeCountInv(bLeftHalf, bRightHalf, numInv);

     auto sizeofA = a.size();
     auto sizeofB = b.size();
     auto i = 0; // keeps track of vectorA
     auto j = 0; // keeps track of vectorB
     for (auto k = 0; k < outsize; ++k) { // k = index of out vector
       if (i == sizeofA) {
         out.push_back(b.at(j));
         numInv += a.size() - i;
         j++;
       } else if (j == sizeofB) {
         out.push_back(a.at(i));
         i++;
       } else if (a.at(i) <= b.at(j)) {
         out.push_back(a.at(i));  // output array
         i++;
       } else {  // D[j] <C[i]  note the less than artifact of distinct elements
         numInv += a.size() - i;
         out.push_back(b.at(j));
         j++;
       }
     }
   }

   return out;

  }


 public:


  std::vector<int> cntInv(std::vector<int> input, int & numInv){
    std::vector<int> out;

    if(input.size()<=1){
      return input;
    }

    auto inputHalfSize = input.size()/2;
    std::vector<int> leftHalf(input.begin(),input.begin() + inputHalfSize);
    std::vector<int> rightHalf(input.begin() + inputHalfSize, input.end());
    return mergeCountInv(leftHalf, rightHalf, numInv);
  }

};