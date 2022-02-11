/* ROOTS LIMITS IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 2nd, 2022 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Limites.hpp"

using namespace std;

double limite_superior(const double &B, const double Cn, const int &grau, const double &k){

    return 1 + pow((B / Cn), (1 / (grau - k)));

}

void print_disp(int &grau, double M[][4], int *k, int *B, 
                double *L, double *L_xi){

    cout << " n       P_x       P_1       P_2       P_3" << endl;

    for(unsigned i = 0; i < grau + 1; i++){

        cout << setprecision(0) << fixed << " C" << grau - i << "    ";

        for(unsigned j = 0; j < 4; j++){

            cout << setprecision(5) << fixed << M[i][j] << "  ";

        }

        cout << endl;

    }

    cout << endl << " k        ";

    for(unsigned i = 0; i < 4; i++){

        cout << setprecision(0) << fixed << k[i] << "         ";

    }

    cout << endl << " n-k      ";

    for(unsigned i = 0; i < 4; i++){

        cout << setprecision(0) << fixed << grau - k[i] << "         ";

    }

    cout << endl << " B        ";

    for(unsigned i = 0; i < 4; i++){

        cout << setprecision(0) << fixed << B[i] << "        ";

    }

    cout << endl << " Li    ";

    for(unsigned i = 0; i < 4; i++){

        cout << setprecision(5) << fixed << L[i] << "   ";

    }

    cout << endl << " L_xi  ";

    for(unsigned i = 0; i < 4; i++){

        cout << setprecision(5) << fixed << L_xi[i] << "   ";

    }

    cout << "\n\nLimites:   " << L_xi[1] << " <= R+ <= "
         << L_xi[0] << " e " << L_xi[2]
         << " <= R- <= " << L_xi[3] << "\n\n";

}

void limites(int &grau, double *c){

    cout << "\nLimites das raizes de equacao algebrica pelo Teorema de Lagrange\n" << endl;

    double L[4];
    double L_xi[4];

    int Sinal;

    int B[] = {0, 0, 0, 0};
    int k[] = {-1, -1, -1, -1};

    if(grau % 2 == 0){

        Sinal = 1;

    }

    else{

        Sinal = -1;

    }

    double MatC[grau + 1][4];

    for(unsigned i = 0; i < grau + 1; i++){

        MatC[i][0] = c[i];
        MatC[grau - i][1] = c[i];
        MatC[i][2] = Sinal * c[i];
        Sinal *= -1;
        MatC[grau - i][3] = MatC[i][2];

    }

    for(unsigned j = 0; j < 4; j++){

        if(MatC[0][j] < 0){

            for(unsigned i = 0; i < grau + 1; i++){

                if(MatC[i][j] != 0){

                    MatC[i][j] *= -1;

                }

            }

        }
        
        for(unsigned i = 0; i < grau + 1; i++){

            if(MatC[i][j] < 0 && k[j] == -1){

                k[j] = grau - i;

            }

            if(MatC[i][j] < 0 && fabs(MatC[i][j]) > B[j]){

                B[j] = fabs(MatC[i][j]);

            }

        }

        if(B[j] != 0){

            L[j] = limite_superior(B[j], MatC[0][j], grau, k[j]);

        }

        else{

            L[j] = pow(10, 10);

        }

    }

    L_xi[0] = L[0];
    L_xi[1] = 1 / L[1];
    L_xi[2] = -1 * L[2];
    L_xi[3] = -1 / L[3];

    print_disp(grau, MatC, k, B, L, L_xi);

}
