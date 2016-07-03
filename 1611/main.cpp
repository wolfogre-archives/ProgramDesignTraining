#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int min_record[21][21];
string result_record[21][21];

vector<int> input;

int get_min_time_to_mul(int start, int end, string &result)
{
	if (start == end)
	{
		stringstream sstr;
		sstr << "A" << start + 1;
		sstr >> result;
		return 0;
	}
		
	if (min_record[start][end] != -1)
	{
		result = result_record[start][end];
		return min_record[start][end];
	}
		
	int min = INT32_MAX;

	for(int i = start; i < end; ++i)
	{
		string temp_str1, temp_str2;
		int temp = input[start] * input[i + 1] * input[end + 1] + get_min_time_to_mul(start, i, temp_str1) + get_min_time_to_mul(i + 1, end, temp_str2);
		if (min > temp)
		{
			result = temp_str1 + temp_str2;
			min = temp;
		}
			
	}
	result = "(" + result + ")";
	min_record[start][end] = min;
	result_record[start][end] = result;
	return min;
}


int get_min_time(string &result)
{
	int r =  get_min_time_to_mul(0, input.size() - 2, result);
	if(result.length() > 2)
	{
		result.erase(0, 1);
		result.erase(result.length() - 1, 1);
	}
	return r;
}


int main()
{
	int n;
	int count = 0;
	while(cin >> n)
	{
		++n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				min_record[i][j] = -1;
				result_record[i][j] = "";
			}
				
		input.clear();
		while(n-- > 0)
		{
			int temp;
			cin >> temp;
			input.push_back(temp);
		}
		string result;
		cout << "Case " << ++count << endl;
		cout << get_min_time(result) << " " << result << endl;
		

	}
	return 0;
}