#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utility.h"

// Sort On the basis of Arrival Time only!


void MergeArr(struct task* readyQueue, int low, int mid, int high){
  int i = low;
  int j = mid+1;
  struct task temp[high-low+1];
  int z=0;
  while(i<=mid && j <= high){
    if(readyQueue[i].at <= readyQueue[j].at){
        temp[z++]=readyQueue[i];
        i++;
    }else{
      temp[z++]=readyQueue[j];
      j++;
    }
  }
  
  while(i<=mid) temp[z++] = readyQueue[i++];

  while(j<=high) temp[z++] = readyQueue[j++];
  
  for(int k = low; k <= high ;k++){
      readyQueue[k] = temp[k-low];
  }
}

//Implementing Merge Sort to get min T.C of NlogN
void MergeSort(struct task* readyQueue,int low,int high){
    if(low >= high) return;
    int mid = (low + high)/2;
    MergeSort(readyQueue,low,mid);
    MergeSort(readyQueue,mid+1,high);
    MergeArr(readyQueue,low,mid,high);
}

