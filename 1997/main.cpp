#include <iostream>
#include <vector>

using namespace std;

struct Food
{
	int w;
	int t;
	int c;
};

vector<Food> foods;

int n, m, s;
int min_price;
int price;
int weight;
int buy_count;

//搜索解空间树的最优解
void get_min_price(size_t index)
{
	//若已经到达解空间树的叶节点以下
	if(index >= foods.size())
	{
		//记录得到解的最低价格并返回
		min_price = price;
		return;
	}

	//若满足"买"的约束条件和限定条件:
	//1.该食物的价格加上已买的食物的总价格不超过已找到的解的最低价格；
	//2.该食物的重量加上已买的食物的总重量不超过能背负的最大重量；
	//3.该食物的保质期大于已经买的食物的份数；
	if (price + foods[index].c < min_price && weight + foods[index].w <= s
		&& foods[index].t > buy_count)
	{
		price += foods[index].c;//已购买的食物总价格自加当前食物价格
		weight += foods[index].w;//已购买的食物总重量自加当前食物重量
		buy_count += 1;//已购买的食物份数增1
		get_min_price(index + 1);//求解左子树的解空间
		buy_count -= 1;//已购买的食物份数减1
		weight -= foods[index].w;//已购买的食物总重量自减当前食物重量
		price -= foods[index].c;//已购买的食物总价格自减当前食物价格
	}

	//若满足"不买"的约束条件:
	//剩余的可买食物份数加上已买的食物份数大于需要购买的总份数
	if(foods.size() - 1 - index + buy_count >= n)
		get_min_price(index + 1);//求解右子树的解空间
}

int main()
{
	int T;
	cin >> T;
	while(T-- > 0)
	{
		//清除上组测试数据读入的食物信息
		foods.clear();
		//读入需要购买的食物份数,商店拥有的食物份数,食物总重量的最大值
		cin >> n >> m >> s;
		while(m-- > 0)
		{
			Food food;
			//读入一份新食物的信息
			cin >> food.w >> food.t >> food.c;
			//记录是否已经插入到食物信息数组
			bool inserted = false;
			//遍历食物信息数组
			for(auto it = foods.begin(); it != foods.end(); ++it)
				//若食物信息数组中某一份食物的保质期大于新食物的保质期
				if(it->t > food.t)
				{
					//将新食物插入到该食物的前面
					foods.insert(it, food);
					//记录已经插入
					inserted = true;
					break;
				}
			//若没有插入
			if (!inserted)
				//追加到食物信息数组末尾
				foods.push_back(food);
		}
		//初始化最低价格为无穷大
		min_price = INT32_MAX;
		//初始化已购买食物总价格,总重量,数量为0
		price = weight = buy_count = 0;
		//搜索解空间树
		get_min_price(0);

		//如果最低价格仍为无穷大,即无解
		if (min_price == INT32_MAX)
			cout << -1 << endl;
		else//若有解
			cout << min_price << endl;
	}
	return 0;
}