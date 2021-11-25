#include<stdio.h>


//inserting elements
void push(int stack[],int MAX_SIZE, int *top)
{
    if(*top>=MAX_SIZE)        //check if stack is full
    {
        printf("Stack is full\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d",&stack[++(*top)]);   //insert if space is available
    printf("\n");
}

int pop(int stack[],int *top)
{
    if(*top==-1)                 //check if is stack is empty
    {
        printf("Stack is empty\n\n");
        return 0;
    }
    printf("%d removed from stack\n\n",stack[(*top)--]);   //decrementing top if element is available
    return 0;
}

int display(int stack[],int *top)
{
    if(*top==-1)       //check if stack is empty
    {
        printf("Stack is empty\n\n");
        return 0;
    }
    for(int i=0;i<=*top;i++)     //print all stack elements
        printf("%d ",stack[i]);
    printf("<-top\n\n");
    return 0;
}

int main()
{
    int stack[100],MAX_SIZE=100,top=-1;
    char input[2];
    printf("Available operations:\n");
    while(1)
    {
        printf("Insert(I) Remove(R) Display_Stack(D) Exit(E)\n");
        printf("Press any: ");
        scanf("%s",input);
        printf("\n\n");
        switch(input[0])
        {
            case 'I': push(stack,MAX_SIZE,&top);
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
