#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head,*newnode,*temp;
int n;
void creation()
{
	printf("\n Enter the size of Linklist=");
	scanf("%d",&n);
	int i;
	head=(struct node *)malloc(sizeof(struct node));
	if(head == NULL)
	{
		printf("\n unable to allocate memory");
		exit(0);
	}
	
	printf("\n Enter the data of node 1: ");
	scanf("%d",&head->data);
	head->next=NULL;
	temp=head;
	
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		
		if(newnode==NULL)
		{
			printf("unable to allocate memory");
			break;
		}
		printf("enter the data of node %d : ",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp->next=newnode;
		temp=temp->next;
	}
	
	}
	
	
void insert_begin()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n unable to allocate");
	}
	printf("\n enter the data to be inserted at the beginning");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
}




void insert_position()
{
	int pos,i;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nunable to allocate");
	}
	else
	{
		printf("\nEnter the position to be inserted : ");
		scanf("%d",&pos);
		printf("\nEnter the data to be inserted at %d : ",pos);
		scanf("%d",&newnode->data);
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			break;
		}
		if(temp!=NULL)
		{
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	
}
	
void insert_end()
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to allocate");
	}
	else
	{
		printf("\n Enter the data to be inserted at the end: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
}	
	
void delete_begin()
{
	if(head!=NULL)
	temp=head;
	head=temp->next;
	free(temp);
}

void delete_end()
{
	struct node *prevnode;
	if(head==NULL)
	{
		printf("\n Linklist is empty");
	}
	else
	{
		
		for(temp=head;temp->next!=NULL;temp=temp->next)
		{
			prevnode=temp;
		}
		if(temp==head)
		{
			head==NULL;
		}
		else
		{
			prevnode->next=NULL;
		}
		free(temp);
	}
}

void delete_position()
{
	struct node *nextnode;
	int pos,i;
	temp=head;
	printf("\n Enter the position at where the node has to be deleted: ");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}

void display()
{
	if(head==NULL)
	{
		printf("\n Linklist is empty");
	}
	else
	{
		for(temp=head;temp!=NULL;temp=temp->next)
		{
			printf("data=%d\t",temp->data);
	    }
    }
}
void main()
{
	int choice,c;
	printf("\n...LINKLIST...\n");
	printf("\n 1.CREATION \t 2.INSERTION\t 3.DELETION\t 4.DISPLAY\t 5.EXIT \n");
	do
	{
		printf("\n Enter a choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				creation();
				break;
			    
			case 2:
				printf("\n 1.At the beginning\t 2.At a specific position\t 3.At the end\t 4.Exit\n");
				printf("enter a choice: ");
				scanf("%d",&c);
				switch(c)
				{
					case 1:insert_begin();break;
					case 2:insert_position();break;
					case 3:insert_end();break;
					case 4:break;
					default:printf("\n invalid choice,try again \n");
				}
				break;
			case 3:
				printf("\n 1.At the beginning\t 2.At specific position 3.At the end\t 4.Exit \n");
				printf("enter a choice: ");
				scanf("%d",&c);
				switch(c)
				{
					case 1:delete_begin();break;
					case 2:delete_position();break;
					case 3:delete_end();break;
					case 4:break;
					default:printf("\n invalid choice,try again \n");
				}
				break;
			case 4:
				display();
				break;
			case 5:
				printf("\n EXIT \n");
			default:
				printf("\n invalid choice,try again");
				
		}
	}while(choice!=5);
}


