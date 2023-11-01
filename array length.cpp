#include<stdio.h>
int main()
{
int n;
printf("Enter the length of array.");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)
{
printf("Enter the element.");
scanf("%d",&arr[i]);
}
int c;
printf("Enter the searching element.");
scanf("%d",&c);
int f=0;
for(int i=0;i<n;i++)
{
if(arr[i]==c)
{
f++;
break;
}
}
if(f==1)
{
printf("Element found.");
}
else
{
printf("Element not found.");
}
}
