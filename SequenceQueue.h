#ifndef __SEQUENCEQUEUE__
#define __SEQUENCEQUEUE__
#include "DynamicArray.h"
#define MAX 1024

typedef void* __seqQueue;


__seqQueue __init_SeqQueue();

void __push_SeqQueue(__seqQueue __queue, void* __data);

void __pop_SeqQueue(__seqQueue __queue);

void* __tail_SeqQueue(__seqQueue __queue);

void* __front_SeqQueue(__seqQueue __queue);

int __size_SeqQueue(__seqQueue __queue);

int __empty_SeqQueue(__seqQueue __queue);

int __full_SeqQueue(__seqQueue __queue);

void __destroy_SeqQueue(__seqQueue __queue);


#endif // !__SEQUENCEQUEUE__



