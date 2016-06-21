#include <iostream>
#include <vector>
#include <map>

#error 1015 Time Limit Exceed

using namespace std;

vector<int> input;
vector<int> group;
//int max = INT_MIN, min = INT_MAX;
int max_v = (-2147483647 - 1), min_v = 2147483647;
int group_count = 0;
int group_aim_count = 0;

bool get_next_num(size_t index, int &num)
{
	if (input.empty())
		return false;
	int new_index = (index + 1) % input.size();
	if (group[new_index] == 0)
		return false;
	num = input[new_index];
	return true;
}

int get_sum()
{
	map<int, int> groups;
	for(size_t i = 0; i <input.size(); ++i)
	{
		groups[group[i]] = groups[group[i]] + input[i];
	}
	int sum = 1;
	for(auto p : groups)
	{
		int t = p.second;
		while (t < 0)
			t += 10;
		t %= 10;
		sum *= t;
	}
		
	
	return sum;
}

void get_max_min(size_t index)
{
	if (group_count == 0)
	{
		++group_count;
		group[index] = 1;
		get_max_min((index + 1) % input.size());
		group[index] = 0;
		--group_count;
		return;
	}
	if(group[index] != 0)
	{
		if(group_count == group_aim_count)
		{
			int temp = get_sum();
			if (temp < min_v)
				min_v = temp;
			if (temp > max_v)
				max_v = temp;
		}
		return;
	}
	if(group_count == group_aim_count)
	{
		group[index] = group[(index - 1 + input.size()) % input.size()];
		get_max_min((index + 1) % input.size());
		group[index] = 0;
		return;
	}
	if (group_count > group_aim_count)
		return;

	group[index] = group[(index - 1 + input.size()) % input.size()];
	get_max_min((index + 1) % input.size());
	group[index] = 0;

	++group_count;
	group[index] = group[(index - 1 + input.size()) % input.size()] + 1;
	get_max_min((index + 1) % input.size());
	group[index] = 0;
	--group_count;
}


int main()
{

	int n;
	cin >> n >> group_aim_count;
	while(n-- > 0)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
		group.push_back(0);
	}
	for (size_t i = 0; i < input.size(); ++i)
		get_max_min(i);
	cout << min_v << endl << max_v;
	return 0;
}