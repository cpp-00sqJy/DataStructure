#ifndef __LINKQUEUECOMPANY__
#define __LINKQUEUECOMPANY__
#define MAX 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __QListNode
{
	struct __QListNode* __next;
};

struct __LinkQueue
{
	struct __QListNode __head;

	struct __QListNode* __tail;

	int __m_size;
};

typedef void* __linkqueue;


__linkqueue __Cinit_LinkQueue();

void __Cpush_LinkQueue(__linkqueue __queue, void* __data);

void __Cpop_LinkQueue(__linkqueue __queue);

void* __Ctail_LinkQueue(__linkqueue __queue);

void* __Cfront_LinkQueue(__linkqueue __queue);

int __Csize_LinkQueue(__linkqueue __queue);

int __Cempty_LinkQueue(__linkqueue __queue);

int __Cfull_LinkQueue(__linkqueue __queue);

void __Cdestroy_LinkQueue(__linkqueue __queue);




#endif