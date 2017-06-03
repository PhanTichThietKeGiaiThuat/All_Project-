#include<stdio.h>
#include<conio.h>
#include<string.h>
void Alloc(int n,int m,int **&A)
{
int i;
A=new int *[n+1];
for(i=0;i<=n;i++)
A[i]=new int[m+1];
}
void Free(int n,int **A)
{
for(int i=0;i<=n;i++) delete A[i];
delete A;
}
#define max(a,b) (a)>(b)?a:b
void buocthuan(char *x,int n,char *y,int m,int **c)
{
int i,j;
for(i=0;i<=n;i++) c[i][0]=0;
for(j=0;j<=m;j++) c[0][j]=0;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
if(x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
else c[i][j]=max(c[i-1][j],c[i][j-1]);
}
void inkq(char *x,int n,int m,int **c)
{
if(c[n][m] == 0) return;
if(c[n][m] == c[n-1][m]) inkq(x,n-1,m,c);
else if(c[n][m] == c[n][m-1]) inkq(x,n,m-1,c);
else
{
inkq(x,n-1,m-1,c);
printf("%c",x[n]);
}
}
void main()
{
int n,m,**c;
char x[100],y[100];
printf("Nhap xau x = "); fflush(stdin); gets(x+1);
printf("Nhap xau y = "); fflush(stdin); gets(y+1);
n=strlen(x+1);
m=strlen(y+1);
Alloc(n,m,c);
buocthuan(x,n,y,m,c);
printf("\nXau con chung dai nhat co do dai la %d",c[n][m]);
printf("\nXau con chung dai nhat la :\n");
inkq(x,n,m,c);
Free(n,c);
getc
