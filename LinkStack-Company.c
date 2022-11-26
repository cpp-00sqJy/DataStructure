#include "LinkStack-Company.h"

__linkStack __Cinit_LinkStack()
{
	struct __LinkStack* __stack = malloc(sizeof(struct __LinkStack));

	if (NULL == __stack)
	{
		return NULL;
	}

	__stack->__head.next = NULL;

	__stack->__m_size = 0;

	return __stack;

}

void __Cpush_LinkStack(__linkStack __stack, void* __data)
{
	if (NULL == __stack)
	{
		return;
	}

	if (NULL == __data)
	{
		return;
	}

	struct __LinkStack* __linkstack = __stack;

	if (__linkstack->__m_size == MAX)
	{
		return;
	}

	struct __CListNode* __listnode = __data;

	__listnode->next = __linkstack->__head.next;

	__linkstack->__head.next = __listnode;

	__linkstack->__m_size++;
}

void __Cpop_LinkStack(__linkStack __stack)
{
	if (NULL == __stack)
	{
		return;
	}

	struct __LinkStack* __linkstack = __stack;

	if (__linkstack->__m_size == 0)
	{
		return;
	}

	struct __CListNode* __listnode = __linkstack->__head.next;

	__linkstack->__head.next = __listnode->next;

	__linkstack->__m_size--;
}

void* __Ctop_LinkStack(__linkStack __stack)
{
	if (NULL == __stack)
	{
		return NULL;
	}

	struct __LinkStack* __linkstack = __stack;

	if (__linkstack->__m_size == 0)
	{
		return NULL;
	}

	return __linkstack->__head.next;
}

int __Csize_LinkStack(__linkStack __stack)
{
	if (NULL == __stack)
	{
		return -1;
	}
	struct __LinkStack* __linkstack = __stack;

	return  __linkstack->__m_size;

}

void __Cfree_LinkStack(__linkStack __stack)
{
	if (NULL != __stack)
	{
		free(__stack);
		__stack = NULL;
	}

	return;
}

int __Cempty_LinkStack(__linkStack __stack)
{
	if (NULL == __stack)
	{
		return -1;
	}
	struct __LinkStack* __linkstack = __stack;

	if (0 == __linkstack->__m_size)
	{
		return 1;
	}

	return  0;
}

int __Coverflow_LinkStack(__linkStack __stack)
{
	if (NULL == __stack)
	{
		return -1;
	}
	struct __LinkStack* __linkstack = __stack;

	if (MAX == __linkstack->__m_size)
	{
		return 1;
	}

	return  0;
}