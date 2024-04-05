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
	Tree(vector<int>&& inorders, vector<int>&& postorders)
	{
		this->inorders = inorders;
		this->postorders = postorders;
		root = new Node{ this->postorders.back(), nullptr, nullptr};
	}

	void ParseTree()
	{
		int data = root->data;
		int start = 0, end = inorders.size() - 1;

		Recur(start, end, start, end, &root);
	}

	void Recur(int in_start, int in_end, int post_start, int post_end, Node** current)
	{
		if (in_start > in_end || *current == nullptr) return;

		int data = postorders[post_end];
		int index = FindData(in_start, in_end, data, inorders);
		int left_size = index - in_start;
		(*current)->data = data;

		if (index != -1)
		{
			if (index - in_start > 0)
			{
				(*current)->left = new Node{ 0, nullptr, nullptr };
				Recur(in_start, index - 1, post_start, post_start + left_size - 1, &(*current)->left);
			}

			if (in_end - index > 0)
			{
				(*current)->right = new Node{ 0, nullptr, nullptr };
				Recur(index + 1, in_end, post_start + left_size, post_end - 1, &(*current)->right);
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
	vector<int> inorders;
	vector<int> postorders;
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

	Tree tree(move(inorders), move(postorders));

	tree.ParseTree();
	tree.PrintPreOrder(tree.root);

	return 0;
}

//#include <iostream>
//
//using namespace std;
//
//int Index[100001];
//int inorder[100001];
//int postorder[100001];
//int n;
//
//// 입력 받기
//void input()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> inorder[i];
//		Index[inorder[i]] = i; // inorder 요소들의 Index 정보 저장
//	}
//	for (int i = 1; i <= n; i++)
//		cin >> postorder[i];
//}
//
//// preorder 를 출력하는 함수 (재귀)
//void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
//{
//	// 더 이상 분할 할 수 없는 경우 return
//	if (inStart > inEnd || postStart > postEnd)
//		return;
//	// postorder의 끝 값이 root값
//	// Index 배열을 통해 inorder에서의 root index를 쉽게 구할 수 있다.
//	int rootIndex = Index[postorder[postEnd]];
//	int leftSize = rootIndex - inStart;
//	int rightSize = inEnd - rootIndex;
//	cout << inorder[rootIndex] << ' '; // root 값 출력
//
//	// 재귀 함수 호출
//	getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
//	getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
//}
//
//int main()
//{
//	input();
//	getPreOrder(1, n, 1, n);
//	return 0;
//}