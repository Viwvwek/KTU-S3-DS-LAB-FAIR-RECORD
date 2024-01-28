#include <stdio.h>

int read(int r,int c,int a[][c])
{
	int k=0;
	printf("Enter the elements of the matrix : ");
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j]!=0)
			{
				k++;
			}
		}
	}
	return k;
}



void display(int r,int c,int a[][c])
{
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}





void sp_to_tup(int r,int c,int a[][c],int s,int t[][3])
{
	t[0][0]=r;
	t[0][1]=c;
	t[0][2]=s;
	int k=1;
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (a[i][j]!=0)
			{
				t[k][0]=i;
				t[k][1]=j;
				t[k][2]=a[i][j];
				k++;
			}
		}
	}

}



void sort(int s[][3])
{
	int c=s[0][2],temp;
	for (int i=0;i<c;i++)
	{
		for (int j=1;j<c-i;j++)
		{
			if (s[j][0]>s[j+1][0])
			{
				temp=s[j][0];
				s[j][0]=s[j+1][0];
				s[j+1][0]=temp;
				temp=s[j][1];
				s[j][1]=s[j+1][1];
				s[j+1][1]=temp;
				temp=s[j][2];
				s[j][2]=s[j+1][2];
				s[j+1][2]=temp;
			}
		}
	}
}



void trans (int t[][3],int tr[][3])
{
	int s=t[0][2];
	for (int i=0;i<=s;i++)
	{
		tr[i][0]=t[i][1];
		tr[i][1]=t[i][0];
		tr[i][2]=t[i][2];
	}
	sort(tr);

}



int add(int t1[][3],int t2[][3],int s[][3],int ra,int ca)
{
	int i=1,j=1,k=1,e=0;
	while((i<ra)&&(j<ca))
	{
		if ((t1[i][0]==t2[j][0])&&(t1[i][1]==t2[j][1]))
		{
			s[k][0]=t1[i][0];
			s[k][1]=t1[i][1];
			s[k][2]=t1[i][2]+t2[j][2];
			i++;j++;k++;e++;
		}
		else if((t1[i][0]==t2[j][0])&&(t1[i][1]!=t2[j][1]))
		{
			if(t1[i][1]<t2[j][1])
			{
				s[k][0]=t1[i][0];
				s[k][1]=t1[i][1];
				s[k][2]=t1[i][2];
				i++;k++;e++;
			}
			else
			{
				s[k][0]=t2[j][0];
				s[k][1]=t2[j][1];
				s[k][2]=t2[j][2];
				j++;k++;e++;
			}
		}
		else if(t1[i][0]<t2[j][0])
		{
			s[k][0]=t1[i][0];
			s[k][1]=t1[i][1];
			s[k][2]=t1[i][2];
			i++;k++;e++;
		}
		else
		{
			s[k][0]=t2[j][0];
			s[k][1]=t2[j][1];
			s[k][2]=t2[j][2];
			j++;k++;e++;
		}
	}
	while(i<ra)
	{
		s[k][0]=t1[i][0];
		s[k][1]=t1[i][1];
		s[k][2]=t1[i][2];
		i++;k++;e++;
	}
	while(j<ca)
	{
		s[k][0]=t2[j][0];
		s[k][1]=t2[j][1];
		s[k][2]=t2[j][2];
		j++;k++;e++;
	}
	s[0][0]=t1[0][0];
	s[0][1]=t1[0][1];
	s[0][2]=e;
	return e;
}




void main()
{
	int r1,c1,choice;
	printf("\nEnter the no. of rows in the matrix : ");
	scanf("%d",&r1);
	printf("Enter the no. of columns in the matrix : ");
	scanf("%d",&c1);
	int arr[r1][c1];
	int s1=read(r1,c1,arr);
	int t1[s1+1][3];
	sp_to_tup(r1,c1,arr,s1,t1);
	printf("The Tuple matrix of the Sparce matrix  :\n");
	display(s1+1,3,t1);
	do
	{
		printf("\n1.Transpose\n2.Addition\n3.Exit\n\nEnter your choice : ");
		scanf("%d",&choice);
		if (choice==1)
		{
			int tr[s1+1][3];
			trans(t1,tr);
			printf("\nThe Transpose tuple  : \n");
			display(s1+1,3,tr);

		}
		else if (choice==2)
		{
			int r2,c2;
			printf("\nEnter the no. of rows in the matrix to be added: ");
			scanf("%d",&r2);
			printf("Enter the no. of columns in the matrix to be added : ");
			scanf("%d",&c2);
			if (r1==r2 && c1==c2)
			{
				int brr[r2][c2];
				int s2=read(r2,c2,brr);
				int t2[s2+1][3],crr[s2+s1+2][3];
				sp_to_tup(r2,c2,brr,s2,t2);
				printf("The tuple matrix of the sparce matrix  :\n");
				display(s2+1,3,t2);
				printf("\nThe resultant tuple matrix :\n");
				int o=add(t1,t2,crr,s1+1,s2+1);
				display(o+1,3,crr);
			}
			else
			{
				printf("\nAddition is not possible.\n");
			}

		}




	}
	while(choice!=3);
}
