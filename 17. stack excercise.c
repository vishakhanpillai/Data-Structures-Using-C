/*	
A letter means push and an asterisk means pop in the  following sequence. Give the sequence of values returned by the pop operations when this sequence of operations is performed on an initially empty LIFO stack.
Eg:  Input from user=>   E A S * Y * Q U E * * * S T * * * I O * N * * *
(Push the letters E,A,S and when you encounter an * pop S, again push y and at * pop Y…..)
*/

#include<stdio.h>
#include<ctype.h>

char stack[50];
int top = -1;

void push(char a){
    stack[++top] = a;
}

void pop(){
    printf("%c", stack[top]);
    top--;
}

int main(){
    char str[50];
    int i;

    printf("Enter the expression: ");
    scanf("%s", str);

    printf("The Sequence Is: ");
    for( i = 0; str[i] != '\0'; i++){
        if( str[i] == '*'){
            pop();
        }
        else{
            push(str[i]);
        }
    }

    return 0;    
}