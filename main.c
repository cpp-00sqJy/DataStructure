#include  <crtdbg.h>  
#include "DynamicArray.h"
#include "LinkList-Company.h"
#include "SequenceStack.h"
#include "LinkStack-Company.h"
#include "Stack-Nearby-Matching.h"
#include "SequenceQueue.h"
#include "LinkQueue-Company.h"
#include "RecursiveBinaryTree.h"
#include "Non-Recursive-BinaryTree.h"
#define CRTDBG_MAP_ALLOC  

//在入口函数中包含 _CrtDumpMemoryLeaks();  
//即可检测到内存泄露

//定义函数：
inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
//该函数可以放在主函数的任意位置，都能正确的触发内存泄露输出


struct Person
{
	char name[64];
	int age;
};
struct CPerson
{
	int* node;
	char name[64];
	int age;
};
void _Diy_Print(void* arg)
{
	struct CPerson* p = (struct CPerson*)arg;

	printf("姓名: %s , 年龄: %d \n", p->name, p->age);
}

int _Compare_Data(void* _Data1, void* _Data2)
{
	if (NULL == _Data1 || NULL == _Data2)
	{
		return -1;
	}
	struct CPerson* p1 = (struct CPerson*)_Data1;
	struct CPerson* p2 = (struct CPerson*)_Data2;


	return strcmp(p1->name, p1->name) == 0 && p1->age == p2->age;
}

int main()
{
#if 0
	EnableMemLeakCheck();
	struct _DynamicArray* _Array = __initDynamicArray(5);

	struct Person p1 = { "额娃",12 };
	struct Person p2 = { "可去",11 };
	struct Person p3 = { "日日",13 };
	struct Person p4 = { "让我",14 };
	struct Person p5 = { "砸在",15 };
	struct Person p6 = { "而且",18 };

	__Insert_DynamicArray(_Array, &p1, 0);
	__Insert_DynamicArray(_Array, &p2, 1);
	__Insert_DynamicArray(_Array, &p3, 2);
	__Insert_DynamicArray(_Array, &p4, 3);
	__Insert_DynamicArray(_Array, &p5, 4);
	__Insert_DynamicArray(_Array, &p6, 5);

	__Traversal__DynamicArray(_Array, _Diy_Print);
	printf("-----------------------\n");

	__DeletebyPos_DynamicArray(_Array, 1);
	__Traversal__DynamicArray(_Array, _Diy_Print);
	printf("-----------------------\n");

	__DeletebyValue_DynamicArray(_Array, _Compare_Data, &p5);
	__Traversal__DynamicArray(_Array, _Diy_Print);
	printf("-----------------------\n");

	__Free_DynamicArray(_Array);
#endif // DynamicArray

#if 0

	EnableMemLeakCheck();

	__linklist list = __init_Singly_LinkList();


	struct Person p1 = { "额娃",12 };
	struct Person p2 = { "可去",11 };
	struct Person p3 = { "日日",13 };
	struct Person p4 = { "让我",14 };
	struct Person p5 = { "砸在",15 };
	struct Person p6 = { "而且",18 };

	printf("当前链表大小为: %d \n", __Get_LinkList_Size(list));

	__insere_Singly_LinkList(list, &p1, 0);
	__insere_Singly_LinkList(list, &p2, 1);
	__insere_Singly_LinkList(list, &p3, 2);
	__insere_Singly_LinkList(list, &p4, 3);
	__insere_Singly_LinkList(list, &p5, 4);
	__insere_Singly_LinkList(list, &p6, 5);

	__Traversal_Singly_LinkList(list, _Diy_Print);

	printf("当前链表大小为: %d \n", __Get_LinkList_Size(list));

	__Delete_Singly_LinkList_By_Pos(list, 0);

	__Traversal_Singly_LinkList(list, _Diy_Print);

	printf("当前链表大小为: %d \n", __Get_LinkList_Size(list));

	__Delete_Singly_LinkList_By_Value(list, &p2, _Compare_Data);

	__Traversal_Singly_LinkList(list, _Diy_Print);

	printf("当前链表大小为: %d \n", __Get_LinkList_Size(list));

	__Clear_Singly_LinkList(list);

	printf("当前链表大小为: %d \n", __Get_LinkList_Size(list));

	__Free_Singly_LinkList(list);


#endif // LinkList-Tradition

#if 0

	EnableMemLeakCheck();

	__linklist list = __Cinit_Singly_LinkList();


	struct CPerson p1 = { NULL,"额娃",12 };
	struct CPerson p2 = { NULL,"可去",11 };
	struct CPerson p3 = { NULL,"日日",13 };
	struct CPerson p4 = { NULL,"让我",14 };
	struct CPerson p5 = { NULL,"砸在",15 };
	struct CPerson p6 = { NULL,"而且",18 };


	__Cinsert_Singly_LinkList(list, &p1, 0);
	__Cinsert_Singly_LinkList(list, &p2, 1);
	__Cinsert_Singly_LinkList(list, &p3, 2);
	__Cinsert_Singly_LinkList(list, &p4, 3);
	__Cinsert_Singly_LinkList(list, &p5, 4);
	__Cinsert_Singly_LinkList(list, &p6, 5);

	__CTraversal_Singly_LinkList(list, _Diy_Print);
	printf("-----------------------\n");


	__CDelete_Singly_LinkList_By_Pos(list, 3);

	__CTraversal_Singly_LinkList(list, _Diy_Print);
	printf("-----------------------\n");

	__CDelete_Singly_LinkList_By_Value(list, &p2, _Compare_Data);
	__CTraversal_Singly_LinkList(list, _Diy_Print);
	printf("-----------------------\n");

	__CClear_Singly_LinkList(list);
	printf("当前链表大小为: %d \n", __CGet_LinkList_Size(list));

	__CFree_Singly_LinkList(list);
	printf("当前链表大小为: %d \n", __CGet_LinkList_Size(list));

#endif // LinkList-Company;

#if 0
	EnableMemLeakCheck();

	__seqStack seq = __init_SeqStack();

	struct Person p1 = { "额娃",12 };
	struct Person p2 = { "可去",11 };
	struct Person p3 = { "日日",13 };
	struct Person p4 = { "让我",14 };
	struct Person p5 = { "砸在",15 };
	struct Person p6 = { "而且",18 };

	__push_SeqStack(seq, &p1);
	__push_SeqStack(seq, &p2);
	__push_SeqStack(seq, &p3);
	__push_SeqStack(seq, &p4);
	__push_SeqStack(seq, &p5);
	__push_SeqStack(seq, &p6);

	printf("当前栈大小: %d \n", __size_SeqStack(seq));

	while (__empty_SeqStack(seq) == 0)
	{
		struct Person* p = __top_SeqStack(seq);

		printf("姓名: %s , 年龄: %d \n", p->name, p->age);

		__pop_SeqStack(seq);
	}
	printf("当前栈大小: %d \n", __size_SeqStack(seq));

	__free_SeqStack(seq);
	printf("当前栈大小: %d \n", __size_SeqStack(seq));

#endif //SequenceStack

#if 0


	EnableMemLeakCheck();

	__linkStack linkStack = __Cinit_LinkStack();

	struct CPerson p1 = { NULL,"额娃",12 };
	struct CPerson p2 = { NULL,"可去",11 };
	struct CPerson p3 = { NULL,"日日",13 };
	struct CPerson p4 = { NULL,"让我",14 };
	struct CPerson p5 = { NULL,"砸在",15 };
	struct CPerson p6 = { NULL,"而且",18 };

	__Cpush_LinkStack(linkStack, &p1);
	__Cpush_LinkStack(linkStack, &p2);
	__Cpush_LinkStack(linkStack, &p3);
	__Cpush_LinkStack(linkStack, &p4);
	__Cpush_LinkStack(linkStack, &p5);
	__Cpush_LinkStack(linkStack, &p6);

	printf("当前栈大小: %d \n", __Csize_LinkStack(linkStack));


	while (__Cempty_LinkStack(linkStack) == 0)
	{
		struct CPerson* p = __Ctop_LinkStack(linkStack);

		printf("链栈 ----  姓名: %s , 年龄: %d \n", p->name, p->age);

		__Cpop_LinkStack(linkStack);
	}

	printf("当前栈大小: %d \n", __Csize_LinkStack(linkStack));

	__Cfree_LinkStack(linkStack);
	printf("当前栈大小: %d \n", __Csize_LinkStack(linkStack));

#endif// LinkStack-Company

#if 0

	char* str = "5+5*(6)+9/3*1-(1+3(";

	__Scan_From_String(str);

#endif // Stack-Nearby-Matching


#if 0

	EnableMemLeakCheck();

	__seqQueue queue = __init_SeqQueue();

	struct Person p1 = { "额娃",12 };
	struct Person p2 = { "可去",11 };
	struct Person p3 = { "日日",13 };
	struct Person p4 = { "让我",14 };
	struct Person p5 = { "砸在",15 };
	struct Person p6 = { "而且",18 };

	__push_SeqQueue(queue, &p1);
	__push_SeqQueue(queue, &p2);
	__push_SeqQueue(queue, &p3);
	__push_SeqQueue(queue, &p4);
	__push_SeqQueue(queue, &p5);
	__push_SeqQueue(queue, &p6);

	printf("当前队列大小: %d \n", __size_SeqQueue(queue));

	while (__empty_SeqQueue(queue) == 0)
	{
		struct Person* p = __front_SeqQueue(queue);
		struct Person* p10 = __tail_SeqQueue(queue);
		printf("队头: %s  %d \n", p->name, p->age);
		printf("队尾: %s  %d \n", p10->name, p10->age);

		__pop_SeqQueue(queue);
	}

	printf("当前队列大小: %d \n", __size_SeqQueue(queue));

	__destroy_SeqQueue(queue);
	printf("当前队列大小: %d \n", __size_SeqQueue(queue));


#endif // SequenceQueue

#if 0

	EnableMemLeakCheck();

	__linkqueue linkq = __Cinit_LinkQueue();

	struct CPerson p1 = { NULL,"额娃",12 };
	struct CPerson p2 = { NULL,"可去",11 };
	struct CPerson p3 = { NULL,"日日",13 };
	struct CPerson p4 = { NULL,"让我",14 };
	struct CPerson p5 = { NULL,"砸在",15 };
	struct CPerson p6 = { NULL,"而且",18 };

	__Cpush_LinkQueue(linkq, &p1);
	__Cpush_LinkQueue(linkq, &p2);
	__Cpush_LinkQueue(linkq, &p3);
	__Cpush_LinkQueue(linkq, &p4);
	__Cpush_LinkQueue(linkq, &p5);
	__Cpush_LinkQueue(linkq, &p6);

	printf("当前队列大小: %d \n", __Csize_LinkQueue(linkq));

	while (__Cempty_LinkQueue(linkq) == 0)
	{
		struct CPerson* p = __Cfront_LinkQueue(linkq);
		struct CPerson* p10 = __Ctail_LinkQueue(linkq);
		printf("链式队列 ----- 队头: %s  %d \n", p->name, p->age);
		printf("链式队列 ----- 队尾: %s  %d \n", p10->name, p10->age);

		__Cpop_LinkQueue(linkq);
	}

	printf("当前队列大小: %d \n", __Csize_LinkQueue(linkq));

	__Cdestroy_LinkQueue(linkq);
	printf("当前队列大小: %d \n", __Csize_LinkQueue(linkq));


#endif // LinkQueue-Company

#if 0

	EnableMemLeakCheck();


	struct __BinaryTree __treeA = { 'A',NULL,NULL };
	struct __BinaryTree __treeB = { 'B',NULL,NULL };
	struct __BinaryTree __treeC = { 'C',NULL,NULL };
	struct __BinaryTree __treeD = { 'D',NULL,NULL };
	struct __BinaryTree __treeE = { 'E',NULL,NULL };
	struct __BinaryTree __treeF = { 'F',NULL,NULL };
	struct __BinaryTree __treeG = { 'G',NULL,NULL };
	struct __BinaryTree __treeH = { 'H',NULL,NULL };

	__treeA.__lChild = &__treeB;
	__treeA.__rChild = &__treeF;

	__treeB.__rChild = &__treeC;

	__treeC.__lChild = &__treeD;
	__treeC.__rChild = &__treeE;

	__treeF.__rChild = &__treeG;

	__treeG.__lChild = &__treeH;

	printf("先序遍历: ↓\n");

	__DLR_Recursion_Traversal(&__treeA);

	printf("\n");

	printf("中序遍历: ↓\n");

	__LDR_Recursion_Traversal(&__treeA);

	printf("\n");

	printf("后序遍历: ↓\n");

	__LRD_Recursion_Traversal(&__treeA);

	printf("\n");
	int num = 0;
	__Lear_Node(&__treeA, &num);

	printf("叶子结点个数: %d \n", num);
	printf("\n");

	printf("树的高度: %d \n", __Height_Tree(&__treeA));

	struct __BinaryTree* tree = __Copy_BinaryTree(&__treeA);

	printf("先序遍历: ↓\n");

	__DLR_Recursion_Traversal(tree);

	printf("\n");
	__Destroy_BinaryTree(tree);


#endif // RecursiveBinaryTree

#if 1

	EnableMemLeakCheck();


	struct __NBinaryTree __treeA = { 'A',NULL,NULL,0 };
	struct __NBinaryTree __treeB = { 'B',NULL,NULL,0 };
	struct __NBinaryTree __treeC = { 'C',NULL,NULL,0 };
	struct __NBinaryTree __treeD = { 'D',NULL,NULL,0 };
	struct __NBinaryTree __treeE = { 'E',NULL,NULL,0 };
	struct __NBinaryTree __treeF = { 'F',NULL,NULL,0 };
	struct __NBinaryTree __treeG = { 'G',NULL,NULL,0 };
	struct __NBinaryTree __treeH = { 'H',NULL,NULL,0 };

	__treeA.__lChild = &__treeB;
	__treeA.__rChild = &__treeF;

	__treeB.__rChild = &__treeC;

	__treeC.__lChild = &__treeD;
	__treeC.__rChild = &__treeE;

	__treeF.__rChild = &__treeG;

	__treeG.__lChild = &__treeH;

	printf("先序遍历: ↓\n");

	__Non_Recursion_Traversal(&__treeA, __DLR);

	printf("\n");

	//printf("中序遍历: ↓\n");


	//__Non_Recursion_Traversal(&__treeA, __LDR);

	//printf("\n");

	//printf("后序遍历: ↓\n");

	//__Non_Recursion_Traversal(&__treeA,__LRD);

#endif //Non-Recursive-BinaryTree 




	return 0;
}