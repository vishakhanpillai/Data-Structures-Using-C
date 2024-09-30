// Define a structure for dates with dd/mm/yyyy. Provide functions for reading, displaying and comparing two dates are equal or not 

#include <stdio.h>
	
struct date{
	int day;
	int month;
	int year;
};

void readDate(struct date *d){
	printf("Enter the day: ");
    scanf("%d", &d->day);
    printf("Enter the month: ");
    scanf("%d", &d->month);
    printf("Enter the year: ");
    scanf("%d", &d->year);
}

void displayDate(struct date d) {
	
    printf("%d-%d-%d\n", d.day, d.month, d.year);
}

void compareDates( struct date d1, struct date d2){
	if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year){
		printf("Date 1 and Date 2 are Equal");
	}	
	else{
		printf("The two dates are not equal!!");
	}
}

int main(){
	
	struct date d1, d2;
	
	printf("Date 1:\n");
	readDate(&d1);
	
	printf("Date 2:\n");
	readDate(&d2);
	
	
	printf("\n");
	
	printf("Date 1: ");
	displayDate(d1);
	printf("Date 2: ");
	displayDate(d2);
	
	compareDates(d1, d2);
	return 0;
	
}