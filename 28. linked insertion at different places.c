//Write a program with functions  to insert a new node at the beginning, at the end and after a specified element in a linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;

list *head = NULL;

void insertAtBeginning(){
    int num;
    printf("Enter the number you want to insert: ");
    scanf("%d", &num);

    if( head == NULL){
        head = (list *)malloc(sizeof(list));
        head -> data = num;
        head -> next = NULL;
    }
    else{
        list *t;
        t = (list *) malloc(sizeof(list));
        t -> data = num;
        t -> next = head;
        head = t;
    }
}

void insertAfterAnElement(int e){
    int num;
    printf("Enter the number you want to insert: ");
    scanf("%d", &num);

    if( head == NULL){
        head = (list *)malloc(sizeof(list));
        head -> data = num;
        head -> next = NULL;
    }
    else{
        list *t, *newNode;
        for( t = head; t != NULL && t -> data != e; t = t-> next);

        if( t == NULL){
            printf("\nElement Not Found\n");
        }

        newNode = (list*) malloc(sizeof(list));
        newNode -> data = num;
        newNode -> next = t -> next;
        t -> next = newNode;
        
        
    }
}
void insertAtEnd(){
    int num;
    printf("Enter the number you want to insert: ");
    scanf("%d", &num);
    if( head == NULL){
        head = (list *)malloc(sizeof(list));
        head -> data = num;
        head -> next = NULL;
    }
    else{
        list *t;
        for(t = head; t -> next != NULL; t = t-> next);
        t -> next = (list *) malloc(sizeof(list));
        t -> next -> data = num;
        t -> next -> next = NULL;
    }
}

void display(){
    if( head == NULL ){
        printf("\nEmpty Linked List\n");
    }
    else{
        list *t;
        for(t = head; t != NULL; t = t -> next){
            printf("%d -> ", t -> data);
        }
        printf("NULL");
    }
}

int main(){
    int choice, num;
    while (1)
    {
        printf("\n1. Insert At Beginning\n2. Insert After An Element\n3. Insert At End\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            printf("Enter the element after which you want to insert: ");
            scanf("%d", &num);
            insertAfterAnElement(num);
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
  
}