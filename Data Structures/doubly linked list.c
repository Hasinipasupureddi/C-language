#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *llink;
    int data;
    struct node *rlink;
}*head=NULL,*tail=NULL;

int count()
{
    struct node *temp;
    int i=1;
    temp=head;
    while(temp->rlink!=NULL)
    {
        temp=temp->rlink;
        i++;
    }
    return(i);
}

struct node *create(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->rlink=NULL;
    temp->llink=NULL;
    return temp;
}
void insert_begin(int value)
{
    struct node *newnode;
    newnode=create(value);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        newnode->rlink=head;
        head->llink=newnode;
        head=newnode;
    }
    printf("\nNode inserted at beginning. ");
}

void insert_end(int value)
{
    struct node *newnode, *temp;
    newnode=create(value);
    if(head==NULL)
    {
        head=tail=newnode;
    }
    else
    {
        newnode->llink=tail;
        tail->rlink=newnode;
        tail=newnode;
    }
     printf("\nNode inserted at end.");
}

void insert_pos(int value,int pos)
{
    struct node *newnode, *temp1,*temp2,*temp;
    int c,i=1;
    newnode=create(value);
    c=count();
    if(pos==1)
        insert_begin(value);
    else if(pos>c+1)
    {
        printf("insertion is not posible");
        return;
    }
    else if(pos==c+1)
    {
        insert_end(value);
    }
    else
    {
        temp=head;
        while(i<=pos-1 && temp!=NULL)
        {
            temp=temp->rlink;
            i++;
        }
        temp1=temp->llink;
        temp1->rlink=newnode;
        temp->llink=newnode;
        newnode->llink=temp1;
        newnode->rlink=temp;
        printf("\nNode inserted at %d position",pos);
    }
}

void delete_begin()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("deletion is not possible");
    }
    else
    {
        temp=head;
        head=head->rlink;
        if(head==NULL)
            tail=NULL;
        else
        	head->llink=NULL;
        free(temp);
        printf("\nNode deleted from the begining ...\n");
    }
}
void delete_end()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("deletion is not possible");
    }
    else
    {
        temp=tail;
        tail=tail->llink;
        if(tail==NULL)
            head=NULL;
        else
            tail->rlink=NULL;
        free(temp);
        printf("\nDeleted Node from the last ...\n");
    }
}
void delete_pos(int pos)
{
    struct node *temp1,*temp2,*temp;
    int c,i=1;
    c=count();
    if(pos==1)
        delete_begin();
    else if(pos>c)
    {
        printf("Deletion is not posible");
        return;
    }
    else if(pos==c)
    {
        delete_end();
    }
    else
    {
        temp=head;
        while(i<pos && temp->rlink!=NULL)
        {
            temp=temp->rlink;
            i++;
        }
        temp1=temp->llink;
        temp2=temp->rlink;
        temp1->rlink=temp2;
        temp2->llink=temp1;
        free(temp);
        printf("\nDeleted node at %d position",pos); 
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        printf("\n The elements of list are:");
        while(temp->rlink!=NULL)
        {
            printf("%d <-> ",temp->data);
            temp=temp->rlink;
        }
        printf("%d",temp->data);
    }
}

void main()
{
    int ch,pos,value;
    do
    {
    	printf("\n Choose the operation to perform:");
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Delete Begin\n5.Delete End\n6.Delete Position\n7.Display\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("Enter the value: ");
                scanf("%d",&value);
                insert_begin(value);
                break;
        case 2: printf("Enter value: ");
                scanf("%d",&value);
                insert_end(value);
                break;
        case 3: printf("Enter value: ");
                scanf("%d",&value);
                printf("Enter position you want to insert: ");
                scanf("%d",&pos);
                insert_pos(value,pos);
                break;
        case 4: delete_begin();
                break;
        case 5: delete_end();
                break;
        case 6: printf("Enter position you want to delete: ");
                scanf("%d",&pos);
                delete_pos(pos);
                break;
        case 7: display();
                break;
        case 8:break;
        default: printf("\nyour choice is wrong!.. ");
        }
    }while(ch!=8);
}        