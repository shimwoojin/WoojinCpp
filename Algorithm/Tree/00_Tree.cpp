#include <iostream>

struct Tree
{
	int Data;

	Tree* LeftChild;
	Tree* RightSibling;
};

Tree* LCRS_CreateTree(int Data)
{
	Tree* new_tree = static_cast<Tree*>(malloc(sizeof(Tree)));

	new_tree->LeftChild = nullptr;
	new_tree->RightSibling = nullptr;
	new_tree->Data = Data;
	
	return new_tree;
}

void LCRS_DestroyTree(Tree* tree)
{
	free(tree);
}

void LCRS_AddChildTree(Tree* Parent, Tree* Child)
{
	if (Parent->LeftChild == nullptr)
	{
		Parent->LeftChild = Child;
	}
	else
	{
		Tree* temp = Parent->LeftChild;
		while (temp->RightSibling != nullptr) temp = temp->RightSibling;

		temp->RightSibling = Child;
	}
}

void LCRS_PrintTree(Tree* tree, int Depth)
{
	for (int i = 0; i < Depth; i++)
		std::cout << " ";

	std::cout << tree->Data << std::endl;

	if (tree->LeftChild != nullptr)
		LCRS_PrintTree(tree->LeftChild, Depth + 1);
	if (tree->RightSibling != nullptr)
		LCRS_PrintTree(tree->RightSibling, Depth + 1);


}


int main()
{
	Tree* Root = LCRS_CreateTree(0);

	Tree* Gen_1_1 = LCRS_CreateTree(1);
	Tree* Gen_1_2 = LCRS_CreateTree(2);

	Tree* Gen_2_1 = LCRS_CreateTree(3);
	Tree* Gen_2_2 = LCRS_CreateTree(4);
	Tree* Gen_2_3 = LCRS_CreateTree(5);

	Tree* Gen_3_1 = LCRS_CreateTree(6);
	Tree* Gen_3_2 = LCRS_CreateTree(7);
	Tree* Gen_3_3 = LCRS_CreateTree(8);

	LCRS_AddChildTree(Root, Gen_1_1);
	LCRS_AddChildTree(Root, Gen_1_2);

	LCRS_AddChildTree(Gen_1_1, Gen_2_1);
	LCRS_AddChildTree(Gen_1_2, Gen_2_2);
	LCRS_AddChildTree(Gen_1_2, Gen_2_3);

	LCRS_AddChildTree(Gen_2_1, Gen_3_1);
	LCRS_AddChildTree(Gen_2_2, Gen_3_2);
	LCRS_AddChildTree(Gen_2_3, Gen_3_3);

	LCRS_PrintTree(Root, 0);

	LCRS_DestroyTree(Root);


	return 0;
}