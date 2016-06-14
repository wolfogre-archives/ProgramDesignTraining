#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int i, j;

	for(i = 0, j = str.length() - 1; i <= j; ++i, --j)
		if(str[i] != str[j])
		{
			cout << "N";
			return 0;
		}

	cout << "Y";
	return 0;
}