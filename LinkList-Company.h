#ifndef __LinkListCompany__
#define __LinkListCompany__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __ListNode
{
	struct __ListNode* __next;
};

struct __LinkList
{
	struct __ListNode __m_head;

	int __m_Size;
};

typedef void* __linklist;

__linklist __Cinit_Singly_LinkList();

void __Cinsert_Singly_LinkList(__linklist __list, const void* __data, int __pos);

void  __CTraversal_Singly_LinkList(const __linklist __list, const void(*_Diy_Print)(void* arg));

void __CDelete_Singly_LinkList_By_Pos(__linklist __list, int __pos);

void __CDelete_Singly_LinkList_By_Value(__linklist __list, void* __data, int (*__Compare_Data)(void* __data1, void* __data2));

void __CClear_Singly_LinkList(__linklist __list);

void __CFree_Singly_LinkList(__linklist __list);

int  __CGet_LinkList_Size(const __linklist __list);




#endif // !LinkList-Company
