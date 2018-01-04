#include "smallmatlib.h"
#include <cstdio>
#include <stdlib.h>
#define SIZE 2

int main(){
  double A[SIZE*SIZE]=
    { 1,2,
      3,4 };
  double v[SIZE*SIZE]=
        {2,5.2,
         1,1.2};
  double u[SIZE*SIZE]=
        {0,0,
         0,0};
  matvecprod(A,v,u,SIZE);
  printf("%f %f\n",u[0],u[1]);
  printf("%f %f\n",u[2],u[3]);
//  vecmatprod(v,A,u,SIZE);
//  printf("%f %f\n",u[0],u[1]);
//  printf("%f %f\n",u[2],u[3]);
  return 0;
  }
