#include "SequenceStack.h"


__seqStack __init_SeqStack()
{
	struct __SeqStack* __stack = malloc(sizeof(struct __SeqStack));

	if (NULL == __stack)
	{
		return NULL;
	}
	memset(__stack->__data, 0, sizeof(void*) * MAX);

	__stack->__m_size = 0;

	return __stack;
}
void __push_SeqStack(__seqStack __stack, void* __data)
{
	if (NULL == __stack)
	{
		return;
	}

	if (NULL == __data)
	{
		return;
	}

	struct __SeqStack* seq = __stack;

	if (seq->__m_size == MAX)
	{
		return;
	}

	seq->__data[seq->__m_size] = __data;

	seq->__m_size++;
}
void __pop_SeqStack(__seqStack __stack)
{
	if (NULL == __stack)
	{
		return;
	}

	struct __SeqStack* seq = __stack;

	if (seq->__m_size == 0)
	{
		return;
	}

	seq->__data[seq->__m_size - 1] = NULL;

	seq->__m_size--;
}

void* __top_SeqStack(__seqStack __stack)
{
	if (NULL == __stack)
	{
		return NULL;
	}

	struct __SeqStack* seq = __stack;

	if (seq->__m_size == 0)
	{
		return NULL;
	}

	return seq->__data[seq->__m_size - 1];
}

int __size_SeqStack(__seqStack __stack)
{
	if (NULL == __stack)
	{
		return -1;
	}

	struct __SeqStack* seq = __stack;

	return seq->__m_size;
}

void __free_SeqStack(__seqStack __stack)
{
	if (NULL != __stack)
	{
		free(__stack);
		__stack = NULL;
	}

	return;
}

int __empty_SeqStack(__seqStack __stack)
{
	if (NULL == __stack)
	{
		return -1;
	}
	struct __SeqStack* seq = __stack;

	if (seq->__m_size == 0)
	{
		return 1;
	}

	return 0;
}

int __overflow_SeqStack(__seqStack __stack)
{
	if (NULL == __stack)
	{
		return -1;
	}
	struct __SeqStack* seq = __stack;

	if (seq->__m_size == MAX)
	{
		return 1;
	}

	return 0;
}