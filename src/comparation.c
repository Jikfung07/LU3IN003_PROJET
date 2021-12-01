/**
 * @file comparation.c
 * @brief This file content a function, 
 * which launch the specified algo, 
 * then record the duration in term of `S` and `k`.
 * Finally, we save all the data in a *.csv file
 * 
 */

#include "algos.h"
#include "analyse.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void stat_time_algo(int num_algo, int d, int S_max, int k_max)
{
  FILE *fp = NULL;
  // set path
  char* path;
  asprintf(&path, "exe_time_algo_%d.csv",num_algo);
  // open the file
  fp = fopen(path,"w");
  // write in the titels
  fputs("S;k;time\n",fp);
  for(int s=0; s<S_max; s++)
  {
    for(int k=0; k<k_max; k++)
    {
      // int* temp_A = (int*)malloc(k * sizeof(int));
      // for(int i=0; i<k; i++){temp_A[i] = 0;}
      int* V = getExpocapacitySystem(k, d);
      // start the timer
      time_t start = clock();
      // execute the algo
      launch(num_algo, s, V, k, HIDE);
      // algo_III(V, k, s, k-1, &temp_A);
      // end the timer
      time_t end = clock();
      // set the result
      char* result;
      asprintf(&result, "%d;%d;%f\n", s, k, (double)(end-start)/CLOCKS_PER_SEC);
      fputs(result, fp);
      free(result);
      free(V);
      // free(temp_A);
    }
  }
  fclose(fp);
  // free the memory
  free(path);
}