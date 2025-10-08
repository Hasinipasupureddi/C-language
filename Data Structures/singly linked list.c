#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
}*head=NULL;
int count()
{
    struct node *temp;
    int i=1;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return(i);
}
struct node *create(int value)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
void insert_begin(int value)
{
    struct node *newnode;
    newnode=create(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
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
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("\nNode inserted at end.");
}
void insert_pos(int value,int pos)
{
    struct node *newnode, *temp,*temp1;
    int i,c;
    newnode=create(value);
    c=count();
    if(pos==1)
        insert_begin(value);
    else if(pos>c+1)
    {
        printf("\ninsertion is not posible");
        return;
    }
    else
    {
        temp=head;
        for(i=1;i<=pos-1 && temp!=NULL;i++)
        {
            temp1=temp;
            temp=temp->next;
        }
        newnode->next=temp1->next;
        temp1->next=newnode;
        printf("\nNode inserted at %d position",pos);
    }
}
void delete_begin()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\ndeletion is not possible");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("\nNode deleted from the begining ...\n");
    }
}
void delete_end()
{
    struct node *temp,*temp1;
    if(head==NULL)
    {
        printf("\ndeletion is not possible");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
        printf("\nDeleted Node from the last ...\n");
    }
}
void delete_pos(int pos)
{
    struct node *temp,*temp1;
    int i,c;
    c=count();
    if(pos==1)
        delete_begin();
    else if(pos>c)
    {
        printf("\nDeletion is not posible");
        return;
    }
    else
    {
        temp=head;
        for(i=1;i<=pos && temp->next!=NULL;i++)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        free(temp);
        printf("\nDeleted node at %d position",pos);
    }
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        temp=head;
        printf("\n The elements of list are:");
        while(temp!=NULL)
        {
            printf("%d-> ",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int ch,pos,value;
    do
    {
        printf("\n Choose the operation to perform:");
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Delete Begin\n5.DeleteEnd\n6.Delete Position\n7.Display\n8.Exit");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("\nenter the value:");
                scanf("%d",&value);
                insert_begin(value);
                break;
        case 2: printf("\nenter value:");
                scanf("%d",&value);
                insert_end(value);
                break;
        case 3: printf("\nenter value:");
                scanf("%d",&value);
                printf("\nenter position you want to insert: ");
                scanf("%d",&pos);
                insert_pos(value,pos);
                break;
        case 4: delete_begin();
                break;
        case 5: delete_end();
                break;
        case 6: printf("\nenter position you want to delete: ");
                scanf("%d",&pos);
                delete_pos(pos);
                break;
        case 7: display();
                break;
        case 8:break;
        default: printf("\nyour choice is wrong!.. ");
        }
    }while(ch!=8);
    return 0;
}