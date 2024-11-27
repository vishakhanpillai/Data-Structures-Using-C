#include <stdio.h>
#include <ctype.h>
#include <string.h>

int priority(char ch){
    if( ch == '^'){
        return 3;
    }
    else if( ch == '*' || ch == '/'){
        return 2;
    }
    else if( ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

void reverse(char str[]){
    int len = strlen(str);
    int i, j;
    char temp;

    for( i = 0, j = len - 1; i < j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    for( i = 0; i < len - 1 ; i++){
        if(str[i] == '('){
            str[i] = ')';
        }
        else if(str[i] == ')'){
            str[i] = '(';
        }
    }
}


int main(){
    char stack[50], infix[50], prefix[50];
    int top = -1, i, j = -1;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    for( i = 0; infix[i] != '\0'; i++){
        if(isalnum(infix[i])){
            prefix[++j] = infix[i];
        }
        else if( infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if( infix[i] == ')'){
            while( top != -1 && stack[top] != '('){
                prefix[++j] = stack[top--];
            }
            top--;
        }
        else if( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
            while(top != -1 && priority(stack[top]) > priority(infix[i])){
                prefix[++j] = stack[top--];
            }
            stack[++top] = infix[i];
        }

    }

    while( top != -1){
        prefix[++j] = stack[top--];
    }
    prefix[++j] = '\0';

    reverse(prefix);
    printf("The Prefix of the expression is: %s", prefix);

    return 0;

}