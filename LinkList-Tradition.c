﻿#include "LinkList-Tradition.h"



__linklist __init_Singly_LinkList()
{

	struct __LinkList* __link = malloc(sizeof(struct __LinkList));

	if (NULL == __link)
	{
		return NULL;
	}

	__link->__m_head.__next = NULL;
	__link->__m_Size = 0;

	return __link;

}

void __insere_Singly_LinkList(__linklist __list, void* __data, int __pos)
{
	if (NULL == __list)
	{
		return;
	}

	if (NULL == __data)
	{
		return;
	}
	struct __LinkList* __TempList = (struct __LinkList*)__list;

	if (__pos < 0 || __pos >__TempList->__m_Size)
	{
		__pos = __TempList->__m_Size;
	}

	struct __ListNode* __CurrentNode = &__TempList->__m_head;

	for (size_t i = 0; i < __pos; i++)
	{
		__CurrentNode = __CurrentNode->__next;
	}

	struct __ListNode* __NewNode = malloc(sizeof(struct __ListNode));

	__NewNode->__data = __data;
	__NewNode->__next = NULL;

	__NewNode->__next = __CurrentNode->__next;
	__CurrentNode->__next = __NewNode;

	__TempList->__m_Size++;
}

void  __Traversal_Singly_LinkList(const __linklist __list, const void(*_Diy_Print)(void* arg))
{
	if (NULL == __list)
	{
		return;
	}

	struct __LinkList* __TempList = (struct __LinkList*)__list;

	struct __ListNode* __listNode = __TempList->__m_head.__next;


	for (int i = 0; i < __TempList->__m_Size; i++)
	{
		_Diy_Print(__listNode->__data);

		__listNode = __listNode->__next;
	}

}

void __Delete_Singly_LinkList_By_Pos(__linklist __list, int __pos)
{
	if (NULL == __list)
	{
		return;
	}

	struct __LinkList* __TempList = (struct __LinkList*)__list;

	if (__pos < 0 || __pos >__TempList->__m_Size - 1)
	{
		return;
	}

	struct __ListNode* __CurrentNode = &__TempList->__m_head;

	for (size_t i = 0; i < __pos; i++)
	{
		__CurrentNode = __CurrentNode->__next;
	}

	struct __ListNode* __DelNode = __CurrentNode->__next;

	__CurrentNode->__next = __DelNode->__next;

	free(__DelNode);

	__TempList->__m_Size--;
}

void __Delete_Singly_LinkList_By_Value(__linklist __list, void* __data, int (*__Compare_Data)(void* __data1, void* __data2))
{
	if (NULL == __list)
	{
		return;
	}

	if (NULL == __data)
	{
		return;
	}

	struct __LinkList* __TempList = (struct __LinkList*)__list;

	struct __ListNode* __CurrentNode = __TempList->__m_head.__next;

	struct __ListNode* __PreNode = &__TempList->__m_head;

	for (int i = 0; i < __TempList->__m_Size; i++)
	{
		if (__Compare_Data(__data, __CurrentNode->__data))
		{
			__PreNode->__next = __CurrentNode->__next;

			free(__CurrentNode);
			__CurrentNode = NULL;

			__TempList->__m_Size--;

			break;
		}
		__PreNode = __CurrentNode;
		__CurrentNode = __CurrentNode->__next;
	}



}

void __Clear_Singly_LinkList(__linklist __list)
{
	if (NULL == __list)
	{
		return;
	}

	struct __LinkList* __TempList = (struct __LinkList*)__list;

	struct __ListNode* __CurrentNode = __TempList->__m_head.__next;



	for (int i = 0; i < __TempList->__m_Size; i++)
	{
		struct __ListNode* __Curr_Next_Node = __CurrentNode->__next;

		free(__CurrentNode);

		__CurrentNode = __Curr_Next_Node;

	}

	__TempList->__m_head.__next = NULL;
	__TempList->__m_Size = 0;
}

void __Free_Singly_LinkList(__linklist __list)
{
	if (NULL != __list)
	{
		free(__list);
		__list = NULL;
	}


	return;
}


int __Get_LinkList_Size(const __linklist __list)
{
	if (NULL == __list)
	{
		return -1;
	}


	struct __LinkList* __TempList = (struct __LinkList*)__list;

	return __TempList->__m_Size;
}
