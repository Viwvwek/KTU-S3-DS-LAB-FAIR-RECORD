#include <stdio.h>
struct poly
{
	int coeff;
	int expo;
}p1[10],p2[10],p3[10];
int readPoly (struct poly []);
int addPoly (struct poly[],struct poly[],int,int,struct poly[]);
void display(struct poly[],int t);

int main()
{
	int t1,t2,t3;
	printf("\nFirst polynomial\n");
	t1 = readPoly(p1);
	display(p1,t1);
	printf("\nSecond polynomial: \n");
	t2 = readPoly(p2);
	display(p2,t2);
	t3 = addPoly(p1,p2,t1,t2,p3);
	printf("\nResultant polynomial: \n");
	display(p3,t3);
	return 0;
}
int readPoly(struct poly p[10])
{
	int i,t;
	printf("Enter the no. of terms of the polynomial: ");
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		printf("Enter coeffecient: \n");
		scanf("%d",&p[i].coeff);
		printf("Enter exponent: \n");
		scanf("%d",&p[i].expo);
	}
	return t;
}
void display(struct poly p[10],int t)
{
	int i=0;
	printf("\n");
	for (i=0;i<t-1;i++)
	{
		printf("%d(x^%d) + ",p[i].coeff,p[i].expo);
	}
	printf("%d(x^%d) ",p[t-1].coeff,p[t-1].expo);
}
int addPoly(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
{
	int i=0,j=0,k=0;
	while (i<t1 && j<t2)
	{
		if(p1[i].expo == p2[j].expo)
		{
			p3[k].expo = p1[i].expo;
			p3[k].coeff = p1[i].coeff + p2[j].coeff;
			i++;
			j++;
			k++;
		}
		else if(p1[i].expo > p2[j].expo)
		{
			p3[k].expo = p1[i].expo;
			p3[k].coeff = p1[i].coeff;
			i++;
			k++;
		}
		else
		{
			p3[k].expo = p2[j].expo;
			p3[k].coeff = p2[j].coeff;
			j++;
			k++;
		}
	}
	while (i<t1)
	{
		p3[k].expo = p1[i].expo;
		p3[k].coeff = p1[i].coeff;
		i++;
		k++;
	}
	while (j<t2)
	{
		p3[k].expo = p2[j].expo;
		p3[k].coeff = p2[j].coeff;
		j++;
		k++;
	}
	return k;
}



