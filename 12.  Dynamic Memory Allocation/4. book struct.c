#include <stdio.h>
#include <stdlib.h>

typedef struct books{
    char author[50];
    char book_name[50];
} b;

void readBooks(b *books, int n){
    int i;
    for( i = 0 ; i < n; i++){
        printf("Enter the author name of books %d: ", i+ 1);
        scanf("%s", books[i].author);
        printf("Enter the name of the book: ");
        scanf("%s", books[i].book_name); 
    }
}


void displayBooks(b *books, int n){
    int i;
    for( i = 0; i < n; i++){
        printf("Book Name: %s", books[i].book_name);
        printf("\nAuthor Name: %s", books[i].author);
        printf("\n");
    }
}
 
int main(){
    int n;

    printf("Enter the no of books: ");
    scanf("%d", &n);

    b *ptr;

    ptr = (b *) malloc( n * sizeof(b));

    readBooks(ptr, n);
    displayBooks(ptr,n);

    free(ptr);

    return 0;
}
