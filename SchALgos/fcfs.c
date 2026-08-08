#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utility.h" 


int main(){
  struct task* readyQueue = NULL;
  int processCount=0;
  
  prepareReadyQueue(&readyQueue,&processCount);

  schedule_sjf(readyQueue,processCount);
  
  printResult(readyQueue,processCount);

  free(readyQueue);  
  
  return 0;
}
