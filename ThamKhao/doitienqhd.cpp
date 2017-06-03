include<stdio.h>
#include<conio.h>
//Doi tien qhd
typedef int Matran[20][10000];
int *Nhap(int &n)
{
printf("\nNhap so menh gia n=");
scanf("%d",&n);
int *a=new int [n+1];
for (int i=1;i<=n;i++)
{
printf("a[%d]=",i);
scanf("%d",a+i);
}
return a;
}
void buocthuan(int n,int *a,int M,Matran &c)
{
int i,j,k;
for(j=1;j<=M;j++) c[0][j]=M+1; //vo cung = M+1
for(i=1;i<=n;i++) c[i][0]=0; //vo cung = M+1
for(i=1;i<=n;i++)
for(j=1;j<=M;j++)
{
c[i][j]=c[i-1][j];
if(j>=a[i] && c[i][j]>c[i][j-a[i]]+1)
c[i][j]=c[i][j-a[i]]+1;
}
}
void inkq(int n,int *a,int M,Matran &c)
{
if(c[n][M])
{
if(c[n][M]==c[n-1][M]) inkq(n-1,a,M,c);
else
{
inkq(n,a,M-a[n],c);
printf("%d+",a[n]);
}
}
}
void main()
{
int n,M,*a;
Matran c;
a=Nhap(n);
printf("\nNhap so tien can doi la M = ");
scanf("%d",&M);
buocthuan(n,a,M,c);
if(c[n][M]==M+1) printf("\nKhong doi duoc");
else
{
printf("\nSo to tien it nhat la %d\n%d=",c[n][M],M);
inkq(n,a,M,c);
printf("\b ");
}
delete a;
getch();
}
