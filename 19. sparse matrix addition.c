#include <stdio.h>

void readmatrix(int a[10][10], int r, int c){
    int i, j;
    for( i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void dispmatrix(int a[10][10], int r, int c){
    int i, j;
    for( i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int sparseMatrixConversion(int sparse[10][3], int a[10][10], int r, int c){
    int i, j, k = 0;
    for( i = 0; i < r; i++ ){
        for( j = 0; j < c; j++){
            if(a[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];
                k++;
            }
        }
    }
    return k;
}

void displaySparse(int sparse[10][3], int k){
    int i;
    printf("\nRow\tColumn\tvalue\n");
    for( i = 0; i < k; i++){
        printf("%d\t%d\t%d", sparse[i][0], sparse[i][1], sparse[i][2]);
        printf("\n");
    }
}



int main(){

    int a[10][10], b[10][10], sum[10][10], r, c, i, j;
    int sparse1[10][3], sparse2[10][3], sumSparse[10][3];
    int k1, k2, k3;
    printf("Enter the number of rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of matrix 1: ");
    readmatrix(a, r, c);
    printf("Enter the elements of matrix 2: ");
    readmatrix(b, r, c);

    printf("\nMatrix 1\n");
    dispmatrix(a, r, c);
    printf("\nMatrix 2\n");
    dispmatrix(b, r, c);

    
    k1 = sparseMatrixConversion(sparse1, a, r, c);
    k2 = sparseMatrixConversion(sparse2, b, r, c);

    printf("\nSparse Matrix Representation of Matrix 1:\n");
    displaySparse(sparse1, k1);
    printf("\nSparse Matrix Representation of Matrix 2:\n");
    displaySparse(sparse2, k2);

    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    k3 = sparseMatrixConversion(sumSparse, sum, r, c);
    printf("\nSparse Matrix Addition Representation:\n");
    displaySparse(sumSparse, k3);


    return 0;
}