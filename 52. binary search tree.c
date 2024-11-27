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

void inorder(tree *node){
    if( node == NULL){
        return;
    }
    inorder(node -> left);
    printf("%d\t", node -> data);
    inorder(node -> right);
}

void preorder(tree *node){
    if( node == NULL){
        return;
    }
    printf("%d\t", node -> data);
    preorder(node -> left);
    preorder(node -> right);
}

void postorder(tree *node){
    if( node == NULL){
        return;
    }
    postorder(node -> left);
    postorder(node -> right);
    printf("%d\t", node -> data);
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

    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

    return 0;
}