#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}list;


list *head = NULL;

void insert(){
    int num;
    printf("Enter the value to insert: ");
    scanf("%d", &num);

    if( head == NULL ){
        head = (list*)malloc(sizeof(list));
        head -> data = num;
        head -> prev = NULL;
        head -> next = NULL;
    }
    else{
        list *t;
        for( t = head; t -> next != NULL; t = t -> next);
        t -> next = (list*)malloc(sizeof(list));
        t -> next -> data = num;
        t -> next -> prev = t;
        t -> next -> next = NULL;
    }
}

void delete(){
    if(head == NULL){
        printf("\nEmpty Doubly Linked List\n");
    }
    else{
        int num;
        printf("Enter the number you want to delete: ");
        scanf("%d", &num);

        if( head -> data == num && head -> next == NULL && head -> prev == NULL){
            head = NULL;
        }
        else if( head -> data == num){
            head = head -> next;
            head -> prev = NULL;
        }
        else{
            list *t;
            for( t = head; t -> next != NULL && t -> next -> data != num; t = t -> next);
            if( t -> next == NULL){
                printf("\nElement not found\n");
            }
            else if( t -> next -> next == NULL){
                t -> next = NULL;
            }
            else{
                t -> next = t -> next -> next;
                t -> next -> prev = t;
            }
        }
    }
}

void display(){
    if( head == NULL){
        printf("\nEmpty Doubly Linked List\n");
    }
    else{
        list *t;
        for( t = head; t != NULL; t = t-> next){
            printf("%d <-> ", t -> data);
        }
        printf(" NULL ");
    }
}

int main(){
    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}