#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int* ratings;
    int totalScore;
};

void inputEmployees(int** ratings,int numEmployees,int numPeriods) {
    for(int i=0;i<numEmployees;i++) {
        printf("Enter ratings for employee %d:\n",i+1);
        for(int j=0;j<numPeriods;j++) {
            int rating;
            do {
                printf("Period %d (1-10): ",j+1);
                scanf("%d",&rating);
                if(rating<1||rating>10) {
                    printf("Invalid input. Rating must be between 1 and 10.\n");
                }
            }while(rating<1||rating>10);
            ratings[i][j]=rating;
        }
    }
}

void displayPerformance(int** ratings,int numEmployees,int numPeriods) {
    for(int i=0;i<numEmployees;i++) {
        printf("Ratings for employee %d: ",i+1);
        for(int j=0;j<numPeriods;j++) {
            printf("%d ",ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings,int numEmployees,int numPeriods) {
    int bestEmployee=-1;
    float highestAverage=0;
    for(int i=0;i<numEmployees;i++) {
        int total=0;
        for(int j=0;j<numPeriods;j++) {
            total+=ratings[i][j];
        }
        float average=(float)total/numPeriods;
        if(average>highestAverage) {
            highestAverage=average;
            bestEmployee=i;
        }
    }
    return bestEmployee;
}

int findHighestRatedPeriod(int** ratings,int numEmployees,int numPeriods) {
    int bestPeriod=-1;
    float highestAverage=0;
    for(int j=0;j<numPeriods;j++) {
        int total=0;
        for(int i=0;i<numEmployees;i++) {
            total+=ratings[i][j];
        }
        float average=(float)total/numEmployees;
        if(average>highestAverage) {
            highestAverage=average;
            bestPeriod=j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int** ratings,int numEmployees,int numPeriods) {
    int worstEmployee=-1;
    float lowestAverage=100;
    for(int i=0;i<numEmployees;i++) {
        int total=0;
        for(int j=0;j<numPeriods;j++) {
            total+=ratings[i][j];
        }
        float average=(float)total/numPeriods;
        if(average<lowestAverage) {
            lowestAverage=average;
            worstEmployee=i;
        }
    }
    return worstEmployee;
}

int main() {
    int numEmployees,numPeriods;
    printf("Enter number of employees: ");
    scanf("%d",&numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d",&numPeriods);

    int** ratings=(int**)malloc(numEmployees*sizeof(int*));
    for(int i=0;i<numEmployees;i++) {
        ratings[i]=(int*)malloc(numPeriods*sizeof(int));
    }

    inputEmployees(ratings,numEmployees,numPeriods);
    displayPerformance(ratings,numEmployees,numPeriods);

    int bestEmployee=findEmployeeOfTheYear(ratings,numEmployees,numPeriods);
    int bestPeriod=findHighestRatedPeriod(ratings,numEmployees,numPeriods);
    int worstEmployee=findWorstPerformingEmployee(ratings,numEmployees,numPeriods);

    printf("\nEmployee of the Year: Employee %d\n",bestEmployee+1);
    printf("Best rated evaluation period: Period %d\n",bestPeriod+1);
    printf("Worst performing employee: Employee %d\n",worstEmployee+1);

    for(int i=0;i<numEmployees;i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
