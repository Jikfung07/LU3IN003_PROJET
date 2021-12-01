#include "algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Get the Min value of `a` and `b`
 * 
 * @return int : Min value
 */
int getMin(int a, int b)
{
  return a<b ? a : b;
}

// Initialize an array of dimention 2
int** initM(int nRow, int nCol)
{
  int** M = (int**)malloc(nRow*sizeof(int*));
  for(int s=0; s<nRow; s++)
  {
    M[s] = (int*)malloc(nCol*sizeof(int));
  }
  return M;
}

// Get the value m(s,i)
int getM(int** M, int s, int i)
{
  if(s==0){return 0;}
  if(s<0 || i<0){return Inf;}
  return M[s][i];
}

// Destroy the array and return the target value
int destroyM(int** M, int nRow, int nCol)
{
  int result = getM(M,nRow-1,nCol-1);
  // free M
  for(int s=0; s<nRow; s++)
  {
    free(M[s]);
  }
  free(M);
  // return the result (min quantity)
  return result;
}

int algo_II(int* V, int k, int S, int i, int** out_A)
{
  int s, result;
  // create M = new int[S+1][k]
  int** M = initM(S+1, k);
  // start complet the table
  for(i=0; i<k; i++)
  {
    for(s=1; s<=S; s++)
    {
      if(s-V[i]<0)
        M[s][i] = getM(M, s, i-1);
      else
        M[s][i] = getMin( getM(M,s,i-1), getM(M,s-V[i],i) + 1 );
    }
  }
  // calculate A
  s = S;
  i = k-1;
  while(s>0 && i>=0)
  {
    if(s-V[i]<0 || getM(M,s,i-1) <= getM(M,s-V[i],i)+1){
      i -- ;
    }else{
      (*out_A)[i] ++;
      s -= V[i];
    }
  }
  // // free M and return the result (min quantity)
  return destroyM(M, S+1, k);
}