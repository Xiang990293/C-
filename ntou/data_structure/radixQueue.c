/* 程式範例: radixQueue.c */
#define MAX_LEN 10
#define DIGIT_SIZE 10
struct Node
{					   /* 佇列結構的宣告 */
	int data;		   /* 資料 */
	struct Node *next; /* 結構指標 */
};
typedef struct Node QNode; /* 佇列節點的新型態 */
typedef QNode *RQueue;	   /* 佇列的新型態 */
/* 函數: 將資料存入佇列 */
void enqueue(RQueue head[], int i, int d)
{
	RQueue newnode, rear;
	/* 配置節點記憶體 */
	newnode = (RQueue)malloc(sizeof(QNode));
	newnode->data = d;	  /* 存入佇列節點 */
	newnode->next = NULL; /* 設定初值 */
	if (head[i] == NULL)  /* 第1個節點 */
		head[i] = newnode;
	else
	{
		rear = head[i]; /* 取得佇列的開始指標 */
		/* 找到最後1個節點 */
		while (rear->next != NULL)
			rear = rear->next;
		rear->next = newnode; /* 插入成為最後1個節點 */
	}
}
/* 函數: 從佇列取出資料 */
int dequeue(RQueue head[], int i)
{
	int temp;
	RQueue ptr = head[i];	 /* 取得佇列的開始指標 */
	head[i] = head[i]->next; /* 刪除第1個節點 */
	temp = ptr->data;		 /* 取得資料 */
	free(ptr);
	return temp;
}
