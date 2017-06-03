#include<conio.h>
#include<iostream>
using namespace std;
class dovat
{
public:
int a, //kich thuoc
b, //gia tri
v; //vat
float t;//ty le
};
class BALO
{
dovat *D; //Mang cac do vat
int n; //So do vat
int B; //Kich thuoc ba lo
public:
void Nhap(); //Nhap du lieu
void SapXep(); //Sap xep theo ty le giam dan
void Balo(); //Lay ba lo
~BALO(){delete D;}
};
void BALO::Nhap()
{
cout<<"Nhap so do vat n = ";
cin>>n;
D=new dovat [n+1];
for(int i=1;i<=n;i++)
{
cout<<"Kich thuoc a["<<i<<"] = ";
cin>>D[i].a;
cout<<"Gia tri b["<<i<<"] = ";
cin>>D[i].b;
D[i].v=i;
D[i].t=float(D[i].b)/D[i].a;
}
cout<<"\nKich thuoc ba lo M = ";
cin>>B;
}
void BALO::SapXep()
{ //v - thu tu cac vat
for(int i=1;i<=n;i++)
for(int j=i+1;j<=n;j++)
if(D[i].t<D[j].t || (D[i].t==D[j].t && D[i].a<D[j].a))
swap(D[i],D[j]);
}
void BALO::Balo()
{
SapXep();
int K=0,G=0;
for(int i=1;i<=n;i++)
if(K+D[i].a<=B)
{
K+=D[i].a;
G+=D[i].b;
cout<<"\nLay vat "<<D[i].v <<" kich thuoc "<<D[i].a<<
" gia tri "<<D[i].b;
}
cout<<"\n\nTong kich thuoc la "<<K;
cout<<"\n\nTong Gia tri la "<<G;
}
int main()
{
BALO K;
K.Nhap();
K.Balo();
getch();
}
