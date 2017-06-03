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
void TRY(int *x,int k,int *d,int f); //quay lui
void Out(int *x,int k); //xuat duong di
void TRY_Hamilton(int *x,int k,int *d,int s) ;
};
void Dothi::TRY_Hamilton(int *x,int k,int *d,int s){
if(k==n && A[x[n]][s]==1) {Out(x,k); return;}
for(int t=1;t<=n;t++)
if(A[x[k]][t]==1 && d[t]==0)
{
d[t]=1;
x[k+1]=t;
TRY_Hamilton(x,k+1,d,s);
d[t]=0; //lui
}
}
void Dothi::TRY(int *x,int k,int *d,int f)
{//mang d danh dau nhung dinh da chon
if(x[k]==f) {Out(x,k); return;}
for(int t=1;t<=n;t++)
if(A[x[k]][t] && d[t]==0)
{
d[t]=1;
x[k+1]=t;
TRY(x,k+1,d,f);
d[t]=0; //lui
}
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
void Dothi::Out(int *x,int k)
{
cout<<"\n";
for(int i=1;i<=k;i++) cout<<x[i]<<"->";
cout<<x[1];
}
int main()
{
Dothi G;
int *d,*x;
G.LoadFile("graph.txt");
G.Print();
d=new int[G.n+2];
x=new int[G.n+2];
int s,f;
do
{
for(int i=0;i<=G.n;i++) d[i]=0;
printf("\nNhap dinh xuat phat s : "); scanf("%d",&s);
//printf("\nNhap dinh ket thuc f : "); scanf("%d",&f);
x[1]=s;
d[s]=1;
G.TRY_Hamilton(x,1,d,s);
d[s]=0;
}
while(s);
getch();
}
