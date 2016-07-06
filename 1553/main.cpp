#include <iostream>

using namespace std;

int mat[100][100];
int row, col;
int record[100][100];


//计算从点(r,c)滑到底的最长距离
int max_length_from(int r , int c)
{
	//若备忘录中存在计算结果,则返回该结果
	if (record[r][c] != -1)
		return record[r][c];

	//记录最优值max初始值为1,即若不存在可以滑向的相邻点,则点的最优值为1
	int max = 1;

	//若下方的点可以滑向
	if (r + 1 < row && mat[r][c] > mat[r + 1][c])
	{
		//计算下方的点滑到底的最长距离加1,更新max
		int temp = max_length_from(r + 1, c) + 1;
		if (temp > max)
			max = temp;
	}
	//若右方的点可以滑向
	if (c + 1 < col && mat[r][c] > mat[r][c + 1])
	{
		//计算右方的点滑到底的最长距离加1,更新max
		int temp = max_length_from(r, c + 1) + 1;
		if (temp > max)
			max = temp;
	}
	//若上方的点可以滑向
	if (r - 1 >= 0 && mat[r][c] > mat[r - 1][c])
	{
		//计算上方的点滑到底的最长距离加1,更新max
		int temp = max_length_from(r - 1, c) + 1;
		if (temp > max)
			max = temp;
	}
	//若左方的点可以滑向
	if (c - 1 >= 0 && mat[r][c] > mat[r][c - 1])
	{
		//计算左方的点滑到底的最长距离加1,更新max
		int temp = max_length_from(r, c - 1) + 1;
		if (temp > max)
			max = temp;
	}

	//记录最优值到备忘录
	record[r][c] = max;
	//返回最优值
	return max;
}

//计算所有点滑到底的最长距离的最大值
int max_length()
{
	//记录最大值初始值为-1
	int max = -1;

	//遍历所有点
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			//计算该点滑到底的最长距离
			int temp = max_length_from(i, j);
			//更新最大值
			if (max < temp)
				max = temp;
		}

	//返回最大值
	return max;
}

//主函数
int main()
{
	//读入行列
	cin >> row >> col;

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
		{
			//初始化备忘录
			record[i][j] = -1;
			//读入点的值
			cin >> mat[i][j];
		}

	//输出所有点滑到底的最长距离的最大值
	cout << max_length() << endl;
	return 0;
}