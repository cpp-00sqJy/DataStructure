#include "LinkQueue-Company.h"


__linkqueue __Cinit_LinkQueue()
{
	struct __LinkQueue* __Linkqueue = malloc(sizeof(struct __LinkQueue));

	if (NULL == __Linkqueue)
	{
		return NULL;
	}

	__Linkqueue->__head.__next = NULL;

	__Linkqueue->__tail = &__Linkqueue->__head;

	__Linkqueue->__m_size = 0;

	return __Linkqueue;

}

void __Cpush_LinkQueue(__linkqueue __queue, void* __data)
{
	if (NULL == __queue)
	{
		return;
	}

	if (NULL == __data)
	{
		return;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	if (__Linkqueue->__m_size == MAX)
	{
		return;
	}

	struct __QListNode* __qListNode = __data;

	__Linkqueue->__tail->__next = __qListNode;

	__qListNode->__next = NULL;

	__Linkqueue->__tail = __qListNode;

	__Linkqueue->__m_size++;
}

void __Cpop_LinkQueue(__linkqueue __queue)
{
	if (NULL == __queue)
	{
		return;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	if (__Linkqueue->__m_size == 0)
	{
		return;
	}

	if (__Linkqueue->__m_size == 1)
	{
		__Linkqueue->__head.__next = NULL;

		__Linkqueue->__tail = &__Linkqueue->__head;

		__Linkqueue->__m_size--;

		return;
	}

	struct __QListNode* __DelNode = __Linkqueue->__head.__next;

	__Linkqueue->__head.__next = __DelNode->__next;

	__Linkqueue->__m_size--;

}

void* __Ctail_LinkQueue(__linkqueue __queue)
{
	if (NULL == __queue)
	{
		return NULL;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	if (__Linkqueue->__m_size == 0)
	{
		return NULL;
	}

	return __Linkqueue->__tail;
}

void* __Cfront_LinkQueue(__linkqueue __queue)
{
	if (NULL == __queue)
	{
		return NULL;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	if (__Linkqueue->__m_size == 0)
	{
		return NULL;
	}

	return __Linkqueue->__head.__next;
}

int __Csize_LinkQueue(__linkqueue __queue)
{
	if (NULL == __queue)
	{
		return -1;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	return __Linkqueue->__m_size;
}

int __Cempty_LinkQueue(__linkqueue __queue)
{
	if (NULL == __queue)
	{
		return -1;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	if (__Linkqueue->__m_size == 0)
	{
		return 1;
	}

	return 0;
}

int __Cfull_LinkQueue(__linkqueue __queue)
{
	if (NULL == __queue)
	{
		return -1;
	}

	struct __LinkQueue* __Linkqueue = __queue;

	if (__Linkqueue->__m_size == MAX)
	{
		return 1;
	}

	return 0;
}

void __Cdestroy_LinkQueue(__linkqueue __queue)
{
	if (NULL != __queue)
	{
		free(__queue);
		__queue = NULL;
		return;
	}

	return;
}