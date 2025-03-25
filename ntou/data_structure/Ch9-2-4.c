/* 程式範例: Ch9-2-4.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 30 /* 最大陣列尺寸 */
#define H_LEN 4	   /* h佇列的最大數 */
/* 函數: 謝耳排序法 */
void shellSort(int *data, int count)
{
	int incs[H_LEN] = {8, 4, 2, 1}; /* 設定h序列的增量 */
	int pos;					 /* 處理的目前索引 */
	int h;						 /* h序列的位移量 */
	int i, j, k, temp;
	for (i = 0; i < H_LEN; i++)
	{				 /* 處理h序列的迴圈 */
		h = incs[i]; /* 取得h位移量 */
		for (j = h; j < count; j++)
		{							   /* 交換迴圈 */
			temp = data[j];			   /* 保留值 */
			pos = j - h;			   /* 計算索引 */
			while (temp < data[pos] && /* 比較 */
				   pos >= 0 && j <= count)
			{
				data[pos + h] = data[pos]; /* 交換 */
				pos = pos - h;			   /* 下一個處理索引 */
			}
			data[pos + h] = temp; /* 與最後元素交換 */
		}
		/* 顯示處理後的陣列內容 */
		printf("h序列 %d: ", h);
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
	shellSort(data, len); /* 執行謝耳排序法 */
	/* 顯示排序後的整數陴列 */
	printf("\n輸出排序結果: ");
	for (i = 0; i < len; i++)
		printf("[%d]", data[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}
