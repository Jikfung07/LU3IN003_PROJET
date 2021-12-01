#include "algos.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Print out the result in terminal
 * 
 * @param result Total number of jam-jars
 * @param length length of the array of jam-jars capacities
 * @param V the array of jam-jars capacities
 * @param A array of numbers of jam-jars
 */
void print_result(int result, int length, int* V, int S, int* A)
{
  printf("For %d jam : \n",S);
  printf("Total number of jam-jars : %d\n",result);
  printf("volume\tQuantity\n");
  for(int i=0; i<length; i++)
  {
    printf("%d\t%d\n",V[i],A[i]);
  }
}


void launch(int num_algo, int S, int* V, int k, int showRasult)
{
  // int* A = (int*)calloc(k, sizeof(int));
  int* A = (int*)malloc(k * sizeof(int));
  for(int i=0; i<k; i++){A[i] = 0;}
  int res;
  switch (num_algo)
  {
    case 1:
      res = algo_I(V, k, S, k-1, &A);
      break;
    case 2:
      res = algo_II(V, k, S, k-1, &A);
      break;
    case 3:
      res = algo_III(V, k, S, k-1, &A);
      break;   
    default:
      res = -1;
      break;
  }
  if(-1==res)
    printf("Error in algo number\n");
  else
    if(showRasult)
      print_result(res, k, V, S, A);
  free(A); 
}