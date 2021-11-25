#include<stdio.h>

int main()
{
    int a[100];  //array declaration
    int n;
    
    printf("Number of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);      //storing all elements in array

    return 0;
}
