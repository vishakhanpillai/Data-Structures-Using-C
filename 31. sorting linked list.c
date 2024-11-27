#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} list;

list *head = NULL;
list *top = NULL;

void insert(int num){
    if( head == NULL){
        head = (list *) malloc(sizeof(list));
        head -> data = num;
        head -> next = NULL;
    }
    else{
        list *t;
        for( t = head; t -> next != NULL; t = t -> next);
        t -> next = (list*) malloc(sizeof(list));
        t -> next -> data = num;
        t -> next -> next = NULL;
    }
}

void display(){
    if( head == NULL ){
        printf("\nEmpty Linked List\n");
    }
    else{
        list *t;
        for(t = head; t != NULL; t = t -> next){
            printf("%d -> ", t -> data);
        }
        printf("NULL");
    }
}

void sort(){
    list *i, *j;
    for( i = head; i != NULL; i = i -> next){
        for( j = i ->next; j!= NULL; j = j -> next){
            if( i -> data > j -> data){
                int temp = i -> data;
                i -> data = j -> data;
                j -> data = temp;
            }
        }
    }
}

int main(){
    
    int n, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for( int i = 0; i < n; i++){
        printf("Enter element no %d: ", i + 1);
        scanf("%d", &num);
        insert(num);
    }

    printf("The Linked List Is: ");
    display();

    sort();
    printf("\nThe Linked List After Sort: ");
    display();

    return 0;
}