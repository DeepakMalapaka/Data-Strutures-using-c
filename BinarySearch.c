#include<stdio.h>
int bubble(int [],int );
int main() 
{
 int i,n,key,pos=-1,start,end,mid;
 printf("Enter size of an array:");
 scanf("%d",&n);
 int a[n];
   for(i=0;i<n;i++) 
  {
  printf("Enter a[%d]:",i);
  scanf("%d",&a[i]);
  }
 bubble(a,n);
 printf("Enter any element for binary search:");
 scanf("%d",&key);
 start=0;
 end=n-1;
 while(start<=end) 
 {
  mid=(start+end)/2;
  if(key==a[mid])
  {
   pos=mid+1;
   break;
  }
  else if(key<a[mid])
  {
   end=mid-1;
  }
  else 
  {
   start=mid+1;
  }
 }
 if(pos==-1) 
 {
  printf("position not found\n");
 }
 else 
 {
  printf("position found at %d\n",pos);
 }
 return 0;
}
void bubble(int a[],int n) 
{
 int t,i,j;
 printf("\nBefore sorting\n");
 for(i=0;i<n;i++) 
 {
  printf("%4d",a[i]);
 }
 for(i=0;i<n;i++) 
{
  for(j=0;j<n-i;j++)
 {
   if(a[j]>a[j+1]) 
   {
    t=a[j];
    a[j]=a[j+1];
    a[j+1]=t;
   }  
  }
 }
 printf("\nAfter sorting\n");
 for(i=0;i<n;i++)
 {
  printf("%4d",a[i]);
 }
 printf("\n");
}
