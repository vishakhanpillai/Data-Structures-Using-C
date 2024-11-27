#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int i, int j){
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapify(int heap[], int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && heap[left] > heap[largest]){
        largest = left;
    }

    if(right < n && heap[right] > heap[largest]){
        largest = right;
    }

    if(largest != i){
        swap(largest,i);
        heapify(heap, n, largest);
    }
}

void insert(int value) {
    if (size == MAX) {
        printf("Heap overflow! Cannot insert more elements!\n");

        return;
    }
    heap[size] = value;
    size++;
    int i = size - 1;
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

int extractMax(){
    if(size <= 0){
        printf("Heap underflow! no elements to extract!");
        return -1;
    }
    if(size == 1){
        size--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(heap,size,0);
    return root;
}

void display(){
    if(size == 0){
        printf("Priority queue is empty!!!!");
        return;
    }
    printf("Priority Queue: \n");

    int i;
    for(i = 0 ; i < size; i++){
        printf("%d \t",heap[i]);
    }
    printf("\n");
}

int main(){
    int choice, value;
    while(1){
        printf("\nPriority Queue using heap:\n");
        printf("1. Insert \n2. Extract Max \n3. Display \n4. Exit \nEnter your choice = ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                value = extractMax();
                if(value != -1){
                printf("Max element extracted: %d\n",value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice!! Please try again! \n");
        }
    }
    return 0;
}