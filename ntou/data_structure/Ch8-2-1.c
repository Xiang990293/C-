/* 程式範例: Ch8-2-1.c */
#include <stdio.h>
#include <stdlib.h>
#include "Ch8-2-1.h"
/* 函數: 使用邊線陣列建立圖形 */
void createGraph(int len, int *edge)
{
	int from, to; /* 邊線的起點和終點 */
	int i, j;
	for (i = 1; i < MAX_VERTICES; i++)
		for (j = 1; j < MAX_VERTICES; j++)
			graph[i][j] = 0; /* 清除鄰接矩陣 */
	for (i = 0; i < len; i++)
	{						  /* 讀取邊線的迴圈 */
		from = edge[i * 2];	  /* 邊線的起點 */
		to = edge[i * 2 + 1]; /* 邊線的終點 */
		graph[from][to] = 1;  /* 存入圖形的邊線 */
	}
}
/* 函數: 顯示圖形 */
void printGraph()
{
	int i, j;
	/* 使用迴圈顯示圖形 */
	for (i = 1; i < MAX_VERTICES; i++)
	{
		for (j = 1; j < MAX_VERTICES; j++)
			printf(" %d ", graph[i][j]);
		printf("\n");
	}
}
/* 主程式 */
int main()
{
	int edge[16][2] = {{1, 2}, {2, 1}, /* 邊線陣列 */
					   {1, 3},
					   {3, 1},
					   {2, 3},
					   {3, 2},
					   {2, 4},
					   {4, 2},
					   {3, 5},
					   {5, 3},
					   {4, 5},
					   {5, 4},
					   {4, 6},
					   {6, 4},
					   {5, 6},
					   {6, 5}};
	createGraph(16, &edge[0][0]); /* 建立圖形 */
	printf("圖形G的鄰接矩陣內容:\n");
	printGraph(); /* 顯示圖形 */
	system("PAUSE");
	return 0;
}
