#include <iostream>
#include <vector>
#include <set>

#error 1719 Time out

using namespace std;

int path_length[1000][1000];

vector<int> dijkstra(int start_node, int node_count)
{
	vector<int> min_length_to_start_node(node_count, -1);

	min_length_to_start_node[start_node] = 0;

	set<int> reached_nodes;

	reached_nodes.insert(start_node);

	while (true)
	{
		int min_lengh = INT32_MAX;
		int next_node = -1;
		for (int node = 0; node < node_count; ++node)
		{
			if (reached_nodes.find(node) != reached_nodes.end())
				continue;
			for (auto it : reached_nodes)
			{
				if (path_length[it][node] != -1 && min_length_to_start_node[it] + path_length[it][node] < min_lengh)
				{
					min_lengh = min_length_to_start_node[it] + path_length[it][node];
					next_node = node;
				}
			}
		}
		if (next_node == -1)
			break;
		reached_nodes.insert(next_node);
		min_length_to_start_node[next_node] = min_lengh;
	}

	return min_length_to_start_node;
}

int record[1000];

int how_many_path(int start, int end, int node_count, const vector<int> &min_lennth)
{
	if (start == end)
		return 1;

	if (record[start] != -1)
		return record[start];

	int result = 0;

	for (int i = 0; i < node_count; ++i)
		if (path_length[start][i] != -1 && min_lennth[i] < min_lennth[start])
			result += how_many_path(i, end, node_count, min_lennth);

	record[start] = result;
	return result;
}

int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; ++i)
			record[i] = -1;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				path_length[i][j] = -1;

		int m;
		cin >> m;
		while(m-- > 0)
		{
			int node1, node2, value;
			cin >> node1 >> node2 >> value;
			path_length[node1 - 1][node2 - 1] = path_length[node2 - 1][node1 - 1] = value;
		}
		
		int start = 1 - 1, end = 2 - 1;

		vector<int> min_lennth = dijkstra(end, n);


		cout << how_many_path(start, end, n, min_lennth) << endl;
	}
	return 0;
}