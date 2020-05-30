#include "tailq.h"

void tailq()
{
    struct queue_head_t queue_head;
    struct queue_entry_t *q, *p, *s, *new_item;
    int i;

    TAILQ_INIT(&queue_head);

    for(i = 0; i < 3; ++i)
    {
        p = (struct queue_entry_t*)malloc(sizeof(struct queue_entry_t));
        p->value = i;

        //第三个参数entry的写法很怪，居然是一个成员变量名(field)
        TAILQ_INSERT_TAIL(&queue_head, p, entry);//在队尾插入数据
    }

    q = (struct queue_entry_t*)malloc(sizeof(struct queue_entry_t));
    q->value = 10;
    TAILQ_INSERT_HEAD(&queue_head, q, entry);//在队头插入数据

    //现在q指向队头元素、p指向队尾元素

    s = (struct queue_entry_t*)malloc(sizeof(struct queue_entry_t));
    s->value = 20;
    //在队头元素q的后面插入元素
    TAILQ_INSERT_AFTER(&queue_head, q, s, entry);


    s = (struct queue_entry_t*)malloc(sizeof(struct queue_entry_t));
    s->value = 30;
    //在队尾元素p的前面插入元素
    TAILQ_INSERT_BEFORE(p, s, entry);

    //现在进行输出
	//获取第一个元素
    s = TAILQ_FIRST(&queue_head);
    printf("the first entry is %d\n", s->value);

	//获取下一个元素
    s = TAILQ_NEXT(s, entry);
    printf("the second entry is %d\n\n", s->value);

    //删除第二个元素, 但并没有释放s指向元素的内存
    TAILQ_REMOVE(&queue_head, s, entry);
    free(s);


    new_item = (struct queue_entry_t*)malloc(sizeof(struct queue_entry_t));
    new_item->value = 100;


    printf("now, print again\n");
    i = 0;
    TAILQ_FOREACH(p, &queue_head, entry)//用foreach遍历所有元素
    {
        printf("the %dth entry is %d\n", i, p->value);
    }

    p = TAILQ_LAST(&queue_head, queue_head_t);
    printf("last is %d\n", p->value);

    p = TAILQ_PREV(p, queue_head_t, entry);
    printf("the entry before last is %d\n", p->value);
}
