#include <iostream>
#include <vector>

using namespace std;


bool next_permutation(vector<int> &array)
{
	//从右至左看，找到第一个变小的数array[start]
	int start;
	for(start = array.size() - 1 -1; start >= 0; --start)
		if(array[start] < array[start + 1])
			break;
	if (start < 0)
		return false;

	//从start开始，从左至右看，找到最后一个大于array[start]的数array[end]
	int end;
	for (end = start + 1; end < array.size() - 1; ++end)
		if (array[end + 1] < array[start])
			break;

	//交换array[start]和array[end]
	swap(array[start], array[end]);

	//反转array[start + 1]至尾
	for(int i = start + 1, j = array.size() - 1; i < j; ++i, --j)
		swap(array[i], array[j]);
	return true;
}

void output(const vector<int> &array)
{
	for (auto it : array)
		cout << it << " ";
	cout << endl;
}

int main()
{
	vector<int> a = { 1,2,3,4,5 };
	output(a);
	while(next_permutation(a))
		output(a);
	return 0;
}