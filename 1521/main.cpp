#include <iostream>
#include <vector>

using namespace std;

//C(N,3) - Sum{ D[i]*(N-1-D[i])/2 | i=1..N }
//https://www.byvoid.com/blog/poi-1997-tro

int main()
{
	int t;
	cin >> t;
	while(t-- > 0)
	{
		int n, m;
		cin >> n >> m;
		vector <pair<int, int>> input;
		for(int i = 0; i < m; ++i)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
			input.push_back(pair<int, int>(temp1, temp2));
		}

		vector<int> connect_red_num(n);
		for(auto p : input)
		{
			++connect_red_num[p.first - 1];
			++connect_red_num[p.second - 1];
		}

		double result = n * (n - 1) * (n - 2) / 6;
		for(auto it : connect_red_num)
			result -= it * (n - 1 - it) / 2.0;
		cout << result << endl;
	}
	
	return 0;
}