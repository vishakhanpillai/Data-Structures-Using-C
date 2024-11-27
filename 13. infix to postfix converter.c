#include <stdio.h>
#include <ctype.h>

int priority(char ch){
	switch(ch){
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default :
		return 0;
	}
}

int main(){
    char stack[50], infix[50], postfix[50];
    int top = -1, i, j = -1;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    for( i = 0; infix[i] != '\0'; i++){
        if(isalnum(infix[i])){
            postfix[++j] = infix[i];
        }
        else if( infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if( infix[i] == ')'){
            while(stack[top] != '(' && top != -1){
                postfix[++j] = stack[top--];
            }
            top--;
        }
        else if( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^' ){
            while( top != -1 && priority(stack[top]) > priority(infix[i])){
                postfix[++j] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        else{
            printf("Invaid Expression");
            return 0;
        }
    }

    while(top != -1){
        postfix[++j] = stack[top--];
    }
    postfix[++j] = '\0';

    printf("The Postfix Form Is: %s", postfix);

    return 0;
    
}