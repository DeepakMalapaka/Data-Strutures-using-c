/*SELECTION SORT*/
#include<stdio.h>
void readarray(int a[],int n);
void printarray(int a[],int n);
void swap(int *x,int *y);
void sort(int a[],int x);
int main() 
{
 int n;
 printf("Enter the size of array:");
 scanf("%d",&n);
 printf("Enter %d number of elements:\n",n);
 int a[n];
 readarray(a,n);
 printf("Before sorting\n");
 printarray(a,n);
 sort(a,n);
 printf("After sorting\n");
 printarray(a,n); 
 return 0;
}
void readarray(int a[],int n)
{
 for(int i=0;i<n;i++)
 {
  printf("Enter a[%d]:",i);
  scanf("%d",&a[i]);
 }
}
void printarray(int a[],int n)
{
 for(int i=0;i<n;i++)
 {
  printf("%4d",a[i]);
 }
 printf("\n");
}
void swap(int *x,int *y)
{
 int temp;
 temp=*x;
 *x=*y;
 *y=temp;
}
void sort(int a[],int n)
{
 for(int i=0;i<n-1;i++)
 {
  int min_idx=i;
  for(int j=i+1;j<n;j++)
  {
   if(a[j]<a[min_idx])
   {
    min_idx=j;
   }
  }
  if(min_idx!=i)
   swap(&a[i],&a[min_idx]);
 }
}

