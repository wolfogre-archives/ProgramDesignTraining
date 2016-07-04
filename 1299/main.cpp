#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

#include <iostream>
#include <vector>

using namespace std;

size_t useless(const vector<pair<int, bool>> & input)
{
	size_t min_index = -1;
	int min = INT32_MAX;
	for (size_t i = 0; i < input.size(); ++i)
		if (min > input[i].first && input[i].second)
		{
			min = input[i].first;
			min_index = i;
		}
	return min_index;
}

int useless(const vector<pair<int, bool>> & input, size_t index)
{
	size_t i = (index + 1) % input.size();
	while (!input[i].second)
		i = (i + 1) % input.size();
	return input[i].first;
}

int uselesss(const vector<pair<int, bool>> & input, size_t index)
{
	size_t i = (index - 1 + input.size()) % input.size();
	while (!input[i].second)
		i = (i - 1 + input.size()) % input.size();
	return input[i].first;
}

int uselesss(const vector<pair<int, bool>> & input)
{
	int result = 0;
	for (auto it : input)
		if (it.second)
			++result;
	return result;
}

int useless()
{
	int n;
	cin >> n;

	vector<pair<int, bool>> input;

	while (n-- > 0)
	{
		int t;
		cin >> t;
		input.push_back(pair<int, bool>(t, true));
	}

	int power = 0;

	while (useless(input) > 1)
	{
		size_t min_index = useless(input);
		power += input[min_index].first * useless(input, min_index) * useless(input, min_index);
		input[min_index].second = false;
	}

	cout << power << endl;

	return 0;
}

/*对于第i个水晶， 有3种情况。
1、不放
2、放高塔
3、放矮塔
（1）.高塔仍高
（2）.矮塔变高塔*/
int dp[105][20005];		//dp[i][j]表示前i个数字,高度差为j,高塔的高度、于是YY出转移方程
int tmp[105];
int main()
{
	int n;

	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp[i];
		sum += tmp[i];
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (dp[i - 1][j] > -1)								//1.不放第i块水晶; 
				dp[i][j] = dp[i - 1][j];
			if (tmp[i] > j && dp[i - 1][tmp[i] - j] > -1)		//2.放进去后，高塔变矮塔（第i块放在矮塔上了）; 
				dp[i][j] = max(dp[i][j], dp[i - 1][tmp[i] - j] + j);
			if (j + tmp[i] <= sum&&dp[i - 1][j + tmp[i]] > -1)	//3.放进去后，高塔仍高（第i块放在矮塔上）;  
				dp[i][j] = max(dp[i][j], dp[i - 1][j + tmp[i]]);
			if (j >= tmp[i] && dp[i - 1][j - tmp[i]] > -1)		//4.放进去后，高塔更高（第i块放在高塔上）. 
				dp[i][j] = max(dp[i][j], dp[i - 1][j - tmp[i]] + tmp[i]);
		}
	}
	if (dp[n][0] > 0)
		cout << dp[n][0] << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}