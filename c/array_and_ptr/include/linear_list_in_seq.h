/*
 * linear_list_in_seq.h
 *
 *  Created on: May 31, 2020
 *      Author: anji.zhou
 */

/*线性表的顺序实现*/
#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 10
#define LIST_TYPE int

typedef struct strSequenceLinerList
{
	LIST_TYPE *elem;         //c存储空间基地址
	unsigned int length;    // 当前长度
	unsigned int listSize;  //当前容量
}SequenceLinerList;

typedef enum
{
	OK,
	FAILED,
	OVERFLOW
}Status;

void linear_list_in_seq_main();
Status initSequenceLinerList(SequenceLinerList *list);
Status resizeSequenceLinerList(SequenceLinerList *list);
void printSequnceLinerList(SequenceLinerList *list);
Status insertSequenceLinerList(SequenceLinerList *list, unsigned int position, LIST_TYPE value);
