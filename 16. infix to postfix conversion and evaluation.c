#include <stdio.h>
#include <ctype.h>

int priority(char op){
    if(op == '*' || op == '/'){
        return 2;
    }
    else if(op == '+' || op == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

int operation(int a, int b, char op){
    if(op == '+'){
        return a + b;
    }
    else if( op == '-'){
        return a - b;
    }
    else if( op == '*'){
        return a * b;
    }
    else if( op == '/'){
        return a / b;
    }
    else{
        return 0;
    }
}


int main(){
    char stack[50], infix[50], postfix[50];
    int top = -1, i, j = -1;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    for( i = 0; infix[i] != '\0'; i++){
        if(isdigit(infix[i])){
            postfix[++j] = infix[i]; 
        }
        else if( infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if( infix[i] == ')'){
            while( top != -1 && stack[top] != '('){
                postfix[++j] = stack[top--];
            }
            top--;
        }
        else if( infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/'){
            while(top != -1 && priority(stack[top]) > infix[top]){
                postfix[++j] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while(top != -1){
        postfix[++j] = stack[top--];
    }
    postfix[++j] = '\0';

    printf("The Postfix Form Is: %s", postfix);

    int eval[50],  etop = -1, k;

    for( k = 0; postfix[k] != '\0'; k++){
        if(isdigit(postfix[k])){
            int num = postfix[k] - '0';
            eval[++etop] = num;
        }
        else if( postfix[k] == '+' || postfix[k] == '-' || postfix[k] == '*' || postfix[k] == '/'){
            int a = eval[etop--];
            int b = eval[etop--];
            char op = postfix[k];
            eval[++etop] = operation(b, a, op);
        }
    }

    printf("\nThe result is: %d", eval[etop]);

    return 0;
}