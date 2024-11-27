#include <stdio.h>

void heapify( int arr[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if( largest != i ){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n){
    int i;
    for( i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for( i = n - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main(){
    int i, n, arr[10];
    printf("Enter the number of elements you want in your array: ");
    scanf("%d", &n);

    printf("Enter your elements: ");
    for( i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("\nArray before sort: ");
    for( i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }

    heapsort(arr, n);

    printf("\nArray After sort: ");
    for( i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }

    return 0;
}