#include "SequenceQueue.h"

__seqQueue __init_SeqQueue()
{
	struct __DynamicArray* __queue = __initDynamicArray(MAX);

	return __queue;
}

void __push_SeqQueue(__seqQueue __queue, void* __data)
{
	if (NULL == __queue)
	{
		return;
	}

	if (NULL == __data)
	{
		return;
	}

	struct __DynamicArray* __Queue = __queue;

	if (__Queue->_m_Size == MAX)
	{
		return;
	}

	__Insert_DynamicArray(__Queue, __data, __Queue->_m_Size);
}

void __pop_SeqQueue(__seqQueue __queue)
{
	if (NULL == __queue)
	{
		return;
	}
	struct __DynamicArray* __Queue = __queue;

	if (__Queue->_m_Size == 0)
	{
		return;
	}

	__DeletebyPos_DynamicArray(__Queue, 0);

}

void* __tail_SeqQueue(__seqQueue __queue)
{
	if (NULL == __queue)
	{
		return NULL;
	}
	struct __DynamicArray* __Queue = __queue;

	if (__Queue->_m_Size == 0)
	{
		return NULL;
	}

	return __Queue->_p_Addr[__Queue->_m_Size - 1];
}

void* __front_SeqQueue(__seqQueue __queue)
{

	if (NULL == __queue)
	{
		return NULL;
	}
	struct __DynamicArray* __Queue = __queue;

	if (__Queue->_m_Size == 0)
	{
		return NULL;
	}

	return __Queue->_p_Addr[0];
}

int __size_SeqQueue(__seqQueue __queue)
{
	if (NULL == __queue)
	{
		return -1;
	}
	struct __DynamicArray* __Queue = __queue;

	return __Queue->_m_Size;
}

int __empty_SeqQueue(__seqQueue __queue)
{
	if (NULL == __queue)
	{
		return -1;
	}
	struct __DynamicArray* __Queue = __queue;

	if (__Queue->_m_Size == 0)
	{
		return 1;
	}

	return 0;
}
int __full_SeqQueue(__seqQueue __queue)
{
	if (NULL == __queue)
	{
		return -1;
	}
	struct __DynamicArray* __Queue = __queue;

	if (__Queue->_m_Size == MAX)
	{
		return 1;
	}

	return 0;
}

void __destroy_SeqQueue(__seqQueue __queue)
{
	if (__queue != NULL)
	{
		free(__queue);
		__queue = NULL;
	}

	return;
}