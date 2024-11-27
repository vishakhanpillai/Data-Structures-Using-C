/*Declare a structure for Books having author_name and book_name. Create an array of books using a pointer variable. Provide functions for reading n books and displaying the same using pointers.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct books{
    char author[50];
    char bname[50];
}book;

void readBooks(book *b, int n){
    int i;
    for( i = 0; i < n; i++){
        printf("Enter book %d\n", i + 1);
        printf("Enter Author Name: ");
        scanf("%s", b[i].author);
        printf("Enter Book Name: ");
        scanf("%s", b[i].bname);
    }
}

void display(book *b, int n){
    int i;

    printf("\nAuthor\tBook\n");
    for( i = 0; i < n; i++){
        printf("%s\t%s\n", b[i].author, b[i].bname);
    }
}

int main(){

    int n;

    book *b;

    printf("Enter the number of books you want: ");
    scanf("%d", &n);

    b = (book*)malloc(sizeof(book) * n);

    readBooks(b, n);

    printf("\nThe Books Are\n");
    display(b, n);

    return 0;
}