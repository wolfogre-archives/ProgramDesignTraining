#include <iostream>
#include <vector>
using namespace std;

int mat[1000][1000];
int row, col;

int can_be_bigger(pair<int, int> p, int size)
{
	if (p.first + size + 1 > row || p.second + size + 1 > col)
		return false;
	for (int i = 0; i < size + 1; ++i)
		if (mat[p.first + i][p.second + size] != 1 || mat[p.first + size][p.second + i] != 1)
			return false;
	return true;
}

int max_size()
{
	vector<pair<int, int>> start_point;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if (mat[i][j] == 1)
				start_point.push_back(pair<int, int>(i, j));
	int max_size = 0;
	while(!start_point.empty())
	{
		++max_size;
		vector<pair<int, int>> new_start_point;
		for(auto it : start_point)
			if (can_be_bigger(it, max_size))
				new_start_point.push_back(it);
		start_point = new_start_point;
	}
	return max_size;
}

int main()
{
	int t;
	cin >> t;
	while(t-- > 0)
	{
		cin >> row >> col;
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				cin >> mat[i][j];
		cout << max_size() << endl;
	}
	return 0;
}