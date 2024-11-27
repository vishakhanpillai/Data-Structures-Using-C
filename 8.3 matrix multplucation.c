#include <stdio.h>

void readMatrix(int a[10][10], int r, int c){
    int i, j;
    for(i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void dispMatrix(int a[10][10], int r, int c){
    int i, j;
    for(i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int a[10][10], b[10][10], prod[10][10], i, j, k, r1, r2, c1, c2;
    printf("Enter the row and col of matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the row and col of matrix 2: ");
    scanf("%d %d", &r2, &c2);

    if(c2 != r1){
        printf("Matrix Multiplication Is not possible!!!");
        return 0;
    } 
    else{
        printf("Enter the elements of matrix 1: ");
        readMatrix(a, r1, c1);
        printf("Enter the elements of matrix 2: ");
        readMatrix(b, r2, c2);
        printf("\nMatix 1\n");
        dispMatrix(a, r1, c1);
        printf("\nMatix 2\n");
        dispMatrix(b, r2, c2);

        for( i = 0; i < r1; i++){
            for( j = 0; j< c2; j++){
                prod[i][j] = 0;
                for( k = 0; k < r2; k++){
                    prod[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        printf("The product is\n");
        dispMatrix(prod, r1, c2);

    }
}