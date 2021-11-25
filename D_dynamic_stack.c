#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int data;
    //other elements;
}element;

//inserting elements
void push(element *stack,int *MAX_SIZE, int *top)
{
    if(*top>=*MAX_SIZE)        //check if stack is full
    {
        stack = realloc(stack, 2*(*MAX_SIZE)*sizeof(*stack)); //increase the stack size by 2 times
        *MAX_SIZE = 2 * (*MAX_SIZE);
        if(stack==NULL)
        {
            printf("Insufficient Memory\n");
            exit(0);
        }
    }
    printf("Enter the element: ");
    scanf("%d",&stack[++(*top)].data);  //
    printf("\n");
}

int pop(element *stack,int *top)
{
    if(*top==-1)                 //check if stack is empty
    {
        printf("Stack is empty\n\n");
        return 0;
    }
    printf("%d removed from stack\n\n",stack[(*top)--].data);   //decrementing top if element is available
    return 0;
}

int display(element *stack,int *top)
{
    if(*top==-1)       //check if stack is empty
    {
        printf("Stack is empty\n\n");
        return 0;
    }
    for(int i=0;i<=*top;i++)     //print all stack elements
        printf("%d ",stack[i].data);
    printf("<-top\n\n");
    return 0;
}

int main()
{
    element *stack;
    int top=-1;
    stack = (element *)malloc(sizeof(*stack));
    int capacity = 1;
    char input[2];

    while(1)
    {
        printf("Insert(I) Remove(R) Display_Stack(D) Exit(E)\n");
        printf("Press any: ");
        scanf("%s",input);
        printf("\n\n");
        switch(input[0])
        {
            case 'I': push(stack,&capacity,&top);
                      break;
            case 'R': pop(stack,&top);
                      break;
            case 'D': display(stack,&top);
                      break;
            case 'E': return 0;
            default : printf("Please enter right char\n");
        }

    }
    return 0;
}
