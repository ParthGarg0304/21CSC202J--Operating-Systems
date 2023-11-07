//fcfs scheduling
#include <stdio.h>
#include <stdlib.h>

int main() {

//Read number of processes
int n;
printf("Enter number of processes: ");
scanf("%d", &n);

//Initialize burst time for each process
int b_time[n];
printf("Input the burst time:\n");
for(int i = 0; i < n; i++) {

printf("PROCESS %d: ", i + 1);
scanf("%d", &b_time[i]);
}

// Display the processes with FCFS algorithm and store the waiting time and turnaround time for each process
int time = 0;
int w_time[n];
int ta_time[n];
printf("PROCESS\tWAIT_TIME\tTURNAROUND_TIME\n");
for (int i = 0; i < n; i++) {
time += b_time[i];
ta_time[i] = time;
w_time[i] = ta_time[i] - b_time[i];
printf("P%d\t%d\t\t%d\n", (i + 1), (time - b_time[i]), time, ta_time[i]);
}

//Calculate average Turnaround time and wait time
float avg_wait = 0, avg_turnaround = 0;
for(int i = 0; i < n; i++) {

avg_wait += w_time[i];
avg_turnaround += ta_time[i];
}
avg_wait /= n;
avg_turnaround /= n;

//Display the values
printf("\nAverage Waiting Time: %0.3f\nAverage Turnaround Time: %0.3f\n", avg_wait, avg_turnaround);

return 0;
}