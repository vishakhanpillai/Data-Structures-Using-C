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
    int a[10][10], b[10][10], diff[10][10];
    int r, c, i, j;

    printf("Enter the row and col of the matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of first matrix: ");
    readMatrix(a, r, c);
    printf("Enter the elements of second matrix: ");
    readMatrix(b, r, c);

    printf("\nMatrix 1\n");
    dispMatrix(a, r, c);
    printf("\nMatrix 2\n");
    dispMatrix(b, r, c);

    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            diff[i][j] = a[i][j] - b[i][j];
        }
    }

    printf("\nThe Sum Is\n");
    dispMatrix(diff, r, c);

    return 0;
    
}