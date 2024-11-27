#include <stdio.h>

int main(){
    int a[10], i, j, temp, n, key, flag = 0, low, mid = 0, end;

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

    for( i = 0; i < n; i++){
        for( j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("\nThe Sorted Array Is: \n");
    for( i = 0; i < n; i++){
        printf("%d\t", a[i]);
    }

    printf("\nEnter the element you want to search for: ");
    scanf("%d", &key);

    low = 0;
    end = n - 1;
    while(low <= end){
        mid = (low + end) / 2;
        if( a[mid] == key ){
            printf("Element Found at index %d", mid);
            flag = 1;
            break;
        }
        else if( key > a[mid]){
            low = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    
    if( flag == 0){
        printf("\nElement Not Found\n");
    }
    return 0;
}