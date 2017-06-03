#include<stdio.h>
#include<conio.h>
void Nhap(int &n,int *&a,int *&b)
{
printf("\nNhap so do vat n = ");
scanf("%d",&n);
a=new int [n+1];
b=new int [n+1];
for(int i=1;i<=n;i++)
{
printf("Kich thuoc a[%d]=",i);
scanf("%d",&a[i]);
printf("Gia tri b[%d]=",i);
scanf("%d",&b[i]);
}
}
template <class T>
void swap(T &a,T &b)
{
T t=a;a=b;b=t;
}
void sx(int n,int *a,int *b,int *&id)
{
int i,j;
id=new int[n+1];
float *t=new float[n+1];
for(i=1;i<=n;i++)
{
id[i]=i;
t[i]=(float)b[i]/a[i];
}
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
if(t[i]<t[j])
{
swap(a[i],a[j]);
swap(id[i],id[j]);
swap(b[i],b[j]);
swap(t[i],t[j]);
}
}
void balo(int n,int *a,int *b,int M)
{
int i,*id;
int tkt=0,tgt=0;
sx(n,a,b,id);
for(i=1;i<=n;i++)
if(tkt+a[i]<=M)
{
printf("\nChon vat %d kich thuoc\
%d gia tri %d",id[i],a[i],b[i]);
tgt+=b[i];
tkt+=a[i];
}
printf("\nTong kich thuoc la %d",tkt);
printf("\nTong gia tri lon nhat la %d",tgt);
delete id;
}
void main()
{
int n,m,*a,*b;
Nhap(n,a,b);
printf("\nNhap kich thuoc ba lo M=");
scanf("%d",&m);
balo(n,a,b,m);
delete a;
delete b;
getch();
}
