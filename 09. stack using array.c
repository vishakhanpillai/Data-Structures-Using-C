#include <stdio.h>
int stack[5], top = -1;

void push(){
    if( top + 1 == 5){
        printf("\nStack Overflow\n");
    }
    else{
        int num;
        printf("Enter the number you want to push: ");
        scanf("%d", &num);
        stack[++top] = num;
        printf("\n%d has been pushed to the stack\n", num);
    }
}

void pop(){
    if(top == -1){
        printf("\nStack UnderFlow\n");
    }
    else{
        printf("\n%d has been popped\n", stack[top]);
        top--;
    }
}

void peek(){
    if(top == -1){
        printf("\nStack Underflow\n");
    }
    else{
        printf("\nThe top element is %d\n", stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("\nStack Underflow\n");
    }
    else{
        int i = top;
        printf("\nStack Elements are: \n");
        while (i != -1)
        {
            printf("%d\n", stack[i]);
            i--;
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
