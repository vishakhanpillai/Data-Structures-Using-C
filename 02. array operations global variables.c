#include <stdio.h>
int arr[10], max, n = -1;

void insert(int num){
    if( n + 1 == max){
        printf("\nArray Is Full\n");
    }
    else{
        arr[++n] = num;
    }
}

void display(){
    int i;
    for( i = 0; i < max; i++){
        printf("%d\t", arr[i]);
    }
}

void search(){
    int key, i, flag = 0;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    for( i = 0; i < max; i++){
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
    printf("The Sorted Array Is: ");
    display();
}

void delete(){
    int num, lim, i;
    printf("Enter the number you want to delete: ");
    scanf("%d", &num);
    for( i = 0; i < max; i++){
        if( arr[i] == num ){
            lim = i;
            for( i = lim; i < max; i++){
                    arr[i] = arr[i + 1];
            }
            break;
        }
    }
    max--;
}

int main(){
    int choice;
    int num;
    printf("Enter the size of the array: ");
    scanf("%d", &max);

    while(1){
        printf("\n1. Inser\n2. Display\n3. Sort\n4. Search\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to insert: ");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            printf("Your Array Is: ");
            display();
            break;
        case 3:
            sort();
            break;
        case 4:
            search();
            break;
        case 5:
            delete();
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
