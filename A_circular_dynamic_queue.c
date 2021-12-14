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
	void isFull(struct queue *); //CHECKS IF THE QUEUE IS FULL
	int isEmpty(struct queue *); //CHECKS IF THE QUEUE IS EMPTY
	void resize(struct queue *); //INCREASES SIZE OF THE QUEUE

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
				case 2: dequeue(&q); display(&q); break;
				case 3: display(&q); break;
				case 4: return printf("\n\n\t\tTHANK YOU\n\n");
				default: printf("\n\nInvalid entry !!!\n\n");
			}
		}
	}

	int enqueue(struct queue *q)
	{
		//CHECKING IF QUEUE IS FULL BEFORE ADDING ELEMENT
		isFull(q); 

		//INCREMENTING REAR CIRCULARLY
		q->rear = (q->rear + 1) % q->size;

		printf("\n\nEnter the element: ");
		scanf("%d",&q->queue[q->rear]);

		return printf("\n\nENQUEUE SUCCESSFUL\n");

	}

	int dequeue(struct queue *q)
	{
		//CHECKING IF QUEUE IS EMPTY BEFORE REMOVING ELEMENT
		if(isEmpty(q))
			return printf("\n\nDEQUEUE UNSUCCESSFUL\n");

		//INCREMENTING FRONT CIRCULARLY
		q->front = (q->front + 1) % q->size;

		return printf("\n\nELEMENT REMOVED IS %d\n",q->queue[q->front]);
	}

	int display(struct queue *q)
	{
		//CHECKING IF QUEUE IS EMPTY BEFORE DISPLAYING THE QUEUE
		if(isEmpty(q))
			return printf("\n\nQUEUE IS EMPTY\n\n");

		printf("\n\n|");

		//DISPLAYING ELEMENTS CIRCULARLY
		for(int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size)
			printf("%d|",q->queue[i]);
	
		return printf("\n\n");;
	}

	void isFull(struct queue *q)
	{
		if((q->rear + 1) % q->size == q->front)
			resize(q);
	}

	int isEmpty(struct queue *q)
	{
		if(q->rear == q->front)
			return 1;

		return 0;
	}

	void resize(struct queue *q)
	{
		//TEMPEROARY POINTER POINTING TO THE QUEUE
		int *temp = q->queue;

		//RESIZED QUEUE WILL START ACCOMODATING THE ELEMENTS FROM INDEX 1
		int j = 0;

		//INCREASING THE SIZE TO TWO TIMES
		q->queue = malloc(q->size * 2 * sizeof(int));

		//TRANFERING THE ELEMENTS POINTED BY TEMPORARY POINTER TO THE RESIZED QUEUE
		for(int i = (q->front + 1) % q->size; i != (q->rear + 1) % q->size; i = (i + 1) % q->size)
			q->queue[++j] = temp[i]; 

		//UPDATING FRONT AND REAR
		q->front = 0;
		q->rear = j;

		//UPDATING SIZE OF THE QUEUE
		q->size *= 2;
	}