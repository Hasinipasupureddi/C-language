//Program for Implementation of Stack using Array.
#include <stdio.h>
#include <stdlib.h>
int stack[100],top=-1,size;
void push();
void pop();
void display();
void peek();
int main()
{
int choice;
printf ("Enter Size of stack:");
scanf ("%d", &size);
do
{
printf ("\n choose option: ");
printf ("\n 1. push \t 2. pop \t 3. display \t4. peek \t 5.exit ");
scanf("%d", &choice);
switch (choice)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: peek();
break;
case 5: exit(0);
break;
default:printf("\n invalid choice");
} //switch
}
while(choice!=5);
return 0;
}//main
void push()
{
int value;
if(top>=size-1)
{
printf("\n stack overflow");
return;
}
else
{
printf("\n enter elements to insert:");
scanf("%d",&value);
top=top+1;
stack[top]=value;
}
}
void pop()
{
if(top==-1)
{
printf("\n stack is underflow");
return;
}
else
{
printf("\n deleted element is: %d",stack[top]);
top=top-1;
}
}
void display()
{
int i;
if(top==-1)
{
printf("\n stack is empty");
return;
}
else
{
printf("\n the elements of stack are:");
for(i=top;i>=0;i--)
printf("\n %d \t",stack[i]);
}
}
void peek()
{
if(top==-1)
{
printf("\n stack is empty");
return;
}
else
{
printf("\n %d",stack[top]);
}
}
