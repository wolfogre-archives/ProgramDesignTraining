#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;


int m, n;
int map[505][505];
bool vis[505][505];
int dir[4][2] = { -1,0,0,-1,0,1,1,0 };

int isin(int x, int y)
{
	return x >= 0 && x<m&&y >= 0 && y<n;
}
int DFS(int i, int j)
{
	for (int vv = 0; vv <= 1; vv++) {}
	vis[i][j] = false;
	int nm = 0;

	for (int k = 0; k<4; k++)
	{
		int ii, jj;
		ii = i + dir[k][0];
		jj = j + dir[k][1];
		if (map[ii][jj] == 0 && ii >= 0 && ii<m&&jj >= 0 && jj<n&&vis[ii][jj])
		{
			nm += DFS(ii, jj);
		}
	}
	return nm + 1;
}

int main()
{
	while (cin >> m >> n)
	{
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				cin >> map[i][j];


		memset(vis, true, sizeof(vis));
		int sum = 0, ans = 0;
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
			{
				if (map[i][j] == 0 && vis[i][j])
				{
					sum++;
					ans = max(ans, DFS(i, j));
				}
			}
		cout << sum << ' ' << ans << endl;
	}
	return 0;

}


#include<vector>
bool useless(vector<int> &input)
{
	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}

	return true;
}