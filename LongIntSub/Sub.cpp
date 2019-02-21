#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include "stdlib.h"

// for both of these functions you are not allowed to either multiply or add more than
// one number with another single number

class Solution {

 public:

  // takes two non reversed strings representing long ints and adds them returning a string for the product
  std::string gradeSchoolAdd(std::string &num1, std::string &num2) {

    // OK we know that none of the numbers are zeros

    // reverse the strings

    auto num1r = num1;
    reverse(num1r.begin(), num1r.end());

    auto num2r = num2;
    reverse(num2r.begin(), num2r.end());

    auto lenNum1 = num1.size();
    auto lenNum2 = num2.size();

    ///check the lengths and left pad with zeros so that they are equal
    // required so is indexable

    auto sizeForCalc = (lenNum1 > lenNum2)?lenNum1:lenNum2;

    if (lenNum1 > lenNum2) {
      for (auto j = 0; j < (lenNum1 - lenNum2); j++) {
        num2r.push_back('0');
      }
    }
    if (lenNum2 > lenNum1) {
      for (auto j = 0; j < (lenNum2 - lenNum1); ++j) {
        num1r.push_back('0');
      }
    }

    /// sequentially add the digits

    auto carry = 0;
    auto subtotal = 0;
    auto digit = 0;
    std::string answer{""}; // the sum of the numbers

    for (auto i = 0; i < sizeForCalc; ++i) {
      subtotal = (stoi(num1r.substr(i, 1)) + stoi(num2r.substr(i, 1))) + carry;
      carry = subtotal / 10;
      digit = subtotal % 10;
      char temp = '0' + digit;
      answer.push_back(temp);
    }
    /// you have finished the last digit now take care of the carry
    if (carry != 0) { answer.push_back('0' + carry); }

    reverse(answer.begin(), answer.end());
    return answer;
  }

  //num 1 is bigger than num 2
  std::string gradeSchoolSub(std::string num1, std::string num2) {
    if ((num1.length() < 1) || (num2.length() < 1) || (stoi(num2) > stoi(num1))) { // corner cases
      return "0";
    }

    bool carry = false;
    std::string difference = "0";
    std::string answer = "";

    // here, num 1 is guaranteed to be bigger than num2
    for (unsigned int x = 0; num1.length() > x; x++) {
      if (x >= num2.length()) { //if num2 has less digits than num1
        difference = num1.substr(0, num1.length()-num2.length());
        difference.insert(difference.end(),x ,'0');
        answer = gradeSchoolAdd(answer, difference);
      }

      // convert char to int
      int num1Int = stoi(num1.substr(num1.length()-1-x, 1));
      int num2Int = stoi(num2.substr(num2.length()-1-x, 1));

      if (carry) {
        num1Int -= 1;
        carry = false;
      }

      if (num1Int >= num2Int) {
        difference = subtract(num1Int, num2Int);
        difference.insert(difference.end(), x, '0');
        answer = gradeSchoolAdd(answer, difference);
      }

      if (num1Int < num2Int) {
        num1Int += 10;
        carry = true;
        difference = subtract(num1Int, num2Int);
        difference.insert(difference.end(), x, '0');
        answer = gradeSchoolAdd(answer, difference);
      }
    }
    return answer;
  }

  std::string subtract(int num1, int num2) {
    return std::to_string(num1 - num2);
  }
};