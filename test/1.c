#include <stdio.h>
#include <stdlib.h>
struct node {
	int num1;
	int num2;
	struct node *next;
} node;

int main(void) {
	struct node *Newnode = (struct node*)malloc(sizeof(node));
	for(int i = 0; i<10; i++) {
	//	struct node *Newnode = (struct node*)malloc(sizeof(node));
		Newnode->num1 =rand()%10;
		Newnode->num2 =rand()%10;
		Newnode->next = NULL;
		printf("%d 번째 num1 : %d, num2 : %d\n", i+1, Newnode->num1, Newnode->num2);
				}
	free(Newnode);
	return 0;
}
