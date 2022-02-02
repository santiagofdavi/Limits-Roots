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

int main(){

    int grau;

    cin >> grau;

    double c[grau + 1];

    for(unsigned i = 0; i < grau + 1; i++){

        cin >> c[i];

    }

    limites(grau, c);

    return 0;

}