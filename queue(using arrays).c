//implementation of queue using arrays
#include <stdio.h>
#include <stdlib.h>
int queue [100];
int size, rear = -1, front = -1;
void insert();
void delete();
void display();
int main()
{
int choice;
printf ("Enter Size of array:");
scanf ("%d", &size);
do
{
printf ("\n choose operation to perform on Queue: ");
printf ("\n 1. insertion \t 2. Deletion \t 3. display \t4. Exit ");
scanf("%d", &choice);
switch (choice)
{
case 1: insert();
break;
case 2: delete();
break;
case 3: display();
break;
case 4:exit(0);
break;
default:printf("\n invalid choice");
} //switch
}
while(choice!=4);
return 0;
}//main
void insert()
{
int element;
if(rear>=size-1)
{
printf("\n queue is full");
return;
}
else
{
printf("\n enter elements to insert:");
scanf("%d",&element);
rear=rear+1;
queue[rear]=element;
}
if(front==-1)
{
front=0;
}
}
void delete()
{
if(front==-1 || front>rear)
{
printf("queue is empty");
return;
}
else
{
printf("\n deleted element is: %d",queue[front]);
front=front+1;
}
}
void display()
{
int i;
if(front==-1 || front>rear)
{
printf("\n empty queue");
return;
}
else
{
printf("\n queue elements are:");
for(i=front;i<=rear;i++)
printf("\n %d \t",queue[i]);
}
}
