#include <iostream>
#include <vector>

using namespace std;

bool get_bigger_than(int v, vector<int> &mine)
{
	int min = INT32_MAX;
	int min_index = -1;
	for(size_t i = 0; i < mine.size(); ++i)
		if(mine[i] != -1 && mine[i] > v && mine[i] < min)
		{
			min = mine[i];
			min_index = i;
		}
	if (min_index == -1)
		return false;
	mine[min_index] = -1;
	return true;
}

bool get_min(vector<int> &mine)
{
	int min = INT32_MAX;
	int min_index = -1;
	for (size_t i = 0; i < mine.size(); ++i)
		if (mine[i] != -1 && mine[i] < min)
		{
			min = mine[i];
			min_index = i;
		}
	if (min_index == -1)
		return false;
	mine[min_index] = -1;
	return true;
}

int main()
{
	int n;
	while(cin >> n && n != 0)
	{
		vector<int> mine;
		vector<int> yours;
		for(int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			mine.push_back(t);
		}
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			yours.push_back(t);
		}

		int win = 0;
		for(auto it : yours)
		{
			if (get_bigger_than(it, mine))
				++win;
			else
				get_min(mine);
		}

		if (n - win < win)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}