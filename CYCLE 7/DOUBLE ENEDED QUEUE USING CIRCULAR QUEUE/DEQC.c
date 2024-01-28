#include<stdio.h>
//Global scope
#define size 8
int dq[100];
int item;
int front = -1, rear =-1;
//Insertion from front
void front_Enqueue(int item)
{    if((front==0 && rear==size-1) || (front==rear+1))
        {
        printf("deque is full, Insertion is not possible");
        }
    else if((front==-1) && (rear==-1))
        {
        front=rear=0;
        dq[front]=item;
        }
    else if(front==0)
    {
        front=size-1;
        dq[front]=item;
    }
    else
    {
        front=front-1;
        dq[front]=item;
    }

}

// insertion from rear end
    void rear_Enqueue(int z)
{
    if((front==0 && rear==size-1) || (front==rear+1))
    {
        printf("deque is full");
    }
    else if((front==-1) && (rear==-1))
    {
        rear=0;
        dq[rear]=z;
    }
    else if(rear==size-1)
    {
        rear=0;
        dq[rear]=z;
    }
    else
    {
        rear++;
        dq[rear]=z;
    }

}

//function to analyze state of queue.

void display()
{
    int i=front;
    printf("\n Elements inside the double ended queue are : ");
    while(i!=rear)
    {
        printf("%d ",dq[i]);
        i=(i+1)%size;
    }
    printf("%d",dq[rear]);
}
void front_Dequeue()
{
    if((front==-1) && (rear==-1))
    {
        printf(" Deque Empty !!");
    }
    else if(front==rear)
    {
        printf("\nThe deleted element from the front is %d", dq[front]);
        front=-1;
        rear=-1;
    }
    else if(front==(size-1))
    {
        printf("\nThe deleted element from the front is %d", dq[front]);
        front=0;
    }
    else
    {
        printf("\nThe deleted element from the front is %d", dq[front]);
        front=front+1;
    }
}

// dequeue_rear() function deletes the element from the rear
void rear_Dequeue()
{
    if((front==-1) && (rear==-1))
    {
        printf("Deque is empty");
    }
    else if(front==rear)
    {
        printf("\nThe deleted element from rear is %d", dq[rear]);
        front=-1;
        rear=-1;
    }
    else if(rear==0)
    {
        printf("\nThe deleted element from the rear node is %d", dq[rear]);
        rear=size-1;
    }
    else
    {
        printf("\nThe deleted element from rear node is %d", dq[rear]);
        rear = rear-1;
    }
}

int main()
{   int choice;
    printf("<<< DEQUE OPERATION MENU >>>");
    printf("\n1. INSERT ELEMENT IN REAR END");
    printf("\n2. INSERT ELEMENT IN FRONT END");
    printf("\n3. DELETE ELEMENT FROM REAR END");
    printf("\n4. DELETE ELEMENT FROM FRONT END");
    printf("\n5. DISPLAY QUEUE");
    printf("\n6. EXIT");
    printf("\n");
    printf("\nPlease enter your choice: ");
    scanf("%d",&choice);
    while(choice!=6)
    {
        switch(choice)
        {
        case 1:
            front_Enqueue(-5);
            break;
        case 2:
           rear_Enqueue(17);
            break;
        case 3:
           front_Dequeue();
            break;
        case 4:
            front_Enqueue(5);
            break;
        case 5:
            display();
            break;
        default:
            printf("INVALID CHOICE");
            break;
        }
        printf("\n");

    }
    return 0;
}
