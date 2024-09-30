#include <stdio.h>
#include <string.h>

struct employee{
	int eno;
	char ename[50];
	int esal;
	int dno;
};

typedef struct employee emp;

emp e[50];
int n;

void readEmp(emp e[], int n){
	int i;
	for( i = 0; i < n; i++){
		
		printf("Enter the details of employee %d\n", i+1);
		printf("Enter the Employee No: ");
		scanf("%d", &e[i].eno);
		printf("Enter the Employee Name: ");
		scanf("%s", e[i].ename);
		printf("Enter the Employee Salary: ");
		scanf("%d", &e[i].esal);
		printf("Enter the Department No: ");
		scanf("%d", &e[i].dno);
	}
}

void dispEmp(emp e[], int n){
	int i;
	printf("\nEmployee Details\n");
	
	printf("\nEmp No\t\tName\t\tSalary\t\tDeptno\n");
	for( i = 0; i < n; i++){
		printf("%d\t\t%s\t\t%d\t\t%d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
	}
}

void searchEmp(emp e[], int n){
	int eno, i;
	printf("Enter the employee no of the employee you want to search: ");
	scanf("%d", &eno);
	
	for( i = 0; i < n; i++){
		if(eno == e[i].eno){
			printf("Employee Found\n");
			printf("\nEmp No\tName\tSalary\tDeptno\n");
			printf("%d\t%s\t%d\t%d\n", e[i].eno, e[i].ename, e[i].esal, e[i].dno);
			return;		
		}
	}
	
	printf("Employee Not Found!!");
}

void sortByName(emp e[], int n){
	emp temp;
	int i, j;

	for( i = 0 ; i < n - 1; i++){
		for( j = i + 1; j < n; j++){
			if(strcmp(e[i].ename, e[j].ename) > 0){
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
		}
	}

	dispEmp(e,n);
}

void sortBySalary(emp e[], int n){
	emp temp;
	int i, j;
	for( i = 0 ; i < n - 1; i++){
		for( j = i + 1; j < n; j++){
			if(e[i].esal > e[j].esal){
				temp = e[i];
				e[i] = e[j];
				e[j] = temp;
			}
		}
	}

	dispEmp(e,n);
	
}

void deleteEmp(emp e[], int n){
	
	int eno, i, j, found = 0;
	printf("Enter the employee no of the employee you want to delete: ");
	scanf("%d", &eno);

	for( i = 0; i < n;  i++){
		if( eno == e[i].eno){
			found = 1;
			break;
		}	
	}
	if(found == 1){
		for( j = i; j < n - 1; j++){
			e[j] = e[j + 1];
		}
		n--;
		printf("Employee no %d deleted", eno);
		dispEmp(e,n);
	}
	else{
		printf("Employee not found!!!");
	}

	
}

int main(){
	
	int choice;
	
	printf("Enter the number of employees you want to enter: ");
	scanf("%d", &n);
	
	readEmp(e, n);
	dispEmp(e,n);
	
	while(1){
		printf("\n1. Search Employee by Employee Number\n2. Sort Employee By Name\n3. Sort Employee By Salary\n4. Delete an Employee\n5. Display Employee List\n6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
			
		switch(choice){
			case 1:
				searchEmp(e, n);
				break;
			case 2:
				sortByName(e, n);
				break;
			case 3:
				sortBySalary(e, n);
				break;
			case 4:
				deleteEmp(e, n);
				break;
			case 5:
				dispEmp(e, n);
				break;
			case 6:
				return 0;
				break;

		}
	}
	
	
}
