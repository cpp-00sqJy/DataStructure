#ifndef __LINKSTACKCOMPANY__
#define __LINKSTACKCOMPANY__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

struct __CListNode
{
	struct __CListNode* next;
};

struct __LinkStack
{
	struct __CListNode __head;

	int __m_size;
};

typedef void* __linkStack;


__linkStack __Cinit_LinkStack();

void __Cpush_LinkStack(__linkStack __stack, void* __data);

void __Cpop_LinkStack(__linkStack __stack);

void* __Ctop_LinkStack(__linkStack __stack);

int __Csize_LinkStack(__linkStack __stack);

void __Cfree_LinkStack(__linkStack __stack);

int __Cempty_LinkStack(__linkStack __stack);

int __Coverflow_LinkStack(__linkStack __stack);






#endif // !__LINKSTACKCOMPANY__
