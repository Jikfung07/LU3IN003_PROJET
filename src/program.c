#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "algos.h"
#include "analyse.h"
#include <time.h>


void test_Algo(int num_algo) 
{
  int S, k;
  int* V;
  char* path = "data.txt";
  if(readfile(path, &S, &k, &V) == FILE_SUCCESS)
  {
    launch(num_algo, S, V, k, SHOW);
  }else{
    printf("Error\n");
  } 
}

void test_testGloutonCompatible(int k, int* V)
{
  if(COMPATIBLE == testGloutonCompatible(k,V))
    printf("True\n");
  else
    printf("False\n");
}

void test_func(int num_algo, int d)
{
  stat_time_algo(num_algo, d, 1000, 20);
}

void test_getRandomCapacitySystem(int k, int p_max)
{
  int* V = getRandomCapacitySystem(k, p_max);
  for(int i=0; i<k; i++)
  {
    printf("V[%d] = %d\n", i, V[i]);
  }
}

void test_showStatistics()
{
  showStatistique(100, 20, 10, 50);
}

int main(int argc, char** args)
{
  // initialize the random seed
  srand(time(NULL)); 
  // test_Algo(3);
  // test_showStatistics();
  test_func(3, 2);
  // int* V = getExpocapacitySystem(20, 2);
  // launch(1, 100000, V, 20, SHOW);
  // int i=100;
  // while(i--)
  // {   
  //   time_t start = clock();
  //   // execute the algo
  //   launch(3, 1000, V, 50, HIDE);
  //   // end the timer
  //   time_t end = clock();
  //   printf("%.20f\n",(double)(end-start)/CLOCKS_PER_SEC);
  // }
  return 0;
}