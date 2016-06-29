#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int get_hurt(int index, const vector<int> &indexs, const vector<int> &hurts, int best)
{
	int result = 0;
	for(size_t i = 0; i < indexs.size(); ++i)
	{
		result += max(0 , hurts[i] - ((indexs[i] > index) ? indexs[i] - index : index - indexs[i]));
		if (result > best)
			return INT32_MAX;
	}
	return result;
}

int main()
{
	int t;
	cin >> t;
	while(t-- > 0)
	{
		int l, n;
		cin >> l >> n;
		vector<int> indexs;
		for(int i =0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			indexs.push_back(temp);
		}
		vector<int> hurts;
		for (int i = 0; i < n; ++i)
		{
			int temp;
			cin >> temp;
			hurts.push_back(temp);
		}

		int best_index = -1;
		int best_value = INT32_MAX;

		for(int i = 0; i <= l; ++i)
		{
			int test = get_hurt(i, indexs, hurts, best_value);
			if(test < best_value)
			{
				best_value = test;
				best_index = i;
			}
		}

		cout << best_index << " " << best_value << endl;
	}
	return 0;
}