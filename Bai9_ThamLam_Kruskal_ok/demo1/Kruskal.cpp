//Thu?t toán Kruskal tìm cây khung nh? nh?t
#include<conio.h>
#include<stdio.h>
#include<math.h>
typedef struct
{
int d,c,ts;
}Canh;
typedef Canh MC[100];
void Nhap(int &n,int &m,MC &a) //sua &m
{
printf("So dinh n=");
scanf("%d",&n);
printf("So canh m=");
scanf("%d",&m);
for(int i=1;i<=m;i++) //sua i<=m
{
printf("Dinh dau:"); scanf("%d",&a[i].d);
printf("Dinh cuoi:"); scanf("%d",&a[i].c);
printf("Trong so:"); scanf("%d",&a[i].ts);
}
}
void SX(int m,MC a)
{
for(int i=1;i<=m;i++)
for(int j=1+i;j<=m;j++)
if(a[i].ts>a[j].ts)
{
Canh c=a[i];
a[i]=a[j];
a[j]=c;
}
}
void Kruskal(int n,int m,MC a)
{
int d[100],i,k=0,T=0;
for(i=1;i<=n;i++) d[i]=-i;
SX(m,a);
for(int j=1;j<=m;j++) //j<=m
if(d[a[j].d]!=d[a[j].c])
{
printf("\nchon canh (%d,%d) trong so %d",a[j].d,a[j].c,a[j].ts); //sua i thanh j
T=T+a[j].ts;
if(d[a[j].d]<0&&d[a[j].c]<0)
{
k++;
d[a[j].d]=d[a[j].c]=k;
}
else
if(d[a[j].d]>0&&d[a[j].c]>0)
{
int x=d[a[j].c];
for(i=1;i<=n;i++)
if(d[i]==x) d[i]=d[a[j].d]; //sua a[j].d
}
else
d[a[j].d]=d[a[j].c]=d[a[j].d]>d[a[j].c]?d[a[j].d]:d[a[j].c];
}
printf("\nTong trong so nho nhat la %d",T);
}
int main()
{
MC a;
int m,n;
Nhap(n,m,a);
Kruskal(n,m,a);
getch();
}

