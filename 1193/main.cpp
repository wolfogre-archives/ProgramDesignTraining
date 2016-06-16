#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	int sum;
	while(cin >> n >> sum)
	{
		vector<int> input;
		while(n-- > 0)
		{
			int num;
			cin >> num;
			input.push_back(num);
		}
		sort(input.begin(), input.end());
		bool if_find = false;
		for(size_t i = 0; i < input.size() && !if_find; ++i)
			for (size_t j = i + 1; j < input.size() && !if_find; ++j)
			{
				if (binary_search(input.begin() + j + 1, input.end(), sum - input[i] - input[j]))
				{
					cout << "YES" << endl;
					if_find = true;
				}
			}
		if(if_find)
			continue;
		cout << "NO" << endl;
	}
	return 0;
}