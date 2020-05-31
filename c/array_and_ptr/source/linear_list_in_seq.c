#include <stdlib.h>
#include <stdio.h>
#include "linear_list_in_seq.h"


Status initSequenceLinerList(SequenceLinerList *list);
Status resizeSequenceLinerList(SequenceLinerList *list);
void printSequnceLinerList(SequenceLinerList *list);
Status insertSequenceLinerList(SequenceLinerList *list, unsigned int position, LIST_TYPE value);

/*初始化线性表*/
Status initSequenceLinerList(SequenceLinerList *list)
{
	list->elem = (LIST_TYPE *)malloc(sizeof(LIST_TYPE)*LIST_INIT_SIZE);
	if(!list->elem)
	{
		return OVERFLOW;
	}

	list->length = 0;
	list->listSize = LIST_INIT_SIZE;

	return OK;
}

Status resizeSequenceLinerList(SequenceLinerList *list)
{
	list->elem = (LIST_TYPE *)realloc(list->elem,sizeof(LIST_TYPE)*(list->listSize + LIST_INCREMENT));
	if(!list->elem)
	{
		return OVERFLOW;
	}

	list->listSize += LIST_INCREMENT;

	return OK;
}
/* 打印 */
void printSequnceLinerList(SequenceLinerList *list)
{
    printf("Begin print list...\n");
    printf("length=%d,listSize=%d.\n",list->length,list->listSize);

    if(!list->length)
    {
    	printf("no element in list...\n");
    	printf("End print list.\n");
    	return;
    }

    unsigned int i = 0;
    for (; i < list->length;i++)
    {
        printf("%d,",list->elem[i]);
    }
    printf("\nEnd print list.\n");
}

/*插入数据，从1开始，第一个元素是list.elem[0]*/
Status insertSequenceLinerList(SequenceLinerList *list, unsigned int position, LIST_TYPE value)
{
	if(position < 1 || position > list->length + 1)
	{
		return FAILED;
	}

	if(list->length + 1 > list->listSize)
	{
		if(OK != resizeSequenceLinerList(list))
		{
			return FAILED;
		}
	}

	LIST_TYPE* p = &list->elem[position -1];
	LIST_TYPE* q = &list->elem[list->length];
	for( ; p != q ; --q)
	{
		*q = *(q-1);
	}

	list->length ++;
	*p = value;

	return OK;
}

void linear_list_in_seq_main()
{
	SequenceLinerList list1;
	SequenceLinerList *list  = &list1;
	if(OK != initSequenceLinerList(list))
	{
		 printf("call initSequenceLinerList failed.\n");
		 return;
	};

	/*链表初始化*/
	unsigned int insertposition = 1;
	LIST_TYPE value = 0;
	for(;insertposition <= list->listSize;insertposition++)
	{
		if(OK != insertSequenceLinerList(list,insertposition, value))
		{
			 printf("call insertSequenceLinerList failed.\n");
			 return;
		}
		value++;
	}

	/*插入数据*/
	printf("/n*****************insert before*****************\n");
	printSequnceLinerList(list);
	if(OK != insertSequenceLinerList(list,5, 100))
	{
			printf("call insertSequenceLinerList failed.\n");
			return;
	}
	if(OK != insertSequenceLinerList(list,5, 120))
	{
			printf("call insertSequenceLinerList failed.\n");
			return;
	}
	printf("\n*****************insert end*****************\n");
	printSequnceLinerList(list);
}
