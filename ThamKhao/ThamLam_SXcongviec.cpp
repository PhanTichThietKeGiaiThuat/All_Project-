#include<conio.h>
#include<iostream>
using namespace std;
void Nhap(int &n,int *&a)
{
cout<<"Nhap so do viec n = ";
cin>>n;
a=new int [n+1];
for(int i=1;i<=n;i++)
{
cout<<"Thoi gian a["<<i<<"] = ";
cin>>a[i];
}
}
template <class T>
void Swap(T &a,T &b)
{
T t=a;a=b;b=t;
}
void SapXep(int n,int *a,int *v)
{ //v - viec thu
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
if(a[i]<a[j])
{
Swap(a[i],a[j]);
Swap(v[i],v[j]);
}
}
void PCCV(int n,int *a,int m)
{
int *v=new int [n+1];
for(int i=1;i<=n;i++) v[i]=i;
SapXep(n,a,v);
int *x=new int [m+1];
for(int j=1;j<=m;j++)x[j]=0;
int *pc=new int [n+1];
int k;
for(int i=1;i<=n;i++)
{
k=1;
for(int j=1;j<=m;j++)
if(x[j]<x[k]) k=j; //Tim ra vi tri nho nhat
pc[v[i]]=k;
x[k]+=a[i];
}
float maxx=x[1];
for(int j=1;j<=m;j++)
if(maxx<x[j]) maxx=x[j];
cout<<"\nThoi gian hoan thanh tat ca "<<maxx;
for(int j=1;j<=m;j++)
{
cout<<"\nNguoi "<<j<<" thoi gian "<<x[j]
<<" gom cac viec : ";
for(int i=1;i<=n;i++)
if(pc[i]==j) cout<<"\t"<<i;
}
delete x;
delete pc;
delete v;
}
int main()
{
int n,*a,m;
Nhap(n,a);
cout<<"\nSo nguoi m = ";
cin>>m;
PCCV(n,a,m);
delete a;
getch();
}
