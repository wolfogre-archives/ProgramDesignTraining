#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int count = 0;
	for (auto ch : str)
		if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
			++count;
	cout << count;
	return 0;
}