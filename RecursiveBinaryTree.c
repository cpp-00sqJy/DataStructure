#include "RecursiveBinaryTree.h"


void __DLR_Recursion_Traversal(struct __BinaryTree* __tree)
{
	if (NULL == __tree)
	{
		return;
	}

	printf("%c ", __tree->__ch);

	__DLR_Recursion_Traversal(__tree->__lChild);

	__DLR_Recursion_Traversal(__tree->__rChild);

	return;
}
void __LDR_Recursion_Traversal(struct __BinaryTree* __tree)
{

	if (NULL == __tree)
	{
		return;
	}

	__LDR_Recursion_Traversal(__tree->__lChild);

	printf("%c ", __tree->__ch);

	__LDR_Recursion_Traversal(__tree->__rChild);


}

void __LRD_Recursion_Traversal(struct __BinaryTree* __tree)
{

	if (NULL == __tree)
	{
		return;
	}

	__LRD_Recursion_Traversal(__tree->__lChild);

	__LRD_Recursion_Traversal(__tree->__rChild);

	printf("%c ", __tree->__ch);
}

void __Lear_Node(struct __BinaryTree* __tree, int* p)
{
	if (NULL == __tree)
	{
		return;
	}

	if (__tree->__lChild == NULL && __tree->__rChild == NULL)
	{
		(*p)++;
	}

	__Lear_Node(__tree->__lChild, p);

	__Lear_Node(__tree->__rChild, p);
}


int __Height_Tree(struct __BinaryTree* __tree)
{
	if (NULL == __tree)
	{
		return 0;
	}

	int __lHeight = __Height_Tree(__tree->__lChild);

	int __rHeight = __Height_Tree(__tree->__rChild);

	int __TotalHeight = (__lHeight > __rHeight) ? __lHeight + 1 : __rHeight + 1;

	return __TotalHeight;
}

struct __BinaryTree* __Copy_BinaryTree(struct __BinaryTree* __tree)
{
	if (NULL == __tree)
	{
		return NULL;
	}
	struct __BinaryTree* __left_Child = __Copy_BinaryTree(__tree->__lChild);

	struct __BinaryTree* __right_Child = __Copy_BinaryTree(__tree->__rChild);

	struct __BinaryTree* __newTreeBode = malloc(sizeof(struct __BinaryTree));

	__newTreeBode->__lChild = __left_Child;

	__newTreeBode->__rChild = __right_Child;

	__newTreeBode->__ch = __tree->__ch;

	return __newTreeBode;

}

void __Destroy_BinaryTree(struct __BinaryTree* __tree)
{
	if (NULL == __tree)
	{
		return;
	}

	__Destroy_BinaryTree(__tree->__lChild);

	__Destroy_BinaryTree(__tree->__rChild);

	printf("%c 结点被释放\n ", __tree->__ch);
	free(__tree);


}