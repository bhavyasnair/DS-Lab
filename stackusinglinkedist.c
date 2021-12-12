#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *newnode;
struct node *top=NULL;
int size;

int main()
{
	int choice;
	printf("\nEnter the size of stack = ");
	scanf("%d",&size);
	printf("\nIMPLEMENTION OF STACK OPERATIONS USING ARRAY\n \n 1.PUSH\t 2.POP\t 3.DISPLAY\t 4.SEARCH\t \n");
	do
	{
		printf("\nEnter a choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 4:printf("\nExit\n");break;
			default:printf("\nInvalid choice!Try again\n");
		}
	}
	while(choice!=5);
	return 0;
}

void push()
{
	newnode=(struct node *)malloc(sizeof(struct node)); 
	printf("\nEnter the data to be pushed : ");
	scanf("%d",&newnode->data);
	newnode->next=top;
	top=newnode;//top points to the node 
}


void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{
		printf("\nunderflow\n");
	}
	else
	{
		printf("\n The poped data is %d",top->data);
		top=top->next;
		free(temp);
	}
}

	
void display()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		temp=top;
		for(temp=top;temp!=NULL;temp=temp->next)
		{
			printf("data=%d\t",temp->data);
		}
	}
}

