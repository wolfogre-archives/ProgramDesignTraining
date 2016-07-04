#include <iostream>

using namespace std;

char mat[1000][1000];
int max_flowers_on_left[1000][1000];
int max_flowers_on_right[1000][1000];
int max_flowers_on_up[1000][1000];
int max_flowers_on_down[1000][1000];
int row, col;


int max_flowers()
{

	for (int r = 0; r < row; ++r)
	{
		int record = 0;
		for (int c = 0; c < col; ++c)
		{
			max_flowers_on_left[r][c] = mat[r][c] == '.' ? record : 0;
			if (mat[r][c] == '.')
				++record;
			else
				record = 0;
		}
	}
	for (int r = 0; r < row; ++r)
	{
		int record = 0;
		for (int c = col - 1; c >= 0; --c)
		{
			max_flowers_on_right[r][c] = mat[r][c] == '.' ? record : 0;
			if (mat[r][c] == '.')
				++record;
			else
				record = 0;
		}
	}
	for (int c = 0; c < col; ++c)
	{
		int record = 0;
		for (int r = 0; r < row; ++r)
		{
			max_flowers_on_up[r][c] = mat[r][c] == '.' ? record : 0;
			if (mat[r][c] == '.')
				++record;
			else
				record = 0;
		}
	}
	for (int c = 0; c < col; ++c)
	{
		int record = 0;
		for (int r = row - 1; r >= 0; --r)
		{
			max_flowers_on_down[r][c] = mat[r][c] == '.' ? record : 0;
			if (mat[r][c] == '.')
				++record;
			else
				record = 0;
		}
	}


	int max = INT32_MIN;

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			int temp = max_flowers_on_left[i][j] + max_flowers_on_right[i][j] + max_flowers_on_up[i][j] + max_flowers_on_down[i][j];
			if (temp > max)
				max = temp;
		}
	return max;
}

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		cin >> row >> col;
		getchar();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
				mat[i][j] = getchar();
			getchar();
		}
			
		cout << max_flowers() << endl;
	}
	return 0;
}