#include <iostream>

using namespace std;

int mat[7][7];
int n;
int start[7];

int get_num(int row, int col)
{
	col = (col + start[row]) % n;
	return mat[row][col];
}

int get_mat_max_col_sum()
{
	int max = INT32_MIN;
	for(int col = 0; col < n; ++col)
	{
		int sum = 0;
		for (int row = 0; row < n; ++row)
			sum += get_num(row, col);
		if (sum > max)
			max = sum;
	}
	return max;
}

int get_min_of_mat_max_col_sum(int move_row)
{
	if (move_row >= n)
		return get_mat_max_col_sum();
	int min = INT32_MAX;
	for(start[move_row] = 0; start[move_row] < n; ++start[move_row])
	{
		int temp = get_min_of_mat_max_col_sum(move_row + 1);
		if (temp < min)
			min = temp;
	}
	return min;
}

int main()
{
	while(cin >> n && n > 0)
	{
		for (int row = 0; row < n; ++row)
			for (int col = 0; col < n; ++col)
				cin >> mat[row][col];
		cout << get_min_of_mat_max_col_sum(0) << endl;;
	}
	return 0;
}