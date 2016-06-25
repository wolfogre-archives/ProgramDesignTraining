#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

void reaching(map<int, set<int>> & my_map, vector<int> & groups)
{
	int group_id = 0;
	for(size_t i = 0; i < groups.size(); ++i)
	{
		if (groups[i] == 0)
		{
			++group_id;
			queue<int> reached_nodes;
			reached_nodes.push(i + 1);
			groups[i] = group_id;
			while(!reached_nodes.empty())
			{
				int node = reached_nodes.front();
				reached_nodes.pop();
				for(auto n : my_map.find(node)->second)
					if(groups[n - 1] == 0)
					{
						reached_nodes.push(n);
						groups[n - 1] = group_id;
					}
			}
		}
	}
}


int main()
{
	int n, e;
	while(cin >> n >> e)
	{
		map<int, set<int>> my_map;
		for(int i = 0; i < n; ++i)
			my_map.insert(pair<int, set<int>>(i + 1, set<int>()));

		for(int i = 0; i < e; ++i)
		{
			int node1, node2;
			cin >> node1 >> node2;

			my_map.find(node1)->second.insert(node2);
			my_map.find(node2)->second.insert(node1);
		}

		vector<int> groups(n, 0);
		reaching(my_map, groups);

		int max_group_id = 0;
		for (auto it : groups)
			if (it > max_group_id)
				max_group_id = it;

		cout << max_group_id << endl;

		
	}
	return 0;
}