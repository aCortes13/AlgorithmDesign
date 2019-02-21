#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>
#include <ctime>


class Solution {
private:

    void add_matrices (std::vector<std::vector<int> > &A, std::vector<std::vector<int> > &B, std::vector<std::vector<int> > &C, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                C[i][j] = A[i][j] + B[i][j];

            }
        }
    }

    void subtract_matrices (std::vector<std::vector<int> > &A, std::vector<std::vector<int> > &B, std::vector<std::vector<int> > &C, int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }

    int make_n_power2 (int n) {
        //Input: n, an integer
        //Output: m, where m is the first power of 2 greater than or equal to n

        if ((n & (n - 1)) == 0)
            return n;

        auto next_power2 = 1;
        while (next_power2 < n) next_power2 <<= 1;

        return next_power2;
    }

    int make_nxn_power2 (std::vector<std::vector<int> > &A) {
        //Input: nxn matrix
        //Output: m, where m is the first power of 2 greater than or equal to n
        //Internal: if n < m : resize matrix A to mxm, padded with 0s

        int n = A.size();
        auto m = make_n_power2(n);
        if (n < m) {
            A.resize(m);
            for (auto i = 0; i < m; ++i)
                A[i].resize(m, 0);
        }

        return m;
    }


public:

    void strassen (std::vector<std::vector<int> > &X, std::vector<std::vector<int> > &Y, std::vector<std::vector<int> > &Z, int n) {
        if (n == 1) {
            // base case z[0][0] = x[0][0] * y[0][0]
            Z[0][0] = X[0][0] * Y[0][0];
            return;
        }
        // Enforce invariant: n must be power of 2
        // n & (n-1) == 0 for all n | n = 2^i for some non-negative integer i
        if ((n & (n - 1)) != 0) {
            make_nxn_power2(X);
            make_nxn_power2(Y);
            n = make_nxn_power2(Z);
        }
        auto m = n >> 1;
        std::vector<std::vector<int> >
        /*sub-matrices of X*/
                A(m, std::vector<int>(m)), B(m, std::vector<int>(m)),
                C(m, std::vector<int>(m)), D(m, std::vector<int>(m)),

        /*sub-matrices of Y*/
                E(m, std::vector<int>(m)), F(m, std::vector<int>(m)),
                G(m, std::vector<int>(m)), H(m, std::vector<int>(m)),

        /*sub-matrices of Z*/
        /*(cleverly chosen) additions/subtractions*/
                Z00(m, std::vector<int>(m)), Z01(m, std::vector<int>(m)),
                Z10(m, std::vector<int>(m)), Z11(m, std::vector<int>(m)),

        /*temporary matrices for intermediate results*/
                T1(m, std::vector<int>(m)), T2(m, std::vector<int>(m)),

        /*(cleverly chosen) products*/
                P1(m, std::vector<int>(m)), P2(m, std::vector<int>(m)),
                P3(m, std::vector<int>(m)), P4(m, std::vector<int>(m)),
                P5(m, std::vector<int>(m)), P6(m, std::vector<int>(m)),
                P7(m, std::vector<int>(m));

        //Divide X and Y into sub-matrices
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < m; ++j) {
                // split X vertically and horizontally
                A.at(i).at(j) = X.at(i).at(j);
                B.at(i).at(j) = X.at(i).at(j+m);
                C.at(i).at(j) = X.at(i+m).at(j);
                D.at(i).at(j) = X.at(i+m).at(j+m);

                //split y vertically and horizontally
                E.at(i).at(j) = Y.at(i).at(j); // upper left
                F.at(i).at(j) = Y.at(i).at(j+m); // upper right
                G.at(i).at(j) = Y.at(i+m).at(j); // lower left
                H.at(i).at(j) = Y.at(i+m).at(j+m); // lower right
            }
        }


        //Compute products
        //Think of function calls like assembly instructions

        //P1 = A * (F - H)
        subtract_matrices(F, H, T1, m);
        strassen(A, T1, P1, m);

        //P2 = (A + B) * H
        add_matrices(A, B, T1, m);
        strassen(T1, H, P2, m);

        //P3 = (C + D) * E
        add_matrices(C, D, T1, m);
        strassen(T1, E, P3, m);

        //P4 = D * (G - E)
        subtract_matrices(G, E, T1, m);
        strassen(D, T1, P4, m);

        //P5 = (A + D) * (E + H)
        add_matrices(A, D, T1, m);
        add_matrices(E, H, T2, m);
        strassen(T1, T2, P5, m);

        //P6 = (B - D) * (G + H)
        subtract_matrices(B, D, T1, m);
        add_matrices(G, H, T2, m);
        strassen(T1, T2, P6, m);

        //P7 = (A - C) * (E + F)
        subtract_matrices(A, C, T1, m);
        add_matrices(E, F, T2, m);
        strassen(T1, T2, P7, m);



        //Compute additions/subtractions of products

        //Z00 = P5 + P4 + P6 - P2
        add_matrices(P5, P4, T2, m);
        add_matrices(T2, P6, T1, m);
        subtract_matrices(T1, P2, Z00, m);


        //Z01 = P1 + P2
        add_matrices(P1, P2, Z01, m);

        //Z10 = P3 + P4
        add_matrices(P3, P4, Z10, m);

        //Z11 = P1 - P3 + P5 - P7
        subtract_matrices(P1, P3, T1, m);
        add_matrices(T1, P5, T2, m);
        subtract_matrices(T2, P7, Z11, m);

        //merge sub-matrices of Z
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < m; ++j) {
                // Merge X vertically and horizontally
                A.at(i).at(j) = X.at(i).at(j);
                B.at(i).at(j) = X.at(i).at(j+m);
                C.at(i).at(j) = X.at(i+m).at(j);
                D.at(i).at(j) = X.at(i+m).at(j+m);

                Z.at(i).at(j) = Z00.at(i).at(j);
                Z.at(i).at(j+m) = Z01.at(i).at(j);
                Z.at(i+m).at(j) = Z10.at(i).at(j);
                Z.at(i+m).at(j+m) = Z11.at(i).at(j);
            }
        }
    }

    void populate_matrix (std::vector<std::vector<int> > &A, int max_val, int len) {
        for (auto i = 0; i < len; ++i) {
            for (auto j = 0; j < len; ++j) {
                A[i][j] = rand() % (max_val + 1);
            }
        }
    }

    void print_matrix (const std::vector<std::vector<int> > &A, int n) {
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                printf ("%d ", A[i][j]);
            }
            printf ("\n");
        }
        printf ("\n");
    }

    void print_matrix_vect_form (const std::vector<std::vector<int> > &A, int n) {
        printf ("{");
        for (auto i = 0; i < n; ++i) {
            if (i) printf (" ");
            printf ("{");
            for (auto j = 0; j < n; ++j) {
                printf ("%d, ", A[i][j]);
            }
            printf ("\b\b \b}");
            if (i < n - 1) printf (",\n");
        }
        printf ("};\n\n");
    }

    void naive_matrix_mult (std::vector<std::vector<int> > &X, std::vector<std::vector<int> > &Y, std::vector<std::vector<int> > &Z, int n) {
        if ((n & (n - 1)) != 0) {
            make_nxn_power2(X);
            make_nxn_power2(Y);
            n = make_nxn_power2(Z);
        }
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                Z[i][j] = 0;
                for (auto k = 0; k < n; ++k)
                    Z[i][j] += X[i][k] * Y[k][j];
            }
        }
    }
};

