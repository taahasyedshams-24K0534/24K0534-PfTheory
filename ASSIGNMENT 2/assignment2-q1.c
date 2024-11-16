#include <stdio.h>
#include <bool.h>
int main() {
	bool flag=true;
    int n;
    printf("enter array length: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0; i<n;i++){
        printf("enter element %d: ",i);
        scanf("%d",&arr[i]);
    }
	for (int i=0; i<n;i++){
        if (arr[i]>=9999){
			flag=false;
			printf("element greater than 9999");
			return 0;
    }
	}
	if (flag==true){
    for (int i=0; i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int min=arr[0];
    for (int i=0; i<n;i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    int secmin=arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            secmin = min;
            min = arr[i];
        } else if (arr[i] < secmin && arr[i] != min) {
            secmin = arr[i];
        }
    }
    printf("the second smallest element is %d",secmin);
}
}