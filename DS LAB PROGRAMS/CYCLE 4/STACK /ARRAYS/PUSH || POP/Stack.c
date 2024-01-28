#include<stdio.h>
int s[20];
int size=20;
int top=-1;
void main()
{
    int choice;
    printf("<<< STACK OPERATION MENU >>>");
    printf("\n1. TO PUSH AN ELEMENT");
    printf("\n2. TO POP AN ELEMENT");
    printf("\n3. TO CHECK THE STATUS OF THE STACK");
    printf("\n4. TO DISPLAY THE STACK");
    printf("\n5. TO QUIT");
    printf("\n");
    printf("\nPlease enter your choice: ");
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            status();
            break;
        case 4:
            display();
            break;
        default:
            printf("INVALID CHOICE");
            break;
        }
        printf("\n");
        printf("\nPlease enter your choice: ");
        scanf("%d",&choice);
    }
    return 0;
}
int is_full()
{
    if(top==size-1)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push()
{
    int c=is_full();
    if(c==0)
    {
        int item;
        top++;
        printf("Enter the item to be pushed: ");
        scanf("%d",&item);
        s[top]=item;
    }
    else
        printf("The stack in FULL");
}

void pop()
{
    int c=is_empty();
    if(c==0)
    {
        printf("The popped element is: %d",s[top]);
        top--;
    }
    else
        printf("The stack is EMPTY");
}

void display()
{
    int i,c=is_empty();
    if(c==1)
        printf("The stack is EMPTY");
    else
    {
        for(i=top; i>=0; i--)
        {
            printf("%d\n",s[i]);
        }
    }
}

void status()
{
    if(top==size-1)
        printf("The stack is FULL");
    else if(top==-1)
        printf("The stack is EMPTY");
    else
    {
        printf("There are %d elements in the stack",top+1);
        printf("\nThere are %d spaces left in the stack",size-1-top);
    }
}
