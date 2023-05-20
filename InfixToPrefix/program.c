#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 30

int tos = -1;
char stack[MAX];
char postfix[MAX];
bool isEmpty();
bool isFull();
int presidence(char);
void push(char);
char pop();
void infixToPrefix(char*);

int main()
{
    char exp[MAX];
    printf("Enter your expression : ");
    gets(exp);
    infixToPrefix(strrev(exp));
    return 0;
}

bool isEmpty()
{
    if(tos==-1)
    {
        return true;
    }else{
        return false;
    }
}

bool isFull()
{
    if(tos==MAX-1)
    {
        return true;
    }else{
        return false;
    }
}

char pop()
{
    int temp;
    if(isEmpty()==true)
    {
        printf("Error : Stack Underflow !");
        exit(1);
    }else{
        temp = stack[tos];
        tos--;
        return temp;
    }
}

void push(char ch)
{
    if(isFull()==true)
    {
        printf("Error : Stack Overflow !");
        exit(1);
    }else{
        tos++;
        stack[tos]=ch;
    }
}

int presidence(char ch)
{
    if(ch == '^' || ch=='$')
    {
        return 4;
    }else if(ch=='*'||ch=='/')
    {
        return 3;
    }else if(ch=='+'||ch=='-')
    {
        return 2;
    }else{
        return 1;
    }
}

void infixToPrefix(char *exp)
{
	int i,j=0;
	char temp;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]==')')
		{
			push(exp[i]);
		}else if(exp[i]=='/' ||exp[i]=='*' ||exp[i]=='+' ||exp[i]=='-' ||exp[i]=='$' ||exp[i]=='^')
		{
			if(isEmpty()==false)
			{
				if(presidence(stack[tos])>presidence(exp[i]))
				{
					temp = pop();
					push(exp[i]);
					postfix[j++]=temp;
				}else{
					push(exp[i]);
				}
			}
		}else if(exp[i]=='(')
		{
			while(stack[tos]!=')')
			{
				if(isEmpty()==false)
				{
					temp = pop();
				postfix[j++] = temp;	
				}
			
			}
			if(isEmpty()==false)
			{
			pop();	
			}
			
		}else{
			postfix[j++]=exp[i];
		}
	}
	postfix[j]='\0';
	printf("%s",strrev(postfix));
}