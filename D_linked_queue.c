//
// Created by BDB 🙋🏻‍♂️ on 17/12/21.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct element element;
struct element
{
    int number;
    //other elements
};
typedef struct node node;
struct node
{
    element data;
    node *next;
};

node *top;
node *create_node()
{
    node *temp=NULL;
    temp = malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("\n\n***Memory full***\n");
        return NULL;
    }
    printf("\n\nenter the element: ");
    scanf("%d",&(temp->data.number));
    temp->next = NULL;
    return temp;
}
void push()
{
    node *temp = create_node();
    if(top==NULL)
    {
        top=temp;
        return;
    }
    temp->next = top;
    top = temp;
}
void pop()
{
    if(top==NULL)
    {
        printf("\n\n***Stack underflow***\n");
        return;
    }
    printf("\n\n\t\t\t---removed->|%d|\n\n\n",top->data.number);
    node *temp = top;
    top = top -> next;
    free(temp);
}
void display()
{
    node *temp = top;
    if(temp==NULL)
    {
        printf("\n\nEmpty Stack\n");
        return;
    }
    printf("\t\t\t---------\n");
    printf("\t\t\t| %d |  |\n",temp->data.number);
    printf("\t\t\t---------\n");
    temp=temp->next;
    while(temp!=NULL)
    {
        printf("\t\t\t      ^\n");
        printf("\t\t\t      |\n");
        printf("\t\t\t---------\n");
        printf("\t\t\t| %d |  |\n", temp->data.number);
        printf("\t\t\t---------\n");
        temp = temp->next;
    }
}
void reverse_linked_list(node *head)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        printf("Nothing to reverse\n");
        return;
    }
    node *temp = head->next;
    node *next = temp->next;
    head->next=NULL;
    while(next!=NULL)
    {
        temp->next=head;
        head = temp;
        temp = next;
        next = next->next;
    }
    temp->next=head;
    top = temp;
}
int main()
{
    printf("\t\t\t***********Welcome to the stack world************\n");
    int n;
    while(1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.display 4.exit: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: push();
                    printf("\t\t\tCurrent Queue\n\n\n");
                    display();
                break;
            case 2: reverse_linked_list(top);
                    pop();
                    reverse_linked_list(top);
                    printf("\t\t\tCurrent Queue\n\n\n");
                    display();
                break;
            case 3: display();
                break;
            case 4: return 0;
            default: printf("Wrong input\n");
        }
    }
}
