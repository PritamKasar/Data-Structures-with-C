
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *link;
    int data;
} *start = NULL;

int insertbeg(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = x;
        temp->link = start;
        start = temp;
    }
}

int insertend(int x)
{
    struct node *ptr = start;
    struct node *temp = malloc(sizeof(struct node));
    if (temp != NULL)
    {
        temp->data = x;
        temp->link = NULL;
        if (start != NULL)
        {
            while (ptr->link != NULL)
            {
                ptr = ptr->link;
            }
            ptr->link = temp;
        }
        else
        {
            start = temp;
        }
    }
}

int deletebeg()
{
    struct node *ptr = start;
    if (start != NULL)
    {
        start = ptr->link;
        free(ptr);
    }
    return 0;
}
int traverse()
{
    struct node *ptr = start;
    printf("[");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("]");
}
int search(int x)
{
    int count = 0;
    struct node *ptr = start;
    if (start != NULL)
    {
        while (ptr != NULL)
        {

            if (ptr->data == x)
            {
                printf("Found at %d index\n", count);
            }
            count++;
            ptr = ptr->link;
        }
    }
}

int main()
{
    insertbeg(10);
    insertbeg(20);
    insertbeg(30);
    insertend(20);
    deletebeg();
    search(20);
    traverse();
}

// #include <stdio.h>
// #include <stdlib.h>
// struct node{
//     struct node *link;
//     int data;
// }*start=NULL;

// int insert(int x){
//     struct node *temp;
//     temp=malloc(sizeof(struct node));
//     if (temp!=NULL)
//     {
//         temp->data=x;
//         temp->link=start;
//         start=temp;
//     }

// }
// int traverse(){
//     struct node *ptr;
//     ptr=start;
//     printf("{");
//     while(ptr!=NULL)
//     {
//         printf(" %d",ptr->data);
//         ptr=ptr->link;
//     }
//     printf("}");
// }
// int main(){
//     insert(40);
//     insert(40);
//     insert(40);
//     traverse();
//     return 0;
// }