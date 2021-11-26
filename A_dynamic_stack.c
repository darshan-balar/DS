                ''' DYNAMIC STACK IMPLEMENTATION USING STRUCTURE '''


#include<stdio.h>
#include<stdlib.h>

//structure of stack
typedef struct stack
{
    int *stack;
    int size;
    int top;
}stack;

int push(stack *st); //Adding element onto the stack
int pop(stack *st); //Removing element from the stack
int peek(stack st); //Top most element of the stack
int display(stack *st); //Display the stack 
int isFull(stack *st); //Checking if stack is full
int isEmpty(stack *st); //Checking if stack is empty

int main()
{
    stack st;

    int operation;


    printf("\n\n\t\t\t\tSTACK IMPLEMENTATION\n\n");

    printf("Enter the size of stack: ");
    scanf("%d", &st.size);

    st.stack = malloc(sizeof(int) * st.size);

    st.top = -1;

    while(1)
    {
    
        printf("\n1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit");
    
        printf("\n\nEnter the operation to be performed: ");
        scanf("%d",&operation);
    
        switch(operation)
        {
            case 1: push(&st); break;
            
            case 2: pop(&st); break;
            
            case 3: peek(st); break;
            
            case 4: display(&st); break;
            
            case 5: printf("\n\nTHANK YOU\n\n"); free(st.stack); return 0;
            
            default: printf("\nInvalid Input\n");
        }

    }
    free(st.stack);
}

//Adding element onto the stack
int push(stack *st)
{
    int element;

    if(isFull(st))
    {
        st->stack = realloc(st->stack, sizeof(int)*2*st->size);
        
        if(st->stack == NULL)
            printf("\n\nMemory could not be allocated\n\n");
    }

    printf("\n\nEnter the element to be pushed: ");
    scanf("%d",&element);

    st->stack[++(st->top)] = element;

    printf("\n\nPUSH SUCCESSFUL\n\n");

    display(st);

    return 0;
}

//Removing element from the stack
int pop(stack *st)
{
    if(isEmpty(st))
    {
        printf("\n\nPOP UNSUCCESSFUL\n\nStack is empty\n\n");
        return 0;
    }

    int element = st->stack[(st->top)--];

    printf("\n\nElement popped is %d\n\nPOP SUCCESSFUL\n\n",element);

    if(!isEmpty(st))
        display(st);
}


//Top most element of the stack
int peek(stack st)
{
    if(isEmpty(&st))
    {
        printf("\n\nPEEK UNSUCCESSFUL\n\nStack is empty\n\n");
        return 0;
    }

    int element = st.stack[st.top];
    printf("\n\n%d is at the top of the stack\n\nPEEK SUCCESSFUL\n\n", element);
}

//Display the stack
int display(stack *st)
{
    if(isEmpty(st))
    {
        printf("\n\nDISPLAY UNSUCCESSFUL\n\nStack is empty\n\n");
        return 0;
    }
        
    printf("\t\t-------");
    for(int i = st->top; i >= 0; i--)
        printf("\n\t\t|  %d  |\n\t\t-------", st->stack[i]);

}

//Checking if stack is empty
int isEmpty(stack *st)
{
    if(st->top == -1)
        return 1;
    return 0;
}

//Cheking if stack is full
int isFull(stack *st) 
{
    if(st->top == (st->size - 1))
        return 1;
    return 0;
}
