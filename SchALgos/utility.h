
#ifndef UTILITY_H
#define UTILITY_H

#include<stdio.h>

#define SIZE 20

struct task{
  int pid;
  int bt;
  int at;
  int ct;
  int tat;
  int rt;
  int wt;
  int remt;
  int isCompleted;
};

void MergeSort(struct task* readyQueue,int low, int high);

int schedule_fcfs(struct task* readyQueue,int processCount);

void schedule_sjf(struct task* readyQueue,int processCount);

void printResult(struct task* readyQueue,int processCount);

int prepareReadyQueue(struct task** readyQueue,int *processCount);


#endif
