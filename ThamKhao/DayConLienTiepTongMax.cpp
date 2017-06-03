#include<stdio.h>
#include<conio.h>
#include<string.h>
int maxcon(int n,int *a,int &l,int &r)
{
int max=a[0],t;
l=r=0;
for(int i=0;i<n;i++)
{
t=0;
for(int j=i;j<n;j++)
{
t+=a[j];
if(t>max) {max=t;l=i;r=j;}
}
}
return max;
}
int main()
{
int a[]= {3,-10,5,7,4,6,-5,9,-12,3,6};
int m,l,r,n=sizeof(a)/sizeof(int);
m=maxcon(n,a,l,r);
printf("\nTong max = %d",m);
printf("\nDay con tong max la \n");
for(int i=l;i<=r;i++) printf("%8d",a[i]);
getch();
return 1; 
}
