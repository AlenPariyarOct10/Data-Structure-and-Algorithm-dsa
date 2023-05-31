#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

int front = -1, rear = -1;
bool isEmpty();
bool isFull();
int queue[MAX];
void enqueue(int);
int dequeue();
int peek();
void display();

int main()
{
	int mode, inp;

	while (true)
	{
		printf("Select any mode : \n");
		printf("1. Enqueue() : \n");
		printf("2. Dequeue() : \n");
		printf("3. IsEmpty() : \n");
		printf("4. IsFull() : \n");
		printf("5. print() : \n");
		printf("6. exit() : \n");
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
			printf("Enter value you want to enqueue : ");
			scanf("%d", &inp);
			enqueue(inp);
			break;

		case 2:
			printf("%d is dequeud from Queue.", dequeue());
			break;

		case 3:
			if (isEmpty() == true)
			{
				printf("The queue is Empty");
			}
			else
			{
				printf("The queue is not Empty.");
			}
			break;

		case 4:
			if (isFull() == true)
			{
				printf("The queue is Full");
			}
			else
			{
				printf("The queue is not Full.");
			}
			break;

		case 5:
			printf("Elements in Queue : ");
			for (inp = front; inp <= rear; inp++)
			{
				printf("%d ", queue[inp]);
			}
			break;

		case 6:
			exit(0);
			break;
		default:
			printf("No valid option.");
			exit(0);
		}
	}

	return 0;
}

bool isEmpty()
{
	if (front == -1 && rear == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull()
{
	if (rear == MAX - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void enqueue(int x)
{
	if (isFull())
	{
		printf("Error : Queue Overflow !!");
		exit(1);
	}
	else if (front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = x;
	}
	else
	{
		rear++;
		queue[rear] = x;
	}
}

int dequeue()
{
	int temp;
	if (isEmpty())
	{
		printf("Error : Queue Underflow !!");
		exit(1);
	}
	else if (front == rear)
	{
		temp = queue[front];
		front = rear = -1;
		return temp;
	}
	else
	{
		temp = queue[front];
		front++;
		return temp;
	}
}

int peek()
{
	if (isEmpty())
	{
		printf("Error : Queue is Empty !");
		exit(1);
	}
	else
	{
		return queue[front];
	}
}

void display()
{
	int i;
	if (isEmpty())
	{
		printf("Error : Queue is Empty !");
		exit(1);
	}
	else
	{
		printf("All elements in Queue are : ");
		for (i = front; i <= rear; i++)
		{
			printf("\n%d", queue[i]);
		}
	}
}hello
