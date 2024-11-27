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

int addPoly(poly p1[], int m, poly p2[], int n, poly sum[]){
    int i =0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if(p1[i].exp > p2[j].exp){
            sum[k++] = p1[i++];
        }
        else if(p1[i].exp < p2[j].exp){
            sum[k++] = p1[j++];
        }
        else{
            sum[k].coeff = p1[i].coeff + p2[j].coeff;
            sum[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
        
    }

    while (i < m)
    {
        sum[k++] = p1[i++];
    }
    while (j < n)
    {
        sum[k++] = p2[j++];
    }
    
    return k;
    
}


int main(){
    poly p1[10], p2[10], sum[10];
    int m, n, k;
    printf("Enter the number of terms of first polynomial: ");
    scanf("%d", &m);

    printf("\nEnter the polynomial: ");
    readPoly(p1, m);

    printf("Enter the number of terms of second polynomial: ");
    scanf("%d", &n);

    printf("\nEnter the polynomial: ");
    readPoly(p2, n);

    printf("\nThe First Polynomial Is: ");
    dispPoly(p1, m);

    printf("\nThe Second Polynomial Is: ");
    dispPoly(p2, n);

    k = addPoly(p1, m, p2, n, sum);

    printf("\nThe Sum Is: ");
    dispPoly(sum, k);

    return 0;
}
