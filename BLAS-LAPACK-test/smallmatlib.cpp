#include <cstdio>
#include <stdlib.h>


extern "C"{
    // product C= alphaA.B + betaC
   void dgemm_(char* TRANSA, char* TRANSB, const int* M,
               const int* N, const int* K, double* alpha, double* A,
               const int* LDA, double* B, const int* LDB, double* beta,
               double* C, const int* LDC);
    // product Y= alphaA.X + betaY
   void dgemv_(char* TRANS, const int* M, const int* N,
               double* alpha, double* A, const int* LDA, double* X,
               const int* INCX, double* beta, double* C, const int* INCY);
   }

void initvec(double* v, int N){
    for(int i= 0; i<N; ++i){
        v[i]= 0.0;
        }
   }

void matvecprod(double* A, double* v, double* u, int N){
    double alpha= 1.0, beta= 0.0;
    char no= 'N', tr= 'T';
    int m= N, n= N, k=N, lda= N, incx= N, incy= N;
    double* tmp= new double[N*N];
    initvec(tmp, N);
    dgemm_(&tr,&tr,&m,&n,&k,&alpha,A,&lda,v,&incx,&beta,tmp,&incy);
    for(int i= 0; i<N*N; ++i){
        u[i]= tmp[i];
        }
    delete [] tmp;
    }

void vecmatprod(double* v, double* A, double* u, int N){
    double alpha= 1.0, beta= 0.0;
    char no= 'N', tr= 'T';
    int m= 1, n= N, k= N, lda= 1, ldb= N, ldc= 1;
    double* tmp= new double[N];
    initvec(tmp, N);
    dgemm_(&no,&tr,&m,&n,&k,&alpha,v,&lda,A,&ldb,&beta,tmp,&ldc);
    for(int i= 0; i<N; ++i){
        u[i]= tmp[i];
        }
    delete [] tmp;
    }
