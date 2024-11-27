//Binary search tree insertion using names and display the names in ascending order using inorder traversal.

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node{
    char data[50];
    struct node *left;
    struct node *right;
}tree;

tree *root = NULL;

void insert( char name[]){
    if( root == NULL){
        root = (tree *)malloc(sizeof(tree));

        strcpy(root -> data, name);
        root -> left = NULL;
        root -> right = NULL;
    }
    else{
        tree *x, *p;

        x = root;
        while( x != NULL){
            p = x;
            if(strcmp(name, x -> data) > 0){
                x = x -> right;
            }
            else{
                x = x -> left;
            }
        }
        if(strcmp(name, p -> data) > 0){
            p -> right = (tree *)malloc(sizeof(tree));
            strcpy(p -> right -> data, name);
            p -> right -> left = NULL;
            p -> right -> right = NULL;
        }
        else{
            p -> left = (tree *)malloc(sizeof(tree));
            strcpy(p -> left -> data, name);
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
    printf("%s\t", node -> data);
    inorder(node -> right);
}

int main(){
    int n, i;
    char names[50];
    printf("Enter the number of names you want: ");
    scanf("%d", &n);

    printf("\nEnter the names: ");
    for( i = 0; i < n; i++){
        scanf("%s", names);
        insert(names);
    }

    printf("\nThe Names in Ascending Order are: ");
    inorder(root);

    return 0;

}