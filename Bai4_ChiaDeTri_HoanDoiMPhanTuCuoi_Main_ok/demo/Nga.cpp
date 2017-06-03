#include<conio.h>
#include<stdio.h>

/*Hoán d?i các ph?n t? trong m?ng*/
void Exchange(int a[], int i, int j, int m) {
	for (int p = 0; p < m ; p++)
	{
		int c = a[i + p];
		a[i + p] = a[j + p];
		a[j + p] = c;
	}
}
//
void xuat(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
	}
}

//
void Tran(int a[], int n, int m) {
	int i = m, j = n - m;
	
	while (i != j) {
		if (i > j) {
			Exchange(a, m - i, m, j );	
		//	xuat(a, n);
			i = i - j;
		}
		else {
			j = j - i;
			Exchange(a, m - i, m + j, i);
		}
	}
	Exchange(a, m - i, m, i);
}
int main() {
	int a[] = { 1,2,3,4,5,6,7,8 };
	Tran(a, 8, 3);
//	printf("\nXuat");
	xuat(a, 8);
	_getch();


}
