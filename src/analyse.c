#include "algos.h"
#include "analyse.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Get the Mean of an array, and the max value
 * 
 * @param array the array
 * @param length length of the array
 * @param out_maxValue the max value of the array
 * @return double : The mean of the array
 */
double getMean(double* array, int length, double* out_maxValue)
{
  int indexOfMax = 0;
  double mean = 0;
  for(int i=0; i<length; i++)
  {
    mean += array[i];
    if(array[i]>array[indexOfMax])
    {
      indexOfMax = i;
    }
  }
  *out_maxValue = array[indexOfMax];
  return mean / length;
}

void showResult(char* title, double mean, double maxValue)
{
  printf("The statistic result of %s\n", title);
  printf("The average time : %.2f\n", mean);
  printf("The max time : %.2f\n", maxValue);
}

void showStatistique(int p_max, int f, int k, int length_stat)
{
  double averageTime_algo_I, maxTime_algo_I;
  double averageTime_algo_II, maxTime_algo_II;
  double* stat_algo_I = (double*)calloc(length_stat, sizeof(double));
  double* stat_algo_II = (double*)calloc(length_stat, sizeof(double));
  int round = 0;
  while(round<length_stat)
  {
    int* V = getRandomCapacitySystem(k, p_max);
    if(! testGloutonCompatible(k, V))
    {
      int border = f * p_max;
      double* stat_temp_algo_I = (double*)calloc(border-p_max+1, sizeof(double));
      double* stat_temp_algo_II = (double*)calloc(border-p_max+1, sizeof(double));
      double temp; // a temporary variable
      for(int s=p_max; s<=border; s++)
      {
        // current index
        int i = s - p_max;
        // temporary array of A
        int* A = (int*)malloc(sizeof(int)*k);

        // start timer for algo I
        clock_t start_I = clock();
        // launch algo I
        algo_I(V, k, s, k-1, &A);
        // end timer for algo I
        clock_t end_I = clock();
        // add to statistic array
        stat_temp_algo_I[i] = (double)(end_I-start_I)/CLOCKS_PER_SEC;

        // start timer for algo II
        // launch algo_II
        // end timer for algo II

        // free the temporary array A
        free(A);
      }// END{for}
      // statistic
      stat_algo_I[round-1] = getMean(stat_temp_algo_I, border-p_max+1, &temp);
      //stat_algo_II[round-1] = getMean(stat_temp_algo_II, border-p_max+1, &temp);
      // free the memory
      free(stat_temp_algo_I);
      free(stat_temp_algo_II);
      round++;
    }// END{if}
    free(V);
  }// END{while}
  // statistic
  averageTime_algo_I = getMean(stat_algo_I, length_stat, &maxTime_algo_I);
  // averageTime_algo_II = getMean(stat_algo_II, length_stat, &maxTime_algo_II);
  // free the memory
  free(stat_algo_I);
  free(stat_algo_II);
  // show result
  showResult("Algorithm I", averageTime_algo_I, maxTime_algo_I);
  // showResult("Algorithm II", averageTime_algo_II, maxTime_algo_II);
}

