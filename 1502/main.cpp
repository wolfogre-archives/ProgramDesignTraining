#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

void output(const list<pair<int, int>> &po)
{
	bool if_zero = true;
	for (auto it : po)
		if (it.first != 0)
		{
			cout << "(" << it.first << "," << it.second << ")";
			if_zero = false;
		}
	if (if_zero)
		cout << 0;
	cout << endl;
}

int main()
{
	string line;
	int count = 0;
	while(getline(cin, line))
	{
		stringstream sstr;
		sstr << line;
		list<pair<int, int>>  po1, po2;
		int a, n;
		while(sstr >> a >> n)
		{
			if(n < 0)
				break;
			auto it = po1.begin();
			for(; it != po1.end(); ++it)
			{
				if (it->second == n)
				{
					it->first += a;
					break;
				}
				if (it->second < n)
				{
					po1.insert(it, pair<int, int>(a, n));
					break;
				}
			}
			if (it == po1.end())
				po1.push_back(pair<int, int>(a, n));
		}
		while (sstr >> a >> n)
		{
			if (n < 0)
				break;
			auto it = po2.begin();
			for (; it != po2.end(); ++it)
			{
				if (it->second == n)
				{
					it->first += a;
					break;
				}
				if (it->second < n)
				{
					po2.insert(it, pair<int, int>(a, n));
					break;
				}
			}
			if (it == po2.end())
				po2.push_back(pair<int, int>(a, n));
		}
		cout << "Case " << ++count << ":" << endl;
		output(po1);
		output(po2);
		
		list<pair<int, int>> result;
		auto it1 = po1.begin();
		auto it2 = po2.begin();
		while(it1 != po1.end() || it2 != po2.end())
		{
			if(it2 == po2.end() || it1 != po1.end() && it1->second > it2->second)
			{
				result.push_back(pair<int, int>(it1->first, it1->second));
				++it1;
				continue;
			}
			if (it1 == po1.end() || it2 != po2.end() && it2->second > it1->second)
			{
				result.push_back(pair<int, int>(it2->first, it2->second));
				++it2;
				continue;
			}
			result.push_back(pair<int, int>(it1->first + it2->first, it1->second));
			++it1;
			++it2;
			
		}
		output(result);
		
	}
	return 0;
}