#include<stdio.h>
#define size 100
struct queue
{
    int queue[size];
    int front;
    int rear;
}st;
int qfull()
{
    if(st.rear==size+1)
    return 1;
    else
    return 0;
}
int qempty()
{
    if(st.rear==0)
    return 1;
    else
    return 0;
}
int qinsert(int item)
{
    if(!qfull())
    {
        st.rear++;
        st.queue[st.rear]=item;
        printf("%d inserted\n",item);
    }
    else
    printf("queue is full\n");
}int qdelete()
{
    if(!qempty())
    {
        int a;
        st.front++;
        a=st.queue[st.front];
        
        printf("%d deleted\n ",a);
    }else
    printf("queue is empty\n");
}
int main()
{
    qinsert(5);
    qinsert(10);
    qinsert(2);
    qinsert(3);
    qdelete();

    return 0;
}