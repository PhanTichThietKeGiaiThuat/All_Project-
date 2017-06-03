#include<conio.h>
#include<stdio.h>

void Exchange(int a[], int i, int j, int m,int n) {
	for (int p = n-1; p >n-m-1 ; p--)
	{
		int c = a[p-i];
		a[p-i] = a[p-j];
		a[p-j] = c;
	}
}
//
void Input(int a[],int n)
{
	int i=0;

	for(i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
	}
}
//
void Output(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

//
void Transpose(int a[], int n, int m) {
	int i = m, j = n - m;
	
	while (i != j) {
		if (i > j) {
			Exchange(a, m - i, m, j,n );	
			i = i - j;
		}
		else {
			j = j - i;
			Exchange(a, m - i, m + j, i,n);
		}
	}
	Exchange(a, m - i, m, i,n);
}

int main() {
	int n=0,m=0;
	int a[10];
	printf("Enter n= ");
	scanf("%d",&n);
	printf("\n");
	Input(a,n);
	printf("\n Enter m=");
	scanf("%d",&m);
	printf("\n");
	Transpose(a, n, m);
	printf("\n Result:  ");
	Output(a, 10);
	_getch();


}
