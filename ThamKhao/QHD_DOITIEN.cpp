#include<conio.h>
#include<iostream>
#include<iomanip.h>
using namespace std;
int *Nhap(int &n)
{
cout<<"Nhap so menh gia : ";
cin>>n;
int *a=new int [n+1];
for(int i=1;i<=n;i++)
{
cout<<"a["<<i<<"] = ";
cin>>a[i];
}
return a;
}
int **Alloc(int n,int m)
{
int **a=new int*[n+1];
for(int i=0;i<=n;i++) a[i]=new int[m+1];
return a;
}
void Delete(int n,int **&a)
{
for(int i=0;i<=n;i++) delete a[i];
delete a;
}
int Min(int a,int b){return a<b?a:b;}
int **BuocThuan(int n,int *a,int M)//lap bang C
{
int **c=Alloc(n,M);
for(int j=1;j<=M;j++) c[0][j]=M+1;
c[0][0]=0;
for(int i=1;i<=n;i++)
for(int j=0;j<=M;j++)
if(j<a[i]) c[i][j]=c[i-1][j];
else c[i][j]=Min(c[i-1][j],1+c[i][j-a[i]]);
return c;
}
void Xuat(int **a,int n,int m)
{
for(int i=0;i<=n;i++)
{
cout<<"\n";
for(int j=0;j<=m;j++)
cout<<setw(3)<<a[i][j];
}
}
void BuocNghich(int **c,int n,int *a,int M)
{
if(c[n][M]>0)
{
while(c[n][M]==c[n-1][M]) n--;
BuocNghich(c,n,a,M-a[n]);
cout<<a[n]<<"+";
}
}
int main()
{
int **c,*a,n,M;
a=Nhap(n);
cout<<"\nNhap so tien can doi M = ";
cin>>M;
c=BuocThuan(n,a,M);
Xuat(c,n,M);
if(c[n][M]==M+1) cout<<"\n\nKhong doi duoc";
else
{
cout<<"\n\nSo to tien it nhat"<<c[n][M];
cout<<"\n\n"<<M <<" = ";
BuocNghich(c,n,a,M);
cout<<"\b ";
}
delete a;
Delete(n,c);
getch();
}
