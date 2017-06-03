#include<stdio.h>
#include<conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int Partition(int a[],int L,int R)
{
	int i,j,x;
	i=L+1;
	j=R;
	x=a[L];
	while(i<j)
	{
		while((i<j)&&(a[i]<x)) i++;
		while((j>=i)&&a[j]>=x) j--;
		if(i<j)swap(a[i],a[j]);
	}
	swap(a[L],a[j]);
	return j;
}
void QuickSort(int a[],int left,int right)
{
	int pivot;
	if(left>=right) return;

		pivot=Partition(a,left,right);
	//	if(left<pivot)
		QuickSort(a,left,pivot-1);
	//	if(right>left)
		QuickSort(a,pivot+1,right);
	
}
int main(int argc, char** argv) {
	int a[]={3,5,8,9,4,2,7,5,3,9,8};
	QuickSort(a,0,11);
	int i;
	for(i=0;i<11;i++)
	printf("%d ",a[i]);
	getch();
	return 0;
}
