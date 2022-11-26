#include "SequenceStack.h"

struct __NBinaryTree
{
	char __ch;

	struct __NBinaryTree* __lChild;

	struct __NBinaryTree* __rChild;

	int __flag;

};

enum TraversalType { __DLR, __LDR, __LRD };

void __Non_Recursion_Traversal(struct __NBinaryTree* __tree, int __Type);

