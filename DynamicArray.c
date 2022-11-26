#include "DynamicArray.h"


struct __DynamicArray* __initDynamicArray(const int _Capacity)
{
	if (_Capacity <= 0)
	{
		return NULL;
	}

	struct __DynamicArray* _Array = (struct __DynamicArray*)malloc(sizeof(struct __DynamicArray));

	if (NULL == _Array)
	{
		return NULL;
	}

	_Array->_p_Addr = malloc(sizeof(void*) * _Capacity);

	_Array->_m_Capacity = _Capacity;

	_Array->_m_Size = 0;

	return _Array;

}

void __Insert_DynamicArray(struct __DynamicArray* _Addr, void* _Data, int _Pos)
{

	if (NULL == _Addr)
	{
		return;
	}

	if (NULL == _Data)
	{
		return;
	}

	if (_Pos < 0 || _Pos >= _Addr->_m_Size)
	{
		_Pos = _Addr->_m_Size;
	}

	if (_Addr->_m_Size == _Addr->_m_Capacity)
	{
		int _newSpace = _Addr->_m_Capacity * 2;

		void** _newDynamicArray = malloc(sizeof(void*) * _newSpace);

		memcpy(_newDynamicArray, _Addr->_p_Addr, sizeof(void*) * _Addr->_m_Capacity);

		free(_Addr->_p_Addr);

		_Addr->_p_Addr = _newDynamicArray;

		_Addr->_m_Capacity = _newSpace;

	}

	for (int i = _Addr->_m_Size - 1; i >= _Pos; i--)
	{
		_Addr->_p_Addr[i + 1] = _Addr->_p_Addr[i];

	}

	_Addr->_p_Addr[_Pos] = _Data;

	_Addr->_m_Size++;
}

void __Traversal__DynamicArray(const struct __DynamicArray* _Addr, const void(*_Diy_Print)(void* arg))
{
	if (NULL == _Addr)
	{
		return;
	}

	for (int i = 0; i < _Addr->_m_Size; i++)
	{
		_Diy_Print(_Addr->_p_Addr[i]);
	}

}

void __DeletebyPos_DynamicArray(struct __DynamicArray* _Addr, int _Pos)
{
	if (NULL == _Addr)
	{
		return;
	}

	if (_Pos < 0 || _Pos > _Addr->_m_Size - 1)
	{
		return;
	}

	for (int i = _Pos; i < _Addr->_m_Size; i++)
	{
		_Addr->_p_Addr[i] = _Addr->_p_Addr[i + 1];
	}

	_Addr->_m_Size--;
}

void __DeletebyValue_DynamicArray(struct __DynamicArray* _Addr, int (*_Compare_data)(void* _data1, void* _data2), void* _Data)
{
	if (NULL == _Addr)
	{
		return;
	}

	for (int i = 0; i < _Addr->_m_Size; i++)
	{
		if (_Compare_data(_Addr->_p_Addr[i], _Data))
		{
			__DeletebyPos_DynamicArray(_Addr, i);
		}
	}

}

void __Free_DynamicArray(struct __DynamicArray* _Addr)
{
	if (NULL == _Addr)
	{
		return;
	}

	if (_Addr->_p_Addr != NULL)
	{
		free(_Addr->_p_Addr);
		_Addr->_p_Addr = NULL;
	}

	free(_Addr);
	_Addr = NULL;
}

