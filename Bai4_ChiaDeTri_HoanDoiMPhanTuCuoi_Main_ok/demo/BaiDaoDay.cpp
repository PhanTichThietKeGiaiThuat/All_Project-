#include<stdio.h>
#include<conio.h>

//========HAM DAO DAY=================//
void DaoNguoc(int a[], int n)
{
  int i;
  for (i=0; i<n/2; i++)
  {
     int t=a[i];
     a[i]=a[n-i-1];
     a[n-i-1]=t;
  }
}
//=========HAM NHAP===================//
void Nhap(int a[], int &n, int &k)
{   printf ("Nhap so phan tu cua mang: "); scanf("%d", &n);
  printf("So phan tu can dao :"); scanf("%d", &k);
  for (int i=0; i<n; i++)
  {
     printf("Nhap A[%d]= ",i);
     scanf("%d", &a[i]);
  }
}

//========HAM XUAT====================//
void Xuat(int a[],int n)
  {
     for(int i=0;i<n;i++)
     printf(" %d ", a[i]);
  }

int main ()
{
 int a[20],n,k;
 Nhap(a,n,k);
 printf("Day so vua nhap\n");
 Xuat(a,n);
 DaoNguoc(a,k);
 DaoNguoc(a,n);
 DaoNguoc(a,n-k);
 printf("\n\nDay so da dao %d phan tu \n",k);
 Xuat(a,n);
 getch();
 return 0;
}  
