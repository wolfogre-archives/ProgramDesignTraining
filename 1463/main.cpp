#include <iostream>
#include <vector>
#include <set>

using namespace std;

void check(vector<pair<int, int>> &new_border, set<pair<int, int>> &reached, int row, int col)
{
	if (row >= 1 && row <= 8 && col >= 1 && col <= 8
		&& reached.find(pair<int, int>(row, col)) == reached.end())
	{
		new_border.push_back(pair<int, int>(row, col));
		reached.insert(pair<int, int>(row, col));
	}
}

bool if_reach_end(const vector<pair<int, int>> &border)
{
	for(auto it : border)
		if (it.first == 8 && it.second == 8)
			return true;
	return false;
}

int main()
{
	int row, col;
	while(cin >> row >> col)
	{
		vector<pair<int, int>> border;
		set<pair<int, int>> reached;

		border.push_back(pair<int, int>(row, col));
		reached.insert(pair<int, int>(row, col));

		int step = 0;

		while(!border.empty() && !if_reach_end(border))
		{
			++step;
			vector<pair<int, int>> new_border;
			for(auto it : border)
			{
				check(new_border, reached, it.first - 2, it.second + 1);
				check(new_border, reached, it.first - 1, it.second + 2);
				check(new_border, reached, it.first + 1, it.second + 2);
				check(new_border, reached, it.first + 2, it.second + 1);
			}
			border = new_border;
		}

		if (border.empty())
			cout << "Impossible" << endl;
		else
			cout << step << endl;
	}
	return 0;
}