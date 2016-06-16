#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int n;

	while (cin >> n) {
		vector<long> a;
		vector<long> b;

		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			a.push_back(num);
			b.push_back(num);
		}

		int max_value = 0;

		sort(b.begin(), b.end());

		for (int i = n - 1; i >= 0; --i) {
			for (int j = i - max_value; j >= 0; --j) {
				if (a[i] == b[j]) {
					max_value = max(i - j, max_value);
					break;
				}
			}
			if (i < max_value)
				break;
		}

		cout << max_value << endl;
	}
	return 0;
}