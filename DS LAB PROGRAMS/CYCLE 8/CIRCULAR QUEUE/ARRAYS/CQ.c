#include<stdio.h>

 //Global Declarations
int queue[10];
int size=5,front=-1,rear=-1;

//Functions used
void enqueue();
void dequeue();
void display();

void main()
{
	int choice;
	printf("<<<    CIRCULAR QUEUE OPERATIONS   >>>");
	printf("\n1.To enqueue an element into the queue");
	printf("\n2.To dequeue an element from the queue");
	printf("\n3.To display the queue");
	printf("\n4.To quit");
	printf("\nPlease enter your choice: ");
	scanf("%d",&choice);
	while(choice!=4)
	{
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			default:
				printf("INVALID CHOICE");
		}
		printf("\nPlease enter your choice: ");
		scanf("%d",&choice);
	}
}

void enqueue()
{
	int item;
	if(((rear+1)%size)==front)
		printf("The Queue is full\n");
	else if(front==-1 && rear==-1)
	{
		printf("\nEnter the element to be enqueued: ");
		scanf("%d",&item);
		front=rear=0;
		queue[rear]=item;
	}
	else
	{
		printf("\nEnter the element to be enqueued: ");
		scanf("%d",&item);
		rear=((rear+1)%size);
		queue[rear]=item;
	}
}

void dequeue()
{
	if(front==-1 && rear==-1)
		printf("\nThe Queue is empty\n");
	else if(rear==front)
	{
		printf("\nThe dequeued element is: %d\n",queue[front]);
		front=rear=-1;
	}
	else
	{
		printf("The dequeued element is: %d",queue[front]);
		front=((front+1)%size);
	}
}

void display()
{
	int i;
	if(front==-1&&rear==-1)
		printf("The queue is empty");
	else
	{
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				printf("%d\t",queue[i]);
			}
			printf("\n");
		}
		else
		{
			for(i=front;i<=size-1;i++)
			{
				printf("%d\t",queue[i]);
			}
			for(i=0;i<=rear;i++)
			{
				printf("%d\t",queue[i]);
			}
			printf("\n");
		}
	}
}
