#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} queue;

queue *front = NULL;
queue *rear = NULL;

void enqueue(){
    int num;
    printf("Enter the number you want to enqueue: ");
    scanf("%d", &num);
    
    queue *t;
    t = (queue*)malloc(sizeof(queue));
    t -> data = num;
    t -> next = NULL;
    if(front == NULL){
        front = t;
    }
    else{ 
        rear -> next = t;
    }
    rear = t;
}

void dequeue(){
    if(front == NULL){
        printf("\nQueue Is Empty\n");
    }
    else{
        printf("\n%d has been dequeud\n", front -> data);
        if( front == rear ){
            front = NULL;
            rear = NULL;
        }
        else{
            front = front -> next;
        }
    }
}

void display(){
    if( front == NULL){
        printf("\nQueue Is Empty\n");
    }
    else{
        queue *t;
        for( t = front; t != NULL; t = t -> next){
            printf("%d ", t -> data);
        }
    }
}


int main(){
    int choice;
     while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Option");
            break;
        }
    }
}