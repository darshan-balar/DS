#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *next;
};

struct NODE *start = NULL; //POINTER POINTING TO START OF THE LIST

int insert(); //INSERTION MENU
int insert_at_start(); //INSERT TO THE START OF THE LIST
int insert_at_end(); //INSERT TO THE END OF THE LIST
int insert_at_index(); //INSERT TO THE USER SPECIFIED INDEX

int delete(); //DELETION MENU
int delete_at_start(); //DELETE FROM THE START OF THE LIST
int delete_at_end(); //DELETE FROM THE END OF THE LIST
int delete_at_index(); //DELETE FROM USER SPECIFIED INDEX

int display(); //DISPLAY THE LIST

struct NODE* create_node();//CREATE NODE

int main()
{
	int choice;
	printf("\n\n\t\tLINKED LIST IMPLEMENTATION\n\n");
	while(1)
	{
		printf("\n\n1) INSERT\n2) DELETE\n3) DISPLAY\n4) EXIT");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insert(); display(); break;
			case 2: delete(); display(); break;
			case 3: display(); break;
			case 4: return 0;
			default: printf("\n\nINVALID ENTRY !!!\n\n");
		}
	}
}

//*************************INSERTION********************************//

int insert()
{
	int choice;

	//CHECKING AND CREATING THE LIST IF THE LIST IS EMPTY
	if(start == NULL)
	{
		start = create_node();
		return printf("\n\nLIST CREATED\n\n");
	}

	printf("\n\n1) Insert at start\n2) Insert at end\n3) Insert at index");
	printf("\n\nWhere do you want to INSERT: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: insert_at_start(); break;
		case 2: insert_at_end(); break;
		case 3: insert_at_index(); break;
		default: printf("\n\nINVALID ENTRY !!!\n\n");
	}
}

int insert_at_start()
{
	//CREATING A TEMPORARY POINTER POINTING TO WHERE START POINTS CURRENTLY
	struct NODE *temp = start;

	//CREATING A NEW NODE AND MAKING START POINTING TO IT
	start = create_node();

	//MAKING THE NEW NODE POINTING TO WHERE START WAS PREVIOUSLY POINTING
	start->next = temp;

	return printf("\n\nINSERTION SUCCESSFUL\n\n");
}

int insert_at_end()
{
	//CREATING A TEMPORARY POINTER POINTING TO WHERE START POINTS CURRENTLY
	struct NODE *temp = start;

	//ITERATING UNTIL LAST NODE IS FOUND
	while(temp->next != NULL)
		temp = temp->next;

	//CREATING A NEW NODE AND MAKING THE LAST NODE POINT TO IT
	temp->next = create_node();

	return printf("\n\nINSERTION SUCCESSFUL\n\n");
}

int insert_at_index()
{
	int index, count = 0;
		
	//CREATING TEMPORARY AND PREVIOUS POINTERS AND MAKING THEM POINT TO WHERE START POINTS CURRENTLY
	struct NODE *prev, *temp;
	prev = temp = start;

	printf("\n\nEnter the index (starts from 1): ");
	scanf("%d",&index);

	if(index == 1)
	{
		insert_at_start();
		return 0;
	}

	//ITERATING TILL THE USER MENTIONED INDEX OR THE LAST NODE IS FOUND
	while(++count != index && temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	//IF USER MENTIONED INDEX IS GREATER THAN THE SIZE OF THE LIST, NEW NODE IS INSERTED AT THE END
	if(index > count)
	{	
		insert_at_end();
		return printf("\n\nIndex is greater than the size of the list. Hence inserted at the end\n\n");
	}

	//IF USER MENTIONED INDEX IS FOUND, MAKING THE PREVIOUS NODE TO THE INDEX, POINT TO NEWLY CREATED NODE
	prev->next = create_node();

	//MAKING THE NEW NODE POINT TO THE PREVIOUS EXISTED NODE AT THAT INDEX
	prev->next->next = temp;

	return printf("\n\nINSERTION SUCCESSFUL\n\n");
}

//*************************DELETION********************************//

int delete()
{
	//CHECKING IF LIST IS EMPTY
	if(start == NULL)
		return printf("\n\nDELETION UNSUCCESSFUL\n");

	int choice;

	printf("\n\n1) Delete from start\n2) Delete from end\n3) Delete from index");
	printf("\n\nWhere do you want to delete: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: delete_at_start(); break;
		case 2: delete_at_end(); break;
		case 3: delete_at_index(); break;
		default: printf("\n\nINVALID ENTRY !!!\n\n");
	}
}

int delete_at_start()
{
	//CREATING A TEMPORARY POINTER POINTING TO WHERE START POINTS CURRENTLY (1ST NODE)
	struct NODE *temp = start;
	
	//MAKING THE START POINT TO 2ND NODE IN THE LIST
	start = start->next;
	
	printf("\n\nDELETION SUCCESSFUL\n\nElement removed: %d",temp->data);
	
	free(temp);

	return 0;
}

int delete_at_end()
{
	//CREATING TEMPORARY AND PREVIOUS POINTERS POINTING TO WHERE START POINTS CURRENTLY
	struct NODE *temp, *prev;
	temp = prev = start;

	//ITERATING UNTIL LAST NODE IS FOUND
	while(temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	//IF FIRST NODE IS THE LAST NODE, POINT START TO NULL
	if(temp == start)
		start = NULL;

	printf("\n\nDELETION SUCCESSFUL\n\nELEMENT DELETED: %d\n\n",temp->data);

	free(temp);

	//AFTER DELETION POINT THE CURRENT LAST ELEMENT TO NULL
	prev->next = NULL;

	return 0;
}

int delete_at_index()
{
	int index, count = 0;

	printf("\n\nEnter the index: ");
	scanf("%d",&index);

	//CREATING TEMPORARY AND PREVIOUS POINTERS POINTING TO WHERE START POINTS CURRENTLY
	struct NODE *temp, *prev;
	temp = prev = start;

	if(index == 1)
	{
		delete_at_start();
		return 0;
	}

	//ITERATING TILL THE USER MENTIONED INDEX OR THE LAST NODE IS FOUND
	while(++count != index && temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}

	//IF USER MENTIONED INDEX IS GREATER THAN THE SIZE OF THE LIST, LAST NODE IS DELETED
	if(index > count)
	{
		delete_at_end();
		return printf("\n\nIndex is greater than the size of the list. Hence deleted from the end\n\n");
	}

	//MAKING THE PREVIOUS NODE TO THE INDEX, POINT TO NEXT NODE TO THE INDEX
	prev->next = temp->next;

	printf("\n\nDELETION SUCCESSFUL\n\nELEMENT REMOVED: %d",temp->data);

	free(temp);

	return 0;
}
	

//*************************DISPLAY********************************//

int display()
{
	if(start == NULL)
		return printf("\n\nLIST IS EMPTY\n\n");

	//CREATING A TEMPORARY POINTER POINTING TO WHERE START POINTS CURRENTLY
	struct NODE *temp = start;

	printf("\n---------------------------------------------\n");

	//PRINTING ALL THE NODES TILL NULL(LAST NODE) IS FOUND
	while(temp->next != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	return printf("%d\n---------------------------------------------\n", temp->data);
}


//*************************NODE CREATION********************************//

struct NODE* create_node()
{
	//ALLOCATING SPACE FOR NODE
	struct NODE *temp = malloc(sizeof(struct NODE));

	printf("\n\nEnter the element: ");
	scanf("%d",&temp->data);

	//MAKING THE NODE POINTING TO NULL
	temp->next = NULL;

	return temp;
}