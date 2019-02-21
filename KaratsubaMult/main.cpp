#include <iostream>
#include <string>
#include "Karatsuba.cpp"


int main() {

  Solution mysolution;

  // requires that num1 is bigger then num2
  auto answer = mysolution.karatsuba("21598764513456782159876451345678", "19283746675849382159876451345678");

  std::cout<< answer;


  return 0;
}