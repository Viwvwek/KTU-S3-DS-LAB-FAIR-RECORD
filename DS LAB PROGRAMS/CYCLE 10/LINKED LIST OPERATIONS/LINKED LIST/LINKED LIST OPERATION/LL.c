#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL;
struct node *temp1=NULL;
struct node *next=NULL;
struct node *prev=NULL;

void insert()
{
    int c;
    printf("\n----\tINSERT MENU\t----\n");
    printf("\n1 FRONT");
    printf("\n2 REAR");
    printf("\n3 AT A POINT\n");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        insert_f();
        break;

    case 2:
        insert_b();
        break;

    case 3:
        insert_p();
        break;

    default:
        printf("Enter a valid input");
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List EMPTY");
    }
    else
    {
        temp1=head;
        while(temp1!=NULL)
        {
            printf(" %d ",temp1->data);
            temp1=temp1->link;
        }
    }
}
void insert_f()
{
    int item;
    printf("Enter element to be inserted: ");
    scanf("%d", &item);

    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=item;
    new1->link=NULL;

    temp1=head;
    head=new1;
    new1->link=temp1;
    display();
}
void insert_b()
{
    int item;
    printf("Enter element to be inserted: ");
    scanf("%d", &item);

    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=item;
    new1->link=NULL;

    if(head==NULL)
    {
        head=new1;
    }
    else
    {
        temp1=head;
        while(temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        temp1->link=new1;
    }
    display();
}
void insert_p()
{
    int item,key;
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    printf("Enter Key: ");
    scanf("%d", &key);

    struct node *new1;
    new1=(struct node*)malloc(sizeof(struct node));
    new1->data=item;
    new1->link=NULL;

    if(head==NULL)
    {
        head=new1;
    }
    else
    {
        temp1=head;
        while(temp1->data!=key && temp1->link!=NULL)
        {
            temp1=temp1->link;
        }
        if(temp1->link==NULL && temp1->data!=key)
        {
            printf("KEY Not Found!!");

        }
        else
        {
            next=temp1->link;
            temp1->link=new1;
            new1->link=next;
            display();
        }

    }

}
void delete1()
{
    int c;
    printf("\n----\tDELETE MENU\t----\n");
    printf("\n1 FRONT");
    printf("\n2 REAR");
    printf("\n3 AT A POINT\n");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        deletef();
        break;

    case 2:
        deleteb();
        break;

    case 3:
        deletep();
        break;

    default:
        printf("Enter a valid input");
    }
}
void deletef()
{
    if(head==NULL)
    {
        printf("List Empty");
    }
    else
    {
        temp1=head;
        printf("Deleted Element: %d", temp1->data);
        head=head->link;
        free(temp1);
    }
    display();
}
void deletep()
{
    int key,flag=1;
    printf("Enter element to be deleted");
    scanf("%d", &key);
    if(head==NULL)
    {
        printf("List Empty");
    }
    else
    {
        temp1=head;
        while(temp1->data!=key)
        {
            prev=temp1;
            temp1=temp1->link;
            flag=1;
            break;
        }
        printf("Deleted Element: %d\n", temp1->data);
        next=temp1->link;
        prev->link=next;
        free(temp1);
        if(flag==0)
        {
            printf("Element not Found");
        }
    }
    display();

}
void deleteb()
{
    if(head==NULL)
    {
        printf("List Empty");
    }
    else
    {
        temp1=head;
        while(temp1->link!=NULL)
        {
            prev=temp1;
            temp1=temp1->link;
        }
        printf("Deleted Element: %d\n", temp1->data);
        prev->link=NULL;
        free(temp1);
    }
    display();
}
void sort()
{
    struct node *i=NULL;
    struct node *j=NULL;
    int temp;
    for(i=head;i->link!=NULL;i=i->link)
    {
        for(j=head;j->link!=NULL;j=j->link)
        {
            if(j->data > j->link->data)
            {
                temp=j->data;
                j->data=j->link->data;
                j->link->data=temp;
            }
        }
    }
    display();
}
int main()
{
    int n,c;
    do
    {
        printf("\n----- MAIN MENU -----\n");
        printf("\n1 INSERT\n2 DELETE\n3 DISPLAY\n4 SORT\n5 EXIT\n");
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            insert();
            break;

        case 2:
            delete1();
            break;

        case 3:
            display();
            break;

        case 4:
            sort();
            break;

        case 5:
            break;

        default:
            printf("ENTER A VALID INPUT");

        }

    }while(n!=5);
}
