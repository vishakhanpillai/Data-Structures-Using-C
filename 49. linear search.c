#include <stdio.h>

int main(){
    int a[10], i, n, key, flag = 0;

    printf("Enter the number of elements you want in your array: ");
    scanf("%d", &n);

    printf("\nEnter the array elements: ");
    for( i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("\nThe Array Is: \n");
    for( i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }

    printf("\nEnter the element you want to search for: ");
    scanf("%d", &key);

    for( i = 0; i < n; i++){
        if( key == a[i] ){
            printf("Element Found At Index %d", i);
            flag = 1;
            break;
        }
    }

    if( flag == 0){
        printf("\nElement Not Found\n");
    }
    return 0;
}