#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}tree;

tree *root = NULL;

void insert(int n){
    if( root == NULL){
        root = (tree*) malloc(sizeof(tree));
        root -> data = n;
        root -> left = NULL;
        root -> right = NULL;
    }
    else{
        tree *x, *p;

        x = root;
        while( x != NULL){
            p = x;

            if( n > x-> data){
                x = x -> right;
            }
            else{
                x = x -> left;
            }
        }

        if( n > p -> data){
            p -> right = (tree*) malloc(sizeof(tree));
            p -> right -> data = n;
            p -> right -> left = NULL;
            p -> right -> right = NULL;
        }
        else{
            p -> left = (tree*) malloc(sizeof(tree));
            p -> left -> data = n;
            p -> left -> left = NULL;
            p -> left -> right = NULL;
        }

    }
}

void preorder(){
    
    tree *stack[100];
    int top = -1;
    tree *current = root;
    printf("\nPreorder: ");
    while( current != NULL || top != -1){
        while( current != NULL){
            printf("%d\t", current -> data);
            stack[++top] = current;
            current = current -> left;
        }
        current = stack[top--];
        current = current -> right;
    }
    
}

int main(){
    int num, n, i;

    printf("Enter the number of elements you want in your tree: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for( i = 0; i < n; i++){
        scanf("%d", &num);
        insert(num);
    }

    preorder();
    return 0;
}