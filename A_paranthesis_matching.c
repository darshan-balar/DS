#include<stdio.h>
#include<stdlib.h>

typedef struct stack{

	int top;
	int size;
	int *stack;
	int element;

}stack;

void push(stack *st); //add '(' onto the stack
void pop(stack *st); //remove ')' from the stack
int isFull(stack *st); //check if stack is full
int isEmpty(stack *st); //check if stack is empty
int match(stack *st); //check for matching paranthesis

int main()
{
	stack st;

	st.top = -1;

	st.size = 1;

	st.stack = malloc(st.size * sizeof(char));

	while((st.element = getchar()) != 10)
	{
		if(st.element == '(' || st.element == '{' || st.element == '[')
			push(&st);

		else if(st.element == ')' || st.element == '}' || st.element == ']')
			pop(&st);
	}

	if(st.top == -1)
		printf("\n\nParanthesis Balanced\n\n");

	else
		printf("\n\nParanthesis not balanced\n\n");
}


//add '(' onto the stack
void push(stack *st)
{
	if(isFull(st))
	{
		st->stack = realloc(st->stack, (2 * st->size * sizeof(char)));
		if(st->stack == NULL)
		{
			printf("\n\nMemory couldnt be allocated\n\n");
			exit(0);
		}
		st->size *= 2;
	}

	st->stack[++(st->top)] = st->element;
}

//remove ')' from the stack
void pop(stack *st)
{
	if(isEmpty(st) || match(st))
	{
		printf("\n\nParanthesis not balanced\n\n");
		exit(0);
	}

	--(st->top);
}

//check if stack is full
int isFull(stack *st)
{
	if(st->top == (st->size - 1))
		return 1;
	return 0;
}

//check if stack is empty
int isEmpty(stack *st)
{
	if(st->top == -1)
		return 1;
	return 0;
}

//check for matching paranthesis
int match(stack *st)
{
	if(st->element == ']' && st->stack[st->top] == '[')
		return 0;

	else if(st->element == '}' && st->stack[st->top] == '{')
		return 0;
	
	else if(st->element == ')' && st->stack[st->top] == '(')
		return 0;
	
	else
		return 1;
}