#include "Non-Recursive-BinaryTree.h"


int __Tree_IsNull(struct __NBinaryTree* __tree)
{
	if (__tree == NULL)
	{
		return 1;
	}

	return 0;
}

void __Non_Recursion_Traversal(struct __NBinaryTree* __tree, int __Type)
{
	__seqStack __stack = __init_SeqStack();

	__push_SeqStack(__stack, __tree);

	while (__size_SeqStack(__stack) > 0)
	{
		struct __NBinaryTree* __nTree = __top_SeqStack(__stack);

		__pop_SeqStack(__stack);

		if (__nTree->__flag == 1)
		{
			printf("%c ", __nTree->__ch);
			continue;
		}

		__nTree->__flag = 1;
		switch (__Type)
		{
		case __DLR:
			if (__Tree_IsNull(__nTree->__rChild) == 0) __push_SeqStack(__stack, __nTree->__rChild);

			if (__Tree_IsNull(__nTree->__lChild) == 0) __push_SeqStack(__stack, __nTree->__lChild);

			__push_SeqStack(__stack, __nTree);

			break;

		case __LDR:
			if (__Tree_IsNull(__nTree->__rChild) == 0) __push_SeqStack(__stack, __nTree->__rChild);

			__push_SeqStack(__stack, __nTree);

			if (__Tree_IsNull(__nTree->__lChild) == 0) __push_SeqStack(__stack, __nTree->__lChild);

			break;

		case __LRD:

			__push_SeqStack(__stack, __nTree);

			if (__Tree_IsNull(__nTree->__rChild) == 0) __push_SeqStack(__stack, __nTree->__rChild);

			if (__Tree_IsNull(__nTree->__lChild) == 0) __push_SeqStack(__stack, __nTree->__lChild);

			break;

		default:

			break;
		}

	}

	__free_SeqStack(__stack);
}
