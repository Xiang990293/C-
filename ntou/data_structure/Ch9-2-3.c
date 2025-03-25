/* 程式範例: Ch9-2-3.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 20 /* 最大陣列尺寸 */
/* 函數: 插入排序法 */
void insertSort(int *data, int count)
{
	int i, j, k, temp;
	for (i = 1; i < count; i++)
	{					/* 第一層迴圈 */
		temp = data[i]; /* 建立初值 */
		j = i - 1;		/* 開始索引 */
		/* 空出一個插入位置 */
		while (j >= 0 && temp < data[j])
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = temp; /* 插入整數 */
		/* 顯示第一層迴圈執行後交換的陣列元素 */
		printf("%d: ", i);
		for (k = 0; k < count; k++)
			printf("[%d]", data[k]);
		printf("\n");
	}
}
/* 主程式 */
int main()
{
	int data[MAX_LEN];		 /* 整數陣列 */
	int i, key = 1, len = 0; /* 陣列尺寸 */
	while (key != -1)
	{
		printf("輸入欲排序的整數 ==> ");
		scanf("%d", &key); /* 讀取整數 */
		if (key > 0)
		{					   /* 只儲存正整數 */
			data[len++] = key; /* 更新陣列索引 */
		}
	}
	insertSort(data, len); /* 執行插入排序法 */
	/* 顯示排序後的整數陴列 */
	printf("\n輸出排序結果: ");
	for (i = 0; i < len; i++)
		printf("[%d]", data[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}
