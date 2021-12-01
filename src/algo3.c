#include "algos.h"
#include <stdio.h>
#include <stdlib.h>

int algo_III(int* V, int k, int s, int i, int** out_A)
{
  if(i==0)
  {
    (*out_A)[i] = s;
    return s;
  }
  if(s<V[i])
  {
    return algo_III(V, k, s, i-1, out_A);
  }
  (*out_A)[i] += 1;
  return algo_III(V, k, s-V[i], i, out_A) + 1;
}

int testGloutonCompatible(int k, int* V)
{
  int S,j;
  int* A_buffer = (int*) calloc(k, sizeof(int));
  if(k>=2)
  {
    for(S = V[2]+2; S <= V[k-2]+V[k-1]-1; S++)
    {
      for(j=0; j<k; j++)
      {
        if(V[j]<S && algo_III(V,k,S,k-1,&A_buffer) > 1+algo_III(V,k,S-V[j],k-1,&A_buffer))
        {
          free(A_buffer);
          return !COMPATIBLE;
        }
      }
    }
  }
  free(A_buffer);
  return COMPATIBLE;
}

