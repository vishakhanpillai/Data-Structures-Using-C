#include <stdio.h>
#include <stdio.h>
int arr[10], max;


void read(){
    printf("Enter the array elements: ");
    for( int i = 0; i < max; i++){
        scanf("%d", &arr[i]);
    }
}

void disp(int start){
    
    if(start == -1){
        return;
    }
    else{
        printf("%d\t", arr[start]);
        disp(start - 1);
    }
}


int main(){
    printf("Enter the size of the array: ");
    scanf("%d", &max);
    int start = max - 1;
    read();
    printf("\nThe array elements are: ");
    disp(start);


    return 0;
}
