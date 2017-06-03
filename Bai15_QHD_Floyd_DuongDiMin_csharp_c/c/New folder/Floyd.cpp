#include<iostream>
#include<stdlib.h>
#include<fstream>
#define MAX 100
#define TRUE 1
const int lim =   32767;
using namespace std;

ifstream fi("floyd.txt");
ofstream fo("floyd_output.txt");

int a[MAX][MAX], d[MAX][MAX], trace[MAX][MAX];
int n;

/*:
 a[][] = MTK luu do thi
 d[i][j] = Khoang cach tu dinh i den dinh j, chuong trinh se tim Min(d[i][j])
 n = chi so hang va cot cua MTK
 trace[i][j]= t =>luu vet, truoc dinh j la dinh k
 */

//Nhap ma tran
void Init()
{
 int i,j;
 //Nhap chi so hang - cot
 fi>>n;
 for(i=1;i<=n;++i)
   for(j=1;j<=n;++j)
   {
   fi>>a[i][j];
   
   }
}

//------------------------------------------------------------------------------

void Floyd()
{
 int i,j,k;
 //Khoi tao gia tri ban dau cho mang d
 for(i =1;i<=n;++i)
   for(j=1;j<=n;++j)
   {
   if(a[i][j] == -1)
       d[i][j] = lim;
   else
        {
      d[i][j] = a[i][j];
       /*Do dai duong di tu i->j la do dai duong di truc tiep tu i->j*/
       }

   trace[i][j] = i;
   
   }
   
 for(k=1;k<=n;++k)
   for(i=1;i<=n;++i)
   {
  if(d[i][k] > 0 && d[i][k]<lim)                                                  //Neu co duong di tu i den k
  for(j=1;j<=n;++j)
  {
   if(d[i][j] > d[i][k] + d[k][j])
   {
    d[i][j] = d[i][k] + d[k][j];
    trace[i][j] = k;
   }
  }
   }

}

void in_duong_di()
{
 int i,j,t;
 for( i =1;i<=n;++i)
   for( j =i+1;j<=n;++j)
   {
   fo<<endl<<"Duong di tu dinh "<<j<<" den dinh "                                   <<i<<endl;
   t = trace[i][j];
  // cout<<"Truoc dinh " <<j <<"la dinh"<<t<<endl;
   fo<<j;
   while(t!=i)
   {
    fo<<" "<<t;
    t = trace[i][t];
   }
   fo<<" "<<i;
   fo<<endl<<"Tong chi phi : "<<d[i][j];
   }
}

int main()
{
 Init();
 Floyd();
 in_duong_di();
 fi.close();
 fo.close();
 return 0;
}
