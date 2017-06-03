#include<conio.h>
#include<iostream>
using namespace std;
void Nhap(int &n,int *&a,int *&b)
{
cout<<"Nhap so do vat n = ";
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
}
template <class T>
void Swap(T &a,T &b)
{
T t=a;a=b;b=t;
}
void SapXep(int n,int *a,int *b,int *v)
{ //v - thu tu cac vat
float *t=new float [n+1];
for(int i=1;i<=n;i++) t[i]=b[i]*1.0/a[i];
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
if(t[i]<t[j] || (t[i]==t[j] && a[i]<a[j]))
{
Swap(a[i],a[j]);
Swap(b[i],b[j]);
Swap(t[i],t[j]);
Swap(v[i],v[j]);
}
}
void Balo(int n,int *a,int *b,int B)
{
int *v=new int [n+1];
for(int i=1;i<=n;i++) v[i]=i;
SapXep(n,a,b,v);
int K=0,G=0;
for(int i=1;i<=n;i++)
if(K+a[i]<=B)
{
K+=a[i];
G+=b[i];
cout<<"\nLay vat "<<v[i]<<" kich thuoc "<<a[i]<<
" gia tri "<<b[i];
}
cout<<"\n\nTong kich thuoc la "<<K;
cout<<"\n\nTong Gia tri la "<<G;
delete v;
}
int main()
{
int n,*a,*b,B;
Nhap(n,a,b);
cout<<"\nKich thuoc ba lo M = ";
cin>>B;
Balo(n,a,b,B);
delete a;
delete b;
getch();
}
