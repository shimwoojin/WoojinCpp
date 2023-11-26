#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

struct tree_node
{
    int node = 0;
    int y = 0;
    int x = 0;

    tree_node* left = nullptr;
    tree_node* right = nullptr;
};

void insert(tree_node** root, tree_node* new_node)
{
    tree_node* current = *root;
    tree_node* parent = nullptr;

    while (current != nullptr)
    {
        parent = current;
        if (new_node->x < parent->x)
            current = parent->left;
        else
            current = parent->right;
    }

    if (parent != nullptr)
    {
        if (new_node->x < parent->x)
            parent->left = new_node;
        else
            parent->right = new_node;
    }
    else
        *root = new_node;
}

void PreOrder(tree_node* node, vector<int>& vec)
{
    if (node == nullptr) return;

    vec.push_back(node->node);
    PreOrder(node->left, vec);
    PreOrder(node->right, vec);
}

void PostOrder(tree_node* node, vector<int>& vec)
{
    if (node == nullptr) return;

    PostOrder(node->left, vec);
    PostOrder(node->right, vec);
    vec.push_back(node->node);
}

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<1>(a) > get<1>(b);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>());
    vector<tuple<int, int, int>> nodes;  //x, y, node_number
    tree_node* root = new tree_node;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int node = i + 1;
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];

        nodes.push_back(make_tuple(x, y, node));
    }

    sort(nodes.begin(), nodes.end(), cmp);

    root->node = get<2>(nodes[0]);
    root->x = get<0>(nodes[0]);
    root->y = get<1>(nodes[0]);

    for (int i = 1; i < nodes.size(); i++)
    {
        tree_node* new_node = new tree_node;
        new_node->node = get<2>(nodes[i]);
        new_node->x = get<0>(nodes[i]);
        new_node->y = get<1>(nodes[i]);

        insert(&root, new_node);
    }

    PreOrder(root, answer[0]);
    PostOrder(root, answer[1]);

    return answer;
}