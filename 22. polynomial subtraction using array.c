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

    int poly1[10], poly2[10], sub[10], m, n, maxDegree, i;

    printf("\nEnter the degree of the first polynomial: ");
    scanf("%d", &m);
    printf("\nEnter the polynomial:\n");
    readPoly(poly1, m);
    printf("\nEnter the degree of the second polynomial: ");
    scanf("%d", &n);
    printf("\nEnter the polynomial:\n");
    readPoly(poly2, n);
    
    printf("\nThe First Polynomial Is: ");
    dispPoly(poly1, m);
    printf("\nThe Second Polynomial Is: ");
    dispPoly(poly2, n);

    if( m > n){
        maxDegree = m;
    }
    else{
        maxDegree = n;
    }
    
    for( i = 0; i <= maxDegree; i++){
        sub[i] = poly1[i] - poly2[i];
    }
    
    printf("\nThe Sum Is: ");
    dispPoly(sub, maxDegree);

    return 0;
}