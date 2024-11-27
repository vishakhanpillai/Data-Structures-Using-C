#include <stdio.h>

int queue[5], front = -1, rear = -1;

void enqueue(){
    if((rear + 1) % 5 == front){
        printf("\nCircular queue is full\n");
    }
    else{
        int num;
        printf("Enter the number you want to insert: ");
        scanf("%d", &num);
        if( front == -1){
            front = 0;
        }
        rear = (rear + 1) % 5;
        queue[rear] = num;
    }
}

void dequeue(){
    if(front == -1){
        printf("\nEmpty Circular Queue\n");
    }
    else{
            printf("%d is dequeued", queue[front]);
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front + 1) % 5;
            }       
        
    }
}

void display(){
    int i;
    if( front == -1){
       printf("\nEmpty Queue\n"); 
    }
    else{
        printf("\nQueue Elements Are: ");
        for( i = front; i != rear; i = (i + 1) % 5){
            printf("%d\t", queue[i]);
        }
        printf("%d", queue[rear]);
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