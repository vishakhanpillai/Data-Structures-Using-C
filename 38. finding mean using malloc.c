#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, mean, sum = 0;
    int *ptr;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    ptr = (int*)malloc(sizeof(int) * n);

    printf("\nEnter the terms: ");
    for( i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    for( i = 0; i < n; i++){
        sum += ptr[i];
    }

    mean = sum / n;

    printf("The Mean Is %d", mean);

    return 0;
}