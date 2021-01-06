int ai[4];
double ad[3][4];
char ac[3][4][5];
ai[1] = 7;
ad[2][3] = 7.2;
ac[2][3][4] = 'c';

void f1(int a[3][5]);
void f2(int[][5], int dim1);
voif f3(int[5][], int dim2);
void f4(int[][], int dim1, int dim2);
void f5(int* m, int dim1, int dim2)
{
	for (int i = 0; i < dim1; ++i)
	{
		for (int j = 0; j < dim2; ++j)
		{
			m[i * dim2 + j] = 0;
		}
	}
}