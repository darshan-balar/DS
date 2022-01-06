//IMPLEMENTATION OF BINARY TREE

#include<stdio.h>
#include<stdlib.h>

//STRUCTURE OF A SINGLE OF NODE OF THE BINARY TREE
struct NODE
{
	int data;
	struct NODE *left;
	struct NODE *right;
};

//INITIALIZING THE ROOT TO NULL
struct NODE *root = NULL;

//STRUCTURE OF QUEUE
struct queue
{
	struct NODE **queue;
	int front;
	int rear;
	int size;
};

struct queue q;

//QUEUE FUNCTIONS
void intialize_Queue();
void enqueue(struct NODE *); //ADD ELEMENTS TO THE QUEUE
struct NODE* dequeue(); //REMOVE ELEMENTS FROM THE QUEUE
void isFull(); //CHECKS IF THE QUEUE IS FULL
int isEmpty(); //CHECKS IF THE QUEUE IS EMPTY
void resize(); //INCREASES SIZE OF THE 

//TREE FUNCTIONS
void preorder(struct NODE *p);
void inorder(struct NODE *p);
void postorder(struct NODE *p);
void levelorder(struct NODE *p);


int main()
{
	//INITIALIZING THE QUEUE
	intialize_Queue();

	//CREATING THE ROOT NODE
	root = malloc(sizeof(struct NODE));

	//INITIALIZING THE LEFT AND RIGHT OF ROOT TO NULL
	root->left = root->right = NULL;

	//READING THE ROOT NODE'S DATA
	printf("\n\nENTER THE ELEMENT OF ROOT NODE: ");
	scanf("%d",&root->data);

	//ENQUEUING THE ROOT INTO THE QUEUE
	enqueue(root);

	//READING THE ELEMENTS IN LEVEL ORDER
	while(!isEmpty())
	{

		struct NODE *p = dequeue();
		
		//READING LEFT CHILD
		{
			p->left = malloc(sizeof(struct NODE));

			p->left->left = p->left->right = NULL;

			printf("\n\nENTER THE LEFT CHILD OF %d: ",p->data);
			scanf("%d",&p->left->data);
			enqueue(p->left);


			if(p->left->data == -1)
				dequeue();
		}

		//READING RIGHT CHILD
		{
			p->right = malloc(sizeof(struct NODE));

			p->right->left = p->right->right = NULL;

			printf("\n\nENTER THE RIGHT CHILD OF %d: ",p->data);
			scanf("%d",&p->right->data);
			enqueue(p->right);

			if(p->right->data == -1)
				dequeue();
		}
	}
	
	while(1)
	{
		int choice;
		printf("\n\n1) PRE-ORDER\n2) IN-ORDER\n3) POST-ORDER\n4) LEVEL-ORDER\n5) EXIT\n\n");
		printf("\n\nEnter your choice: ");
		scanf("%d",&choice);
		printf("\n\n");
		switch(choice)
		{
			case 1: preorder(root);  break;
			case 2: inorder(root);   break;
			case 3: postorder(root); break;
			case 4: levelorder(root);break;
			case 5: return 0;
			default: printf("\n\nINVALID CHOICE\n\n");
		}
	}
}

void preorder(struct NODE *p)
{
	if(p)
	{
		if(p->data != -1)
			printf("%d ",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(struct NODE *p)
{
	if(p)
	{
		inorder(p->left);
		if(p->data != -1)
			printf("%d ",p->data);
		inorder(p->right);
	}
}

void postorder(struct NODE *p)
{
	if(p)
	{
		postorder(p->left);
		postorder(p->right);
		if(p->data != -1)
			printf("%d ",p->data);
	}
}

void levelorder(struct NODE *p)
{
	printf("\n\n%d ",p->data);

	enqueue(p);


	while(!isEmpty())
	{

		p = dequeue();
		
		//LEFT CHILD
		{
			if(p->left->data != -1)
				printf("%d ",p->left->data);
				
			enqueue(p->left);

			if(p->left->data == -1)
				dequeue();
		}

		//RIGHT CHILD
		{
			if(p->right->data != -1)	
				printf("%d ",p->right->data);
			
			enqueue(p->right);

			if(p->right->data == -1)
			  dequeue();
		}
	}
}

void intialize_Queue()
{
	q.size  = 5;
	q.queue = malloc(q.size * sizeof(struct NODE *));
	q.front = 0;
	q.rear  = 0;
}	


void enqueue(struct NODE *root)
{
	//CHECKING IF QUEUE IS FULL BEFORE ADDING ELEMENT
	isFull(); 

	//INCREMENTING REAR CIRCULARLY
	q.rear = (q.rear + 1) % q.size;

	q.queue[q.rear] = root;
}

struct NODE* dequeue()
{
	//INCREMENTING FRONT CIRCULARLY
	q.front = (q.front + 1) % q.size;

	return q.queue[q.front];
}


void isFull()
{
	if((q.rear + 1) % q.size == q.front)
		resize();
}

int isEmpty()
{
	if(q.rear == q.front)
		return 1;

	return 0;
}

void resize()
{
	//TEMPEROARY POINTER POINTING TO THE QUEUE
	struct NODE **temp = q.queue;

	//RESIZED QUEUE WILL START ACCOMODATING THE ELEMENTS FROM INDEX 1
	int j = 0;

	//INCREASING THE SIZE TO TWO TIMES
	q.queue = malloc(q.size * 2 * sizeof(struct NODE *));

	//TRANFERING THE ELEMENTS POINTED BY TEMPORARY POINTER TO THE RESIZED QUEUE
	for(int i = (q.front + 1) % q.size; i != (q.rear + 1) % q.size; i = (i + 1) % q.size)
		q.queue[++j] = temp[i]; 

	//UPDATING FRONT AND REAR
	q.front = 0;
	q.rear = j;

	//UPDATING SIZE OF THE QUEUE
	q.size *= 2;
}