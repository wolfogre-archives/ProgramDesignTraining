#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//妈蛋这是大二时写的，另一个账户提交的，判重

void useless(int *p, int n, int **m, int **s)
{
	//the least multiply times required of matrix[i : i] is 0
	for (int i = 1; i <= n; ++i)
		m[i][i] = 0;
	// I dont know the meaning of r, I should make it sense 
	for (int r = 2; r <= n; ++r)
		for (int i = 1; i <= n - r + 1; ++i)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
			for (int k = i + 1; k < j; ++k)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
}

string useless(int i, int j, int **s, string left_str, string right_str)
{
	//char str[100];
	if (i == j)
	{
		string str;
		return str;
		//return "A" + string(itoa(i, str, 10));
	}

	/*if (i == j)
	{
	char str[100];
	_itoa_s(i, str, 10);
	return "A" + string(str);
	}*/

	left_str += useless(i, s[i][j], s, "", "");
	right_str += useless(s[i][j] + 1, j, s, "", "");
	return "(" + left_str + right_str + ")";
}

int useless()
{
	int p[100];
	int **m = new int*[100];
	int **s = new int*[100];
	for (int i = 0; i < 100; ++i)
	{
		m[i] = new int[100];
		s[i] = new int[100];
	}

	int n;
	int count = 0;
	while (cin >> n)
	{
		++count;
		for (int i = 0; i <= n; ++i)
		{
			cin >> p[i];
		}
		useless(p, n, m, s);
		string result = useless(1, n, s, "", "");
		if (n != 1)
		{
			result.erase(0, 1);
			result.erase(result.length() - 1, 1);
		}
		cout << "Case " << count << endl;
		cout << m[1][n] << " " << result << endl;
	}

	for (int i = 0; i < 100; ++i)
	{
		delete[] m[i];
		delete[] s[i];
	}
	delete[] m;
	delete[] s;
	//system("pause");
	return 0;
}

template <class ElemType>
struct Node
{
	ElemType data;
	int inputOrder;
	Node<ElemType> *leftChild;
	Node<ElemType> *rightChild;
	string huffmanCode;
	Node(ElemType newDate, int newInputOrder)
	{
		leftChild = rightChild = NULL;
		data = newDate;
		inputOrder = newInputOrder;
	}
};

void CalHuffmanCode(Node<int>  *root)
{
	if (root->leftChild != NULL)
	{
		root->leftChild->huffmanCode = root->huffmanCode + "0";
		CalHuffmanCode(root->leftChild);
	}
	if (root->rightChild != NULL)
	{
		root->rightChild->huffmanCode = root->huffmanCode + "1";
		CalHuffmanCode(root->rightChild);
	}
}

void ShowHuffmanCode(Node<int> *root)
{
	CalHuffmanCode(root);
	struct
	{
		int data;
		string huffmanCodes;
	} outputHuffmanCodes[1000];
	queue<Node<int> *> nodeQueue;
	nodeQueue.push(root);
	while (!nodeQueue.empty())
	{
		Node<int> * node = nodeQueue.front();
		nodeQueue.pop();
		bool isLeef = true;
		if (node->leftChild != NULL)
		{
			isLeef = false;
			nodeQueue.push(node->leftChild);
		}
		if (node->rightChild != NULL)
		{
			isLeef = false;
			nodeQueue.push(node->rightChild);
		}
		if (isLeef)
		{
			outputHuffmanCodes[node->inputOrder].data = node->data;
			outputHuffmanCodes[node->inputOrder].huffmanCodes = node->huffmanCode;
		}
	}
	for (int i = 1; i < 1000; ++i)
	{
		if (outputHuffmanCodes[i].huffmanCodes.length() == 0)
			break;
		cout << outputHuffmanCodes[i].data << " " << outputHuffmanCodes[i].huffmanCodes << endl;
	}
}

int main(void)
{
	int caseNum;
	cin >> caseNum;
	int caseCount = 0;
	while (++caseCount <= caseNum)
	{
		Node<int>* trees[1000];
		int treesCount = 0;
		int valueNum;
		int valueCount = 0;
		cin >> valueNum;
		while (++valueCount <= valueNum)
		{
			int value;
			cin >> value;
			trees[treesCount++] = new Node<int>(value, valueCount);
		}
		//-----------------------------------------------------------
		while (treesCount > 1)
		{
			int minIndex = -1;
			for (int i = treesCount - 1; i >= 0; --i)
			{
				if (minIndex == -1 || trees[i]->data < trees[minIndex]->data)
					minIndex = i;
			}
			if (minIndex != treesCount - 1)
			{
				Node<int>* temp = trees[minIndex];
				for (int i = minIndex; i < treesCount - 1; ++i)
					trees[i] = trees[i + 1];
				trees[treesCount - 1] = temp;
			}

			int minSecondIndex = -1;
			for (int i = treesCount - 1 - 1; i >= 0; --i)
			{
				if (minSecondIndex == -1 || trees[i]->data < trees[minSecondIndex]->data)
					minSecondIndex = i;
			}
			if (minSecondIndex != treesCount - 1 - 1)
			{
				Node<int>* temp = trees[minSecondIndex];
				for (int i = minSecondIndex; i < treesCount - 1 - 1; ++i)
					trees[i] = trees[i + 1];
				trees[treesCount - 1 - 1] = temp;
			}
			Node<int> *newNode = new Node<int>(trees[treesCount - 1 - 1]->data + trees[treesCount - 1]->data, -1);
			newNode->leftChild = trees[treesCount - 1 - 1];
			newNode->rightChild = trees[treesCount - 1];
			treesCount -= 2;

			int last;
			for (last = treesCount - 1; last >= 0; --last)
			{
				if (trees[last]->data >= newNode->data)
					break;
			}

			for (int i = treesCount - 1; i > last; --i)
			{
				trees[i + 1] = trees[i];
			}

			trees[last + 1] = newNode;
			++treesCount;

		}
		//-----------------------------------------------------------
		cout << "Case " << caseCount << endl;
		ShowHuffmanCode(trees[0]);
		cout << endl;
	}

	return 0;
}