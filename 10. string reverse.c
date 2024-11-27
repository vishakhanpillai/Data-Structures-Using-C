#include <stdio.h>

int main(){
    char str[50], temp;
    int i, len, j;

    printf("Enter the string: ");
    scanf("%s", str);

    

    for( i = 0; str[i] != '\0'; i++);
    len = i;
    printf("The String Is: %s of length %d", str, len);

    printf("\nThe Reverse of the string by printing in reverse order: ");
    for( i = len - 1; i >= 0; i--){
        printf("%c", str[i]);
    }
    
    for( i = 0, j = len - 1; i < j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    

    printf("\nThe Reverse of the string by sorting it in the same array: %s", str);
    return 0;
}