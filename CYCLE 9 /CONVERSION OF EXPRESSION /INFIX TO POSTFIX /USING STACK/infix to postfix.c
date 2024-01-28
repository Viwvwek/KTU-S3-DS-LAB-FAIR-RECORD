#include<stdio.h>

char postfix[10],stack[10],infix[10],top=-1;
//****Stack-Push****

void push(char c)
{       top++;
        stack[top]=c;
}

//****Stack-pop****
char pop()
{
    char c;
    c=stack[top];
    top--;
    return c;
}
//****priority****
int pre(char x)
{
    if(x=='(')
    {
        return 1;
    }
    else if((x=='+')||(x=='-'))
    {
        return 2;
    }
    else if((x=='*')||(x=='/'))
    {
        return 3;
    }
    else
    {
        return 0;
    }

}
//****main****
int main()
{
    int i,j=0;
    char x;
    printf("enter the expression:");
    scanf("%s",infix);
    printf("the expression is :%s\n",infix);
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[j]=infix[i];
            j++;

        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while((x=pop())!='(')
            {
                postfix[j]=x;
                j++;
            }
        }
        else
        {
            while(pre(stack[top])>=pre(infix[i]))
            {
                 postfix[j]=pop();
                    j++;
            }
            push(infix[i]);

        }
    }
    while(top!=-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("the post expression is :%s\n",postfix);

}


