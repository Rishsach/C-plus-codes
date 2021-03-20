#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COL 4
int minu(int a, int b)
{ return (a < b)? a: b; }
int min(int a, int b, int c)
{ return minu(minu(a, b), c);}
int max(int a, int b)
{ return (a > b)? a: b; }
void diagonalOrder(int matrix[][COL])
{
	for (int line=1; line<=(ROW + COL -1); line++)
	{

		int start_col = max(0, line-ROW);

		int count = min(line, (COL-start_col), ROW);

		for (int j=0; j<count; j++)
			printf("%5d ", 
				matrix[minu(ROW, line)-j-1][start_col+j]);

		printf("\n");
	}
}

void printMatrix(int matrix[ROW][COL])
{
	for (int i=0; i< ROW; i++)
	{
		for (int j=0; j<COL; j++)
			printf("%5d ", matrix[i][j]);
		printf("\n");
	}
}
int main()
{
	int M[ROW][COL] = {{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16},
					{17, 18, 19, 20},
					};
	printf ("Given matrix is \n");
	printMatrix(M);

	printf ("\nDiagonal printing of matrix is \n");
	diagonalOrder(M);
	return 0;
}
