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
    if( op == '+'){
        return a + b;
    }
    else if( op == '-'){
        return a - b;
    }
    else if( op == '*'){
        return a * b;
    }
    else if( op ==  '/'){
        return a / b;
    }
    else{
        return 0;
    }
}

int evaluation(char exp[]){
    int values[50], top = -1, j = -1, i;
    char operand[50];
    int num;

    for( i = 0; exp[i] != '\0'; i++){
        if(isdigit(exp[i])){
            num = exp[i] - '0';
            values[++top] = num;
        }
        else if( exp[i] == '('){
            operand[++j] = exp[i];
        }
        else if( exp[i] == ')'){
            while( j != -1 && operand[j] != '('){
                int a = values[top--];
                int b = values[top--];
                char op = operand[j--];
                values[++top] = operation(b, a, op);
            }
            j--;
        }
        else{
            while( j != -1 && priority(operand[j]) >= priority(exp[i])){
                int a = values[top--];
                int b = values[top--];
                char op = operand[j--];
                values[++top] = operation(b, a, op);
            }
            operand[++j] = exp[i];
        }
    }

    while( j != -1){
        int a = values[top--];
        int b = values[top--];
        char op = operand[j--];
        values[++top] = operation(b, a, op);
    }

    return values[top];
}


int main(){
    char infix[30];
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    int result = evaluation(infix);

    printf("The Result Is: %d", result);

    return 0;
}


