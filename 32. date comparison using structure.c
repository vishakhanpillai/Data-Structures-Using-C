#include <stdio.h>

typedef struct date
{
    int day;
    int month;
    int year;
} date;

void readDate(date *d){
    printf("Enter the day: ");
    scanf("%d", &d->day);
    printf("Enter the month: ");
    scanf("%d", &d->month);
    printf("Enter the year: ");
    scanf("%d", &d->year);
}

void dispDate(date d){
    printf("%d / %d / %d", d.day, d.month, d.year);
}

int main(){
    date d1, d2;

    printf("Enter Date 1\n");
    readDate(&d1);
    printf("Enter date 2\n");
    readDate(&d2);

    printf("Date 1: ");
    dispDate(d1);
    printf("\nDate 2: ");
    dispDate(d2);

    if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year){
        printf("\nThe Dates Are Equal\n");
    }
    else{
        printf("\nThe Dates Are Unequal\n");
    }

    return 0;
}
