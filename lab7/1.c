#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 100
#define MAXWORD 100
char buf[BUFSIZE];
int bufp = 0;
typedef struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
} tnode;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(FILE *, char *, int);
struct tnode *talloc(void);

int main() {
	struct tnode *root;
	char word[MAXWORD];
	FILE *fp;
	
	root = NULL;
	fp = fopen("alice.txt","r");
	if (fp == NULL) {
		fprintf(stderr, "Error. can't open file");
		return 1;
		}
	while(getword(fp, word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	printf("\n");
	fclose(fp);
	return 0;
}
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if(p == NULL) {
		p = talloc();
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if((cond = strcmp(w, p->word)) ==0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else 
		p->right = addtree(p->right, w);
	return p;
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
void treeprint(struct tnode *p)
{
	if (p !=NULL) {
		treeprint(p->left);
		static int count = 0;
		printf("%4d %s ", p->count, p->word);
		count++;
		if(count % 6 == 0) {
			printf("\n");
		
		}
		treeprint(p->right);
	}
}
int getword(FILE *fp, char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getc(fp)))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for( ; --lim> 0; w++)
		if (!isalnum(*w = getc(fp))) {
			ungetc(*w, fp);
			break;
		}
	*w = '\0';
	return word[0];
}

