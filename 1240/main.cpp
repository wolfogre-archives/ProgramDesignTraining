#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cal(int a, int b, int op, int &result)
{
	switch (op)
	{
	case 0:
		result = a + b;
		return true;
	case 1:
		if (a - b < 0)
			return false;
		result = a - b;
		return true;
	case 2:
		result = a * b;
		return true;
	case 3:
		if(b == 0 || a % b != 0)
			return false;
		result = a / b;
		return true;
	}
	return false;
}

int get_int(string str)
{
	if (str.length() == 2)
		return 10;
	if (str[0] == 'A')
		return 1;
	if (str[0] == 'J')
		return 11;
	if (str[0] == 'Q')
		return 12;
	if (str[0] == 'K')
		return 13;
	return str[0] - '0';
}

void perm(vector<int> &numbers, int start, vector<vector<int>> &result)
{
	if (start == numbers.size() - 1)
	{
		result.push_back(numbers);
		return;
	}
	for(int i = start; i < numbers.size(); ++i)
	{
		swap(numbers[start], numbers[i]);
		perm(numbers, start + 1, result);
		swap(numbers[start], numbers[i]);
	}
}

bool check(const vector<vector<int>> &num_arrangement, const vector<vector<int>> &op_arrangement)
{
	for(auto num : num_arrangement)
		for(auto op : op_arrangement)
		{
			int result;
			if (!cal(num[0], num[1], op[0], result))
				continue;
			if (!cal(result, num[2], op[1], result))
				continue;
			if (!cal(result, num[3], op[2], result))
				continue;
			if (result == 24)
				return true;
				

			int temp1, temp2;
			if (!cal(num[0], num[1], op[0], temp1))
				continue;
			if (!cal(num[2], num[3], op[1], temp2))
				continue;
			if (!cal(temp1, temp2, op[2], result))
				continue;
			if (result == 24)
				return true;
		}
	return false;
}

vector<vector<int>> get_all_num_arrangement(vector<int> numbers)
{
	vector<vector<int>> result;
	sort(numbers.begin(), numbers.end());
	perm(numbers, 0, result);
	return result;
}

vector<vector<int>> get_all_op_arrangement()
{
	vector<vector<int>> result;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				result.push_back(vector<int>{i, j, k});
	return result;
}

int main()
{
	string input[4];
	vector<vector<int>> op_arrangement = get_all_op_arrangement();

	while(cin >> input[0] >> input[1] >> input[2] >> input[3])
	{
		vector<int> numbers;
		for (size_t i = 0; i < 4; ++i)
			numbers.push_back(get_int(input[i]));
		vector<vector<int>> num_arrangement = get_all_num_arrangement(numbers);
		if (check(num_arrangement, op_arrangement))
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	
	return 0;
}