# include <stdio.h>
typedef struct nodes
{

    int key;
    struct nodes *link;
}node;
int main()
{
    int ch,hashTable[10],ele,index,flag,count,ch2;
    node *hTable[10],*head,*new_node,*temp;
    while(1)
    {
        printf("\n\t\tMENU\n\t\t****\n\t1. Closed Hashing \n\t2. Open Hashing\n\t3. Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
           case 1:
                    for(int i=0;i<10;i++)
                        hashTable[i]=-1;
                    while(1)
                   {
                        printf("Enter the element");
                        scanf("%d",&ele);
                        index=ele%10;
                        if(hashTable[index]==-1)
                        {
                            hashTable[index]=ele;
                        }
                        else
                        {
                            printf("\nCollision occurs at index %d",index);
                            flag=0;
                            count=0;
                            while(flag==0 && count<9)
                            {
                                count++;
                                if(index<9)
                                    index++;
                                else if(index==9)
                                    index=0;
                                if(hashTable[index]==-1)
                                {
                                    hashTable[index]=ele;
                                    flag=1;
                                }
                                else
                                    printf("\nCollision occurs at index %d",index);
                            }
                            if(count==9)
                                printf("Overflow");
                        }
                        printf("\nHash Table:");
                        for(int i=0;i<10;i++)
                            printf("%d\t",hashTable[i]);
                        printf("\nDo you want to enter another element?(Yes=1/No=0)");
                        scanf("%d",&ch2);
                        if(ch2==0)
                            break;
                    }
                    break;
           case 2:
                    for(int i=0;i<10;i++)
                        hTable[i]=NULL;
                    while(1)
                   {
                        printf("Enter the element");
                        scanf("%d",&ele);
                        new_node=(node *)malloc(sizeof(node));
                        new_node->key=ele;
                        new_node->link=NULL;
                        index=ele%10;
                        head =hTable[index];
                        if(head==NULL)
                            hTable[index]=new_node;
                        else
                        {
                             new_node->link=head;
                             hTable[index]=new_node;
                        }
                        printf("\nHash Table:");
                        for(int i=0;i<10;i++)
                        {
                            printf("\n%d:",i);
                            temp=hTable[i];
                            if(temp==NULL)
                                printf("NULL");
                            else
                            {
                                while(temp!=NULL)
                                {
                                    printf("%d\t",temp->key);
                                    temp=temp->link;
                                }

                            }
                        }
                        printf("\nDo you want to enter another element?(Yes=1/No=0)");
                        scanf("%d",&ch2);
                        if(ch2==0)
                            break;
                    }
                    break;
                case 3: break;
                default: printf("Invalid choice");
        }
    }

}
