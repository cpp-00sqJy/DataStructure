#ifndef __LinkListTradition__
#define __LinkListTradition__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __ListNode
{
	void* __data;

	struct __ListNode* __next;

};

struct __LinkList
{
	struct __ListNode __m_head;

	int __m_Size;
};

typedef void* __linklist;

__linklist __init_Singly_LinkList();

void __insere_Singly_LinkList(__linklist __list, void* __data, int __pos);

void  __Traversal_Singly_LinkList(const __linklist __list, const void(*_Diy_Print)(void* arg));

void __Delete_Singly_LinkList_By_Pos(__linklist __list, int __pos);

void __Delete_Singly_LinkList_By_Value(__linklist __list, void* __data, int (*__Compare_Data)(void* __data1, void* __data2));

void __Clear_Singly_LinkList(__linklist __list);

void __Free_Singly_LinkList(__linklist __list);

int __Get_LinkList_Size(const __linklist __list);




#endif // !__LINKLIST
