#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string new_str(str);
	for (size_t i = 0; i < str.length(); ++i)
		new_str[str.length() - 1 - i] = str[i];
	cout << new_str;
	return 0;
}