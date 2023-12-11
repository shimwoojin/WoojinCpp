#include <bits/stdc++.h>
using namespace std;

struct Node
{
	Node(int data) : data(data) {}

	Node* left = nullptr;
	Node* right = nullptr;

	int data;
};

void insert(Node** root, int data)
{
	Node* cur = *root;
	Node* before = nullptr;

	while (cur != nullptr)
	{
		before = cur;
		if (data < cur->data)
		{
			cur = before->left;
		}
		else
		{
			cur = before->right;
		}
	}
	
	if (before != nullptr)
	{
		if (data < before->data)
		{
			before->left = new Node(data);
		}
		else
		{
			before->right = new Node(data);
		}
	}
	else
	{
		*root = new Node(data);
	}
}

//void PostOrder(Node* node, vector<int>& vec)
//{
//	if (node == nullptr) return;
//
//	PostOrder(node->left, vec);
//	PostOrder(node->right, vec);
//	vec.push_back(node->data);
//}

void PostOrder(Node* node, vector<int>& vec)
{
	stack<Node*> s;
	s.push(node);
	
	while (!s.empty())
	{
		auto& top = s.top();
		bool bSomePush = false;

		if (top->right)
		{
			s.push(top->right);
			top->right = nullptr;
			bSomePush = true;
		}

		if (top->left)
		{
			s.push(top->left);
			top->left = nullptr;
			bSomePush = true;
		}

		if (top->left == nullptr && top->right == nullptr && !bSomePush)
		{
			vec.push_back(top->data);
			s.pop();
			delete top;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Node* root = nullptr;
	vector<int> results;
	int a;

	while (cin >> a)
	{
		insert(&root, a);
	}

	PostOrder(root, results);

	for (int r : results)
	{
		cout << r << '\n';
	}

	return 0;
}