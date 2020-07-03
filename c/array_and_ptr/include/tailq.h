#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
//队列中的元素结构体。它有一个值，并且有前向指针和后向指针
//通过前后像指针，把队列中的节点(元素)连接起来
struct queue_entry_t
{
    int value;

    //从TAILQ_ENTRY的定义可知，它只能是结构体或者共用体的成员变量
    TAILQ_ENTRY(queue_entry_t) entry;
};

//定义一个结构体，结构体名为queue_head_t，成员变量类型为queue_entry_t
//就像有头节点的链表那样，这个是队列头。它有两个指针，分别指向队列的头和尾
TAILQ_HEAD(queue_head_t, queue_entry_t);
void tailq();
void tailq1();

