#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int row, col;
	int k;
	while(cin >> row >> col >> k)
	{
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
				cout << 2 * i * j + 3 * i + 3 * j + 3 << " ";
			cout << endl;
		}

		vector<int> test;
		for(int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
				test.push_back(2 * i * j + 3 * i + 3 * j + 3);
		}
		sort(test.begin(), test.end());
		cout << test[k - 1] << endl;
		vector<int> what_fuck;
		for(int i = 0; i < row + col - 1; ++i)
		{
			if(i + 1 < min(row, col))
				what_fuck.push_back(i + 1);
			else if (i + 1 > max(row, col))
				what_fuck.push_back(row + col - 1 - i);
			else
				what_fuck.push_back(min(row, col));
			cout << what_fuck.back() << " ";
		}
		cout << endl;
		int sum = 0;
		int aim = 0;
		int left = 0;
		for(size_t i = 0; i < what_fuck.size(); ++i)
		{
			sum += what_fuck[i];
			if(sum >= k)
			{
				aim = i + 2;
				left = what_fuck[i] - (sum - k) - 1;
				break;
			}
		}
		vector<int> value;
		/*
		int count = 0;
		if(aim - 2 + 1 < max(row, col))
			for (int i = 1; ++count <= what_fuck[aim - 2]; ++i)
			{
				value.push_back(2 * i * (aim - i) + 3 * i + 3 * (aim - i) + 3);
			}
		else
			for (int i = 1 + (aim - 2 + 1) - max(row, col); ++count <= what_fuck[aim - 2]; ++i)
			{
				value.push_back(2 * i * (aim - i) + 3 * i + 3 * (aim - i) + 3);
			}
		*/
		vector<pair<int, int>> have_try;
		for(int i = 1; i < aim; ++i)
		{
			have_try.push_back(pair<int, int>(i, aim - i));
		}
		vector<pair<int, int>> have_try_new;
		for(auto p : have_try)
		{
			if (p.first <= row && p.second <= col)
				have_try_new.push_back(p);
		}

		for (auto p : have_try_new)
		{
			value.push_back(2 * p.first * p.second + 3 * p.first + 3 * p.second + 3);
			cout << p.first << " " << p.second << " " << value.back() << endl;
			
		}
			
		sort(value.begin(), value.end());
		cout << value[left] << endl;
		
	}
	return 0;
}