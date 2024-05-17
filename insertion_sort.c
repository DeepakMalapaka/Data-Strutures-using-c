#include<stdio.h>
int main()
{
	int n,i,j,key;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the %d number of elements for an array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	printf("After sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	return 0;
}
