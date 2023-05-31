#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int index = -1;
bool isEmpty();
bool isFull();
void create();
int list[MAX];
void insert(int, int);
int delete(int);
void update(int, int);
void search(int);
void display();

int main()
{
    int mode;
    int pos, val;

	while (true)
	{
		printf("Select any mode : \n");
		printf("1. create() : \n");
		printf("2. isEmpty() : \n");
		printf("3. IsFull() : \n");
		printf("4. Insert(postion, value) : \n");
		printf("5. Delete(pos) : \n");
		printf("6. update(position, value) : \n");
		printf("7. search(value) : \n");
		printf("8. display() : \n");
		printf("9. exit() : \n");
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
			create();
			break;

		case 2:
			if (isEmpty() == true)
			{
				printf("The queue is Empty");
			}
			else
			{
				printf("The queue is not Empty.");
			}
			break;
		case 3:
			if (isFull() == true)
			{
				printf("The queue is Full");
			}
			else
			{
				printf("The queue is not Full.");
			}
			break;

		case 4:
			
            printf("Enter position : ");
            scanf("%d",&pos);
            printf("Enter value : ");
            scanf("%d",&val);
            insert(pos,val);
			break;

		case 5:
		
            printf("Enter Position : ");
            scanf("%d",&pos);
            printf("\n%d element deleted.\n",delete(pos));
			break;

		case 6:
            
            printf("Enter position : ");
            scanf("%d",&pos);
            printf("Enter value : ");
            scanf("%d",&val);
            update(pos,val);
			break;

		case 7:
            
            printf("Enter value : ");
            scanf("%d",&val);
            search(val);
			break;

		case 8:
            display();
			break;
		case 9:
            exit(1);
			
		default:
			printf("No valid option.");
			exit(0);
		}
	}

	return 0;
}

bool isEmpty()
{
    if (index == -1)
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
    if (index == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void create()
{
    int i, size;
    printf("\nEnter Size of Initial List : ");
    scanf("%d", &size);

    if (size >= MAX)
    {
        printf("Error ! MAX limit exceeded!");
        exit(1);
    }
    else
    {

        for (i = 0; i < size; i++)
        {
            printf("\nEnter value for Index [%d] : ", i);
            scanf("%d", &list[i]);
        }
        index=size-1;
    }
}

void insert(int pos, int val)
{
    int i;
    
    if(pos>index && !isFull())
    {
        printf("Invalid Position Value !");
        exit(1);
    }else{
        for(i=index+1;i>=pos;i--)
        {
            list[i+1] = list[i];
        }
        list[pos]=val;
        index++;
    }
}

int delete(int pos)
{
    int i,temp = list[pos];
    if(pos>index && !isEmpty())
    {
        printf("Invalid Position Value !");
        exit(1);
    }else{
        for(i=pos;i<index;i++)
        {
            list[i] = list[i+1];
        }
        index--;
        return temp;

    }
}

void update(int pos,int value)
{
    if(isEmpty() || pos>index)
    {
        printf("Error ! Invalid Position !");
        exit(1);
    }else{
        list[pos]=value;
    }
}

void search(int value)
{
    int i;
    if(isEmpty())
    {
        printf("List is Empty !");
        exit(1);
    }else{
        for(i=0;i<=index;i++)
        {
            if(value == list[i])
            {
                printf("\nThe value is at index : %d\n",i);
                break;                
            }
        }
        if(i==index+1)
        {
        	printf("Value not found!");
		}
    }
}


void display()
{
    int i;
    if(isEmpty())
    {
        printf("List is empty !");
        exit(1);
    }else{
        printf("\nAll Elements in List : \n");
        for(i=0;i<=index;i++)
        {
            printf("%d ",list[i]);
        }
    }
}