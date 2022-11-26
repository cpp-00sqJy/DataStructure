#include "Non-Recursive-BinaryTree.h"


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

		if (__Type == __DLR)
		{
			if (__nTree->__rChild != NULL)
			{
				__push_SeqStack(__stack, __nTree->__rChild);
			}
			if (__nTree->__lChild != NULL)
			{
				__push_SeqStack(__stack, __nTree->__lChild);
			}
			__push_SeqStack(__stack, __nTree);
		}
		else if (__Type == __LDR)
		{
			if (__nTree->__rChild != NULL)
			{
				__push_SeqStack(__stack, __nTree->__rChild);

			}
			__push_SeqStack(__stack, __nTree);

			if (__nTree->__lChild != NULL)
			{
				__push_SeqStack(__stack, __nTree->__lChild);
			}
		}
		else if (__Type == __LRD)
		{
			__push_SeqStack(__stack, __nTree);

			if (__nTree->__rChild != NULL)
			{
				__push_SeqStack(__stack, __nTree->__rChild);
			}

			if (__nTree->__lChild != NULL)
			{
				__push_SeqStack(__stack, __nTree->__lChild);
			}
		}

	}

	__free_SeqStack(__stack);
}



