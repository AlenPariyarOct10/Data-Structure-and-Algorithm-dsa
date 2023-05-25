/*
*
 Stack implementation using Array
*
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 4

int stack_arr[MAX];
bool isEmpty();
bool isFull();
void push(int);
int pop();
int top();
int size();
int tos = -1;

int main()
{
    int mode, data, count;

    while (1)
    {
        printf("Select any operation : \n");
        printf("1. PUSH():\n");
        printf("2. POP():\n");
        printf("3. TOP():\n");
        printf("4. SIZE():\n");
        printf("5. isEmpty():\n");
        printf("6. isFull():\n");
        printf("7. Print all elements in Stack : \n");
        printf("8. Exit\n");

        printf(":>> ");
        scanf("%d", &mode);
        system("cls");

        switch (mode)
        {
        case 1:

            printf("\nEnter data you want to push : ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            printf("\nYou poped %d from the stack.", pop());
            break;

        case 3:
            printf("\nTop element in the stack is %d", top());
            break;

        case 4:
            printf("\nThe size of Stack is %d.", size());
            break;

        case 5:
            if (isEmpty() == true)
            {
                printf("\nThe stack is empty.");
            }
            else
            {
                printf("\nThe stack is not empty.");
            }
            break;

        case 6:
            if (isFull() == true)
            {
                printf("\nThe stack is full.");
            }
            else
            {
                printf("\nThe stack is not full.");
            }
            break;

        case 7:
            printf("\n Elements in Stack are : ");
            for (count = 0; count < tos; count++)
            {
                printf("%d ", stack_arr[count]);
            }
            break;

        default:
            printf("exit.");
            exit(1);
        }
    }

    return 0;
}

bool isEmpty()
{
    if (tos == -1)
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
    if (tos == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int data)
{
    int i;
    if (isFull())
    {
        printf("\nStack Overflow");
        exit(0);
    }

    tos++;
    stack_arr[tos] = data;

    printf("\nStack : [%d] : %d\n", tos, stack_arr[tos]);
}

int pop()
{
    if (!isEmpty())
    {
        int cur = stack_arr[tos];
        tos--;
        return cur;
    }
    else
    {
        printf("\nStack Underflow");
        exit(0);
    }
}

int top()
{
    if (!isEmpty())
    {
        return stack_arr[tos];
    }
    else
    {
        printf("\nStack is empty");
        exit(0);
    }
}

int size()
{
    if (!isEmpty())
    {
        return tos + 1;
    }
    else
    {
        printf("\nStack is empty");
        exit(0);
    }
}
