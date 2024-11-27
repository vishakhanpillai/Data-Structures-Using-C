#include <stdio.h>
#include <string.h>

int main(){
    int n, i, j;
    char str[10][10], temp[50];
    
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    printf("Enter the strings: ");
    for( i = 0; i < n; i++){
        scanf("%s",str[i]);
    }

    printf("The Strings Are: ");
    for( i = 0; i < n; i++){
        printf("%s \t",str[i]);
    }

    for( i = 0; i < n; i++){
        for( j = i + 1; j < n; j++ ){
            if( strcmp(str[i], str[j]) > 0){
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nThe Sorted Strings Are: ");
    for( i = 0; i < n; i++){
        printf("%s \t",str[i]);
    }

    return 0;
}