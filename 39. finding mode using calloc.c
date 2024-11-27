#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, i, j, count = 0, maxCount = 0, mode = 0;
    int *ptr;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    ptr = (int*)calloc(sizeof(int), n);

    printf("\nEnter the terms: ");
    for( i = 0; i < n; i++){
        scanf("%d", &ptr[i]);
    }

    for( i = 0; i < n; i++){
        count = 0;
        for(j = 0; j < n; j++){
            if(ptr[i] == ptr[j]){
                count++;
            }
        }

        if(count > maxCount){
            maxCount = count;
            mode = ptr[i];
        }
    }


    printf("\nThe Mode Is %d", mode);
    

    return 0;
}