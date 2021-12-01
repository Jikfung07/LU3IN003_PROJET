#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int func(int** a)
{
  int* res = (int*)calloc(4, sizeof(int));
  res[2] = 5;
  (*a) = res;
  return 1;
}

int main()
{
  clock_t start,end;  
  start =clock();//or time(&start);  
  //…calculating…  
  printf("Hello World\n");
  int i = 9999999*99;
  while(i--);
  end =clock();  
  printf("time=%f\n",(double)(end-start)/CLOCKS_PER_SEC);  
  return 0;
}
