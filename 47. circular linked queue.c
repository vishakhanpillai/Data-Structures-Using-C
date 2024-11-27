#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}  queue;

queue *front = NULL;
queue *rear = NULL;

void enqueue(){
    queue *t;
    int num;
    printf("Enter the value you want to enter: ");
    scanf("%d", &num);

    t = (queue*)malloc(sizeof(queue));
    t -> data = num;
    t -> next = NULL;

    if(front == NULL){
        front = rear = t;
    }
    else{
        rear -> next = t;
        rear = rear -> next;
    }
    rear -> next = front;
}


void dequeue(){
    if( front == NULL ){
        printf("\nEmpty Circular Queue\n");
    }
    else{
        printf("\n%d had been dequeued\n", front -> data);
        if( front == rear){
            front = rear = NULL;
        }
        else{
            front = front -> next;
            rear -> next = front;
        }
    }
}

void display(){
    if( front == NULL){
        printf("\nEmpty Circular Queue\n");
    }
    else{
        queue *t;
        t = front;
        do{
            printf("%d -> ", t -> data);
            t = t -> next;
        }while(t != front);
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