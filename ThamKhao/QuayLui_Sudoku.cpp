#include "stdio.h"
#include "conio.h"
#include "iostream"
#include "math.h"
#include <iomanip>
#define n 9
using namespace std;
class So
{
private :
int A[9][9];
public :
int KiemTra(int k, int t);
void Try(int k);
void Nhap()
{
int i,j;
cout<<"Nhap Ma Tran \n";
for( i=0; i<=n-1 ; i++)
for(j = 0; j<=n-1;j++)
{
cout<<"A["<<i<<"]["<<j<<"]=";
cin>>A[i][j];
}
}
void NhapFile(char *fn)
{
FILE *f = fopen(fn,"rt");
if (!f)
{cout<<"Loi mo file";
return;}
int i,j;
for( i=0; i<=n-1 ; i++)
for(j = 0; j<=n-1;j++)
fscanf(f,"%d",&A[i][j]);
fclose(f);
}
void Xuat()
{
cout<<"Xuat Ma Tran\n";
for(int i=0; i<=n-1 ; i++)
{
for(int j = 0; j<=n-1;j++)
cout<<setw(6)<<A[i][j];
cout<<"\n";
}
}
};
int So::KiemTra(int k, int t)
{
int i,j;
for(i=0;i<n;i++)
{
if (A[i][k%n]==t) return 0;
if (A[k/n][i]== t) return 0;
}
int u = k/n, v = k%n;
for(i = u/3*3;i< u/3*3+3;i++)
for(j = v/3*3;j<v/3*3+3;j++)
if(A[i][j]==t) return 0;
return 1;
}
void So::Try(int k = -1)
{
if(k==80){Xuat();
getch(); return;
}
k++;
if(A[k/n][k%n]) Try(k);
else
{
for(int t = 1; t<=n ; t++)
if(KiemTra(k,t))
{
A[k/n][k%n]=t;
Try(k);
A[k/n][k%n]=0;
}
}
}
int main()
{
So T;
T.Nhap();
T.Xuat();
T.Try();
getch();
}
