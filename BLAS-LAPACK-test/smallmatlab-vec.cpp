#include "smallmatlib.h"
#include <cstdio>
#include <stdlib.h>
#include <vector>
#define SIZE 2

int main(){
  std::vector <double> A1(SIZE*SIZE);
  A1[0] = 1;
  A1[1] = 2;
  A1[2] = 3;
  A1[3] = 4;

  std::vector <double> v1(SIZE*SIZE);
  v1[0] = 2;
  v1[1] = 5.2;
  v1[2] = 1;
  v1[3] = 1.2;

/*  vector <double> u(SIZE*SIZE);
  A[0] = 1;
  A[1] = 2;
  A[2] = 3;
  A[3] = 4;
*/
/*  double A[SIZE*SIZE]=
    { 1,2,
      3,4 };
  double v[SIZE*SIZE]=
        {2,5.2,
         1,1.2};
*/
 double u[SIZE*SIZE];//=
//      {0,0,
//       0,0};
 double* A = &A1[0];
 double* v = &v1[0];

  matvecprod(A,v,u,SIZE);
  printf("%f %f\n",u[0],u[2]);
  printf("%f %f\n",u[1],u[3]);
//  vecmatprod(v,A,u,SIZE);
//  printf("%f %f\n",u[0],u[1]);
//  printf("%f %f\n",u[2],u[3]);
  return 0;
  }
