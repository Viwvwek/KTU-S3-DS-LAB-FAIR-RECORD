#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coeff;
	int expo;
	struct node *link;
};
struct node *readPoly();
struct node *addPoly(struct node *h1,struct node *h2);
struct node *multiplyPoly(struct node *h1,struct node *h2);
void displayPoly(struct node *head);
int main()
{
	struct node *Phead,*Qhead,*Rhead;
	int ch;
	Phead=Qhead=Rhead=NULL;
	printf("Enter details of First Polynomial:\n");
	Phead=readPoly();
	printf("\n");
	printf("Enter details of Second Polynomial:\n");
	Qhead=readPoly();
	printf("\n");
	printf("\nFirst Polynomial:");
	displayPoly(Phead);
	printf("\nSecond Polynomial:");
	displayPoly(Qhead);

    printf("\n\n\n<<<POLYNOMIAL OPERATIONS>>>\n");
	printf("\n1.Polynomial Addition\n");
	printf("\n2.Polynomial Multiplication\n");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			Rhead=addPoly(Phead,Qhead);
			printf("\n\tResultant Polynomial after addition:");
			displayPoly(Rhead);
			break;
		case 2:
			Rhead=multiplyPoly(Phead,Qhead);
			printf("\n\tResultant Polynomial after multiplication:");
			displayPoly(Rhead);
			break;
		default:
			printf("Invalid operation");
            break;
	}
	return 0;
}
struct node *readPoly()
{
	int N,i,c,e;
	struct node *n,*ptr,*head=NULL;
	printf("\nEnter number of terms of the polynomial:");
	scanf("%d",&N);
	printf("\nEnter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
	for(i=0;i<N;i++)
	{
		n=(struct node *)malloc(sizeof(struct node));
		printf("\n\t\t\tEnter the coefficient(%d) :",(i+1));
		scanf("%d",&c);
		printf("\n\t\t\tEnter your exponent(%d) :",(i+1));
		scanf("%d",&e);
		n->coeff=c;
		n->expo=e;
        if(head==NULL)
			head=ptr=n;
		else
		{
			ptr->link=n;
			ptr=n;
		}
		ptr->link=NULL;
	}
	return head;
}
struct node *addPoly(struct node *h1,struct node *h2)
{
	struct node *p,*q,*r,*n,*head=NULL;
	p=h1;
	q=h2;
	while(p!=NULL&&q!=NULL)
	{
		if(p->expo==q->expo)
		{
			n=(struct node *)malloc(sizeof(struct node));
			n->coeff=p->coeff+q->coeff;
			n->expo=p->expo;
			n->link=NULL;
			p=p->link;
			q=q->link;
		}
		else if(p->expo>q->expo)
		{
			n=(struct node *)malloc(sizeof(struct node));
			n->coeff=p->coeff;
			n->expo=p->expo;
			n->link=NULL;
			p=p->link;
		}
		else
		{
			n=(struct node *)malloc(sizeof(struct node));
			n->coeff=q->coeff;
			n->expo=q->expo;
			n->link=NULL;
			q=q->link;
		}
		if(head==NULL)
			head=r=n;
		else
		{
			r->link=n;
			r=n;
		}
	}
	while(p!=NULL)
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->coeff=p->coeff;
		n->expo=p->expo;
		n->link=NULL;
		if(head==NULL)
			head=r=n;
		else
		{
			r->link=n;
			r=n;
		}
		p=p->link;
	}
	while(q!=NULL)
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->coeff=q->coeff;
		n->expo=q->expo;
		n->link=NULL;
		if(head==NULL)
			head=r=n;
		else
		{
			r->link=n;
			r=n;
		}
		q=q->link;
	}
	return head;
}
struct node *multiplyPoly(struct node *h1,struct node *h2)
{
	struct node *p,*q,*r,*head,*n,*prev;
	p=h1;
	q=h2;
	head=NULL;
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			n=(struct node*)malloc(sizeof(struct node));
			n->coeff=p->coeff*q->coeff;
			n->expo=p->expo+q->expo;
			n->link=NULL;
			if(head==NULL)
				head=r=n;
			else
			{
				r->link=n;
				r=n;
			}
			q=q->link;
		}
		p=p->link;
		q=h2;
    }
    p=head;
    while(p!=NULL)
	{
		prev=p;
		q=p->link;
		while(q!=NULL)
		{
			if(p->expo==q->expo)
			{
                p->coeff=p->coeff+q->coeff;
                prev->link=q->link;
                free(q);
                q=prev->link;
			}
			else
            {
                prev=q;
                q=q->link;
            }
		}
		p=p->link;
    }
    return head;
}
void displayPoly(struct node *head)
{
	struct node *ptr;
	ptr=head;
	while(ptr->link!=NULL)
	{
		printf("%d(x^%d)+",ptr->coeff,ptr->expo);
		ptr=ptr->link;
	}
	printf("%d(x^%d)",ptr->coeff,ptr->expo);
}
