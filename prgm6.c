#include<stdio.h>
#include<stdlib.h>
#define size 5
char cq[size],ele;
int front=-1,rear=-1,ch;
void enque();
void deque();
void display();
void main()
{
	printf("1. insert 2.delete 3. display 4.exit");
	while(1)
	{
		printf("\n enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enque();
				break;
			case 2:deque();
				break;
			case 3:display();
				break;
			case 4:exit(0);
		}
	}
}
void enque()
{
	if(front==(rear+1)%size)
	{
		printf("circular queue overflow");
		return;
	}
	if(front==-1)
	front++;
	printf("enter the character of the circular queue");
	scanf("\n%c",&ele);
	rear=(rear+1)%size;
	cq[rear]=ele;
}
void deque()
{
	char item;
	if(front==-1)
	{
		printf("circular queue underflow");
		return;
	}
	else if(front==rear)
	{
		item=cq[front];
		printf("deleted  item is %c",item);
		front=-1;
		rear=-1;
	}
	else
	{
		item=cq[front];
		printf("deleted element is %c",item);
		front=(front+1)%size;
	}
}
void display()
{
	int i;
	if(front==-1)
	{
	printf("circular queue is empty");
	}
	else
	{
		printf("elements of the circular queue are ");
		for(i=front;i=rear;i=(i+1)%size)
		{
			printf("%c\t",cq[i]);
		}
		printf("%c",cq[rear]);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
