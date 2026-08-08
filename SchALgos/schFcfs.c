#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utility.h"

int schedule_fcfs(struct task* readyQueue,int processCount){
  MergeSort(readyQueue,0,processCount-1);
  
  int time=0;
  for(int i=0;i<processCount;i++){
      int runtime = readyQueue[i].bt;
      // Ran on CPU;
      if(time < readyQueue[i].at) time = readyQueue[i].at;
      readyQueue[i].rt=time - readyQueue[i].at;
      time+=runtime;
      // EACH PROCESS STATS
      readyQueue[i].ct = time;
      readyQueue[i].tat = readyQueue[i].ct - readyQueue[i].at;
      readyQueue[i].wt = readyQueue[i].tat - readyQueue[i].bt;
      readyQueue[i].isCompleted = 1;
  }
  return time;
}
