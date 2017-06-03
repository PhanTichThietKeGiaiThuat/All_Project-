#include<conio.h>
#include<iostream>
#include<iomanip.h>
using namespace std;
void Nhap(char *x,char *y)
{
cout<<"Nhap xau x ";
fflush(stdin);
gets(x+1);
cout<<"Nhap xau y ";
fflush(stdin);
gets(y+1);
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
int **BuocThuan(char *x,char *y)//lap bang C
{
int n=strlen(x+1);
int m=strlen(y+1);
int **c=Alloc(n,m);
for(int j=1;j<=m;j++) c[0][j]=0;
for(int i=0;i<=n;i++) c[i][0]=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
else c[i][j]=Max(c[i-1][j],c[i][j-1]);
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
void BuocNghich(int **c,int n,int m,char *x)
{
if(c[n][m]>0)
{
while(c[n][m]==c[n-1][m]) n--;
while(c[n][m]==c[n][m-1]) m--;
BuocNghich(c,n-1,m-1,x);
cout<<x[n];
}
}
int main()
{
char x[100],y[100];
Nhap(x,y);
int n=strlen(x+1);
int m=strlen(y+1);
int **c=BuocThuan(x,y);
Xuat(c,n,m);
if(c[n][m]==0) cout<<"\n\nKhong co xau con chung";
else
{
cout<<"\n\nDo dai xau con chung dai nhat "<<c[n][m];
BuocNghich(c,n,m,x);
}
Delete(n,c);
getch();
}
