
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 700010
struct atp
{
	int x, y;
}P[MaxN];
struct bian
{
	int y, next;
}e[MaxN]; int first[MaxN];

int d[MaxN], dfn[MaxN], low[MaxN], belong[MaxN], cost[MaxN];
bool b[MaxN];
bool bar[MaxN];
int stap[MaxN];
int tot = 0, n, m, Bcnt, Index, stop, center, ans = 0;


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

	return true;
}

void add(int x, int y)
{
	tot++;
	e[tot].y = y;
	e[tot].next = first[x];
	first[x] = tot;
}

void init()
{
	int x, t;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &P[i].x, &P[i].y), add(P[i].x, P[i].y);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	scanf("%d%d", &center, &x);
	for (int i = 1; i <= x; i++)
	{
		scanf("%d", &t);
		bar[t] = true;
	}
}

void tarjan(int i)
{
	int j;
	dfn[i] = low[i] = ++Index;
	b[i] = true;
	stap[++stop] = i;
	for (int p = first[i]; p; p = e[p].next)
	{
		j = e[p].y;
		if (!dfn[j])
		{
			tarjan(j);
			if (low[j]<low[i]) low[i] = low[j];
		}
		else
			if (b[j] && dfn[j]<low[i]) low[i] = dfn[j];
	}
	if (dfn[i] == low[i])
	{
		Bcnt++;
		do
		{
			j = stap[stop--];
			b[j] = false;
			belong[j] = Bcnt;
		} while (j != i);
	}
}




void spfa()
{
	int u;
	bool v[MaxN];
	memset(v, false, sizeof(false));
	queue<int>q; while (!q.empty()) q.pop();
	memset(d, 0, sizeof(d));
	d[belong[center]] = cost[belong[center]];
	q.push(belong[center]);
	v[belong[center]] = true;
	while (!q.empty())
	{
		u = q.front(); q.pop(); v[u] = false;
		for (int p = first[u]; p; p = e[p].next)
		{
			if (d[u] + cost[e[p].y]>d[e[p].y]) d[e[p].y] = d[u] + cost[e[p].y];
			if (!v[e[p].y])
			{
				v[e[p].y] = true;
				q.push(e[p].y);
			}

		}
	}
	for (int i = 1; i <= Bcnt; i++)
		if (b[i] && d[i]>ans)ans = d[i];
}

void work()
{
	stop = Bcnt = Index = 0;
	memset(dfn, 0, sizeof(dfn));
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	memset(first, 0, sizeof(first)); tot = 0;
	memset(b, false, sizeof(false));
	for (int i = 1; i <= n; i++)
	{
		cost[belong[i]] += d[i];
		if (bar[i]) b[belong[i]] = true;
	}
	for (int i = 1; i <= m; i++)
		if (belong[P[i].x] != belong[P[i].y])
			add(belong[P[i].x], belong[P[i].y]);
	spfa();
	printf("%d\n", ans);
}
int main()
{
	init();
	work();
	return 0;
}