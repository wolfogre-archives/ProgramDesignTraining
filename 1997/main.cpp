#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Food
{
	int w;
	int t;
	int c;
};

vector<Food> foods;
vector<bool> buy;

int n, m, s;

int min_price;

int price;

int weight;

int buy_count;

void get_min_price(size_t index)
{
	if(index >= foods.size())
	{
		min_price = price;
		return;
	}

	buy[index] = true;
	if (price + foods[index].c < min_price && weight + foods[index].w <= s && foods[index].t > buy_count)
	{

		price += foods[index].c;
		weight += foods[index].w;
		buy_count += 1;
		get_min_price(index + 1);
		price -= foods[index].c;
		weight -= foods[index].w;
		buy_count -= 1;
	}
		
	buy[index] = false;
	if(foods.size() - 1 - index + buy_count >= n)
		get_min_price(index + 1);
}

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		foods.clear();
		buy.clear();
		cin >> n >> m >> s;
		while(m-- > 0)
		{
			buy.push_back(false);
			Food food;
			cin >> food.w >> food.t >> food.c;
			bool done = false;
			for(auto it = foods.begin(); it != foods.end(); ++it)
				if(it->t > food.t)
				{
					foods.insert(it, food);
					done = true;
					break;
				}
			if (!done)
				foods.push_back(food);
		}
		min_price = INT32_MAX;
		price = 0;
		weight = 0;
		buy_count = 0;
		get_min_price(0);
		if (min_price == INT32_MAX)
			cout << -1 << endl;
		else
			cout << min_price << endl;
	}
	return 0;
}