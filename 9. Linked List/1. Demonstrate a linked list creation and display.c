#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} link;

link *head = NULL;

void insert( int n ){
    link *t;
    if( head == NULL){
        head = (link *) malloc(sizeof(link));
        head -> data = n;
        head -> next = NULL;
    }
    else{
        t = head;
        while( t -> next != NULL){
            t = t -> next;
        }
        t -> next = (link *) malloc(sizeof(link));
        t -> next -> data = n;
        t -> next -> next = NULL;
    }
}

void display(){
    link *t;
    if( head == NULL ){
        printf("\n\nList is Empty\n\n");
    }
    else{
        t = head;
        while( t != NULL ){
            printf("%d\t", t -> data);
            t = t -> next; 
        }
    }

}

int main(){

    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Display\n3. Exit\n");
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
            printf("\nGoodBye!!\n");
            return 0;
        }
    }
    
    

}