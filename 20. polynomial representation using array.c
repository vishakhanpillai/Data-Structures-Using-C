#include <stdio.h>

void readPoly(int a[10], int n){
    int i;

    for( i = n; i >= 0; i--){
        printf(" enter x^%d term: ", i);
        scanf("%d", &a[i]);
    }
}

void dispPoly(int a[10], int n){
    int i;

    for( i = n; i >= 0; i--){
        printf(" %dx^%d", a[i], i);
        if(i != 0){
            printf(" + ");
        }
    }
}

int main(){

    int poly[10], n;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);

    printf("Enter the polynomial:\n");
    readPoly(poly, n);

    printf("\nThe Polynomial Is: ");
    dispPoly(poly, n);

    return 0;
}