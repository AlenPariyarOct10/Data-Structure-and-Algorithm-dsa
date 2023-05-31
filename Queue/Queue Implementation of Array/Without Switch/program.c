#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

int front=-1,rear=-1;
bool isEmpty();
bool isFull();
int queue[MAX];
void enqueue(int);
int dequeue();
int peek();
void display();

int main()
{
	enqueue(5);
	enqueue(10);
	enqueue(15);
	dequeue();
	enqueue(20);
	dequeue();
	printf("%d",peek());
	printf("\n");
	display();
	return 0;
}

bool isEmpty()
{
	if(front==-1 && rear == -1)
	{
		return true;
	}else{
		return false;
	}
}

bool isFull()
{
	if(rear==MAX-1)
	{
		return true;
	}else{
		return false;
	}
}

void enqueue(int x)
{
	if(isFull())
	{
		printf("Error : Queue Overflow !!");
		exit(1);
	}else if(front==-1 && rear == -1)
	{
		front=rear=0;
		queue[rear]=x;
	}else{
		rear++;
		queue[rear]=x;
	}
}

int dequeue()
{
	int temp;
	if(isEmpty())
	{
		printf("Error : Queue Underflow !!");
		exit(1);
	}else if(front==rear)
	{
		temp = queue[front];
		front=rear=-1;
		return temp;
	}else{
		temp = queue[front];
		front++;
		return temp;
	}
}

int peek()
{
	if(isEmpty())
	{
		printf("Error : Queue is Empty !");
		exit(1);
	}else{
		return queue[front];
	}
}

void display()
{
	int i;
	if(isEmpty())
	{
		printf("Error : Queue is Empty !");
		exit(1);
	}else{
		printf("All elements in Queue are : ");
		for(i=front;i<=rear;i++)
		{
			printf("\n%d",queue[i]);
		}
	}
}