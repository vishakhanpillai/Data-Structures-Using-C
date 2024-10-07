#include <stdio.h>
#include <stdlib.h>
int main(){

    int *ptr;
    int n, i, mean, sum = 0;

    printf("Enter the no of elements: ");
    scanf("%d", &n);
    
    ptr = (int *) malloc( n * sizeof(int));

    printf("Enter the numbers: ");
    for( i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    for( i = 0; i < n; i++){
        sum = sum + ptr[i];
    }

    mean = sum / n;

    printf("The Mean Is %d", mean);

    free(ptr);

    return 0;
}