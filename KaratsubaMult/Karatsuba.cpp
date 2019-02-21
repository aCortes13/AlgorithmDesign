/*
  Authors: Anthony Cortes && Elliot Esponda
*/
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


 


  // takes two non reversed strings representing long ints and adds them returning a string for the product
  std::string gradeSchoolAdd(std::string &num1, std::string &num2) {
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

  //////////////////////////////////////////////////////////////////////////////////////////
  // Requires num1 to be bigger than num2

  std::string gradeSchoolSub(std::string num1, std::string num2) {

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

    auto carry = false;
    int subtotal = 0;
    int digit = 0;
    std::string answer{""}; // the sum of the numbers

    for (unsigned i = 0; i < num1r.length(); ++i) {
      subtotal = (stoi(num1r.substr(i, 1))-carry - stoi(num2r.substr(i, 1)));
      carry = subtotal < 0; // carry will be true when subtotal is less than 0 b/c carry.
      digit = subtotal % 10;
      if (digit < 0) {
        digit += 10;
      }
      char temp = '0' + digit;
      answer.push_back(temp);
    }
    /// you have finished the last digit now take care of the carry
    if (carry != 0) { answer.push_back('0' + carry); }

    reverse(answer.begin(), answer.end());
    return answer;
  }


 public:

  /////////////////////////////////////////////////////////////////////////////
  // takes two non reversed strings representing long ints and multiplies them returning a string for the product

  std::string karatsuba( std::string num1, std::string num2) {
    std::string result;
    if (num1.size() == 1) {
      return std::to_string(stoi(num1) * stoi(num2));
    }
    else {

      auto a = num1.substr(0, num1.length()/2);
      auto b = num1.substr(num1.length()/2, num1.length()/2);
      auto c = num2.substr(0, num2.length()/2);
      auto d = num2.substr(num2.length()/2, num2.length()/2);

      // compute p := a+b and q := c+d using grade school addition
      auto p = gradeSchoolAdd(a, b);
      auto q = gradeSchoolAdd(c, d);

      // monitor p and q and adjust lengths

      auto l1 = p.length();
      auto l2 = q.length();

      if (l1 > l2) {
        while ((l1 & (l1 - 1)) != 0) {
          p.insert(0, "0");
          l1++;
        }
        auto numToIn = p.length() - l2;
        q.insert(0, numToIn, '0');

      }
      else if (l2 > l1) {
        while ((l2 & (l2 - 1)) != 0) {
          q.insert(0, 1, '0');
          l2++;
        }
        auto numToIn = q.length() - l1;
        p.insert(0, numToIn, '0');
      }
      else {

        while ((l1 & (l1 - 1)) != 0) {
          p.insert(0, "0");
          q.insert(0, "0");
          l1++;
        }
      }

      // recursively compute ac , bd, pq
      auto ac = karatsuba(a, c);
      auto bd = karatsuba(b, d);
      auto pq = karatsuba(p, q);

      // compute adbc := pq – ac – bd
      auto acpq = gradeSchoolSub(pq, ac);
      auto adbc = gradeSchoolSub(acpq, bd);

      // 10^n * ac
      ac.insert(ac.end(), num1.length(), '0');

      // 10 ^(n/2) * adbc
      adbc.insert(adbc.end(), num1.length()/2, '0');

      //ac + adbc
      result = gradeSchoolAdd(ac, adbc);

      // result + bd
      result = gradeSchoolAdd(result, bd);

      // strip off leading zeros

      result.erase(0, result.find_first_not_of('0'));

    }
    return result;
  }
};
