#include<stdio.h>
#include<stdlib.h>

void resize(int Queue[],int *rear,int *front,int *MAXSIZE)
{

        int i;
        int *newQueue = (int *)malloc(sizeof(int)*2*(*MAXSIZE));
        if((*front)<((*MAXSIZE)-1))
        {
            ++(*front);
            for(i=0;(*front)<(*MAXSIZE);i++,++(*front))
                newQueue[i] = Queue[*front];
            for(int j=0;j<=(*rear);j++,i++)
                newQueue[i]=Queue[j];
        }
        else
        {
            for(i=0;i<(*MAXSIZE)-1;i++)
                newQueue[i]=Queue[i];
        }
        *rear = i-1;
        *front = 2*(*MAXSIZE)-1;
        *MAXSIZE = (*MAXSIZE)*2;
        free(Queue);
        Queue = newQueue;
}


void EnQueue(int *Queue,int *rear,int *front,int *MAXSIZE)
{
    if((*rear+1)%(*MAXSIZE) == *front)      //checking if next is empty
        resize(Queue,rear,front,MAXSIZE);
    *rear = (*rear+1)%(*MAXSIZE);    //incrementing rear circularly
    printf("\n\nEnter the element: ");
    scanf("%d",&Queue[(*rear)]);      //store elements and increment rear
    printf("\n\n");
}

void DeQueue(int Queue[],int *front, int *rear,int MAXSIZE)
{
    if(*front==*rear)       //checking if queue is empty
    {
        printf("\n\nQueue is empty\n\n");
        return;
    }
    *front = (*front+1)%MAXSIZE;    //circularly incrementing front
    printf("\n\nElement removed: %d\n\n",Queue[(*front)]); //removed element
}

void Show(int Queue[],int *front,int *rear,int MAXSIZE)
{
    if(*rear==*front)
    {
        printf("\n\nQueue is empty\n\n");
        return;
    }
    printf("\n\nQueue: front -> ");
    if(*rear<*front)
    {
        for(int i=(*front)+1;i<MAXSIZE;i++)      //print the Available elements
            printf("%d ",Queue[i]);
        for(int i=0;i<=*rear;i++)      //print the Available elements
            printf("%d ",Queue[i]);
    }
    else
        for(int i=*front+1;i<=*rear;i++)      //print the Available elements
            printf("%d ",Queue[i]);

    printf("<- rear\n\n");
}
int main()
{
    int MAXSIZE=1;
    char input[2];
    int *Queue = (int *)malloc(sizeof(int)*MAXSIZE);
    int rear=-1,front=0;
    printf("Available options: \n");
    while(1)
    {
        printf("EnQueue(E) DeQueue(D) Show_Queue(S) Quit(Q)\n");
        printf("Press any: ");
        scanf("%s",input);
        switch(input[0])
        {
            case 'E': EnQueue(Queue,&rear,&front,&MAXSIZE);
                        Show(Queue,&front,&rear,MAXSIZE);
                        break;
            case 'D': DeQueue(Queue,&front,&rear,MAXSIZE);
                        break;
            case 'S': Show(Queue,&front,&rear,MAXSIZE);
                        break;
            case 'Q': return 0;
            default : printf("Enter the right option\n");
        }
    }
}
