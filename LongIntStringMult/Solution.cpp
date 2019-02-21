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

private:
    // takes two non reversed strings representing long ints and adds them returning a string for the product
    std::string gradeSchoolAdd(std::string &num1, std::string &num2) {

        // check for either of the numbers being zero and just return the correct sum

        if (stoi(num1.substr(0, 1)) == 0 && stoi(num2.substr(0, 1)) == 0) {
            return "0";
        }
        if (stoi(num1.substr(0, 1)) == 0 && stoi(num2.substr(0, 1)) != 0) {
            return num2;
        }
        if (stoi(num1.substr(0, 1)) != 0 && stoi(num2.substr(0, 1)) == 0) {
            return num1;
        }

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
        // there might be a case where num1 < num2 so set sizeForCalc to largest

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

public:


    // takes two non reversed strings representing long ints and multiplies them returning a string for the product

    std::string gradeSchoolMult(std::string num1, std::string num2) {
        // check for negatives
        bool isNeg = false;

        if (num1.at(0) == '-') {
            num1.erase(num1.begin());
            isNeg = true;
        }

        if (num2.at(0) == '-') {
            num2.erase(num2.begin());
            if (isNeg) {
                isNeg = false;
            }
            else {
                isNeg = true;
            }
        }

        // flip the numbers
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        // do individual multiplication
        // call add function
        std::string result = "0";
        std::string temp = "0";
        for (auto i = 0; i < num1.length(); ++i) {
            for (auto j = 0; j < num2.length(); ++j) {
                //
                temp = std::to_string(stoi(num1.substr(i, 1)) * stoi(num2.substr(j,1)));
                if (i > 0) {
                    temp.insert(temp.end(), i, '0');
                }
                if (j > 0) {
                    temp.insert(temp.end(), j, '0');
                }
                result = gradeSchoolAdd(result, temp);
            }
        }
        if (isNeg) {
            result.insert(result.begin(), 1, '-');
        }
        return result;
    }
};
