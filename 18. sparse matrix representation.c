#include <stdio.h>

int main(){
    int a[10][10], r, c, sparse[10][3], i, j, k = 0;

    printf("Enter the number of rows and cols: ");
    scanf("%d %d", &r, &c);

    printf("Enter the matrix elements: ");
    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("The matrix is\n");
    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for( i = 0; i < r; i++){
        for( j = 0; j < c; j++){
            if(a[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = a[i][j];
                k++;
            }
        }
    }

    printf("Sparse Matrix Representaion\n");
    printf("Row\tColumn\tValue\n");
    for( i = 0; i < k; i++){
        printf("%d\t%d\t%d", sparse[i][0], sparse[i][1], sparse[i][2]);
        printf("\n");
    }
}
