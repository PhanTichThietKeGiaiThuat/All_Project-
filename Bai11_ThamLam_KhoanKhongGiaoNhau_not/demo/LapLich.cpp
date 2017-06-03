#include<conio.h>
#include<iostream>
#include<mem.h>
using namespace std;
//Lap lich
void Nhap(int &n,int *&a,int *&b)
{
cout<<"Nhap so su kien n = ";
cin>>n;
a=new int [n+1];
b=new int [n+1];
for(int i=1;i<=n;i++)
{
cout<<"Bat Dau a["<<i<<"] = ";
cin>>a[i];
cout<<"Ket Thuc b["<<i<<"] = ";
cin>>b[i];
}
}
template <class T>
void Swap(T &a,T &b)
{
T t=a;a=b;b=t;
}
void SapXep(int n,int *a,int *b,int *v)
{ //v - thu tu cac vat
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
if(b[i]>b[j])
{
Swap(a[i],a[j]);
Swap(b[i],b[j]);
Swap(v[i],v[j]);
}
}
void LapLich(int n,int *a,int *b,int m=2)
{
int *x=new int [m+1];
int *v=new int [n+1];
for(int i=1;i<=n;i++) v[i]=i;
SapXep(n,a,b,v);
for(int j=1;j<=m;j++) x[j]=a[1]-1;
int k=0;
for(int i=1;i<=n;i++)
{
int pos=1;
for(int j=1;j<=m;j++)
if(x[j]<x[pos]) pos=j;
if(a[i]>=x[pos])
{
k++;
cout<<"\nChon su kien"<<v[i]<<" bat dau " <<a[i]<<
" ket thuc "<<b[i] << "vao hoi truong "<<pos ;
x[pos]=b[i];
}
}
cout<<"\n\nTong so co "<<k<<" su kien duoc to chuc";
delete v;
}
int main()
{
int n,*a,*b,m;
Nhap(n,a,b);
cout<<"\nNhap so hoi truong ";
cin>>m;
LapLich(n,a,b,m);
delete a;
delete b;
getch();
}

