#include <stdio.h>
int main(){
    int arr[10], i, n, count = 0, key;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("Enter the array elements: ");
    for( i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element who's occurence you want to find: ");
    scanf("%d", &key);

    for( i = 0; i < n; i++){
        if(arr[i] == key){
            printf("\nThe element %d occurs at index %d", key, i);
            count++;
        }
    }

    printf("\n\nThe element %d occurs a total of %d times", key, count);

    return 0;   
}
