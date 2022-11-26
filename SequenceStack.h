#ifndef __SEQSTACK__
#define __SEQSTACK__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1024

struct __SeqStack
{
	void* __data[MAX];

	int __m_size;
};

typedef void* __seqStack;


__seqStack __init_SeqStack();

void __push_SeqStack(__seqStack __stack, void* _data);

void __pop_SeqStack(__seqStack __stack);

void* __top_SeqStack(__seqStack __stack);

int __size_SeqStack(__seqStack __stack);

void __free_SeqStack(__seqStack __stack);

int __empty_SeqStack(__seqStack __stack);

int __overflow_SeqStack(__seqStack __stack);


#endif // !__SEQSTACK__
