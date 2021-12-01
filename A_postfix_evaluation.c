#include<stdio.h>

struct stack
{
	char element;
	int a[1000];
	int top;
	int total;
};

void evaluate(struct stack *);
void char_to_int(struct stack *);

int main()
{
	struct stack st;
	st.top = -1;
	st.total = 0;

	printf("\n\nEnter the POSTFIX EXPRESSION: ");

	while((st.element = getchar()) != 10)
		char_to_int(&st);

	printf("\n\nRESULT = %d\n\n",st.a[st.top]);
}

void char_to_int(struct stack *st)
{
	if(st->element >= '0' && st->element <= '9')
		st->total = st->total * 10 + (st->element - '0');

	else if(st->element == ' ' && st->total)
	{
		st->a[++st->top] = st->total;
		st->total = 0;								
	}

	else if(st->element == ' ')
		return;

	else
		evaluate(st);
}

void evaluate(struct stack *st)
{
	if(st->element == '+')
		st->a[st->top] = st->a[--st->top] + st->a[st->top+1];
	else if(st->element == '-')
		st->a[st->top] = st->a[--st->top] - st->a[st->top+1];
	else if(st->element == '*')
		st->a[st->top] = st->a[--st->top] * st->a[st->top+1];
	else if(st->element == '/')
		st->a[st->top] = st->a[--st->top] / st->a[st->top+1];
	else if(st->element == '%')
		st->a[st->top] = st->a[--st->top] % st->a[st->top+1];
}