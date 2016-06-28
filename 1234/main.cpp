#include <iostream>
#include <vector>

using namespace std;

size_t get_min_index(const vector<pair<int, bool>> & input)
{
	size_t min_index = -1;
	int min = INT32_MAX;
	for(size_t i = 0; i < input.size(); ++i)
		if(min > input[i].first && input[i].second)
		{
			min = input[i].first;
			min_index = i;
		}
	return min_index;
}

int get_next_value(const vector<pair<int, bool>> & input, size_t index)
{
	size_t i = (index + 1) % input.size();
	while (!input[i].second)
		i = (i + 1) % input.size();
	return input[i].first;
}

int get_prev_value(const vector<pair<int, bool>> & input, size_t index)
{
	size_t i = (index - 1 + input.size()) % input.size();
	while (!input[i].second)
		i = (i - 1 + input.size()) % input.size();
	return input[i].first;
}

int get_live_size(const vector<pair<int, bool>> & input)
{
	int result = 0;
	for (auto it : input)
		if (it.second)
			++result;
	return result;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, bool>> input;

	while(n-- > 0)
	{
		int t;
		cin >> t;
		input.push_back(pair<int, bool>(t, true));
	}

	int power = 0;

	while(get_live_size(input) > 1)
	{
		size_t min_index = get_min_index(input);
		power += input[min_index].first * get_next_value(input, min_index) * get_prev_value(input, min_index);
		input[min_index].second = false;
	}

	cout << power << endl;

	return 0;
}