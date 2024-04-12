#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
int getop(char []);
void push(double);
double pop(void);


int main()
{
	int type;
	double op2;
	char =[MAXOP];

	while((type = getop(s) !=EOF) {
		switch(type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop()+pop());
			break;
		case '-':
			push(pop()-op2);
			break;
		case '*':
			push(pop()  pop());
			break;
		case '/':
			op2 = pop();
			if( op2 != 0.0)
				push(pop() / op2);
			else
				printf("error");
		case '\n':
			printf("\t%.8g\n", pop());
		default:
			printf("error:unknown commad %s\n", s);
			break;
		}
	}


