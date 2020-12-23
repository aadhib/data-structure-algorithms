#include <stdio.h>
#include <stdlib.h>
int stack[5];
void push();
int pop();
void traverse();
int is_empty();
int top_element();
int top = 0;
int main()
{int element, choice;
for (;;)
{printf("Stack Operations.\n");
 printf("1. Push.\n2. Pop.\n3.Traverse stack.\n4. Exit.\n");
 printf("Enter your choice.\n");
 scanf("%d",&choice);
switch (choice)
{case 1:
 if (top == 5)
 printf("Error: Overflow\n\n");
else {printf("Enter a value to insert:");
scanf("%d", &element);
push(element);}
break;
case 2:if (top == 0)
printf("Error: Underflow.\n\n");
else {element = pop();
printf("Element removed from the stack is %d.\n", element);}
break;
case 3:traverse();
break;
case 4:exit(0);}}}
void push(int value)
{stack[top] = value;
top++;}
int pop() 
{top--;
 return stack[top];}
void traverse()
{int d;
if (top == 0)
{printf("The stack is empty.\n\n");
return;}
printf("There are %d elements in the stack.\n", top);
for (d = top - 1; d >= 0; d--)
printf("%d\n", stack[d]);
printf("\n");}
int is_empty()
{if (top == 0)
return 1;
else
return 0;}
int top_element()
{
	
return stack[top-1];
}
       
