#include <stdio.h>

typedef struct polynomial{
    int coeff;
    int exp;
} poly;

void readPoly(poly p[], int n){
    int i;
    for( i = 0; i < n; i++){
        printf("Enter the coefficent: ");
        scanf("%d", &p[i].coeff);
        printf("Enter the exponent: ");
        scanf("%d", &p[i].exp);
    }
}

void dispPoly(poly p[], int n){
    int i;
    for( i = 0; i < n; i++){
        printf("%dx^%d", p[i].coeff, p[i].exp);
        if( i != n -1 ){
            printf(" + ");
        }
    }
}


int main(){
    poly p[10];
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the polynomial: ");
    readPoly(p, n);

    printf("The Polynomial Is: ");
    dispPoly(p, n);

    return 0;
}
