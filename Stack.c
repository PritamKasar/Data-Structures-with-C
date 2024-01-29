#include <stdio.h>
# define size 200
int stack[size];
int top=-1;

int push(int x)
{
    if(top!=size-1)
    {
        top++;
        stack[top]=x;
    }
    else    
    printf("Stack is Already Full");
}

int show()
{
    for(int i=top;i>-1;i--)
    {
        printf("%d\n",stack[i]);

    }
}

int pop()
{
    if(top!=-1)
    {

        int var=stack[top];
        top--;
        printf("%d is popped\n",var);
    }
    else
    printf("Stack is Already Full");
}
int main()
{
    push(10);
    push(20);
    show();
    pop();
    show();

}