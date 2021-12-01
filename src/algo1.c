#include "algos.h"
#include <stdio.h>
#include <stdlib.h>



/**
 * @brief copy an array
 * 
 * @param array the array to be copied
 * @param k length of the array
 * @return int* the copy array
 */
int* copy_int_array(int* array, int k)
{
  int* res = (int*)malloc(sizeof(int)*k);
  for(int i=0; i<k; i++)
  {
    res[i] = array[i];
  }
  return res;
}

int algo_I(int* V, int k, int s, int i, int** out_A)
{
  if(s==0)
  {
    return 0;
  }
  if(s<0 || i<0)
  {
    return Inf;
  }
  int* A1 = copy_int_array(*out_A, k);
  int* A2 = copy_int_array(*out_A, k);
  int res1 = algo_I(V, k, s, i-1, &A1);
  int res2 = algo_I(V, k, s-V[i], i, &A2) + 1;
  free(*out_A);
  if(res1<res2)
  {
    *out_A = A1;
    free(A2);
    return res1;
  }else{
    *out_A = A2;
    (*out_A)[i] += 1;
    free(A1);
    return res2;
  }
}
