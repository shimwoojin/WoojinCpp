#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

class Tree
{
public:
	Tree(int data)
	{
		root = new Node{ data, nullptr, nullptr };
	}

	void ParseTree(const vector<int>& inorders, const vector<int>& postorders)
	{
		int data = root->data;
		int start = 0, end = inorders.size() - 1;

		Recur(start, end, data, inorders, postorders, &root);
	}

	void Recur(int start, int end, int data, const vector<int>& inorders, const vector<int>& postorders, Node** current)
	{
		if (start >= end || *current == nullptr) return;

		int index = FindData(start, end, data, inorders);

		if (index != -1)
		{
			if (index - start > 0)
			{
				(*current)->left = new Node{ postorders[index - 1], nullptr, nullptr };
				Recur(start, index - 1, postorders[index - 1], inorders, postorders, &(*current)->left);
			}

			if (end - index > 0)
			{
				(*current)->right = new Node{ postorders[end - 1], nullptr, nullptr };
				Recur(index + 1, end, postorders[end - 1], inorders, postorders, &(*current)->right);
			}
		}
	}

	int FindData(int start, int end, int data, const vector<int>& inorders)
	{
		for (int i = start; i <= end; i++)
		{
			if (inorders[i] == data)
			{
				return i;
			}
		}
		return -1;
	}

	void PrintPreOrder(Node* node)
	{
		if (node == nullptr) return;

		cout << node->data << ' ';
		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
	}

public:
	Node* root;
};

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> inorders(n, 0);
	vector<int> postorders(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> inorders[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> postorders[i];
	}

	Tree tree(postorders.back());

	tree.ParseTree(inorders, postorders);
	tree.PrintPreOrder(tree.root);

	return 0;
}