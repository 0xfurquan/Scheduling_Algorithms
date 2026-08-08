#include<stdio.h>
#include "utility.h"

void printResult(struct task *readyQueue, int processCount) {
    if (readyQueue == NULL || processCount <= 0) {
        printf("\n[!] No process data available to print.\n");
        return;
    }

    // 1. Print the Table Header with explicitly fixed column widths
    printf("\n========================================================================\n");
    printf("%-8s | %-12s | %-10s | %-15s | %-15s | %-12s\n", 
           "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time");
    printf("========================================================================\n");

    double total_wt = 0;
    double total_tat = 0;

    // 2. Loop through the array and render each process row perfectly aligned
    for (int i = 0; i < processCount; i++) {
        printf("%-8d | %-12d | %-10d | %-15d | %-15d | %-12d\n",
               readyQueue[i].pid,
               readyQueue[i].at,
               readyQueue[i].bt,
               readyQueue[i].ct,
               readyQueue[i].tat,
               readyQueue[i].wt);
               
        // Accumulate statistics for final arithmetic averages
        total_wt += readyQueue[i].wt;
        total_tat += readyQueue[i].tat;
    }
    printf("========================================================================\n");

    // 3. Print the calculated system averages bounded to 2 decimal places
    printf("Average Waiting Time    : %.2f ms\n", total_wt / processCount);
    printf("Average Turnaround Time : %.2f ms\n", total_tat / processCount);
    printf("========================================================================\n");
}




