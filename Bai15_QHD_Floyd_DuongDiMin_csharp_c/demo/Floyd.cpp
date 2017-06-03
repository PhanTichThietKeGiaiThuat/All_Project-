#include<stdio.h>
#include<conio.h>
void Alloc(int n, int **&A)
{
int i;
A= new int *[n+1];
for(i=0;i<=n;i++)
A[i] = new int [n+1];
}
void Free(int n,int **A)
{
for(int i=0;i<=n;i++) delete []A[i];
delete A;
}
int Nhap(int &n,int **&a,int **&Pi,char *fn)
{
FILE *f;
f=fopen(fn,"r");
if(!f) {printf("\nLoi mo file"); getch(); return 0;}
fscanf(f,"%d",&n);
Alloc(n,a);
Alloc(n,Pi);
for(int i=1;i<=n;i++)
for(int j=1;j<=n;j++)
{
fscanf(f,"%d",&a[i][j]);
Pi[i][j]=i;
}
}
//int min(int a,int b){return a<b?a:b;}
void buocthuan(int n,int **c,int **Pi)
{
int i,j,k;
for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(c[i][k]>0 && c[k][j]>0)
if(c[i][j] == -1 || c[i][j]>c[i][k]+c[k][j])
{
c[i][j]=c[i][k]+c[k][j];
Pi[i][j]=k;
}
}
void inkq(int s,int f,int **pi)
{
int k=pi[s][f];
if(k==s) printf("->%d",f);
else
{
inkq(s,k,pi);
inkq(k,f,pi);
}
}
int main()
{
int n,**a,**pi,s=1,f;
Nhap(n,a,pi,"g.txt");
buocthuan(n,a,pi);
do
{
printf("\nNhap xuat phat s ="); scanf("%d",&s);
printf("\nNhap ket thuc f ="); scanf("%d",&f);
if(a[s][f] == -1) printf("\nKhong co duong di");
else
{
printf("\nDuong di ngan nhat %d la: %d",a[s][f],s);
inkq(s,f,pi);
}
getch();
}while(s);
Free(n,a);
Free(n,pi);
return 1;
}
