#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>
#include <ctime>
#include "Strassen.cpp"

int main () {
    const int SIZE = 15, MV = 1;
    Solution mysolution;
    std::vector<std::vector<int> > v1 (SIZE, std::vector<int>(SIZE)),
                                   v2 (SIZE, std::vector<int>(SIZE)),
                                   myAnswer(SIZE, std::vector<int>(SIZE)),
                                   correctAnswer(SIZE, std::vector<int>(SIZE));

    srand(time(NULL));
    mysolution.populate_matrix(v1, MV, SIZE);
    mysolution.populate_matrix(v2, MV, SIZE);

    mysolution.strassen(v1, v2, myAnswer, SIZE);
    mysolution.naive_matrix_mult(v1, v2, correctAnswer, SIZE);
    mysolution.print_matrix(myAnswer, SIZE);
    if (myAnswer == correctAnswer) 
        printf ("\nis correct.");
    else
        printf ("\nis incorrect.");
        

    return 0;
}
