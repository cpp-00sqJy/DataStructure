#ifndef __DynamicArray__
#define __DynamicArray__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct __DynamicArray
{
	void** _p_Addr;

	int _m_Capacity;

	int _m_Size;

};

struct __DynamicArray* __initDynamicArray(const int _Capacity);

void __Insert_DynamicArray(struct __DynamicArray* _Addr,  void* _Data, int _Pos);

void __Traversal__DynamicArray(const struct __DynamicArray* _Addr, const void(*_Diy_Print)(void* arg));

void __DeletebyPos_DynamicArray(struct __DynamicArray* _Addr, int _Pos);

void __DeletebyValue_DynamicArray(struct __DynamicArray* _Addr, void (*_Compare_data)(void* _data1, void* _data2), void* _Data);

void __Free_DynamicArray(struct __DynamicArray* _Addr);


#endif // !__DynamicArray__
