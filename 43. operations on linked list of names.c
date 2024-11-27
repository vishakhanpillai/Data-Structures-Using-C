#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data[50];
    struct node *next;
}list;

list *head = NULL;

void insert(){
    char name[50];
    printf("Enter the name to insert: ");
    scanf("%s", name);

    if(head == NULL){
        head = (list *) malloc(sizeof(list));
        strcpy(head -> data, name);
        head -> next = NULL;
    }
    else{
        list *t;
        for( t = head; t -> next != NULL; t = t -> next);
        t -> next = (list *)malloc(sizeof(list));
        strcpy(t -> next -> data, name);
        t -> next -> next = NULL;
    }
}

void delete(){
    if( head == NULL){
        printf("\nEmpty Linked List\n");
    }
    else{
        char name[50];
        printf("Enter the name to delete: ");
        scanf("%s", name);

        if( strcmp(head ->data, name) == 0 && head -> next == NULL){
            head = NULL;
        }
        else if( strcmp(head -> data, name) == 0){
            head = head -> next;
        }
        else{
            list *t;
            for(t = head; t -> next !=NULL && strcmp(t -> next -> data, name) != 0; t = t -> next);
            if( t -> next == NULL){
                printf("\nName Not Found\n");
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
        for( t = head; t != NULL; t = t -> next){
            printf("%s -> ", t -> data);
        }
        printf("NULL");
    }
}

void count(){
    list *t;
    int count = 0;
    for( t = head; t != NULL; t = t -> next){
        count++;
    }

    printf("\nCount is %d\n", count);
}

void reverse(list *node){
    if( node == NULL){
        return;
    }
    reverse(node -> next);
    printf("%s -> ", node -> data);
}

void sort(){

    printf("\nBefore Sort: ");
    display();
    list *i, *j;
    char temp[50];

    for( i = head; i != NULL; i = i -> next){
        for( j = i -> next; j != NULL; j = j -> next){
            if(strcmp(i ->data, j -> data) > 0){
                strcpy(temp, i -> data);
                strcpy(i -> data, j -> data);
                strcpy(j -> data, temp);
            }
        }
    }

    printf("\nAfter Sort: ");
    display();
}

int main(){

    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Sort\n5. Reverse\n6. Count\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            sort();
            break;
        case 5:
            reverse(head);
            printf("NULL");
            break;
        case 6:
            count();
            break;
        case 7:
            return 0;
            break;
        default:
            printf("Invalid Choice!!!");
            break;
        }
    }
    
    return 0;
}