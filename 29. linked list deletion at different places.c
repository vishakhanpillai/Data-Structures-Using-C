//Write a program with functions to delete a new node from the beginning, from the end and after a specified element in a linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} list;

list * head = NULL;

void insert(int num){
    if( head == NULL){
        head = (list *) malloc(sizeof(list));
        head -> data = num;
        head -> next = NULL;
    }
    else{
        list *t;
        for( t = head; t -> next != NULL; t = t -> next);
        t -> next = (list*) malloc(sizeof(list));
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

void deleteAtFirst(){
    if( head == NULL){
        printf("\nEmpty Linked List\n");
    }
    else{
        head = head -> next;
    }
}

void deleteAtLast(){
    if( head == NULL){
        printf("\nEmpty Linked List\n");
    }
    else{
      list *t;
      for( t = head; t -> next -> next != NULL; t = t -> next);
      t -> next = NULL;
    }
}

void deleteAfterSpecificElement(int n){
    if( head == NULL){
        printf("\nEmpty Linked List\n");
    }
    else{
        list *t;
        for( t = head; t != NULL && t -> data != n; t = t -> next);
        t -> next = t -> next -> next;
    }
}

int main(){
    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Delete First\n4. Delete Last\n5. Delete After  a Specific Element\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int n;
            printf("Enter the value you want to insert: ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            display();
            break;
        case 3:
            deleteAtFirst();
            break;
        case 4:
            deleteAtLast();
            break;
        case 5:
            int num;
            printf("Enter the value after which you want to delete: ");
            scanf("%d", &num);
            deleteAfterSpecificElement(num);
            break;
        case 6:
            printf("\nGoodBye!!\n");
            return 0;
        }
    }  

}