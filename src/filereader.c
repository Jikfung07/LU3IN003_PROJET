#include "filereader.h"
#include <stdio.h>
#include <stdlib.h>

int readfile(const char* path, int* S, int* k, int** V)
{
  char buff[50];
  FILE * fp = fopen(path, "r");
  if(fp==NULL) // if the reading is error
    return FILE_ERROR;
  // read the quantity of the jam
  fscanf(fp, "%s", buff);
  *S = atoi(buff);
  // read the number of the type of jam-jars
  fscanf(fp, "%s", buff);
  *k = atoi(buff);
  // initialize the sequence
  *V = malloc(sizeof(int)*(*k));
  // read the sequence of the capacities of jam-jars
  for(int i=0; i<*k; i++)
  {
    fscanf(fp, "%s", buff);
    (*V)[i] = atoi(buff);
  }
  // close the file
  fclose(fp);

  return FILE_SUCCESS;
}