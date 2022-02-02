/* ROOTS LIMITS IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 2nd, 2022 */

#ifndef LIMITS_H
#define LIMITS_H

double limite_superior(const double &B, const double Cn, const int &grau, const double &k);

void print_disp(int &grau, double M[][4], int *k, int *B, 
                double *L, double *L_xi);

void limites(int &grau, double *c);

#endif