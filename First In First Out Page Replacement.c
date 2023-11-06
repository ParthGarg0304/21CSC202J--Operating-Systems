#include<stdio.h>

int main()
{
    int x;
    int frames;
    printf("enter the number of incomming reference inputs");
    scanf("%d",&x);
    int incomingStream[x];
    printf("enter the incomming reference stream");
    for(int i=0;i<x;i++){
        scanf("%d",&incomingStream[i]);
    }
   
    printf("enter the number of frames");
    scanf("%d",&frames);
   
    int pageFaults = 0;
    int m, n, s, pages;

    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);

    printf("Incoming \t");
    for(int i=1;i<=frames;i++){
        printf("Frame %d \t\t",i);
    }
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
       
        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
     
        printf("\n");
        printf("%d\t\t\t",incomingStream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:%d\n", pageFaults);
    return 0;
}