#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<char, int> input;
	string str;
	getline(cin, str);
	getline(cin, str);
	for(auto ch : str)
	{
		if (input.find(ch) != input.end())
			++input.find(ch)->second;
		else
			input.insert(pair<char, int>(ch, 1));
	}
	for (auto p : input)
		cout << p.first << p.second << endl;
	//TODO:go on
	return 0;
}