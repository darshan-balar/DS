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
				case 1: enqueue(&q); break;
				case 2: dequeue(&q); break;
				case 3: display(&q); break;
				case 4: return printf("\n\n\t\tTHANK YOU\n\n");
				default: printf("\n\nInvalid entry !!!\n\n");
			}
		}
	}

	int enqueue(struct queue *q)
	{
		//CHECKING IF QUEUE IS FULL
		if((q->rear + 1) % (q->size + 1) == q->front)
			return printf("\n\nEnqueue Unsuccessful\n\nQueue is full\n\n");

		printf("\n\nEnter the element: ");
		scanf("%d",&q->queue[q->rear]);

		//INCREMENTING REAR CIRCULARLY
		q->rear = (q->rear + 1) % (q->size + 1);

		return printf("\n\nENQUEUE SUCCESSFUL\n\n");
	}

	int dequeue(struct queue *q)
	{
		//CHECKING IF QUEUE IS EMPTY
		if(q->rear == q->front)
			return printf("\n\nDequeue Unsuccessful\n\nQueue is empty\n\n");

		printf("\n\nElement removed: %d",q->queue[q->front]);

		q->front = (q->front + 1) % (q->size + 1);
		
		return 0;
	}

	int display(struct queue *q)
	{
		//CHECKING IF QUEUE IS EMPTY
		if(q->rear == q->front)
			return printf("\n\nDisplay Unsuccessful\n\nQueue is empty\n\n");

		printf("|");

		//DISPLAYING THE ELEMENTS CIRCULARLY
		for(int i = q->front; i != q->rear; i = (i + 1) % (q->size + 1))
			printf("%d|",q->queue[i]);

		return printf("\n\nDISPLAY SUCCESSFUL\n\n");
	}

