#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Max(int a,int b)
{
	int max=0;
	if(a>b)
	max=a;
	else
	max=b;
	return max;
}
int Max3(int a,int b,int c)
{
	int max=0;
	if(a>b&& a>c)
	max=a;
	if(b>a&&b>c)
	max=b;
	if(c>a&&c>b)
	max=c;
}
void MaxLeftVector(int a[],int i,int j)
{
	int MaxSum= -2147483647;
	int Sum=0;
	int k;
	for(k=j;k>=i;k--)
	{
		Sum=Sum+a[k];
		MaxSum=Max(Sum,MaxSum);
	}
	return MaxSum;
}
void MaxRightVector(int a[],int i,int j)
{
	int MaxSum=-2147483647;
	int Sum=0,k=0;
	for(k=i;k<=j;k++)
	{
		Sum=Sum+a[k];
		MaxSum=Max(Sum,MaxSum);
	}
	return MaxSum;
	
}
void MaxSubVector(int a[],int i,int j)
{
	int m;
	if(i==j)
	 return a[i];
	else 
	{
		m=(i+j)/2;
		WL=MaxSubVector(a,i,m);
		WR=MaxSubVector(a,m+1,j);
		WM=MaxLeftVector(a,i,m)+MaxRightVector(a,m+1,j);
		return Max3(WL,WR,WM);
	}
}

int main(int argc, char** argv) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	MaxSubVector(a,1,6);
	
	return 0;
}
