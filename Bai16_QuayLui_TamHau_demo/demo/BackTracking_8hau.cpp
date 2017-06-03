//Backtracking 
//Bài toán 8 h?u
#include<conio.h>
#include<iostream>
#include<iomanip.h>
#include<math.h>
//Phuong phap quay lui 8 hau
int d=0;
void Out(int *x,int k)
{
cout<<"\n"<<++d<<" ";
for(int i=1;i<=k;i++) cout<<setw(5)<<x[i];
}
int datduoc(int *x,int k,int t)
{
for(int i=1;i<=k;i++)
{
if(k+1-i==x[i]-t) return 0;
if(k+1-i==t-x[i]) return 0;
}
return 1;
}
void TRY(int *x,int k,int n,int *dau)
{
if(k==n) {Out(x,k); return;}
for(int t=1;t<=n;t++)
if(dau[t]==0 && datduoc(x,k,t))
{
dau[t]=1;
x[k+1]=t;
TRY(x,k+1,n,dau);
dau[t]=0; //lui
}
}
int main()
{
int n,x[100],dau[100];
cout<<"Nhap so hau n = ";
cin>>n;
for(int i=1;i<=n;i++) dau[i]=0;
TRY(x,0,n,dau);
getch();
}
