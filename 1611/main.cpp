#include <iostream>
#include <vector>

using namespace std;

int record[21][21];
vector<int> input;

#error 1611 not work

int get_min_time_to_mul(int start, int end)
{
	if (start == end)
	{
		cout << start << " " << end << " " << input[start - 1] * input[start] * input[start + 1] << endl;;
		return input[start - 1] * input[start] * input[start + 1];
	}
		
	if (record[start][end] != -1)
		return record[start][end];
	int min = INT32_MAX;
	for(int mid = start; mid < end; ++mid)
	{
		int temp = get_min_time_to_mul(start, mid) + get_min_time_to_mul(mid + 1, end) + input[start - 1] * input[mid + 1] * input[end + 1];
		if (temp < min)
			min = temp;
	}
	record[start][end] = min;
	cout << start << " " << end << " " << min << endl;;
	return min;
}


int get_min_time()
{
	return get_min_time_to_mul(1, input.size() - 2);
}


int main()
{
	int n;
	while(cin >> n)
	{
		++n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				record[i][j] = -1;
		input.clear();
		while(n-- > 0)
		{
			int temp;
			cin >> temp;
			input.push_back(temp);
		}
		cout << get_min_time() << endl;
		

	}
	return 0;
}