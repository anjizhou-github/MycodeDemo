#include <stdio.h>
#include "array_and_ptr.h"

void showOneDimenArray()
{
	printf("**************一维数组和指针的关系*******************\n\n");

	char chArr[2] = {'a','b'};
	printf("chArr是char* 类型指针，其值的是数组中第一个元素的地址：%p\n" , chArr);
	printf("chArr + 1 表示的第二个元素的地址：%p\n" , chArr + 1);

	printf("&chArr是char*[] 类型指针，其类型是数组指针：%p\n" , &chArr);
	printf("&chArr + 1 表示的是整个数组的下一个地址：%p\n\n" , &chArr + 1);
}

void showTwoDimenArray()
{
	printf("**************二维数组和指针的关系*******************\n\n");
	printf("**************理解的关键是将二维数组当成一维数组来看待*******************\n\n");

	char chArr[2][2] = {{'a','b'},{'c','d'}};
	printf("chArr是char* 类型指针，其值的是数组中第一个元素的地址：%p\n" , chArr);
	printf("chArr + 1 表示的第二维数组第一个：%p\n" , chArr + 1);

	printf("&chArr是char*[][] 类型指针，其类型是数组指针：%p\n" , &chArr);
	printf("&chArr + 1 表示的是整个数组的下一个地址：%p\n" , &chArr + 1);
}
