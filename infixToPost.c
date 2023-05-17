#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 50
char stack[MAX];
char postexp[MAX];
int tos = -1;
char pop();
void push(char);
bool isEmpty();
bool isFull();
int presidence(char);
void pfix(char*);
void print();

int main()
{
	char str[MAX];
	printf("Enter your expression : ");
	gets(str);
	pfix(str);
	print(str);
}

bool isEmpty()
{
	if(tos == -1)
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
	char pop_ch;
	if(isEmpty()==true){
		printf("Error : Stack Underflow!!");
		exit(0);
	}else{
		pop_ch = stack[tos];
		tos--;
		return pop_ch;	
	}
}

void push(char ch)
{
	if(isFull()==true)
	{
		printf("Error : Stack Overflow !!");
		exit(0);
	}else{
		tos++;
		stack[tos]=ch;
	}
}

int presidence(char x){
	if(x=='^')
	{
		return 3;
	}else if(x=='*'||x=='/')
	{
		return 2;
	}else if(x=='+'||x=='-')
	{
		return 1;
	}else{
		return 0;
	}
}


void pfix(char*expr)
{
	int i,j=0;
	char ch;
	

	for(i=0;i<strlen(expr);i++)
	{
		ch = expr[i];
		
		if(ch=='(')
		{
			push(ch);
		}else if(ch==')')
		{
			while((ch=pop())!='(')
			{
				
				postexp[j] = ch;
//				printf("\n-pe[%d]--%c---\n",j,postexp[j]);
				j++;
			}
		}else if(ch=='*'||ch=='/'||ch=='^'||ch=='+'||ch=='-')
		{
			while(isEmpty()==false && presidence(stack[tos])>=presidence(ch))
			{
				postexp[j]=pop();
//				printf("\n-pe[%d]--%c---\n",j,postexp[j]);
				j++;
			}
			push(ch);
		}else{
			postexp[j++]=ch;
//			printf("\n-pe[%d]--%c---\n",j,ch);
	}
}
}

void print()
{
	int i;
	printf("\n Post-Expression: \n");
	
	for(i=0;i<strlen(postexp);i++)
	{
		
		 printf("%c",postexp[i]);	
		
		
	}
	
}