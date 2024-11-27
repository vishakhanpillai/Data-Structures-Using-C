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
    int a[10][10], r, c, i, j;
    printf("Enter the rows and cols of the matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter the matrix elements\n");
    readMatrix(a, r, c);
    printf("\nThe Matrix Is\n");
    dispMatrix(a, r, c);

    printf("The Traspose Is\n");
    for( i = 0; i < c; i++){
        for( j = 0; j < r; j++){
            printf("%d\t", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}