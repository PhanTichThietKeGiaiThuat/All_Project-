#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
class Dothi
{
public:
int n;
int A[100][100];
int LoadFile(char *fn); //do ma tran ke tu file
void Print(); //Xuat ma tran ra man hinh
int *Bac();
friend void SapXep(int n,int *d,int *b);
void Tomau();
};
void Dothi::Tomau()
{
int *b=Bac();
int *d=new int [n+1];
int *t=new int [n+1];
for(int i=1;i<=n;i++) {d[i]=i;t[i]=0;}
SapXep(n,d,b);
int m=0;
for(int i=1;i<=n;i++)
if(t[d[i]]==0)
{
m++;
t[d[i]]=m;
for(int j=i+1;j<=n;j++)
if(t[d[j]]==0)
{
int id;
for(id=1;id<=n;id++)
if(t[id]==m && A[id][d[j]]==1) break;
if(id>n) t[d[j]]=m;
}
}
cout<<"\nSo mau it nhat la "<<m;
for(int i=1;i<=m;i++)
{
cout<<"\nMau "<<i<<" gom cac dinh : ";
for(int j=1;j<=n;j++)
if(t[j]==i) cout <<j<<" ";
}
}
void Swap(int &a,int &b){int t=a;a=b;b=t;}
void SapXep(int n,int *d,int *b)
{
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
if(b[i]<b[j])
{
Swap(b[i],b[j]);
Swap(d[i],d[j]);
}
}
int *Dothi::Bac()
{
int *b=new int [n+1];
for(int i=1;i<=n;i++)
{
b[i]=0;
for(int j=1;j<=n;j++) b[i]+=A[i][j];
}
return b;
}
int Dothi::LoadFile(char *fn)
{
FILE *f=fopen(fn,"rt");
if(f==NULL) {printf("\nloi mo file");return 0;}
fscanf(f,"%d",&n);
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
fscanf(f,"%d",&A[i][j]);
fclose(f);
return 1;
}
void Dothi::Print()
{
printf("\n\n");
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++) printf("%6d",A[i][j]);
printf("\n");
}
}
int main()
{
Dothi G;
int *d,*x;
G.LoadFile("graph.txt");
G.Print();
G.Tomau();
getch();
}
