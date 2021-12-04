#include<stdio.h>
#include<stdlib.h>

void infix_to_postfix(char *exp)
{
    int i=0;
    int stage = 0;
    while(exp[i]!='\0')
    {
        while(exp[i]!=' ')
            putchar(exp[i++]);
        if(c==' ')
            i++;
        if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='(' || c==')')
        {
            if(c=='(')
                push(stack,&top,c);
            else if(c=='+' || c=='-')
            {
                while(pop(stack,&top)!='(' && top>=0);
                    push(stack,&top,c);
            }
            else
        }
    }
}

int main()
{
    int MAXSIZE = 2;
    char *exp = (char *)malloc(sizeof(char)*MAXSIZE);

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
    exp[i]='\0';
    printf("%s\n",exp);
    infix_to_postfix(exp);
}
