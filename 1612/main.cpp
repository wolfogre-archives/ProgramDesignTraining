#include <iostream>
#include <vector>

using namespace std;

vector<char> input1;
vector<char> input2;

int record[50][50];

int get_max_same_length(size_t start1, size_t start2)
{
	if (start1 == input1.size() - 1 && start2 == input2.size() - 1)
		return input1[start1] == input2[start2] ? 1 : 0;
	if (start1 == input1.size() - 1)
	{
		if (input1[start1] == input2[start2])
			return 1;
		return get_max_same_length(start1, start2 + 1);
	}
	if (start2 == input2.size() - 1)
	{
		if (input1[start1] == input2[start2])
			return 1;
		return get_max_same_length(start1 + 1, start2);
	}

	if (record[start1][start2] != -1)
		return record[start1][start2];

	int max = INT32_MIN;

	int temp;

	if (input1[start1] == input2[start2])
	{
		temp = get_max_same_length(start1 + 1, start2 + 1) + 1;
		if (max < temp)
			max = temp;
	}
		
	temp = get_max_same_length(start1, start2 + 1);
	if (max < temp)
		max = temp;

	temp = get_max_same_length(start1 + 1, start2);
	if (max < temp)
		max = temp;

	record[start1][start2] = max;
	return max;

}


int main()
{
	int t;
	int count = 0;
	cin >> t;
	while(t-- > 0)
	{
		input1.clear();
		input2.clear();
		
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				record[i][j] = -1;

		while(n-- > 0)
		{
			char ch;
			cin >> ch;
			input1.push_back(ch);
		}
		while (m-- > 0)
		{
			char ch;
			cin >> ch;
			input2.push_back(ch);
		}

		cout << "Case " << ++count << endl;
		cout << get_max_same_length(0, 0) << endl;

	}
	return 0;
}