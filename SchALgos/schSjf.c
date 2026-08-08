#include<stdio.h>
#include<stdlib.h>
#include "utility.h"
#include<limits.h>

void schedule_sjf(struct task* readyQueue, int processCount){
  // Sorts on Arrival Time
  MergeSort(readyQueue,0,processCount-1);  
  
  //Runtime Environment Variables
  int i=0;
  int time=0;
  int minbt = INT_MAX;
  int runningProcess = -1;
  
  while(i < processCount){
    for(int j=0;j<processCount;j++){
      if(time < readyQueue[j].at) break;
      else if(!readyQueue[j].isCompleted 
                && readyQueue[j].remt < minbt){
        
        minbt = readyQueue[j].remt;
        runningProcess = j;
      }
    }
    
    if(runningProcess == -1){
      time++;
      continue;
    }
    
    // Ran On Cpu;
    readyQueue[runningProcess].remt--;
    minbt = readyQueue[runningProcess].remt;
    time++;
    
    if(readyQueue[runningProcess].remt == 0){
      readyQueue[runningProcess].isCompleted = 1;
      readyQueue[runningProcess].ct = time;
      readyQueue[runningProcess].tat = readyQueue[runningProcess].ct - readyQueue[runningProcess].at;
      readyQueue[runningProcess].wt = readyQueue[runningProcess].tat - readyQueue[runningProcess].bt;
      
      runningProcess = -1;
      minbt = INT_MAX;
      i++;
    }
  }
}
