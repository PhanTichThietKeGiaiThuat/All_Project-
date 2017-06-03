#include<conio.h>
#include<iostream>
using namespace std;
float **Alloc(int n)
{
float **a=new float *[n+1];
for(int i=1;i<=n;i++) a[i]=new float [n+1];
return a;
}
void Delete(int n,float **&a)
{
for(int i=1;i<=n;i++) delete a[i];
delete a;
}
void Nhap(int &n,float **&a)
{
cout<<"\nNhap co ma tran n = ";
cin>>n;
a=Alloc(n);
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
cout<<"a["<<i<<"]["<<j<<"] = ";
cin>>a[i][j];
}
}
void Xuat(int n,float **a)
{
cout<<"\n\n";
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++) printf("%8.2f",a[i][j]);
cout<<endl;
}
}
void BDTT(int n,float **&a,int u,int v,float t)
{
for(int j=1;j<=n;j++) a[v][j]+=a[u][j]*t;
}
float Dinhthuc(int n,float **a)
{
for(int j=1;j<n;j++)
{
if(a[j][j]==0)
{
int k;
for(k=j+1;k<=n;k++)
if(a[k][j]!=0) break;
if(k>n) return 0;
BDTT(n,a,k,j,1);
}
for(int i=j+1;i<=n;i++)
BDTT(n,a,j,i,-a[i][j]/a[j][j]);
Xuat(n,a);
}
float t=1;
for(int i=1;i<=n;i++) t=t*a[i][i];
return t;
}
int main()
{
int n;
float **a;
Nhap(n,a);
cout<<"\n\n Ma tran vua nhap \n";
Xuat(n,a);
cout<<"\nGia tri dinh thuc la "<<Dinhthuc(n,a);
Delete(n,a);
getch();
}

