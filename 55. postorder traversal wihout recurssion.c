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

void postorder(){
    
    tree *stack1[100], *stack2[100];
    int i = -1, j = -1;
    tree *current = root;

    stack1[++i] = current;
    while (i != -1)
    {
        current = stack1[i--];
        stack2[++j] = current;
        if(current -> left){
            stack1[++i] = current -> left;
        }
        if(current -> right){
            stack1[++i] = current -> right;
        }
    }

    while(j != -1){
        printf("%d\t", stack2[j--] -> data);
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

    postorder();
    return 0;
}