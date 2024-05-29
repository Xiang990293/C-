/* 程式範例: Ch9-4-1.c */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "radixQueue.c"
/* 函數: 顯示排序陣列的內容 */
void showList(int *data)
{
	int i;
	for (i = 0; i < MAX_LEN; i++)
		printf("[%3d]", data[i]); /* 顯示陣列元素 */
	printf("\n");
}
/* 函數: 取出佇列內容回存到排序陣列 */
void refillList(int *data, RQueue head[])
{
	int i, j = 0;
	/* 走訪佇列開始指標的陣列 */
	for (i = 0; i < DIGIT_SIZE; i++)
		while (head[i] != NULL)
		{
			/* 取出佇列資料存回陣列 */
			data[j] = dequeue(head, i);
			j++;
		}
}
/* 函數: 基數排序法 */
void radixSort(int *data, RQueue head[])
{
	int i, j, max, nth_d;
	int exp = 0;
	int max_d = 0;
	max = data[0]; /* 找出陣列中的最大值 */
	for (i = 0; i < MAX_LEN; i++)
		if (data[i] > max)
			max = data[i];
	while (max > 0)
	{ /* 找出最大值的位數 */
		max_d++;
		max = max / 10;
	}
	for (i = 0; i < max_d; i++)
	{		   /* 執行各位數的排序 */
		exp++; /* 目前的位數 */
		for (j = 0; j < MAX_LEN; j++)
		{ /* 走訪排序陣列 */
			/* 計算排序值指定位數的值 */
			nth_d = data[j] % (int)pow(10, exp);
			nth_d = nth_d / (int)pow(10, exp - 1);
			/* 存入各位數的佇列 */
			enqueue(head, nth_d, data[j]);
		}
		refillList(data, head);
		printf("%3d 位數: ", (int)pow(10, exp - 1));
		showList(data);
	}
}
/* 主程式 */
int main()
{
	/* 排序的整數陣列 */
	int data[MAX_LEN] = {421, 67, 129, 438, 399, 111, 211, 237, 274, 723};
	RQueue head[DIGIT_SIZE]; /* 佇列開始指標的陣列 */
	int i;
	for (i = 0; i < DIGIT_SIZE; i++)
		head[i] = NULL;		/* 初始開始指標陣列 */
	printf("排序前內容: "); /* 排序前陣列內容 */
	showList(data);
	radixSort(data, head);	/* 執行基數排序法 */
	printf("排序後結果: "); /* 排序後陣列內容 */
	showList(data);
	system("PAUSE");
	return 0;
}
