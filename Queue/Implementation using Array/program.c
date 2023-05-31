#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 5 // Max Length of Queue 5
int front=-1,rear=-1; // Setting Queue initially as Empty
int queue[MAX]; 
bool isEmpty(); // Check if Queue is Empty or Not
bool isFull(); // Check if Queue is Full or Not
void enqueue(int); // Insert New Element next to current rear position
int dequeue(); // Remove element in Front of Queue
void print(); // Prints all elements in Queue



int main()
{
    while(true)
    {
        
        int mode,inp;
        printf("\n");
        printf("Select any Operation : \n");
        printf("1. Enqueue() : \n");
        printf("2. Dequeue() : \n");
        printf("3. isEmpty() : \n");
        printf("4. isFull() : \n");
        printf("5. print() : \n");
        printf("6. exit() : \n");
        scanf("%d",&mode);

        switch(mode)
        {
            case 1:
                printf("\nEnter value you want to Enqueue : ");
                scanf("%d",&inp);
                enqueue(inp);
                break;
            case 2:
                printf("\n%d is dequeued.\n",dequeue());

                break;
            case 3:
                if(isEmpty())
                {
                    printf("\nThe queue is Empty !\n");
                }else{
                    printf("\nThe queue is not Empty !\n");
                }
                break;
            case 4:
                if(isFull())
                {
                    printf("\nThe queue is Full !\n");
                }else{
                    printf("\nThe queue is not Full !\n");
                }
                break;

            case 5:
                print();
                break;
            case 6:
                exit(0);
            default:
                printf("\nNo valid option found. Try again.\n");

        }
        

        

    }
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
    if(rear == MAX-1)
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
        printf("\nError : Queue is Full !\n");
        exit(1);
    }else{
        if(front==-1 && rear==-1)
        {
            rear=front=0;

            queue[rear]=x;
        }else{
            rear++;
            queue[rear]=x;

        }
        
    
        
    }
   
}

int dequeue()
{
	int i;
    if(isEmpty())
    {
        printf("\nError : Queue is Empty !\n");
        exit(1);
    }else{
        int temp = queue[front];
        //Checking if there is only one element in Queue
        if(front==0 && rear==0)
        {
            //Setting the queue as Empty
            front=rear=-1;
            //returning Dequeued Value
            return temp;
        }else{

            //Shifting each elements in a Queue left by 1 position
            for(i=0;i<rear;i++)
            {
                //value of current value overwritten by next position value
                queue[i]=queue[i+1];

            }

            //decrementing last position index
            rear--;

            //returning Dequeued Value
            return temp;
        }
    }
   
}

void print()
{
    if(isEmpty())
    {
        printf("\nError : Queue is Empty\n");
        exit(0);
    }else{
        printf("\nElements in queue : \n");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}