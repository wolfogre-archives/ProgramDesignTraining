#include <iostream>
#include <string.h>

#error 1902 think wrong

using namespace std;

int domino[1000];
int max_left_down[1000];
int max_right_down[1001];

bool down[1000];

int get_max_right_down(int from)
{
	int count = 0;
	for(int i = 1; i <= domino[from] && from + i < 1000; ++i)
	{
		if (domino[from + i] != 0 && !down[from + i])
		{
			++count;
			down[from + i] = true;
		}
	}
	for (int i = 1; i <= domino[from] && from + i < 1000; ++i)
	{
		if (domino[from + i] != 0)
			count += get_max_right_down(from + i);
	}
	for (int i = 1; i <= domino[from] && from + i < 1000; ++i)
		down[from + i] = false;

	return count;
}

int get_max_left_down(int from)
{
	int count = 0;
	for (int i = 1; i <= domino[from] && from - i >= 0; ++i)
	{
		if (domino[from - i] != 0 && !down[from - i])
		{
			++count;
			down[from - i] = true;
		}
	}
	for (int i = 1; i <= domino[from] && from - i >= 0; ++i)
	{
		if (domino[from - i] != 0)
			count += get_max_left_down(from - i);
	}
	for (int i = 1; i <= domino[from] && from - i >= 0; ++i)
		down[from - i] = false;

	return count;
}

int main()
{
	memset(down, false, sizeof(down));
	int T;
	cin >> T;
	while(T-- > 0)
	{
		memset(domino, 0, sizeof(domino));
		memset(max_left_down, -1, sizeof(max_left_down));
		memset(max_right_down, -1, sizeof(max_right_down));
		
		int n;
		cin >> n;
		while(n-- > 0)
		{
			int index;
			cin >> index;
			cin >> domino[index - 1];
		}

		for(int i = 0; i < 1000; ++i)
		{
			if(domino[i] != 0)
			{
				max_left_down[i] = get_max_left_down(i);
				max_right_down[i] = get_max_right_down(i);
			}
		}


		cout << "finished" << endl;
	}

	return 0;
}