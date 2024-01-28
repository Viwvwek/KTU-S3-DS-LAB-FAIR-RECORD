#include<stdio.h>
int A[20],size,front=-1,rear=-1;
void INSERT_Front(int item)
{
	if(front==0&&rear==size-1)
		printf("Deque is FULL\n");
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		A[front]=item;
	}
	else if(front>0)
	{
		front=front-1;
		A[front]=item;
	}
	else
	{
		for(int i=rear;i>=0;i--)
			A[i+1]=A[i];
		A[front]=item;
		rear=rear+1;
	}
}
void DELETE_FRONT()
{
	if(front==-1&&rear==-1)
		printf("Deque is EMPTY\n");
	else if(rear==front)
	{
		printf("Dequed item is %d\n",A[front]);
		front=rear=-1;
	}
	else
	{
		printf("Dequed item is %d\n",A[front]);
		front=front+1;
	}
}
void INSERT_Rear(int item)
{
	if(front==0&&rear==size-1)
		printf("Deque is FULL\n");
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		A[rear]=item;
	}
	else if(rear<size-1)
	{
		rear=rear+1;
		A[rear]=item;
	}
	else
	{
		for(int i=front;i<=rear;i++)
			A[i-1]=A[i];
		A[rear]=item;
		front=front-1;
	}
