/* 程式範例: Ch9-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100 /* 最大陣列尺寸 */
/* 函數: 泡沫排序法 */
void bubbleSort(int *data, int count)
{
	int i, j, k; /* 變數宣告 */
	int temp;
	for (j = count; j > 1; j--)
	{								/* 第一層迴圈 */
		for (i = 0; i < j - 1; i++) /* 第二層迴圈 */
			/* 比較相鄰的陣列元素 */
			if (data[i + 1] < data[i])
			{
				temp = data[i + 1]; /* 交換陣列元素 */
				data[i + 1] = data[i];
				data[i] = temp;
			}
		/* 顯示第一層迴圈執行後交換的陣列元素 */
		printf("%d: ", count - j + 1);
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
	bubbleSort(data, len); /* 執行泡沫排序法 */
	/* 顯示排序後的整數陴列 */
	printf("\n輸出排序結果: ");
	for (i = 0; i < len; i++)
		printf("[%d]", data[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}
