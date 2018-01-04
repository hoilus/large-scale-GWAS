#ifndef SMALLMATLIB_H
#define SMALLMATLIB_H

void initvec(double* v, int N);

void matvecprod(double* A, double* v, double* u, int N);

void vecmatprod(double* v, double* A, double* u, int N);

#endif
