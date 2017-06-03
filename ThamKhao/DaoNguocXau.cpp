#include<stdio.h>
#include<conio.h>
#include<string.h>
char *getk(char *s, int k)
{
while(*s && k>1)
{
if(*s==' ') k--;
s++;
}
return s;
}
void cut3(char *s, int i, char *&pre,char *&in,char *&pos)
{
char *t=strdup(s);
char *x=getk(t,i);
char *y=getk(t,i+1);
pos=strdup(y);
*(y-1)=0;
in=strdup(x);
if(x>t) *(x-1)=0; else *t=0;
pre=strdup(t);
delete t;
}
void daotu(char *s,int i,int j)
{
char *p1,*p2,*q,*p3,*p4,*p5;
cut3(s,i,p1,p2,q);
cut3(q,j-i,p3,p4,p5); 
strcpy(s,p1);
if(*p1) strcat(s," ");
strcat(s,p4);
strcat(s," ");
strcat(s,p3);
strcat(s," ");
strcat(s,p2);
strcat(s," ");
strcat(s,p5);
delete p1;
delete p2;
delete p3;
delete p4;
delete p5;
delete q; 
}
int main()
{
char x[1000];
int i,j;
printf("nhap vao xau x = ");
fflush(stdin);
gets(x);
strcat(x," ");
printf("Nhap tu i = "); scanf("%d",&i);
printf("Nhap tu (j>i) j = "); scanf("%d",&j);
daotu(x,i,j);
printf("\nSau khi dao thanh : \n");
printf("%s",x);
getch();
}
