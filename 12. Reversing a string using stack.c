#include <stdio.h>

char stack[50];
int top = -1;


void push(char n){
    stack[++top] = n;
}

void pop(){
    printf("%c", stack[top]);
    top--;
}

int main(){
    char str[20];
    int i;

    printf("Enter the string: ");
    scanf("%s", str);

    for( i = 0; str[i] != '\0'; i++){
        push(str[i]);
    }

    printf("The Reverse of the string is: ");
    while (top != -1)
    {
        pop();
    }

    return 0;
    
}