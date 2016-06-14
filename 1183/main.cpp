#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	while(getline(cin, str))
	{
		//For gcc
		transform(str.begin(), str.end(), str.begin(), ::toupper);

		//For vc++
		//transform(str.begin(), str.end(), str.begin(), toupper);

		cout << str << endl;
	}
	return 0;
}