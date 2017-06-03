#include <stdio.h>
#include <stdlib.h>
#define max 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Merge(int a[],int l,int t,int r)
{
	int i,j,p,c[max];
	i=l;
	j=t+1;
	p=l;
	while(i<=t && j<=r)
	{
		if(a[i]<a[j])
		{
			c[p]=a[i];
			i++;
		}
		else
		{
			c[p]=a[j];
			j++;
		}
		p++;
	}
	while(i<=t)
	{
		c[p]=a[i];
		i++;
		p++;
	}
	while(j<=r)
	{
		c[p]=a[j];
		j++;
		p++;
	}
	for(i=l;i<=r;i++)
	  a[i]=c[i];
}
void MergeSort(int X[],int l,int r)
{
	int m;
	if(l<r)
	{
		m=int(l+r)/2;
		MergeSort(X,l,m);
		MergeSort(X,m+1,r);
		Merge(X,l,m+1,r);
	}
}
void Input(int a[],int n)

{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void Output(int a[],int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
}
int main(int argc, char** argv) {
//	int a[100];
//	Input(a,9);
//	MergeSort(a,0,8);
//	Output(a,9);
	int a[]={12,15,33,35,42,45,55,65,75};
	int n = sizeof(a)/sizeof(a[0]);
	int i;
	MergeSort(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}
