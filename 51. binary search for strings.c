#include <stdio.h>
#include <string.h>

int main(){
    int  i, j, n, flag = 0, low, mid = 0, end;
    char str[50][50], temp[50], key[50];

    printf("Enter the number of elements you want in your array: ");
    scanf("%d", &n);

    printf("\nEnter the array elements: ");
    for( i = 0; i < n; i++){
        scanf("%s", str[i]);
    }

    printf("\nThe Array Is: \n");
    for( i = 0; i < n; i++){
        printf("%s\t", str[i]);
    }

    for( i = 0; i < n; i++){
        for( j = i + 1; j < n; j++){
            if(strcmp(str[i], str[j]) > 0){
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nThe Sorted Array Is: \n");
    for( i = 0; i < n; i++){
        printf("%s\t", str[i]);
    }

    printf("\nEnter the element you want to search for: ");
    scanf("%s", key);

    low = 0;
    end = n - 1;
    while(low <= end){
        mid = (low + end) / 2;
        if( strcmp(key, str[mid]) == 0 ){
            printf("Element Found at index %d", mid);
            flag = 1;
            break;
        }
        else if( strcmp(key, str[mid]) > 0 ){
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