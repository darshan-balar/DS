#include<stdio.h>
#include<stdlib.h>


int char_to_int(char *integer,int len)    //function to convert string to integer
{
    int result=0;
    for(int j=len;j>=0;j--)
        result = result*10 + integer[j]-'0' ;

    return result;
}
void push(int *stack,int element,int *top)   //push integers
{
    stack[++(*top)] = element;
}

int pop(int *stack,int *top)    //pop top 2 integers and evaluate
{
    return stack[(*top)--];
}


int eval(int *exp,int len)
{
    int *stack = (int *)malloc(sizeof(int)*len);
    int top = -1,op1,op2;
    for(int i=0;i<len;i++)
    {
        if(exp[i]==-1)       //check if its an integer or operator
        {
            switch(exp[++i]) //skip -1
            {

                case '+': push(stack,pop(stack,&top)+pop(stack,&top),&top);
                            break;
                case '-': op2 = pop(stack,&top);
                          op1 = pop(stack,&top);
                          push(stack,op1-op2,&top);
                          break;
                case '/': op2 = pop(stack,&top);
                          op1 = pop(stack,&top);
                          if(op1==0)
                          {
                              printf("ERROR: Divide by error\n");
                              exit(0);
                          }
                          push(stack,op1/op2,&top);
                          break;
                case '*': push(stack,pop(stack,&top)*pop(stack,&top),&top);
                            break;
                case '%': op2 = pop(stack,&top);
                          op1 = pop(stack,&top);
                          push(stack,op1%op2,&top);
                            break;
            }
            i++;     //skip -1 in expression array
        }
        else
            push(stack,exp[i],&top);   //push if its an integer
    }
    if(top!=0)
    {
        printf("Wrong expression\n");
        exit(0);
    }
    return stack[top];
}


int main()
{
    int MAXSIZE=2;
    int *exp = (int *)malloc(sizeof(int)*MAXSIZE);
    int i=0;
    char c,integer[100];
    printf("Enter space seperated integer Postfix Expression(ex: 1 2 + 7 *): ");

    while(1)
    {
        int j=0;
        c = getchar();

        //add -1 before and after the operator to differentiate between integer and ascii code of operator
        if(c == '+' || c == '%' || c=='-' || c=='*' || c=='/')  //if operater
        {
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++]=-1;           // add -1 before operator
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++]=c;           //add operator
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++]=-1;          //add -1 after operator
        }
        else if(c == '\n')  //if expression is completed
        {
            break;
        }
        else if(c>='0' && c<='9')
        {
            while(c!=' ' && c!='\n')   //take chars of integer until space is found
            {
                integer[j++]=c;
                c=getchar();
            }
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(int)*(MAXSIZE *= 2));
            exp[i++] = char_to_int(integer,j-1);   //convert string to integer
            if(c=='\n')
                break;
        }
    }
    int result = eval(exp,i);

    printf("Result = %d\n",result);

    return 0;
}
