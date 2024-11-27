#include <stdio.h>



void init(int a[10][10], int n){
    int i, j;
    for( i = 0; i < n; i++){
        for( j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
}

void adjacency(int arr[10][10], int i, int j){
    arr[i][j] = 1;
    arr[j][i] = 1;
}


int main(){
    
    int e, i, j, a, b, am[10][10];
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the number of edges: ");
    scanf("%d", &e);

    init(am, n);

    printf("\nEnter the edges:\n");
    for( i = 0; i < e; i++){
        printf("Enter edge %d: ", i + 1);
        scanf("%d %d", &a, &b);
        adjacency(am, a, b);
    }

    printf("\nThe Adjacency Matrix Is:\n");
    for( i = 0; i < n; i++){
        printf("%d   ", i);
        for( j = 0; j < n; j++){
            printf("%d ", am[i][j]);
        }
        printf("\n");
    }

    return 0;


}