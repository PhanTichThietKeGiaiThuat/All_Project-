
#include "stdio.h"
#include "conio.h"
#define n 9

typedef int Matrix[9][9];
int KiemTra(Matrix A,int k, int t);

void Nhap(Matrix &A)
{
int i,j;
printf("Nhap Ma Tran \n");
for( i=0; i<n ; i++)

for(j = 0; j<n;j++)
{
printf("A[%d][%d]=",i+1,j+1);
scanf("%d",&A[i][j]);
}

}

void Xuat(Matrix A)
{
printf("Xuat Ma Tran\n");
for(int i=0; i<=n-1 ; i++)
{
for(int j = 0; j<=n-1;j++)
printf("%6d",A[i][j]);
printf("\n");
}
}

int KiemTra(Matrix A,int k, int t)
{
int i,j;
int u = k/n, v = k%n;
for(i=0;i<n;i++)
{
if (A[i][v]==t) return 0;
if (A[u][i]== t) return 0;
}

for(i = u/3*3;i< u/3*3+3;i++)
for(j = v/3*3;j<v/3*3+3;j++)
if(A[i][j]==t) return 0;
return 1;
}
void Try(Matrix A,int k = -1)
{

if(k==80){Xuat(A);
getch(); return;
}

k++;
if(A[k/n][k%n]) Try(A,k);
else
{
for(int t = 1; t<=n ; t++)
if(KiemTra(A,k,t))
{

A[k/n][k%n]=t;
Try(A,k);
A[k/n][k%n]=0;

}
}

}
int main()
{

Matrix A;
Nhap(A);
Xuat(A);
Try(A);
getch();
}
