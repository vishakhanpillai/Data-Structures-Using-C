#include <stdio.h>

int a = 10;

void globalvariables(){
    printf("\nDemonstrating Global Variables\n");
    printf("Value of 'a' decalred as Global Variable Is %d", a);
}

void localVariable(){
    int a = 20;
    printf("\nDemonstrating Global Variables\n");
    printf("Value of 'a' declared as Local Variable Is %d", a);
}

void staticVariable(){
    static int y = 10;
    int i;
    printf("\nDemonstrating Static Variables\n");

    for( i = 0 ; i < 5; i++){
        printf("%d\t", y);
        y++;
    }
}

void registerVariable(){
    register int i;
    printf("\nDemonstating Register Variable\n");
    for( i = 0; i < 5;i++){
        printf("%d\t", i);
    }
}

int main(){
    globalvariables();
    localVariable();
    staticVariable();
    registerVariable();

    return 0;
}
