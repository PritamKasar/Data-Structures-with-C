#include<stdio.h>
#include<stdlib.h>
int x;
struct node
{
    int item;
    struct node *left,*right;
};
struct node *createnode(int key)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->item=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return(newnode);
};
void inorder(struct node *root)
{   if(root!=NULL)
    {
    inorder(root->left);
    printf("\n%d",root->item);
    inorder(root->right);
}}
int smallest(struct node *root)
{
    while(root!=NULL && root->left!=NULL)
    root=root->left;
    printf("\nsmallest:%d",root->item);
}
int largest(struct node *root)
{
    while(root!=NULL && root->right!=NULL)
    root=root->right;
    printf("\nlargest:%d",root->item);
}
int search(struct node *head,int key)
{
    while(head!=NULL)
    {
        if(key>head->item)
        return search(head->right,key);
        else if(key<head->item)
        return search(head->left,key);
        else
        return 1;
    }
    return 0;
}
int main()
{
    int flag=0,c;
    struct node *newnode=createnode(2000);
    newnode->left=createnode(222);
    newnode->right=createnode(333);
     newnode->left->left=createnode(444);
      newnode->left->right=createnode(555);
      newnode->right->left=createnode(666);
      newnode->right->right=createnode(777);
      while(1)
      {
        printf("Enter your choice");
        printf("\n1.i  2.s  3.l  4.S 5.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:inorder(newnode);break;
            case 2:smallest(newnode);break;
            case 3:largest(newnode);break;
            case 4:printf("enter a number");
            scanf("%d",&x);
            flag=search(newnode,x);
            if(flag)
            printf("%d is Found",x);
            else
            printf("not Found");break;
            case 5:exit(0);
        }
      }



}