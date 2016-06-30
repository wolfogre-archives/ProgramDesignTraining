#include <iostream>

using namespace std;

int mat[100][100];
int row, col;
int record[100][100];

int max_length_from(int r , int c)
{
	if (record[r][c] != -1)
		return record[r][c];

	int max = 1;
	if (r + 1 < row && mat[r][c] > mat[r + 1][c])
	{
		int temp = max_length_from(r + 1, c) + 1;
		if (temp > max)
			max = temp;
	}
	if (c + 1 < col && mat[r][c] > mat[r][c + 1])
	{
		int temp = max_length_from(r, c + 1) + 1;
		if (temp > max)
			max = temp;
	}
	if (r - 1 >= 0 && mat[r][c] > mat[r - 1][c])
	{
		int temp = max_length_from(r - 1, c) + 1;
		if (temp > max)
			max = temp;
	}
	if (c - 1 >= 0 && mat[r][c] > mat[r][c - 1])
	{
		int temp = max_length_from(r, c - 1) + 1;
		if (temp > max)
			max = temp;
	}
	record[r][c] = max;
	return max;
}

int max_length()
{
	int max = -1;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			int temp = max_length_from(i, j);
			if (max < temp)
				max = temp;
		}
	return max;
}

int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			record[i][j] = -1;
			cin >> mat[i][j];
		}
	cout << max_length() << endl;
	return 0;
}