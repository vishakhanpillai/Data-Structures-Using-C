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
    int a[10][10], r, c,det = 0;
    printf("Enter the rows and cols of the matrix: ");
    scanf("%d %d", &r, &c);
    if( r != c){
        printf("Determinant Cannot Be Calculated");
        return 0;
    }
    else{
        printf("Enter the elements of the matrix\n");
        readMatrix(a, r, c);
        printf("The Matrix Is\n");
        dispMatrix(a, r, c);

        if( r == 2 && c == 2){
            det = (a[0][0] * a[1][1]) - (a[1][0] * a[0][1]);
        }
        else if( r == 3 && c == 3 ){
            det += (a[0][0] * ((a[1][1] * a[2][2]) - (a[2][1] * a[1][2])));
            det -= (a[0][1] * ((a[1][0] * a[2][2]) - (a[2][0] * a[1][2])));
            det += (a[0][2] * ((a[1][0] * a[2][1]) - (a[2][0] * a[1][1])));
        }
    }

    printf("The Determinant of the matrix is: %d", det);

}

