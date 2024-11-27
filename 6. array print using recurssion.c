#include <stdio.h>
int arr[10], max;


void read(){
    printf("Enter the array elements: ");
    for( int i = 0; i < max; i++){
        scanf("%d", &arr[i]);
    }
}

void disp(int start){
    
    if( start >= max ){
        return;
    }
    else{
        printf("%d ", arr[start]);
        disp(start + 1);
    }
}


int main(){
    printf("Enter the size of the array: ");
    scanf("%d", &max);

    read();
    printf("\nThe array elements are: ");
    disp(0);


    return 0;
}