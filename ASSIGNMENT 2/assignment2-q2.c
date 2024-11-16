#include <stdio.h>
int main() {
    int n;
    printf("enter string length: ");
    scanf("%d",&n);
    char arr[n];
    printf("enter string: ");
    for (int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }
    int counted[n]; 
    for (int i=0; i<n;i++) {
        counted[i] = 0;
    }
    printf("\n");
    int count;
    char temp;
    for (int i=0; i<n; i++){
        if (counted[i]==0){
        count=0;
        temp=arr[i];
        for (int j=0;j<n;j++){
            if(temp==arr[j]){
                count=count+1;
                counted[j]=1;
            }
            
        }
        printf("%c: %d ",arr[i],count);
    }
    }
}