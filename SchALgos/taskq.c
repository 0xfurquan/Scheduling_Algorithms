#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utility.h"

int prepareReadyQueue(struct task** readyQueue,int *processCount){
  
  FILE *processFile = fopen("process.txt","r");
  if(processFile == NULL){
    perror("Can't Open File");
    return 1;
  }
  struct task * temp=NULL;
  char buffer[SIZE];
  
  while(fgets(buffer,SIZE,processFile)){
    char *pid = strtok(buffer,",\n\r");
    char *at = strtok(NULL,",\n\r");
    char *bt = strtok(NULL,",\n\r");
    
    if(pid && at && bt){
      (*processCount)++;
      
      temp = realloc(temp,(*processCount)*sizeof(struct task));
      if(temp==NULL){
        perror("temp Failed: Can't Allocate Memory");
        free(*readyQueue);
        return -1;
      }
      *readyQueue = temp;
      
      (*readyQueue)[(*processCount) -1].pid = atoi(pid);
      (*readyQueue)[(*processCount) -1].at = atoi(at);
      (*readyQueue)[(*processCount) -1].bt = atoi(bt);
      (*readyQueue)[(*processCount) -1].remt = atoi(bt);
      (*readyQueue)[(*processCount) -1].isCompleted = 0;
    }
  }
  fclose(processFile);
  return 0;
}
