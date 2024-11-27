#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}stack;

stack *top = NULL;

void push(){
    int n;
    printf("Enter the value you want to push: ");
    scanf("%d", &n);

    stack *t;
    t = (stack*)malloc(sizeof(stack));
    t -> data = n;
    t -> next = top;
    top = t;

    printf("\n%d has been pushed\n", n);
}

void pop(){
    if(top == NULL){
        printf("\nEmpty Stack!!\n");
    }
    else{
        printf("\n%d has been popped\n", top -> data);
        top = top -> next;
    }
}

void peek(){
    if(top == NULL){
        printf("\nEmpty Stack!!\n");
    }
    else{
        printf("\nTop Most Element Is %d\n", top -> data);
    }
}

void display(){
    stack *t;
    if(top == NULL){
        printf("\nEmpty Stack!!\n");
    }
    else{
        t = top;
        while(t != NULL){
            printf("%d\n", t -> data);
            t = t -> next;
        }
    }
}

int main(){
    int choice;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid Option");
            break;
        }
    }
    
}