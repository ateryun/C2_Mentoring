#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root) {
	int num = root->num;
	root->left = (Node *)malloc(sizeof(Node));
	root->left->num = 2*num+1;
	root->left->left = root->left->right = NULL;
	
	root->right = (Node *)malloc(sizeof(Node));
	root->right->num = 2*num+2;
	root->right->left = root->right->right = NULL;
	
	return root;
} 
void print_tree(Node *root) {
	printf("%d\n", root->left->num);
	printf("%d\n", root->right->num);
	}
void free_all(Node *root) {
	if(root == NULL)
		return;
	if (root->left !=NULL) {
		free_all(root->left);
		}
	if(root->right !=NULL) {
		free_all(root->right);
		}
	free(root);
	}
int main(void) {
    Node *root =(Node *)malloc(sizeof(Node));
    root->num = 0;
    root->left = root->right = NULL;
    
    insert(root);
    insert(root->left);
    insert(root->right);
    printf("%d\n", root->num);
    print_tree(root);
    print_tree(root->left);
    print_tree(root->right);
    
    free_all(root);
    
    return 0;
}

