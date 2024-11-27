#include <stdio.h>

int insert(int arr[], int max, int n){
    if( n + 1 == max){
        printf("\nArray Is Full\n");
    }
    else{
        int num;
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        arr[++n] = num;
    }
    return n;
}

void display(int arr[], int n){
    if( n == -1){
        printf("\nEmpty Array\n");
    }
    else{
        int i;
        for(i = 0; i <= n; i++){
            printf("%d\t", arr[i]);
        }
    }
}

void search(int arr[], int n){
    int key, i, flag = 0;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    for( i = 0; i <=n; i++){
        if( arr[i] == key ){
            printf("Element Found At Index %d", i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Element Not Found");
    }
}

void sort(int arr[], int n){
    int i, j, temp;
    for( i = 0; i <=n; i++){
        for( j = i + 1; j <=n; j++){
            if( arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The Sorted Array Is: ");
    display(arr, n);
}

int delete(int arr[], int n){
    int num, lim, i;
    printf("Enter the number you want to delete: ");
    scanf("%d", &num);
    for( i = 0; i <= n; i++){
        if( arr[i] == num ){
            lim = i;
            for( i = lim; i <= n; i++){
                    arr[i] = arr[i + 1];
            }
            break;
        }
    }
    n--;
    return n;
}

int main(){
    int n = -1;
    int choice, arr[10], max;
    printf("Enter the size of the array: ");
    scanf("%d", &max);
     while(1){
        printf("\n1. Inser\n2. Display\n3. Sort\n4. Search\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            n = insert(arr, max, n);
            break;
        case 2:
            printf("Your Array Is: ");
            display(arr, n);
            break;
        case 3:
            sort(arr, n);
            break;
        case 4:
            search(arr, n);
            break;
        case 5:
            n  = delete(arr, n);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid Option");
            break;
        }
    }
    return 0;

}
