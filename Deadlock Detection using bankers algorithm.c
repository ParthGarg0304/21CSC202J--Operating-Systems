#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m; //Number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int max[n][m]; //maximum resource claim of each process
    int alloc[n][m]; // Resources currently allocated to each process
    int avail[m]; // Available resources

    printf("Enter the maximum resource claim matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate the need matrix
    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    printf("\ninitial need matrix:\n");
    printf("    A B C");
    for (int i = 0; i < n; i++) {
        printf("\n P%d ",i);
        for (int j = 0; j < m; j++) {
            printf("%d ",need[i][j]);
        }
    }

    // Safety algorithm to check if the system is in a safe state
    int finish[n];
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int safeSeq[n];
    int count = 0;
    int safe = 1;

    while (count < n) {
        safe = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                printf("\nprocess %d is running\n",i);
                int j;
                int c=0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        printf("Not enough resources for process %d \n",i);
                        printf("....................................");
                        c+=1;
                        break;
                    }
                }
                if (c==0){
                    printf("\nEnough resources available for process %d \n",i);
                }
                if (j == m) {
                    printf("\n\nprocess %d is Executing\n\n",i);
                    
                    for (int k = 0; k < m; k++) {
                        alloc[i][k] += need[i][k];
                    }
                    for (int k = 0; k < m; k++) {
                        avail[k] -= need[i][k];
                    }
                    for (int k = 0; k < m; k++) {
                        need[i][k] = 0;
                    }
                    
                    
                    
                    printf("maximum resource claim matrix after process %d execution:\n",i);
                    printf("    A B C");
                    for (int x = 0; x < n; x++){
                        printf("\n P%d ",i);
                        for (int y = 0; y < m; y++){
                            printf("%d ",max[x][y]);
                        }
                    }
                    printf("\nneed matrix after process %d execution:\n",i);
                    printf("    A B C");
                    for (int x = 0; x < n; x++) {
                        printf("\n P%d ",i);
                        for (int y = 0; y < m; y++) {
                            printf("%d ",alloc[x][y]);
                            
                        }
                    }
                    
                    printf("\navailable matrix after process %d execution:\n",i);
                    printf("A B C\n");
                    for (int x = 0; x < m; x++) {
                        printf("%d ",avail[x]);
                        
                    }
                    
                    printf("\nneed matrix after process %d execution:\n",i);
                    printf("    A B C");
                    for (int x = 0; x < n; x++) {
                        printf("\n P%d ",i);
                        for (int y = 0; y < m; y++) {
                            printf("%d ",need[x][y]);
                        }
                    }
                    
                    printf("\n\nprocess %d has completed execution\n\n",i);
                    
                    for (int k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }
                    
                    for (int k = 0; k < m; k++) {
                        alloc[i][k]=0;
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    safe = 1;
                    
                    printf("maximum resource claim matrix after process %d completion:\n",i);
                    printf("    A B C");
                    for (int x = 0; x < n; x++){
                        printf("\n P%d ",i);
                        for (int y = 0; y < m; y++){
                            printf("%d ",max[x][y]);
                        }
                    }
                    printf("\nneed matrix after process %d completion:\n",i);
                    printf("    A B C");
                    for (int x = 0; x < n; x++) {
                        printf("\n P%d ",i);
                        for (int y = 0; y < m; y++) {
                            printf("%d ",alloc[x][y]);
                            
                        }
                    }
                    
                    printf("\navailable matrix after process %d completion:\n",i);
                    printf("A B C\n");
                    for (int x = 0; x < m; x++) {
                        printf("%d ",avail[x]);
                        
                    }
                    
                    printf("\nneed matrix after process %d completion:\n",i);
                    printf("    A B C");
                    for (int x = 0; x < n; x++) {
                        printf("\n P%d ",i);
                        for (int y = 0; y < m; y++) {
                            printf("%d ",need[x][y]);
                        }
                    }
                    
                    printf("\n...........................................\n");

                    
                    
                }
            }
        }
        if (!safe) {
            break;
        }
    }
    
    printf("\n\n\nResut\n");

    if (count < n) {
        printf("DeadLock is detected\n");
    }else{
        printf("No Deadlock Detected. \n");
    }

    return 0;
}