#include <iostream>
#include <string.h>
#include<algorithm>

using namespace std;

int this_is_mine_but_wrong_what_fuck()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int tree[1001];
		memset(tree, 0, sizeof(tree));
		int n, k, end = -1;
		cin >> n >> k;

		for (int i = 0; i < n; ++i)
		{
			int index;
			cin >> index;
			cin >> tree[index];
			if (index > end)
				end = index;
		}

		int length = 0;
		int now_k = 0;

		while (0 != end)
		{
			if (tree[end] > k - now_k)
			{
				length += 2 * (end - 0);
				tree[end] -= k - now_k;
				now_k = 0;
			}
			else
			{
				now_k += tree[end];
				int new_end = end;
				do
				{
					--new_end;
				} while (tree[new_end] == 0 && new_end > 0);
				length += 2 * (end - new_end);
				end = new_end;
			}
		}
		cout << length << endl;
	}
	return 0;
}

struct Apple
{
	int d, num;
};
bool cmp(Apple a, Apple b)
{
	return a.d<b.d;
}
int main(void)
{
	int b, l, t, i, n, k, far;
	Apple apple[1005];
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		b = 0;
		l = 0;
		for (i = 1; i <= n; i++)
			cin >> apple[i].d >> apple[i].num;
		i = n;
		far = n;
		sort(apple + 1, apple + n + 1, cmp);
		while (apple[1].num != 0)
		{
			if (apple[i].num>k - b)
			{
				apple[i].num -= k - b;
				b = 0;
				l += apple[far].d * 2;
				far = i;
			}
			else if (apple[i].num == k - b)
			{
				l += apple[far].d * 2;
				b = 0;
				apple[i].num = 0;
				i--;
				far = i;
			}
			else
			{
				b += apple[i].num;
				apple[i].num = 0;
				if (i == 1)
					l += apple[far].d * 2;
				i--;
			}
		}
		cout << l << endl;
	}
	return 0;
}

