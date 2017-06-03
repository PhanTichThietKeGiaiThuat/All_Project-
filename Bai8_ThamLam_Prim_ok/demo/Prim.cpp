#include<stdio.h>
#include<conio.h>
typedef int M[100][100];
#define vc 32767
void Nhap(int &n,M &a)
{
printf("\nNhap so dinh cua do thi n =");
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
int t;
printf("a[%d][%d]=",i,j);
scanf("%d",&t);
a[i][j]=t;
}
}
}
void Nhap(int &n,M &a,char *fn)
{
FILE *f;
f=fopen(fn,"r");
if(!f) {n=0;return ;}
fscanf(f,"%d",&n);
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
int t;
fscanf(f,"%d",&t);
a[i][j]=t;
}
}
}
int Ex_Min(int n,int *,int *);
void PRIM(int n,M &a,int *&L,int *&Pi,int s)
{
int i,j,u,v,*d;
L=new int [n+1];
Pi=new int [n+1];
d=new int [n+1];
for(u=0;u<=n;u++)
{
L[u]=vc;
d[u]=0;
}
L[s]=0;
while(u=Ex_Min(n,L,d))
{
d[u]=1;
for(v=1;v<=n;v++)
if(a[u][v]>0)
{
if(d[v]==0&&L[v]>a[u][v])
{
L[v]=a[u][v];
Pi[v]=u;
}
}
}
}
int Ex_Min(int n,int *L,int *d)
{
int i,p=0;
for(i=1;i<=n;i++)
if(d[i]==0)
{
if(p==0) p=i;
else if(L[p]>L[i]) p=i;
}
if (L[p]==vc) return 0;
return p;
}
void induong(int s,int f,int *pi)
{
if(s==f) printf("%d",s);
else
{
induong(s,pi[f],pi);
printf("->%d",f);
}
}
void inkq(int n,int s,int *L,int *pi)
{
int i,T=0;
for(i=1;i<=n;i++)
if(i!=s)
{
printf("\nChon canh (%d,%d) co trong so %d",i,pi[i],L[i]);
T+=L[i];
}
printf("\nTong trong so nho nhat la %d",T);
}
int main()
{
int n,s,f,*L,*pi;
M a;
Nhap(n,a,"g.txt");
PRIM(n,a,L,pi,2);
inkq(n,2,L,pi);
delete L;
delete pi;
getch();
return 1;
}
