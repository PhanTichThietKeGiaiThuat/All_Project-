#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
class graph
{
int n;
int A[100][100];
public:
void nhap();
void xuat();
void Print(int *x,int k);
void TRY(int *x,int k,int f,bool *d);
void Path();
};
#define FOR(i,a,b) for(int i=a;i<=b;i++)
void graph::Path()
{
int s,f;
cout<<"Nhap diem xuat phat "; cin>>s;
cout<<"Nhap diem ket thuc "; cin>>f;
int x[100];
bool d[100];
FOR(i,1,n)d[i]=false;
x[1]=s;
d[s]=true;
TRY(x,1,f,d);
}
void graph::TRY(int *x,int k,int f,bool *d)
{
if(x[k]==f) {Print(x,k);return ;}
FOR(t,1,n)
if(d[t]==false && A[x[k]][t]==1)
{
x[k+1]=t;
d[t]=true; //tien
TRY(x,k+1,f,d);
d[t]=false; //lui
}
}
void graph::Print(int *x,int k)
{
cout<<"\n";
FOR(i,1,k-1) cout<<x[i]<<"->";
cout<<x[k];
}
void graph::xuat()
{
FOR(i,1,n)
{
cout<<"\n";
FOR(j,1,n)
cout<<A[i][j]<<" ";
}
}
void graph::nhap()
{
ifstream is("graph.txt");
is>>n;
FOR(i,1,n)
FOR(j,1,n)
is>>A[i][j];
is.close();
}
int main()
{
// freopen("graph.txt","rt",stdin);
graph G;
G.nhap();
G.xuat();
getch();
}
