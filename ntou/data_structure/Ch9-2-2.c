/* 程式範例: Ch9-2-2.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 20 /* 最大陣列尺寸 */
/* 函數: 選擇排序法 */
void selectSort(int *data, int count)
{
	int i, j, k, pos, temp; /* pos最小整數索引 */
	for (i = 0; i < count - 1; i++)
	{ /* 第一層迴圈 */
		pos = i;
		temp = data[pos];
		/* 找尋最小的整數 */
		for (j = i + 1; j < count; j++) /* 第二層迴圈 */
			if (data[j] < temp)
			{			 /* 是否更小 */
				pos = j; /* 找到最小整數 */
				temp = data[j];
			}
		data[pos] = data[i]; /* 交換兩個整數 */
		data[i] = temp;
		/* 顯示第一層迴圈執行後交換的陣列元素 */
		printf("%d: ", i + 1);
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
	selectSort(data, len); /* 執行選擇排序法 */
	/* 顯示排序後的整數陴列 */
	printf("\n輸出排序結果: ");
	for (i = 0; i < len; i++)
		printf("[%d]", data[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}
