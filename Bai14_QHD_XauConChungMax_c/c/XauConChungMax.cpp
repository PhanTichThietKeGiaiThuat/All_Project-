#include<conio.h>
#include<stdio.h>

char x[8] = {'0', 'K','H','O','A','H','O','C' };
char y[8] = {'0', 'H','O','A','H','O','N','G' };

void LCS() {
	int c[8][8];
	for (int i = 0; i < 8; i++)
		c[i][0] = 0;
	for (int j = 0; j < 8; j++)
		c[0][j] = 0;
	for(int i =1;i<8;i++)
		for(int j =1;j<8;j++)
			if (x[i] == y[j])
			{
				c[i][j] = c[i][j - 1] + 1;
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
					c[i][j] = c[i - 1][j];
				else
				{
					c[i][j] = c[i][j - 1];
				}
			}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
				printf("%d\t", c[i][j]);
	printf("\n");
}

void main() {
	LCS();
	printf("jdfjf");
	_getch();
}
