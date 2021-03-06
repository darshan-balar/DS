	#include<stdio.h>
	#include<stdlib.h>

	struct queue
	{
		int *queue;
		int front;
		int rear;
		int size;
	};

	int enqueue(struct queue *); //ADD ELEMENTS TO THE QUEUE
	int dequeue(struct queue *); //REMOVE ELEMENTS FROM THE QUEUE
	int display(struct queue *); //DISPLAY THE QUEUE
	int isFull (struct queue *); //CHECKS IF THE QUEUE IS FULL
	int isEmpty(struct queue *); //CHECKS IF THE QUEUE IS EMPTY

	int main()
	{
		int choice;
		struct queue q;
		q.size  = 5;
		q.queue = malloc(q.size * sizeof(int));
		
		q.front = 0; 
		q.rear  = 0; 
		
		printf("\n\n\t\t\tQUEUE IMPLEMENTATION\n\n");
		
		while(1)
		{	
			printf("\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit");
			printf("\n\nEnter the operation you want to perform: ");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1: enqueue(&q); display(&q); break;
				case 2: dequeue(&q); display(&q);break;
				case 3: display(&q); break;
				case 4: return printf("\n\n\t\tTHANK YOU\n\n");
				default: printf("\n\nInvalid entry !!!\n\n");
			}
		}
	}

	int enqueue(struct queue *q)
	{
		if(isFull(q)) //CHECKING IF QUEUE IS FULL BEFORE ADDING ELEMENT
			return printf("\n\nENQUEUE UNSUCCESSFUL. QUEUE IS FULL\n\n");

		//INCREMENTING REAR CIRCULARLY
		q->rear = (q->rear + 1) % q->size;

		printf("\n\nEnter the element: ");
		scanf("%d",&q->queue[q->rear]);

		return printf("\n\nENQUEUE SUCCESSFUL\n");

	}

	int dequeue(struct queue *q)
	{
		if(isEmpty(q)) //CHECKING IF QUEUE IS EMPTY BEFORE REMOVING ELEMENT
			return printf("\n\nDEQUEUE UNSUCCESSFUL\n");

		//INCREMENTING FRONT CIRCULARLY
		q->front = (q->front + 1) % q->size;

		return printf("\n\nELEMENT REMOVED IS %d\n",q->queue[q->front]);
	}

	int display(struct queue *q)
	{
		if(isEmpty(q)) //CHECKING IF QUEUE IS EMPTY BEFORE DISPLAYING
			return printf("\n\nQUEUE IS EMPTY\n\n");

		printf("\n\n|");

		//PRINTING THE ELEMENTS CIRCULARLY
		for(int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size)
			printf("%d|",q->queue[i]);
	
		return printf("\n\n");
	}

	int isFull(struct queue *q)
	{
		if((q->rear + 1) % q->size == q->front)
			return 1;

		return 0;
	}

	int isEmpty(struct queue *q)
	{
		if(q->rear == q->front)
			return 1;

		return 0;
	}