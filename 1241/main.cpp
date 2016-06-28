#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_median(vector<int> v)
{
	sort(v.begin(), v.end());
	if (v.size() % 2 == 0)
		return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
	return v[v.size() / 2];
}

int get_distance(const vector<int> &v, int pos)
{
	int distance = 0;
	for(auto it : v)
		distance += (it > pos ? it - pos : pos - it);
	return distance;
}

int main()
{
	vector<int> x, y;

	int n;
	cin >> n;
	while(n-- > 0)
	{
		int input_x, input_y;
		cin >> input_x >> input_y;
		x.push_back(input_x);
		y.push_back(input_y);
	}

	cout << get_distance(x, get_median(x)) + get_distance(y, get_median(y));

	return 0;
}