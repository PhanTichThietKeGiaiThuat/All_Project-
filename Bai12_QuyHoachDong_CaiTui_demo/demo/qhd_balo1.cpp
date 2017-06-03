#include<stdio.h>
#include<conio.h>
void Alloc(int n,int m,int **&A)
{
int i;
A=new int *[n+1];
for(i=0;i<=n;i++)
A[i]=new int[m+1];
}
void Free(int n,int **A)
{
for(int i=0;i<=n;i++) delete A[i];
delete A;
}
void Nhap(int &n,int *&kt,int *&gt)
{
printf("\nNhap so vat n = ");
scanf("%d",&n);
kt=new int [n+1];
gt=new int [n+1];
for(int i=1;i<=n;i++)
{
printf("Nhap vat thu %d",i);
printf("\nkt[%d]=",i); scanf("%d",kt+i);
printf("gt[%d]=",i); scanf("%d",gt+i);
}
}
void buocthuan(int n,int *a,int *b,int M,int **c)
{
int i,j;
for(i=0;i<=n;i++) c[i][0]=0;
for(j=0;j<=M;j++) c[0][j]=0;
for(i=1;i<=n;i++)
for(j=1;j<=M;j++)
{
c[i][j]=c[i-1][j];
if(j>=a[i] && c[i][j]<c[i-1][j-a[i]]+b[i])
c[i][j]=c[i-1][j-a[i]]+b[i];
}
}
void inkq(int n,int *a,int *b,int M,int **c,int &T)
{
if(c[n][M] == 0) return;
if(c[n][M] == c[n-1][M]) inkq(n-1,a,b,M,c,T);
else
{
inkq(n-1,a,b,M-a[n],c,T);
printf("\nChon vat %d co kich thuoc %2d gia tri %2d",n,a[n],b[n]);
T+=a[n];
}
}
int main()
{
int n,*a,*b,**c,M,T=0;
Nhap(n,a,b);
printf("Nhap kich thuoc ba lo M = "); scanf("%d",&M);
Alloc(n,M,c);
buocthuan(n,a,b,M,c);
inkq(n,a,b,M,c,T);
printf("\nTong kich thuoc la %d",T);
printf("\nTong gia tri la %d",c[n][M]);
delete a;
delete b;
Free(n,c);
getch();
}
