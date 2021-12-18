#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

struct NODE *top = NULL;

int push(); //ADD ELEMENT TO THE STACK
int pop();  //REMOVE ELEMENT FROM THE STACK
int display(); //DISPLAY THE STACK

struct NODE *create_node(); //CREATES NEW NODE

int main()
{
	int choice;
	printf("\n\n\t\tSTACK IMPLEMENTATION USING LINKED LIST\n\n");
	while(1)
	{
		printf("\n\n1) PUSH\n2) POP\n3) DISPLAY\n4) EXIT");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push(); display(); break;
			case 2: pop();  display(); break;
			case 3: display(); break;
			case 4: return 0;
			default: printf("\n\nINVALID ENTRY");
		}
	}
}

int push()
{
	//CHECKING IF STACK IS EMPTY
	if(top == NULL)
	{
		//ADDING THE FIRST NODE
		top = create_node();
		//CHECKING IF SPACE FOR FIRST NODE IS ALLOCATED
		if(top == NULL)
			return printf("\n\nSTACK IS FULL\n\n");
		return printf("\n\nStack Created & Element Pushed\n\n");
	}

	//CREATING A TEMPORARY POINTER POINTING TO WHERE TOP POINTS CURRENTLY (1ST NODE)
	struct NODE *temp = top;

	//MAKING THE TOP POINT TO THE NEWLY CREATED NODE
	top = create_node();

	//MAKING THE NEWLY CREATED NODE POINT TO THE PREVIOUSLY EXISTED NODE AT THAT INDEX
	top->next = temp;

	return printf("\n\nPUSH SUCCESSFUL\n\n");
}

int pop()
{
	//CHECKING IF STACK IS EMPTY
	if(top == NULL)
		return printf("\n\nPOP UNSUCCESSFUL\n\n");

	//CREATING A TEMPORARY POINTER POINTING TO WHERE TOP POINTS CURRENTLY (1ST NODE)
	struct NODE *temp = top;

	//MAKING THE TOP POINTING TO NEXT NODE(2ND NODE)
	top = top->next;

	printf("\n\nPOP SUCCESSFUL. ELEMENT REMOVED: %d\n\n",temp->data);

	free(temp);
}


int display()
{
	//CHECKING IF STACK IS EMPTY
	if(top == NULL)
		return printf("\n\nSTACK IS EMPTY");

	struct NODE *temp = top;

	//DISPLAYING THE NODES UNTIL LAST NODE
	for(temp = top; temp != NULL; temp = temp->next)
		printf("\n\t|-------|\n\t|   %d   |",temp->data);

	printf("\n\t|-------|");

	return 0;
}


struct NODE* create_node()
{
	struct NODE *temp;

	//ALLOCATING SPACE FOR THE NODE
	temp = malloc(sizeof(struct NODE));

	//CHECKING IF SPACE IS ALLOCATED
	if(temp == NULL)
	{
		printf("\n\nHEAP IS FULL\n\n");
		return NULL;
	}

	temp->next = NULL;

	printf("\n\nEnter the element: ");
	scanf("%d",&temp->data);

	return temp;
}