#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n;
	cin >> n;

	list<int> input;

	while(n-- > 0)
	{
		int t;
		cin >> t;
		input.push_back(t);
	}

	int power = 0;

	while(input.size() > 1)
	{
		int min = *(input.begin());
		auto min_it = input.begin();
		for(auto it = input.begin(); it != input.end(); ++it)
			if(*it < min)
			{
				min = *it;
				min_it = it;
			}
		int result = *min_it;
		if(min_it == input.begin())
		{
			++min_it;
			result *= *min_it;
			--min_it;
			result *= *(--input.end());
			input.erase(min_it);
		}
	}

	int min = INT32_MAX;
	return 0;
}