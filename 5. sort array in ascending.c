#include <stdio.h>
int arr[10], max;


void read(){

    for( int i = 0; i < max; i++){
        scanf("%d", &arr[i]);
    }

}

void disp(){
    
    for( int i = 0; i < max; i++){
        printf("%d \t", arr[i]);
    }
}

void sort(){
    int i, j, temp;
    for( i = 0; i < max; i++){
        for( j = i + 1; j < max; j++){
            if( arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nThe Sorted Array Is: ");
    disp();
}

int main(){
    printf("Enter the size of the array: ");
    scanf("%d", &max);

    read();
    printf("\nThe array elements are: ");
    disp();

    sort();

    return 0;
}