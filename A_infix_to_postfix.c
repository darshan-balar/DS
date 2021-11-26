#include<stdio.h>
#include<stdlib.h>

typedef struct stack 
{
	char element;
	int index;
	int top;
	char *stack;
	char *result;
	int size;

}stack;

int get_precedence(char element);
void check_precedence(stack *st);


int main()
{
	stack st;
	st.size = 100;
	st.index = 0;
	st.top = -1;

	st.stack = malloc(st.size * sizeof(int));
	st.result = malloc(st.size * sizeof(int));

	printf("\n\nINFIX EXPRESSION   = ");

	while((st.element = getchar()) != 10)
		check_precedence(&st);

	st.result[st.index] = '\0';

	//At the end, transfering the remaining elements from stack to the result
	while(st.top != -1)
		st.result[st.index++] = st.stack[st.top--];

	printf("\n\nPOSTFIX EXPRESSION = %s\n\n", st.result);

	free(st.stack);
	free(st.result);
}

//COMPARING PRECEDENCE OF ELEMENTS
void check_precedence(stack *st)
{

	while(st->top != -1)
	{
		if(st->element == '(')
			break;

		if(st->element == ')')
		{
			//when ')' is encountered, until '(' is encountered on stack, all elements are transferred from stack to result
			while(st->stack[st->top] != '(')
				st->result[st->index++] = st->stack[st->top--];	

			st->top--; //ignoring ')' from getting added to the result
			return;	
		}
		
		//comparing precedence of the current character in the input to the top character in the stack
		else if((st->stack[st->top] != '(') && (get_precedence(st->element) <= get_precedence(st->stack[st->top])))
		{
			//if precedence of current character in input is lesser, then top character from stack is popped into result
			st->result[st->index++] = st->stack[st->top];
			st->top--;
		}
		else
			break;
	}
	//current character in input is pushed onto the stack
	st->stack[++(st->top)] = st->element;
}


//RETURNING PRECEDENCE OF AN ELEMENT
int get_precedence(char element)
{
	if((element >= 'a' && element <= 'z') || (element >= 'A' && element <= 'Z'))
		return 3;
	else if(element == '*' || element == '/')
		return 2;
	else if(element == '+' || element == '-')
		return 1;
	else
	{
		printf("\n\nInvalid Character Encountered\n\n");
		exit(0);
	}	
}