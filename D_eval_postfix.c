#include<stdio.h>
#include<stdlib.h>


int char_to_int(char *integer,int len)
{
    int result=0;
    for(int j=len;j>=0;j++)
        result = result*10 + integer[j]-'0' ;

    return result;
}
void push(int *stack,int element,int *top)
{
    stack[++(*top)] = element;
}

int pop(int *stack,int *top)
{
    return stack[(*top)--];
}


int eval(int *exp,int len)
{
    int *stack = (int *)malloc(sizeof(int)*len);
    int top = -1,op1,op2;
    for(int i=0;i<len;i++)
    {
        if(exp[i]==-1)
        {
            switch(exp[++i])
            {

                case '+': push(stack,pop(stack,&top)+pop(stack,&top),&top);
                            break;
                case '-': op2 = pop(stack,&top);
                          op1 = pop(stack,&top);
                          push(stack,op2-op1,&top);
                          break;
                case '/': op2 = pop(stack,&top);
                          op1 = pop(stack,&top);
                          if(op1==0)
                          {
                              printf("ERROR: Divide by error\n");
                              exit(0);
                          }
                          push(stack,op2/op1,&top);
                          break;
                case '*': push(stack,pop(stack,&top)*pop(stack,&top),&top);
                            break;
                case '%': op2 = pop(stack,&top);
                          op1 = pop(stack,&top);
                          push(stack,op2%op1,&top);
                            break;
            }
            i++;
        }
        else
            push(stack,exp[i],&top);
    }
    return stack[top];
}


int main()
{
    int MAXSIZE=2;
    int *exp = (int *)malloc(sizeof(int)*MAXSIZE);
    int i=0;
    char c,integer[100];
    printf("Enter space seperated integer Postfix Expression: ");

    while(1)
    {
        int j=0;
        c = getchar();
        if(c == '+' || c == '%' || c=='-' || c=='*' || c=='/')
        {
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++]=-1;
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++]=c;
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++]=-1;
        }
        else if(c == '\n')
            break;
        else if(c>='0' && c<='9')
        {
            while(c!=' ')
            {
                integer[j++]=c;
                c=getchar();
            }
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++] = char_to_int(integer,j-1);
        }
        printf("i=%d\n",i);
    }
    printf("input completed\n");
    int result = eval(exp,i);

    printf("Result = %d\n",result);

    return 0;
}
