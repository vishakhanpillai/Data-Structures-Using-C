#include <stdio.h>
#include <stdlib.h>
int main(){

    int *ptr;
    int n, i;

    printf("Enter value for n: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for( i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    printf("The entered elements using malloc are: ");
    for( i = 0; i < n; i++){
        printf("%d \t", ptr[i]);
    }

    free(ptr);

    printf("\n\nEnter value for n: ");
    scanf("%d", &n);

    ptr = (int *) calloc (5, sizeof(int));

     printf("Enter the elements: ");
    for( i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    printf("The entered elements using calloc are: ");
    for( i = 0; i < n; i++){
        printf("%d \t", ptr[i]);
    }

    free(ptr);
    return 0;
}