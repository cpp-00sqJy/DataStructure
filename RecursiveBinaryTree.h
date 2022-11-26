#ifndef __RECURSIVEBINARYTREE__
#define __RECURSIVEBINARYTREE__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __BinaryTree
{
	char __ch;

	struct __BinaryTree* __lChild;

	struct __BinaryTree* __rChild;

};


void __DLR_Recursion_Traversal(struct __BinaryTree* __tree);

void __LDR_Recursion_Traversal(struct __BinaryTree* __tree);

void __LRD_Recursion_Traversal(struct __BinaryTree* __tree);

void __Lear_Node(struct __BinaryTree* __tree, int* p);

struct __BinaryTree* __Copy_BinaryTree(struct __BinaryTree* __tree);

void __Destroy_BinaryTree(struct __BinaryTree* __tree);

int __Height_Tree(struct __BinaryTree* __tree);


#endif // !__RECURSIVEBINARYTREE__

