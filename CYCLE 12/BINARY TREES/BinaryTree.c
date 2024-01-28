#include<stdio.h>
#include<stdlib.h>
struct tree *inOrderPredecessor(struct tree* root);
struct tree *deleteNode(struct tree *root, int value);
struct tree *iPre;
void buildtree(struct tree *ptr);
void preorder(struct tree *ptr);
void postorder(struct tree *ptr);
void inorder(struct tree *ptr);
void search(struct tree *temp,int item);
void insertion(struct tree *root,int item);
struct tree
{
    int data;
    struct tree *lc,*rc;
};
void main()
{
    int elem,el,key,choice;
  struct tree *root;
  root=(struct tree *)malloc(sizeof(struct tree));
  buildtree(root);
  printf("\nPREORDER TRAVERSAL\n");
  preorder(root);
  printf("\nPOSTORDER TRAVERSAL\n");
  postorder(root);
  printf("\nINORDER TRAVERSAL\n");
  inorder(root);
  do
  {
      printf("\nOPERATIONS FOR PERFORMING\n");
      printf("\n1.INSERTING\n2.SEARCHING\n3.DELETION\n4,EXIT\n");
      printf("ENTER THE CHOICE\n");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:    printf("\nENTER DATA FOR INSERTING\n");
                    scanf("%d",&el);
                    insertion(root,el);
                    printf("\nAFTER INSERTING ALL TRAVERSALS ARE GIVEN BELOW\n");
                    printf("\nPREORDER TRAVERSAL\n");
                    preorder(root);
                    printf("\nPOSTORDER TRAVERSAL\n");
                    postorder(root);
                    printf("\nINORDER TRAVERSAL\n");
                    inorder(root);
                    break;

          case 2:   printf("\nENTER DATA FOR SEARCHING\n");
                    scanf("%d",&elem);
                    search(root,elem);
                    break;
          case 3:  printf("\nENTER DATA TO BE DELETED\n");
                    scanf("%d",&key);
                 deleteNode(root,key);
                printf("\nAFTER DELETING ALL TRAVERSALS ARE GIVEN BELOW\n");
                printf("\nPREORDER TRAVERSAL\n");
                preorder(root);
                printf("\nPOSTORDER TRAVERSAL\n");
                postorder(root);
                printf("\nINORDER TRAVERSAL\n");
                inorder(root);
                break;
          default:
            printf("\nEXITED\n");
            break;

      }
  }
  while(choice!=4);
}
void buildtree(struct tree *ptr)
{
    struct tree *lcptr,*rcptr;
    int ch;
    if(ptr!=NULL)
    {
       printf("ENTER THE DATA\n");
       scanf("%d",&ptr->data);
       ptr->lc=NULL;
       ptr->rc=NULL;
       printf("ENTER 1 FOR CREATING LEFT CHILD FOR %d OR ENTER ZERO FOR NOT CREARING\n",ptr->data);
       scanf("%d",&ch);
       if(ch==1)
       {
           lcptr=(struct tree *)malloc(sizeof(struct tree));
           ptr->lc=lcptr;
           buildtree(lcptr);
       }
       printf("ENTER 1 FOR CREATING RIGHT CHILD FOR %d OR ENTER ZERO FOR NOT CREARING\n",ptr->data);
       scanf("%d",&ch);
       if(ch==1)
       {
           rcptr=(struct tree *)malloc(sizeof(struct tree));
           ptr->rc=rcptr;
           buildtree(rcptr);
       }
    }
}
void preorder(struct tree *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        preorder(ptr->lc);
        preorder(ptr->rc);
    }
}
void postorder(struct tree *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->lc);
        postorder(ptr->rc);
        printf("%d\t",ptr->data);
    }
}
void inorder(struct tree *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->lc);
        printf("%d\t",ptr->data);
        inorder(ptr->rc);
    }
}
void search(struct tree *temp,int item)
{
    struct tree *prev;
    int flag=0;
    while(temp!=NULL && flag==0)
    {
        if(temp->data==item)
        {
            printf("\nENTERED DATA %d IS PRESENT AT THE ROOT\n",temp->data);
            flag=1;
        }
        else if(temp->data>item)
        {
            prev=temp;
            temp=temp->lc;
        if(temp->data==item)
        {
            printf("\nENTERED DATA %d IS PRESENT AS THE LEFT CHILD OF %d\n",temp->data,prev->data);
            flag=2;
        }
        }
        else
        {
            prev=temp;
            temp=temp->rc;
       if(temp->data==item)
        {
            printf("\nENTERED DATA %d IS PRESENT AS THE RIGHT CHILD OF %d\n",temp->data,prev->data);
            flag=3;
        }
        }
    }
    if(flag==0)
    {
        printf("\nENTERED DATA IS NOT PRESENT IN THE TREE\n");
    }
}
void insertion(struct tree *root,int item)
{
    struct tree *temp,*parent;
    if(root==NULL)
    {
    struct tree *new;
    new=(struct tree *)malloc(sizeof(struct tree));
    new->data=item;
    new->lc=new->rc=NULL;
    root=new;
    }
    else
    {
        int flag;
        temp=root;
        while(temp!=NULL && flag==0)
        {
            if(temp->data==item)
            {
                flag=1;
                printf("ITEM ALREADY EXISTS\n");
                break;
            }
            else if(temp->data>item)
            {
                parent=temp;
                temp=temp->lc;
            }
            else
            {
                parent=temp;
                temp=temp->rc;
            }
        }
    }
    if(temp==NULL)
    {
    struct tree *new;
    new=(struct tree *)malloc(sizeof(struct tree));
    new->data=item;
    new->lc=new->rc=NULL;
    if(parent->data<item)
    {
        parent->rc=new;
    }
    else
    {
        parent->lc=new;
    }
    }
}
struct tree *deleteNode(struct tree *root, int value)
{
    struct tree *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->lc==NULL && root->rc==NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->lc=deleteNode(root->lc,value);
    }
    else if (value > root->data)
    {
        root->rc=deleteNode(root->rc,value);
    }
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->lc=deleteNode(root->lc,iPre->data);
    }
    return root;
}
struct tree *inOrderPredecessor(struct tree* root)
{
    root = root->lc;
    while (root->rc!=NULL)
    {
        root = root->rc;
    }
    return root;
}
