#include "Stack-Nearby-Matching.h"

//5+5*(6)+9/3*1-(1+3(

void __Scan_From_String(char* str)
{
	char* p = str;

	__seqStack seq = __init_SeqStack();


	while (*p != '\0')
	{
		if (__Left_Bracket(*p))
		{
			__push_SeqStack(seq, p);
		}
		if (__Right_Bracket(*p))
		{
			if (__size_SeqStack(seq) > 0)
			{
				__pop_SeqStack(seq);
			}
			else
			{
				__Error_Log(str, "右括号未正确匹配到左括号", p);
				break;
			}
		}
		p++;
	}

	while (__size_SeqStack(seq) > 0)
	{
		__Error_Log(str, "左括号未正确匹配到右括号", __top_SeqStack(seq));
		printf("\n");
		__pop_SeqStack(seq);

	}

	__free_SeqStack(seq);

	return;
}

void __Error_Log(char* str, char* error, char* p)
{
	printf("%s\n", error);
	printf("%s\n", str);

	__int64 num = p - str;

	for (int i = 0; i < num; i++)
	{
		printf(" ");
	}
	printf("↑");
}

int __Left_Bracket(char p)
{
	return p == '(';
}
int __Right_Bracket(char p)
{
	return p == ')';
}
