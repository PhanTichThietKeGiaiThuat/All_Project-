#include<conio.h>
#include<windows.h>
#include<stdio.h>
void Gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void Chuong(int k,int x,int y)
{
for(int i=1;i<=9;i++)
{
Gotoxy(x,y++);
printf("%2d * %2d = %2d",k,i,k*i);
}
}
void CuuChuong()
{
Gotoxy(30,2);
printf("BANG CUU CHUONG");
for(int k=2;k<=5;k++)
Chuong(k,k*15-23,4);
for(int k=6;k<=9;k++)
Chuong(k,(k-4)*15-23,15);
}
int main()
{
system("cls");
CuuChuong();
getch();
}
