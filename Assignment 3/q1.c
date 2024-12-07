#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    int dayOfJoining;
    int monthOfJoining;
    int yearOfJoining;
};

void empdet(struct Employee emp) {
    printf("Enter employee code: ");
    scanf("%d", &emp.employeeCode);
    printf("Enter employee name: ");
    scanf("%s", emp.employeeName);
    printf("Enter date of joining (DD MM YYYY): ");
    scanf("%d %d %d", &emp.dayOfJoining, &emp.monthOfJoining, &emp.yearOfJoining);
}

void threeYear(struct Employee emp[], int n) {
    int currentDay, currentMonth, currentYear;
    int count = 0;

    printf("\nEnter the current date (DD MM YYYY): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    for (int i = 0; i < n; i++) {
        int tenureInYears = currentYear - emp[i].yearOfJoining;

        if (currentMonth < emp[i].monthOfJoining || (currentMonth == emp[i].monthOfJoining && currentDay < emp[i].dayOfJoining)) {
            tenureInYears--;
        }

        if (tenureInYears > 3) {
            printf("\nEmployee Details:\n");
            printf("Employee Code: %d\n", emp[i].employeeCode);
            printf("Employee Name: %s\n", emp[i].employeeName);
            printf("Date of Joining: %02d-%02d-%04d\n", emp[i].dayOfJoining, emp[i].monthOfJoining, emp[i].yearOfJoining);
            printf("Tenure: %d years\n", tenureInYears);

            count++;
        }
    }

    printf("\nTotal number of employees with tenure more than three years: %d\n", count);
}

int main() {
    struct Employee employees[4];

    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        empdet(employees[i]);
    }

    threeYear(employees, 4);

    return 0;
}
