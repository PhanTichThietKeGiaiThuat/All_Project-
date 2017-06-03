#include<conio.h>
#include<iostream>
#include<iomanip.h>
using namespace std;
int Nhap(int *&a,int *&b)
{
int n;
cout<<"Nhap so do vat : ";
cin>>n;
a=new int [n+1];
b=new int [n+1];
for(int i=1;i<=n;i++)
{
cout<<"Kich thuoc a["<<i<<"] = ";
cin>>a[i];
cout<<"Gia tri b["<<i<<"] = ";
cin>>b[i];
}
return n;
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
int Max(int a,int b){return a>b?a:b;}
int **BuocThuan(int n,int *a,int *b,int M)//lap bang C
{
int **c=Alloc(n,M);
for(int j=1;j<=M;j++) c[0][j]=0;
for(int i=0;i<=n;i++) c[i][0]=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=M;j++)
if(j<a[i]) c[i][j]=c[i-1][j];
else c[i][j]=Max(c[i-1][j],b[i]+c[i-1][j-a[i]]);
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
void BuocNghich(int **c,int n,int *a,int *b,int M)
{
if(c[n][M]>0)
{
while(c[n][M]==c[n-1][M]) n--;
BuocNghich(c,n-1,a,b,M-a[n]);
cout<<"\nChon vat "<<n<<" kich thuoc"<<a[n]<<" gia tri "<<b[n];
}
}
int main()
{
int **c,*a,*b,n,M;
n=Nhap(a,b);
cout<<"\nNhap kich thuoc M = ";
cin>>M;
c=BuocThuan(n,a,b,M);
Xuat(c,n,M);
if(c[n][M]==0) cout<<"\n\nKhong co do vat nao xep duoc";
else
{
cout<<"\n\nSo gia tri lon nhat"<<c[n][M];
BuocNghich(c,n,a,b,M);
}
delete a;
Delete(n,c);
getch();
}
