#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int data;
	struct NODE *prev;
	struct NODE *next;
};

struct NODE *start = NULL, *end = NULL; //POINTERS POINTING TO START AND END OF LIST

int count = 0; //NUMBER OF NODES IN LIST

int insert(); //INSERTION MENU
int insert_at_start(); //INSERT TO THE START OF THE LIST
int insert_at_end(); //INSERT TO THE END OF THE LIST
int insert_at_index(); //INSERT TO THE USER SPECIFIED INDEX

int delete(); //DELETION MENU
int delete_at_start(); //DELETE FROM THE START OF THE LIST
int delete_at_end(); //DELETE FROM THE END OF THE LIST
int delete_at_index(); //DELETE FROM USER SPECIFIED INDEX

int reverse(); //REVERSE THE LIST

int display(); //DISPLAY THE LIST

struct NODE* create_node(struct NODE**, struct NODE**); //CREATE NODE

int main()
{
	int choice;
	printf("\n\n\t\tDOUBLY LINKED LIST IMPLEMENTATION\n\n");
	while(1)
	{
		printf("\n\n1) INSERT\n2) DELETE\n3) REVERSE\n4) DISPLAY\n5) EXIT");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: insert(); display(); break;
			case 2: delete(); display(); break;
			case 3: reverse(); display(); break;
			case 4: display(); break;
			case 5: return 0;
			default: printf("\n\nINVALID ENTRY !!!\n\n");
		}
	}
}


int insert()
{
	int choice;

	//CHECKING IF LIST IS EMPTY
	if(start == NULL)
	{
		insert_at_start();
		return 0;
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
	//CREATING A NEW NODE AND MAKING START POINT TO IT
	start = create_node(&start, &start);

	//IF LIST HAS ONLY ONE NODE, MAKING THE END POINT TO THAT NODE
	if(start->next == NULL)
		end = start;

	return printf("\n\nINSERTION SUCCESSFUL\n\n");
}

int insert_at_end()
{
	//CREATING A DUMMY POINTER THAT POINTS TO NULL
	struct NODE *dummy = NULL;

	//CREATING A NEW NODE AND MAKING CURRENT LAST NODE AND END POINTER POINTER TO THAT
	end = end->next = create_node(&end, &dummy);

	free(dummy);

	return printf("\n\nINSERTION SUCCESSFUL\n\n");
}

int insert_at_index()
{
	//CREATING A TEMPORARY POINTER AND POINTING IT TO START
	struct NODE *temp = start;

	int index, temp_count = 1;

	printf("\n\nENTER THE INDEX (STARTS FROM 1): ");
	scanf("%d",&index);

	if(index < 1)
		return printf("\n\nINVALID INDEX\n\n");

	//IF INDEX IS 1, INSERTING THE NODE AT THE START
	if(index == 1)
	{
		insert_at_start();
		return 0;
	}

	//IF INDEX IS GREATER THAN COUNT, INSERTING THE NODE AT THE END
	if(index > count)
	{
		insert_at_end();
		return printf("\n\nINDEX IS GREATER THAN LENGTH OF LIST. HENCE INSERTED AT END\n\n");
	}


	//IF INDEX IS NEARER TO START, ITERATE FROM THE BEGINNING
    if((index - 0)  <= (count - index))
    {
    	temp = start;
    	
    	//ITERATING TILL THE INDEX IS FOUND
    	while(index != temp_count++)
    		temp = temp->next;

    }

    //ELSE INDEX IS NEARER TO END, ITERATE FROM THE ENDING
    else
    {
    	temp_count = 0;

    	temp = end;

    	//ITERATING TILL THE INDEX IS FOUND
    	while((count - index) != temp_count++)
    		temp = temp->prev;
    }

	//CREATING A NEW NODE AND MAKE THE (INDEX-1) NODE POINT TO IT
	temp->prev->next = create_node(&temp->prev, &temp);

	return printf("\n\nINSERTION SUCCESSFUL\n\n");
}

int delete()
{
	//CHECKING IF LIST IS EMPTY
	if(start == NULL)
		return printf("\n\nDELETION UNSUCCESSFUL\n");

	//IF ONLY ONE ELEMENT IS IN THE LIST, DELETE THAT
	if(start->next == NULL)
	{
		delete_at_start();
		return 0;
	}

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

	count--;
}

int delete_at_start()
{
	//STORING THE DATA OF FIRST NODE
	int element = start->data;

	//POINTING A TEMPORARY POINTER TO FIRST NODE
	struct NODE *temp = start;
	
	//POINTING THE START TO SECOND NODE
	start = start->next;
	
	free(temp);

	return printf("\n\nDELETION SUCCESSFUL. ELEMENT DELETED: %d\n\n",element);
}

int delete_at_end()
{
	//STORING THE DATA OF THE LAST NODE
	int element = end->data;

	//POINTING A TEMPORARY POINTER TO THE LAST NODE
	struct NODE *temp = end;

	//POINTING THE END POINTER TO LAST BUT ONE NODE
	end = end->prev;

	//AFTER REMOVING LAST NODE, MAKING THE CURRENT LAST NODE POINT TO NULL
	end->next = NULL;

	free(temp);

	return printf("\n\nDELETION SUCCESSFUL. ELEMENT DELETED: %d\n\n",element);	
}

int delete_at_index()
{
	int index, temp_count = 1; 

	struct NODE* temp = NULL;

	printf("\n\nENTER THE INDEX (STARTS FROM 1): ");
	scanf("%d",&index);

	if(index < 1)
	{
		count++;
		return printf("\n\nINVALID INDEX. DELETION UNSUCCESSFUL");
	}

	//IF INDEX IS GREATER THAN THE LENGTH OF LIST, DELETE THE LAST NODE
	if(index > count)
	{
		delete_at_end();
		return printf("\n\nIndex is greater than the size of the list. Hence deleted from the end\n\n");
	}

	//IF INDEX IS 1, DELETE THE FIRST NODE
	if(index == 1)
	{
		delete_at_start();
		return 0;
	}

	//IF INDEX IS NEARER TO START, ITERATE FROM THE BEGINNING
    if((index - 0)  <= (count - index))
    {
    	temp = start;
    	
    	//ITERATING TILL THE INDEX IS FOUND
    	while(index != temp_count++)
    		temp = temp->next;

    }

    //ELSE INDEX IS NEARER TO END, ITERATE FROM THE ENDING
    else
    {
    	temp_count = 0;

    	temp = end;

    	//ITERATING TILL THE INDEX IS FOUND
    	while((count - index) != temp_count++)
    		temp = temp->prev;
    }

    //MAKING NODE BEFORE THE INDEX-NODE POINT TO NODE AFTER INDEX-NODE
   	temp->prev->next = temp->next;

   	//MAKING THE *PREV OF NODE AFTER INDEX-NODE POINT TO NODE BEFORE THE INDEX-NODE
   	temp->next->prev = temp->prev;

   	//STORING THE DATA OF THE NODE TO BE DELETED
    int element = temp->data;

    free(temp);

    return printf("\n\nDELETION SUCCESSFUL. ELEMENT DELETED: %d\n\n",element);
}

int display()
{
	if(start == NULL)
		return printf("\n\nLIST IS EMPTY\n\n");

	//CREATING A TEMPORARY POINTER POINTING TO WHERE START POINTS CURRENTLY
	struct NODE *temp = start;

	printf("\n---------------------------------------------\n");

	//PRINTING ALL THE NODES TILL LAST NODE IS FOUND
	while(temp->next != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}

	//PRINTING THE LAST NODE
	return printf("%d\n---------------------------------------------\n", temp->data);
}

int reverse()
{
	//CHECKING IF LIST IS EMPTY OR HAS ONLY ONE NODE
	if(start == NULL || start->next == NULL)
		return printf("\n\nPODA LOOSU\n\n");

	//POINTING TEMP TO FIRST NODE, TEMP2 TO NULL, TEMP3 TO SECOND NODE
    struct NODE *temp = start, *temp2 = NULL, *temp3 = temp->next;

    //REVERSING THE LIST UNTIL TEMP3 POINTS TO NULL
    while(temp3 != NULL)
    {
    	temp2 = temp3;
    	temp->prev = temp2;
    	temp3 = temp2->next;
    	temp2->next = temp;

    	temp = temp2;
    }

    //EXCHANGING THE LOCATIONS OF START AND END POINTERS
    temp = start;
    start = end;
    end = temp;
    end->next = NULL;

	return printf("\n\nREVERSE SUCCESSFUL");
}


struct NODE* create_node(struct NODE **front, struct NODE **back)
{
	//ALLOCATING SPACE FOR THE NODE
	struct NODE *temp = malloc(sizeof(struct NODE));

	printf("\n\nENTER THE ELEMENT: ");
	scanf("%d",&temp->data);

	//POINTING THE NEXT OF THE NODE TO NEXT NODE
	temp->next = *back;
	//POINTING THE PREV OF THE NODE TO PREVIOUS NODE
	temp->prev = *front;

	//IF THE NEXT NODE IS PRESENT, POINTING THE PREV OF FRONT NODE TO CURRENT NODE
	if(*back != NULL)
		(*back)->prev = temp;

	//UPDATING THE COUNT OF NODES
	count++;

	return temp;
}
