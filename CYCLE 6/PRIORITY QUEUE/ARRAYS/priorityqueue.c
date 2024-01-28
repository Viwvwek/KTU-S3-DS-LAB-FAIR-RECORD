#include<stdio.h>
int size,front,rear;
struct PQ
{
    int item,priority;
}A[20];
void ENQUEUE(int ITEM,int PRIORITY)
{
	int i,loc;
	if(front==0&&rear==size-1)
		printf("Queue is FULL\n");
	else if(front==-1)
	{
		front=0;
		rear=0;
		A[rear].item=ITEM;
		A[rear].priority=PRIORITY;
	}
	else if(rear==size-1)
	{
	    for(i=front;i<=rear;i++)
		        A[i-1]=A[i];
		    front=front-1;
		    rear=rear-1;
		for(i=rear;i>=front;i--)
		{
		    if(A[i].priority<PRIORITY)
		    {
		        break;
		    }
		}
		loc=i+1;
		for(i=rear;i>=loc;i--)
		{
		    A[i+1]=A[i];
		}
		A[loc].item=ITEM;
		A[loc].priority=PRIORITY;
		rear=rear+1;
	}
	else
    {
		for(i=rear;i>=front;i--)
		{
		    if(A[i].priority<PRIORITY)
		    {
		        break;
		    }
		}
		loc=i+1;
		for(i=rear;i>=loc;i--)
		{
		    A[i+1]=A[i];
		}
		A[loc].item=ITEM;
		A[loc].priority=PRIORITY;
		rear=rear+1;
	}
}
void DEQUEUE()
{
	if(front==-1)
		printf("Queue is EMPTY\n");
	else if(front==rear)
	{
		printf("The deleted item is %d\n",A[front].item);
		front=rear=-1;
	}
	else
	{
		printf("The deleted item is %d\n",A[front].item);
		front=front+1;
	}
}
void DISPLAY()
{
	if(front==-1)
		printf("Queue is EMPTY\n");
	else
	{
		for(int i=front;i<=rear;i++)
			printf("%d\t",A[i].item);
	}
	printf("\n");
}
void main()
{
	int opt,item,prio;
	printf("Enter size of QUEUE:");
	scanf("%d",&size);
	front=-1;
	rear=-1;
	printf("1.ENQUEUE\t2.DEQUEUE\t3.DISPLAY\t4.QUIT\n");
	do
	{
		printf("Enter your choice:");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("Enter the item and priority\n");
				scanf("%d%d",&item,&prio);
				ENQUEUE(item,prio);
				break;
			case 2:
				DEQUEUE();
				break;
			case 3:
				DISPLAY();
				break;
			case 4:
				break;
			default:
				printf("Please Enter a valid choice(1/2/3/4)\n");
		}
	}while(opt!=4);
}
