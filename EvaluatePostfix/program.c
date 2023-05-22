/*
Evalute Postfix Expression 

*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

int tos = -1;
int stack[MAX];
char postfix[MAX];
int eval;
void push(int);
int pop();
int charToInt(char);
int postEval(char*);


int main()
{
	char exp[MAX];
	printf("Enter your POSTFIX expression : ");
	gets(exp);
	printf("%d",postEval(exp));
	
	
	return 0;
}

void push(int digit)
{
	if(tos == MAX-1)
	{
		printf("Error : Stack Overflow !!");
		exit(1);
	}else{
		tos++;
		stack[tos]=digit;
	}
}

int pop()
{
	int temp;
	if(tos==-1)
	{
		printf("Error : Stack Underflow !!");
		exit(1);
	}else{
		temp = stack[tos];
		tos--;
		return temp;
	}
}

int charToInt(char ch)
{
	int num;
	if(ch>='0' && ch<='9')
	{
		return (ch-48);
	}else{
		printf("%c Invalid Conversion to Int !",ch);;
		exit(1);
	}
	
}


int postEval(char* exp)
{
	int i,A,B,result;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
		{
			push(charToInt(exp[i]));
			printf("\n--Push(%d)--\n",stack[tos]);
				
		}else{
			if(tos>-1)
			{
				A=pop();
				B=pop();
			switch(exp[i])
			{
				case '+':
					result = B+A;
					push(result);
					printf("\n--Push(%d)--\n",stack[tos]);
				
					break;
				case '-':
					result = B-A;
					push(result);
					printf("\n--Push(%d)--\n",stack[tos]);
					break;
				case '*':
					result = B*A;
					push(result);
					printf("\n--Push(%d)--\n",stack[tos]);
					break;
				case '/':
					result = B/A;
					push(result);
					printf("\n--Push(%d)--\n",stack[tos]);
					break;
				case '^':
					result = pow(B,A);
					push(result);
					printf("\n--Push(%d)--\n",stack[tos]);
					break;
				case '$':
					result = pow(B,A);
					push(result);
					printf("\n--Push(%d)--\n",stack[tos]);
					break;
			}
			}
			
			}

	}
	return pop();
}



