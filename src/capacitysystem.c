#include"analyse.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getExpocapacitySystem(int k, int d)
{
  int* V = (int*) malloc(k*sizeof(int));
  V[0] = 1;
  for(int i=1; i<k; i++)
  {
    V[i] = V[i-1] * d;
  }
  return V;
}

void swap(int* array, int i, int j)
{
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void sort(int* array, int length)
{
  int i = 0;
  while(i<length)
  {
    if(i==0 || array[i] > array[i-1])
    {
      i++;
    }else{
      swap(array, i, i-1);
      i--;
    }
  }
}

/**
 * @brief Find if `value` in the `array`
 */
int find(int* array, int length, int value)
{
  for(int i=0; i<length; i++)
  {
    if(array[i] == value)
    {
      return 1;
    }
  }
  return 0;
}

int* getRandomCapacitySystem(int k, int p_max)
{
  if(p_max < k) {return NULL;}
  int* res = (int*)malloc(sizeof(int)*k);
  res[0] = 1;
  for(int i=1; i<k; i++){
    // int max_value = p_max - (k - i) + 1;
    // int min_value = res[i-1] + 1;
    // res[i] = rand() % (max_value - min_value) + min_value;
    int random_value = 0;
    do{
      random_value = rand() % (p_max - 1) + 2;
    }while(find(res, i+1, random_value));
    res[i] = random_value;
  }
  sort(res, k);
  return res;
}