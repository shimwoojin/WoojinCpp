#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node
{
	Node(T data) : data(data) {}

	T data;

	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};

template<typename T>
void PreOrder(Node<T>* root)
{
	cout << root->data;
	if (root->left)
	{
		PreOrder(root->left);
	}
	if (root->right)
	{
		PreOrder(root->right);
	}
}

template<typename T>
void InOrder(Node<T>* root)
{
	if (root->left)
		InOrder(root->left);
	cout << root->data;
	if (root->right)
		InOrder(root->right);
}

template<typename T>
void PostOrder(Node<T>* root)
{
	if (root->left)
		PostOrder(root->left);
	if (root->right)
		PostOrder(root->right);
	cout << root->data;
}

int main()
{
	int n;
	char a, b, c;
	map<char, Node<char>*> m;
	cin >> n;

	Node<char>* root = nullptr;
	cin >> a >> b >> c;

	root = new Node<char>(a);
	m[a] = root;
	if (b != '.')
	{
		root->left = new Node<char>(b);
		m[b] = root->left;
	}
	if (c != '.')
	{
		root->right = new Node<char>(c);
		m[c] = root->right;
	}

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;

		Node<char>* now = m[a];

		if (b != '.')
		{
			now->left = new Node<char>(b);
			m[b] = now->left;
		}
		if (c != '.')
		{
			now->right = new Node<char>(c);
			m[c] = now->right;
		}
	}

	PreOrder(root);
	cout << '\n';
	InOrder(root);
	cout << '\n';
	PostOrder(root);

	for (auto& ele : m)
	{
		delete ele.second;
	}

	return 0;
}