/* 程式範例: queue.c */
struct Node
{					   /* 佇列結構的宣告 */
	int data;		   /* 資料 */
	struct Node *next; /* 結構指標 */
};
typedef struct Node QNode; /* 佇列節點的新型態 */
typedef QNode *LQueue;	   /* 串列佇列的新型態 */
LQueue front = NULL;	   /* 佇列的前端 */
LQueue rear = NULL;		   /* 佇列的尾端 */
/* 抽象資料型態的操作函數宣告 */
extern int isQueueEmpty();
extern void enqueue(int d);
extern int dequeue();
/* 函數: 檢查佇列是否是空的 */
int isQueueEmpty()
{
	if (front == NULL)
		return 1;
	else
		return 0;
}
/* 函數: 將資料存入佇列 */
void enqueue(int d)
{
	LQueue new_node;
	/* 配置節點記憶體 */
	new_node = (LQueue)malloc(sizeof(QNode));
	new_node->data = d;	   /* 存入佇列節點 */
	new_node->next = NULL; /* 設定初值 */
	if (rear == NULL)	   /* 是否是第一次存入 */
		front = new_node;  /* front指向new_node */
	else
		rear->next = new_node; /* 插入rear之後 */
	rear = new_node;		   /* rear指向new_node */
}
/* 函數: 從佇列取出資料 */
int dequeue()
{
	LQueue ptr;
	int temp;
	if (!isQueueEmpty())
	{					   /* 佇列是否是空的 */
		if (front == rear) /* 如果是最後一個節點 */
			rear = NULL;
		ptr = front;		 /* ptr指向front */
		front = front->next; /* 刪除第1個節點 */
		temp = ptr->data;	 /* 取得資料 */
		free(ptr);			 /* 釋回記憶體 */
		return temp;		 /* 傳回取出的資料 */
	}
	else
		return -1; /* 佇列是空的 */
}
