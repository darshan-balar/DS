#include<stdio.h>

void EnQueue(int Queue[],int *rear,int *front,int MAXSIZE)
{
    if(*front==*rear)               //if all elements are removed
        *front=*rear=0;              //initialise front and rear to start of queue
    if(*rear == MAXSIZE)
    {
        printf("\n\nInsufficient space\n\n");
        return;
    }
    printf("\n\nEnter the element: ");
    scanf("%d",&Queue[(*rear)++]);      //store elements and increment rear
}

void DeQueue(int Queue[],int *front, int *rear)
{
    if(*front==*rear)
    {
        printf("\n\nQueue is empty\n\n");
        return;
    }
    printf("\n\nElement removed: %d\n\n",Queue[(*front)++]); //Increment front for removal
}

void Show(int Queue[],int *front,int *rear)
{
    if(*rear==*front)
    {
        printf("\n\nQueue is empty\n\n");
        return;
    }
    printf("\n\nQueue: front -> ");
    for(int i=*front;i<*rear;i++)      //print the Available elements
        printf("%d ",Queue[i]);
    printf("<- rear\n\n");
}
int main()
{
    int MAXSIZE=1000;
    char input[2];
    int Queue[MAXSIZE];
    int rear=0,front=0;
    printf("Available options: \n");
    while(1)
    {
        printf("EnQueue(E) DeQueue(D) Show_Queue(S) Quit(Q)\n");
        printf("Press any: ");
        scanf("%s",input);
        switch(input[0])
        {
            case 'E': EnQueue(Queue,&rear,&front,MAXSIZE);
                        break;
            case 'D': DeQueue(Queue,&front,&rear);
                        break;
            case 'S': Show(Queue,&front,&rear);
                        break;
            case 'Q': return 0;
            default : printf("Enter the right option\n");
        }
    }
}
