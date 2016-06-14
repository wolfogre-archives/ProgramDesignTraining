#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string str;
	getline(cin, str);
	for(int i = 0; i < n; ++i)
	{
		getline(cin, str);
		cout << str << endl << endl;
	}
	while (cin >> str)
		cout << str << endl << endl;
	return 0;
}