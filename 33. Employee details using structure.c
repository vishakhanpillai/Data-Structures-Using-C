//	Define a structure for employees with eno,ename, esal and dno. Read  n employees information and provide functions for the following:  Searching, Sorting and Deleting employees

#include <stdio.h>

typedef struct employee
{
    int eno;
    char ename[50];
    int esal;
    int dno;
}employee;

employee emp[50];
int n;

void display(){
    int i;
    printf("\nEmp No\tName\tSalary\tDepartment No\n");
    for( i = 0; i < n; i++){
        printf("%d\t%s\t%d\t%d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
    }
}

void search(){
    int key, i, flag = 0;
    printf("Enter the emp no of the employee you want to search: ");
    scanf("%d", &key);

    for( i = 0; i < n; i++){
        if(key == emp[i].eno){
            printf("Employee Found!!");
            printf("%d\t%s\t%d\t%d\n", emp[i].eno, emp[i].ename, emp[i].esal, emp[i].dno);
            flag = 1;
        }
    }

    if( flag == 0 ){
        printf("Employee Not Found!!");
    }
}

void sort(){
    int i, j;
    employee temp;
    for( i = 0; i < n; i++){
        for( j = i+1; j < n; j++){
            if(emp[i].eno > emp[j].eno){
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }

    printf("After Sorting\n");
    display();
}

void delete(){
    int num, i, lim;
    printf("Enter the emp no of the employee you want to delete: ");
    scanf("%d", &num);
    for( i = 0; i < n; i++){
        if(num == emp[i].eno){
            lim = i;
            for( i = lim; i < n; i++){
                emp[i] = emp[i + 1];
            }
            break;
        }
    }
    n--;
}

int main(){

    int i, choice;
    
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    printf("Enter the employee details\n");
    for( i = 0; i < n; i++){
        printf("\nEmployee %d\n", i+ 1);
        printf("Enter the Employee Number: ");
        scanf("%d", &emp[i].eno);
        printf("Enter the Employee Name: ");
        scanf("%s", emp[i].ename);
        printf("Enter the Salary: ");
        scanf("%d", &emp[i].esal);
        printf("Enter the Department No: ");
        scanf("%d", &emp[i].dno);
    }

    while(1){
        printf("1. Search\n2. Sort\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            search();
            break;
        case 2:
            sort();
            break;
        case 3:
            delete();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid Option!!");
            break;
        }
    }


}
