#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

struct NODE *front = NULL; 
struct NODE *rear = NULL; 

int enqueue(); //ADD ELEMENT TO THE QUEUE
int dequeue(); //REMOVE ELEMENT FROM THE QUEUE
int display(); //DISPLAY THE QUEUE

struct NODE* create_node(); //CREATE NODE

int main()
{
	int choice;
	printf("\n\n\t\tQUEUE IMPLEMENTATION USING LINKED LIST\n\n");
	while(1)
	{
		printf("\n\n1) ENQUEUE\n2) DEQUEUE\n3) DISPLAY\n4) EXIT");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: enqueue(); display(); break;
			case 2: dequeue();  display(); break;
			case 3: display(); break;
			case 4: return 0;
			default: printf("\n\nINVALID ENTRY");
		}
	}
}

int enqueue()
{
	//CHECKING IF QUEUE IS EMPTY
	if(front == NULL)
	{
		front = rear = create_node();
		return printf("\n\nQUEUE CREATED AND ELEMENT ENQUEUED\n\n");
	}

	//CREATING A NODE AND ADDING IT TO THE END OF THE QUEUE
	rear->next = create_node();

	//POINTING THE REAR TO THE RECENTLY ADDED NODE
	rear = rear->next;

	return printf("\n\nENQUEUE SUCCESSFUL\n\n");
}

int dequeue()
{
	//CHECKING IF THE QUEUE IS EMPTY
	if(front == NULL)
		return printf("\n\nDEQUEUE UNSUCCESSFUL");

	//CREATING A TEMP VARIABLE THAT POINTS TO WHERE FRONT POINTS (1ST NODE)
	struct NODE *temp = front;

	//MAKING FRONT POINT TO THE NEXT NODE
	front = front->next;

	int element_removed = temp->data;

	free(temp);

	return printf("\n\nDEQUEUE SUCCESSFUL. ELEMENT REMOVED: %d\n\n",temp->data);
}

int display()
{
	//CHECKING IF THE QUEUE IS EMPTY
	if(front == NULL)
		return printf("\n\nQUEUE IS EMPTY\n\n");

	struct NODE *temp;

	printf("|");

	//PRINTING THE ELEMENTS TILL THE LAST NODE WHICH POINTS TO NULL
	for(temp = front; temp != NULL; temp = temp->next)
		printf("%d|",temp->data);

	printf("\n\n");
}

struct NODE *create_node()
{
	struct NODE *temp = NULL;

	//ALLOCATING SPACE FOR A SINGLE NODE
	temp = malloc(sizeof(struct NODE));

	printf("\n\nENTER THE ELEMENT: ");
	scanf("%d",&temp->data);

	//MAKING THE NODE POINT TO NULL INITIALLY
	temp->next = NULL;

	return temp;
}