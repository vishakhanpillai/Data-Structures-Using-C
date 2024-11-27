#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;


list *head = NULL;

void insert(){
    int num;
    printf("Enter the value you want to enter: ");
    scanf("%d", &num);

    if( head == NULL ){
        head = (list *) malloc(sizeof(list));
        head -> data = num;
        head -> next = head;
    }
    else{
        list *t;
        for( t = head; t -> next != head; t = t -> next);
        t ->next = (list*) malloc(sizeof(list));
        t -> next -> data = num;
        t -> next -> next = head;
    }
}


void delete(){
    
    if( head == NULL ){
        printf("\nEmpty Linked List\n");
    }
    else{
        int num;
        printf("Enter the number you want to delete: ");
        scanf("%d", &num);

        list *t;

        if( head -> data == num && head -> next == head){
            head = NULL;
        }
        else if( head -> data == num){
            for( t = head; t -> next != head; t = t -> next);
            t -> next = t -> next -> next;
            head = head -> next;
        }
        else{
            for( t = head; t -> next != head && t -> next -> data != num; t = t-> next);
            if( t -> next == NULL){
                printf("\nElement not found\n");
            }
            else{
                t -> next = t -> next -> next;
            }
        }
    }
}

void display(){
    if( head == NULL){
        printf("\nEmpty Linked List\n");
    }
    else{
        list *t;

        t = head;
        do{
            printf("%d -> ", t -> data);
            t = t -> next;
        }while( t != head);
        printf("NULL");
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