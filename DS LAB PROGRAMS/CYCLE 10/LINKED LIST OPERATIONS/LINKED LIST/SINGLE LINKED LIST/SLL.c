#include <stdio.h>
#include <stdlib.h>
//GLOBAL DECLARATIONS
struct node
{
	int data;
	struct node * link;
};


struct node *HEAD=NULL;


//FUNCTIONS USED
int display();
int delete();
int insert();
int insatbeg();
int insatend();
int insatpoint();
int delatbeg();
int delatend();
int delatpoint();
int search();
int merge();
int create_list(int num);

// LIST CREATION
int create_list(int num)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->link=NULL;
	return temp;
}


int main()
{
	int ch;

	while(1)
	{
    printf("\n\n\n**** SINGLE LINKED LIST OPERATIONS ****");
	printf("\n 1.Insert \n2.Delete \n3.Search \n4.exit");
	printf("\n\t Enter your choice\t:");
	scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
		    insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			search();
			break;
		case 4:
			exit(0);

		default:
			printf("Invalid choice!!!");
      }

    }
}
int insert()
{
	int choice;
	printf("<<<  INSERTION >>>\n\n");
	printf("\n 1.Insert at beginning \n 2.Insert at end \n 3.Insert at any point");
	printf("\n Enter your choice for insertion  : ");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				insatbeg();
				break;
			case 2:
				insatend();
				break;
			case 3:
				insatpoint();
				break;

			default:
				printf("Invalid choice!!!");
	        }
}
int delete()
{
	int choice;
	printf("<<<  DELETION >>>\n\n");
	printf("\n 1.Delete at beginning \n 2.Delete at end \n 3.Delete at any point");
	printf("\n Enter your choice");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				delatbeg();
				break;
			case 2:
				delatend();
				break;
			case 3:
				delatpoint();
				break;
		    default:
				printf("Invalid choice!!!");
		}
}
int display()
{
  struct node *temp;
  if(HEAD==NULL)
  {
  	printf("\n ***  List is empty  *** ");

  }
  temp=HEAD;
  printf("\n List is");
  while(temp!=NULL)
  {
  	printf("  %d  ",temp->data);
  	temp=temp->link;
  }
  printf("\n");

}
int insatbeg()
{
	int x;
	printf("\n Enter data to be inserted at Begining :");
	scanf("%d",&x);
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->link=HEAD;
	HEAD=temp;
	display();
}
int insatend()
{
    int x;
    printf("\n Enter data to be inserted at the end :");
    scanf("%d",&x);
    struct node * temp,*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=x;
	temp=HEAD;
	while(temp->link!=NULL)
            temp=temp->link;
	temp->link=newnode;
	newnode->link=NULL;
	display();

}
int insatpoint()
{
	int data1,x;
	struct node * p,*newnode;
	printf("Enter the value to be added");
    scanf("%d",&x);
	printf("Enter data after which new node should be inserted");
	scanf("%d",&data1);
	if(HEAD==NULL)
		{
		 printf("List is empty!!!");
		}
	else
	{
		p=HEAD;
		while(p->data!=data1 && p->link!=NULL)
                p=p->link;
        if(p->data!=data1)
                printf("search element is not found");
        else
			{
		        newnode=(struct node *) malloc (sizeof(struct node));
				newnode->data=x;
				newnode->link=p->link;
				p->link=newnode;
            }
     }
	display();

}
int delatbeg()
{
	{
	struct node *p;
	if(HEAD==NULL)
        {
         printf("\n*** list is empty  ****");
        }
        else
        {
          p=HEAD;
          HEAD=p->link;
          printf("\n Node %d deleted",p->data);
          free(p);
       }
      }
      display();
}
int delatend()
{
	struct node * p,*ptr;
	if(HEAD==NULL)
    {
        printf("*** list is empty  ***");

    }
    else if(HEAD->link==NULL)
    {
      HEAD=NULL;
      free(HEAD);
      printf("Single Node List.");
    }
    else
    {
       p=HEAD;
       while(p->link!=NULL)
       {
           ptr=p;
           p=p->link;
       }
       ptr->link=NULL;
       free(p);
       printf("Node deleted");
    }
	display();
}
int delatpoint()
{
            struct node*temp, *prev,*curr;
           int key;
           printf("Enter the element to be deleted:");
           scanf("%d",&key);
           if(HEAD==NULL)
            {
            printf("List is Empty!!. Deletion not possible");
            }
            else if(HEAD->data==key)
              {
                 temp=HEAD;
                 HEAD=HEAD->link;
                 free(temp);
              }
           else
              {
               prev=HEAD;
                    curr=HEAD->link;
                    while( curr->data!= key && curr->link!=NULL)
                      {
                         prev=curr;
                         curr=curr->link;
                      }
                    if(curr->data!= key)
                       printf("\n Search element is not found ");
                     else
                        prev->link=curr->link;

                        free(curr);
               }
             display();
}
int search()
{
	struct node *ptr;
	int key;
	printf("Enter element to be searched  ");
	scanf("%d",&key);
	if(HEAD==NULL)
	{
		printf("List is empty!!!");
	}
	else
	{
		ptr=HEAD;
		while(ptr->data!=key && ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		if (ptr->data==key)
		{
			printf("Element found !!!");
		}
		else
		{
			printf("Search element not found !!!");
		}
	}
}
