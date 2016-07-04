//http://m.blog.csdn.net/article/details?id=47266399
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 110;
int p[maxn];
int h[maxn];
int dp[maxn];

bool useless(vector<int> &input)
{
	for (size_t i = input.size(); i > 0; --i)
	{
		for (size_t j = 0; j < i - 1; ++j)
		{
			if (input[j + 1] - 1 > input[j])
			{
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				--input[j];
				++input[j + 1];
			}
		}
	}

	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] < input[i + 1])
			return false;
	}
	return true;;
}

int useless()
{
	int n;
	cin >> n;
	while (n-- > 0)
	{
		int count;
		cin >> count;
		vector<int> input;
		while (count-- > 0)
		{
			int num;
			cin >> num;
			input.push_back(num);
		}
		if (useless(input))
		{
			cout << input[0];
			for (size_t i = 0 + 1; i < input.size(); ++i)
				cout << " " << input[i];
			cout << endl;
		}
		else
			cout << "Impossible" << endl;
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(dp, INF, sizeof(dp));
		for (int i = 1; i <= n; i++) cin >> p[i] >> h[i];
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			int r = p[i] + h[i];
			for (int j = i; j <= n; j++) {
				if (p[j]<r) {
					dp[j] = min(dp[j], dp[i - 1] + 1);
					r = max(p[j] + h[j], r);
				}
				else    break;
			}
			int l = p[i];
			for (int j = i; j <= n; j++) {
				if (p[j] - h[j] < l) {
					dp[j] = min(dp[j], dp[i - 1] + 1);
					l = p[j];
				}

			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}