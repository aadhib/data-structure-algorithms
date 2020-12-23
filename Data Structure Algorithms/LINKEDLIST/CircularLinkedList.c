#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *tail, *temp;
void main()
{
int ch,p;
while(1)
{
printf("\nEnter the following");
printf("\n1.Create:");
printf("\n2.Insert at beg:");
printf("\n3.Insert at end:");
printf("\n4.Insert at any location:");
printf("\n5.Delete from beg:");
printf("\n6.Delete from end:");
printf("\n7.Delete from given location:");
printf("\n8.Display:");
printf("\n9.Exit:");
printf("\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: create();
break;
case 2:insert_beg();
break;
case 3:insert_end();
break;
case 4:insert_loc();
break;
case 5:delete_beg();
break;
case 6:delete_end();
break;
case 7:delete_loc();
 break;
case 8:display();
break;
case 9:exit(0);
default:
printf("\nInvalid choice");
}
}
}
void create()
{
 struct node *newnode;
newnode = (struct node *)malloc(sizeof(struct node)); 
    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next=0;
    if(tail==0){
        tail=newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_beg()
{
  struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));
    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next=0;
    if(tail==0){
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}
  void insert_end()
  {
  struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}
int getLength()
{
    int count=0;
    temp = tail->next;
    while(temp->next != tail->next)
    {
        count++;
        temp = temp->next;
    }
    return count+1;
}
  void insert_loc()
  {
  int i=1, position;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));

    printf("Enter Position ");
    scanf("%d", &position);

    int l = getLength();

    if(position<1 || position> l+1){
        printf("INVALID POSITION");
    }
    else if(position == 1){
        insert_beg();
    }
    else if(position == l+1){
        insert_end();
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data ");
        scanf("%d", &newnode->data);
        newnode->next=0;

        temp = tail->next;
        while(i<position-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
 }
 void delete_beg()
{
  temp = tail->next;
    if(tail==0){
        printf("LIST IS EMPTY!!!\N");
    }
    else if(temp->next==temp){
        tail=0;
        free(temp);
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
 }
 
  void delete_end()
  {
  struct node *current, *previous;
    current = tail->next;

    if(tail==0){
        printf("LIST IS EMPTY\n");
    }
    else if(current->next == current){
        tail = 0;
        free(current);
    }
    else{
        while(current->next != tail->next)
		{
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        tail = previous;
        free(current);
    }
}
  void delete_loc()
  {
     struct node *current, *previous;
    int position, i=1;

    printf("Enter Position ");
    scanf("%d", &position);

    int l = getLength();

    if(position<1 || position>l){
        printf("\nINVALID POSITION!!!\n");
    }
    else if(position==1){
        delete_beg();
    }
    else if(position==l){
        delete_end();
    }
    else{
        current = tail->next;
        while(i<position){
            previous = current;
            current = current->next;
            i++;
        }
        previous->next = current->next;

        free(current);
    }
  } 
  void display()
  {
    if(tail==0)
   {
       printf("LIST is EMPTY\n");
   }
   else{
    temp = tail->next;
   }
   while(temp->next != tail->next)
   {
       printf("%d ", temp->data);
       temp = temp->next;
   }
   printf("%d\n", temp->data);
}
