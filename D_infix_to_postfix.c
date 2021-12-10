#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//external variables
char * stack ;
int top=-1,stage=0;    //stage is to know whether we need to differentiate number and operator

void push(char c)        //push on stack
{
    stack[++top] = c;
}

void pop()     //print when pop
{
        printf("%c",stack[top--]);
        stage=1;
}

void infix_to_postfix(char *exp)
{
    stack = (char *)malloc(sizeof(char)*strlen(exp));
    int i = 0;
    while(exp[i]!='\0')
    {
        if(exp[i]>='0' && exp[i]<='9')       //check if number
        {
            stage = 1;
            printf("%c", exp[i]);
        }
        else if(exp[i]==' ')
        {
            if(stage==1)          //if we printed number or operator then print space
                printf(" ");
            stage=0;
        }
        else if(exp[i]=='+' || exp[i]=='-')
        {
            while(stack[top]!='(' && top>=0)     //keep printing until ( as all other operators are high priority
                pop();
            push(exp[i]);   // push the current operator
        }
        else if(exp[i]==')')
        {
            while(stack[top]!='(')     //keep printing until ( as the ) has the highest priority
                pop();
            top--;          //we should not consider printing (
        }
        else if(exp[i]=='(')     //push as ( has low priority outside stack
        {
            push(exp[i]);
        }
        else
        {
            while(1)
            {
                if(stack[top]=='*' || stack[top]=='/' || stack[top]=='%') //pop until same priority operators are found
                    pop();
                else
                {
                    push(exp[i]);
                    break;
                }
            }
        }
        i++;
    }
    while(top>=0)        //pop rest of the operators
    {
        printf(" ");
        pop();
    }
}

int main()
{
    int MAXSIZE = 2;
    char *exp = (char *)malloc(sizeof(char)*MAXSIZE);
    int brackets = 0;
    printf("Enter the Expression: ");

    char c = getchar();
    int i=0;
    while(1)
    {
        if(i>=MAXSIZE-2)
            exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
        if(c>='0' && c<='9')
            exp[i++]=c;
        else if(c=='*' || c=='/' || c=='%' || c=='(' || c==')')
        {
            if(c==')')
            {
                if(brackets<=0)
                {
                    printf("Wrong statement\n");
                    return 0;
                }
                else
                    brackets--;
            }
            if(c=='(')
                brackets++;

            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
            exp[i++] = ' ';
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
            exp[i++] = c;
            if(i>=MAXSIZE-2)
                exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
            exp[i++] = ' ';
        }
        else if(c=='+' || c=='-')
        {
            if(i>0)
            {
                if(exp[i-1]==' ')
                {
                    if(i>=MAXSIZE-2)
                        exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
                    exp[i++] = c;
                }
                else
                {
                    if(i>=MAXSIZE-2)
                        exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
                    exp[i++] = ' ';
                    if(i>=MAXSIZE-2)
                        exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
                    exp[i++] = c;
                    if(i>=MAXSIZE-2)
                        exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
                    exp[i++] = ' ';
                }
            }
            else
            {
                if(i>=MAXSIZE-2)
                    exp = realloc(exp, sizeof(char)*(MAXSIZE *= 2));
                exp[i++] = c;
            }
        }
        else if(c=='\n')
        {
            if(exp[i-1]>='0' && exp[i-1]<='9')
                break;
            else
            {
                printf("Wrong format\n");
                return 0;
            }
        }
        else
        {
            printf("Wrong format\n");
            return 0;
        }
        c = getchar();
    }
    if(brackets>0)
    {
        printf("Wrong format\n");
        return 0;
    }
    exp[i]='\0';
    printf("%s\n",exp);
    infix_to_postfix(exp);
    printf("\n");
}
