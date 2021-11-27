//''' STACK IMPLEMENTATION '''

#include<stdio.h>
#include<stdlib.h>

int push(int* stack, int *top, int size);
void pop(int* stack, int *top);
void peek(int* stack, int top);
void display(int *stack, int top);
int isFull(int top, int size);
int isEmpty(int top);


int main()
{
	int size, top = -1;

	int operation;


	printf("\n\n\t\t\t\tSTACK IMPLEMENTATION\n\n");

	printf("Enter the size of stack: ");
	scanf("%d", &size);

	int* stack = malloc(sizeof(int) * size);

	while(1)
	{

		printf("\n1) Push\n2) Pop\n3) Peek\n4) Display\n5) Exit");

		printf("\n\nEnter the operation to be performed: ");
		scanf("%d",&operation);

		switch(operation)
		{
			case 1: push(stack, &top, size); break;

			case 2: pop(stack, &top); break;

			case 3: peek(stack, top); break;

			case 4: display(stack,top); break;

			case 5: printf("\n\nTHANK YOU\n\n"); return 0;

			default: printf("\nInvalid Input\n");
		}
	}
}

//Pushing element into the stack
int push(int* stack, int *top, int size)
{
	int element;

	if(isFull(*top, size))
	{
		printf("\n\nPUSH UNSUCCESSFUL\n\nStack is full\n\n");
		return 0;
	}

	printf("\n\nEnter the element to be pushed: ");
	scanf("%d",&element);

	stack[++(*top)] = element;

	printf("\n\nPUSH SUCCESSFUL\n\n");

	display(stack, *top);

	return 0;
}

//Poping element from the stack
void pop(int* stack, int *top)
{
	if(isEmpty(*top))
	{
		printf("\n\nPOP UNSUCCESSFUL\n\nStack is empty\n\n");
		return;
	}

	int element = stack[(*top)--];

	printf("\n\nElement popped is %d\n\nPOP SUCCESSFUL\n\n",element);

	if(!isEmpty(*top))
		display(stack, *top);
}


//Top most element of the stack
void peek(int* stack, int top)
{
	if(isEmpty(top))
	{
		printf("\n\nPEEK UNSUCCESSFUL\n\nStack is empty\n\n");
		return;
	}

	int element = stack[top];
	printf("\n\n%d is at the top of the stack\n\nPEEK SUCCESSFUL\n\n", element);
}

//Display the stack
void display(int *stack, int top)
{
	if(isEmpty(top))
	{
		printf("\n\nDISPLAY UNSUCCESSFUL\n\nStack is empty\n\n");
		return;
	}

	printf("\t\t-------");
	for(int i = top; i >= 0; i--)
		printf("\n\t\t|  %d  |\n\t\t-------",stack[i]);

}

//Checking if stack is empty
int isEmpty(int top)
{
	if(top == -1)
		return 1;
	return 0;
}

//Cheking if stack is full
int isFull(int top, int size)
{
	if(top == (size - 1))
		return 1;
	return 0;
}
