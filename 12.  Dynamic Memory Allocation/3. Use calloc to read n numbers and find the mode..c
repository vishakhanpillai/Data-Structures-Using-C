#include <stdio.h>
#include <stdlib.h>
int main(){

    int *a;
    int i, j, n, mode, count, maxCount = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int *) calloc(n, sizeof(int));

    printf("Enter the elemetns: ");
    for( i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for( i = 0; i < n; i++){
        count = 0;
        for( j = 0; j < n; j++){
            if( a[i] == a[j]){
                count++;
            }
        }

        if(count > maxCount){
            maxCount = count;
            mode = a[i];
        }
    }

    printf("The mode is: %d ", mode);
    return 0;
}