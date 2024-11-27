#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n, i;
    int *p;

    printf("Enter value for n: ");
    scanf("%d", &n);

    p = (int *)malloc(sizeof(int) * n);

    printf("Enter the values: ");
    for( i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    printf("\nThe values entered using malloc are: ");
    for ( i = 0; i < n; i++)
    {
        printf(" %d\t", p[i]);
    }

    free(p);

    printf("\nEnter another value for n: ");

    p = (int *)calloc(sizeof(int), n);
    scanf("%d", &n);

    printf("\nEnter the values: ");
    for( i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }

    printf("\nThe values entered using calloc are: ");
    for ( i = 0; i < n; i++)
    {
        printf(" %d\t", p[i]);
    }

    free(p);

    return 0;
    
}